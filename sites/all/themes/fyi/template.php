<?php

$theme_path = drupal_get_path('theme', 'fyi');
// include_once($theme_path . '/includes/fyi.inc');
// Include a file with theme override functions
include_once($theme_path . '/includes/modules/theme.inc');

/**
 * @file
 * Contains theme override functions and preprocess functions for the FYI theme.
 */

/**
 * Override or insert variables in the html_tag theme function.
 */
function fyi_process_html_tag(&$variables) {
  $tag = &$variables['element'];

  if ($tag['#tag'] == 'style' || $tag['#tag'] == 'script') {
    // Remove redundant type attribute and CDATA comments.
    unset($tag['#attributes']['type'], $tag['#value_prefix'], $tag['#value_suffix']);

    // Remove media="all" but leave others unaffected.
    if (isset($tag['#attributes']['media']) && $tag['#attributes']['media'] === 'all') {
      unset($tag['#attributes']['media']);
    }
  }
}

/**
 * Implements hook_css_alter().
 *
 * Check the files listed in the exclude[css] array in the theme info file and
 * remove them from the list of CSS files.
 */
function fyi_css_alter(&$css) {
  $reset_options = array(
    'group' => CSS_SYSTEM,
    'every_page' => TRUE,
    'weight' => -100,
  );
  
  $css += drupal_add_css(drupal_get_path('theme', 'fyi') . '/css/normalize.css', $reset_options);

  $excluded_files = fyi_theme_get_info('exclude');
  if (isset($excluded_files['css']) && is_array($excluded_files['css'])) {
    foreach ($excluded_files['css'] as $filename) {
      unset($css[$filename]);
    }
  }
}

/**
 * Implements hook_js_alter().
 *
 * Check the files listed in the exclude[js] array in the theme info file and
 * remove them from the list of JS files.
 */
function fyi_js_alter(&$js) {
  $excluded_files = fyi_theme_get_info('exclude');
  if (isset($excluded_files['js']) && is_array($excluded_files['js'])) {
    foreach ($excluded_files['js'] as $filename) {
      unset($js[$filename]);
    }
  }
}

/**
 * Override or insert variables into the page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function fyi_preprocess_page(&$variables, $hook) {
  
  $active_trail = menu_get_active_trail();
  if (isset($active_trail[1]) && isset($active_trail[1]['menu_name'])) {
    if($active_trail[1]['menu_name']  == 'main-menu') {
      $variables['section_title'] = $active_trail[1]['title'];
    }
  }
  
  if (isset($variables['node'])) {
    $node = $variables['node'];
    if ($node->type == 'people_profile') {
      $variables['section_title'] = "Meet the FYI Team";
    }
    if ($node->type == 'article') {
      $type = field_get_items('node', $node, 'field_article_type');
      if ($type[0]['value'] == 'blog') {
        $variables['section_title'] = t("Blog");
      }
      if ($type[0]['value'] == 'news') {
        $variables['section_title'] = t("News");
      }
    }
  }
  

  if ($variables['is_front']) {
    $linkOptions = array(
      'attributes' => array(
        'id' => 'donate',
      ),
    );
    $linkDest = variable_get('fyi_donate_page', '');
    $variables['donate_link'] = l(t('Donate Now'), $linkDest, $linkOptions);
  }
  
// Make sure the menu module is in use before setting menu vars.
  if (module_exists('menu')) {

    // Secondary nav
    $variables['secondary_nav'] = FALSE;
    if ($variables['secondary_menu']) {
      $secondary_menu = menu_load(variable_get('menu_secondary_links_source', 'user-menu'));
    
      // Build list
      $variables['secondary_nav'] = theme('links', array(
        'links' => $variables['secondary_menu'],
        'label' => $secondary_menu['title'],
        'type' => 'success',
        'attributes' => array(
          'id' => 'user-menu',
          'class' => array('inline'),
        ),
        'heading' => array(
          'text' => t('Secondary menu'),
          'level' => 'h2',
          'class' => array('element-invisible'),
        ),
      ));
    }
  }
}

/**
 * Override or insert variables into the node templates.
 * -- taken directly from Zen
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function fyi_preprocess_node(&$variables, $hook) {
  // Add $unpublished variable.
  $variables['unpublished'] = (!$variables['status']) ? TRUE : FALSE;

  // Add pubdate to submitted variable.
  $variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['node']->created, 'medium') . '">' . $variables['date'] . '</time>';
  if ($variables['display_submitted']) {
    $variables['submitted'] = "<p class='submitted'> " . t('Posted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['pubdate'])) . "</p>";
  }

  // Add a class for the view mode.
  if (!$variables['teaser']) {
    $variables['classes_array'][] = 'view-mode-' . $variables['view_mode'];
  }

  // Add a class to show node is authored by current user.
  if ($variables['uid'] && $variables['uid'] == $GLOBALS['user']->uid) {
    $variables['classes_array'][] = 'node-by-viewer';
  }

  $variables['title_attributes_array']['class'][] = 'node-title';
}

/**
 * Preprocess variables for region.tpl.php
 * -- taken directly from Zen
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
function fyi_preprocess_region(&$variables, $hook) {
  // Sidebar regions get some extra classes and a common template suggestion.
  if (strpos($variables['region'], 'sidebar_') === 0) {
    // Allow a region-specific template to override region--sidebar.
    array_unshift($variables['theme_hook_suggestions'], 'region__no_wrapper');
  }
  // Use a template with no wrapper for the content region.
  if ($variables['region'] == 'content' || $variables['region'] == 'footer') {
    // Allow a region-specific template to override region--no-wrapper.
    array_unshift($variables['theme_hook_suggestions'], 'region__no_wrapper');
  }

}

/**
 * Preprocess variables for block.tpl.php
 *
 * @see block.tpl.php
 */
function fyi_preprocess_block(&$variables) {
  $block = $variables['block'];

  // Use a bare template for the page's main content.
  if ($variables['block_html_id'] == 'block-system-main') {
    $variables['theme_hook_suggestions'][] = 'block__no_wrapper';
  }
  
  if ($variables['block_html_id'] == 'block-system-main-menu') {
    $variables['theme_hook_suggestions'][] = 'block__main_nav';
  }
  
  $variables['title_attributes_array']['class'][] = 'block-title';
  
  if ($block->region == 'footer') {
    $variables['classes_array'][] = "block-" . $variables['block_id'];
  }
}

/**
 * Implements theme_preprocess_table().
 * Adds classes to the <table> to use Bootstrap styling.
 */
function fyi_preprocess_table(&$variables) {
  $variables['attributes']['class'][] = 'table';
  $variables['attributes']['class'][] = 'table-striped';
}

/**
 * Get the given setting for this theme
 */
function fyi_theme_get_info($setting_name, $theme = NULL) {
  // If no key is given, use the current theme if we can determine it.
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  $return = array();

  if ($theme) {
    $themes = list_themes();
    $theme_object = $themes[$theme];

    // Create a list which includes the current theme and all its base themes.
    if (isset($theme_object->base_themes)) {
      $theme_keys = array_keys($theme_object->base_themes);
      $theme_keys[] = $theme;
    }
    else {
      $theme_keys = array($theme);
    }
    foreach ($theme_keys as $theme_key) {
      if (!empty($themes[$theme_key]->info[$setting_name])) {
        $return = $themes[$theme_key]->info[$setting_name];
      }
    }
  }
  return $return;
}

function _fyi_to_html($text) {
  $bbcode = array(
    "[strong]", "[/strong]",
    "[b]",  "[/b]",
    "[u]",  "[/u]",
    "[i]",  "[/i]",
    "[em]", "[/em]",
    "[span]", "[/span]",
    "[br]"
  );

  $htmlcode = array(
    "<strong>", "</strong>",
    "<strong>", "</strong>",
    "<u>", "</u>",
    "<em>", "</em>",
    "<em>", "</em>",
    "<span>", "</span>",
    "<br />"
  );
  return str_replace($bbcode, $htmlcode, $text);
}
