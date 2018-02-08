<?php

/**
 * Returns HTML for status and/or error messages, grouped by type.
 *
 * Override of theme_status_message() to use the classes for Bootstrap alert
 * message boxes
 *
 * An invisible heading identifies the messages for assistive technology.
 * Sighted users see a colored box. See http://www.w3.org/TR/WCAG-TECHS/H69.html
 * for info.
 *
 * @param $variables
 *   An associative array containing:
 *   - display: (optional) Set to 'status' or 'error' to display only messages
 *     of that type.
 */
function fyi_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  // Bootstrap classes
  $alert_classes = array(
    'status' => 'alert-success',
    'error' => 'alert-error',
    'warning' => 'alert-warning',
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= '<div class="alert alert-block ' . $alert_classes[$type] . '">';
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
  }
  return $output;
}

/**
 * Overrides theme_links().
 * Returns HTML for a set of links. Does a lot of tweaking around classes that
 * the core implementation does not, and displays child menu links in a
 * dropdown.
 */
function fyi_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];

  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';
    $output .= '<ul' . drupal_attributes($attributes) . '>';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'li',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $children = array();
      if (isset($link['below'])) {
        $children = $link['below'];
      }

      $attributes = array('class' => array($key));

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_links) {
        $attributes['class'][] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page())) && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $attributes['class'][] = 'active';
      }

      if (count($children) > 0) {
        $attributes['class'][] = 'dropdown';
        $link['attributes']['data-toggle'] = 'dropdown';
        $link['attributes']['class'][] = 'dropdown-toggle';
      }

      if (!isset($link['attributes'])) {
        $link['attributes'] = array();
      }

      $class = (count($children) > 0) ? 'dropdown' : NULL;
      $output .= '<li' . drupal_attributes(array('class' => array($class))) . '>';

      if (isset($link['href'])) {
        if (count($children) > 0) {
          $link['html'] = TRUE;
          $link['title'] .= '<b class="caret"></b>';
          $output .=  '<a' . drupal_attributes($link['attributes']) . ' href="#">' . $link['title'] . '</a>';
        }
        else{
        // Pass in $link as $options, they share the same keys.
         $output .= l($link['title'], $link['href'], $link);
        }
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;

      if (count($children) > 0) {
        $attributes = array();
        $attributes['class'] = array('dropdown-menu');

        $output .= theme('fyi_links', array('links' => $children, 'attributes' => $attributes));
      }

      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * Displays a gallery node as a teaser.
 *
 * The Galleries page displays a grid of gallery teasers. Each gallery teaser is
 * themed as a node using node.tpl.php or one if its overrides. Where that
 * template file calls @code render($content) @endcode, the output of this
 * function is returned.
 */
function fyi_media_gallery_teaser($variables) {
  $element = $variables['element'];
  $node = $element['#node'];

  if (isset($element['media_gallery_media'][0])) {
    $element['media_gallery_media'][0]['#theme'] = 'media_gallery_file_field_inline';
    $image = drupal_render($element['media_gallery_media'][0]);
  }
  else {
    $image = theme('image', array('path' => drupal_get_path('module', 'media_gallery') . '/images/empty_gallery.png'));
  }

  $link_vars = array();
  $link_vars['image'] = $image;
  $uri = entity_uri('node', $node);
  $link_vars['link_path'] = $uri['path'];
  $link_vars['classes'] = array('media-gallery-thumb');

  $output = '<div class="media-collection-item-wrapper"><img class="stack-image" src="' . base_path() . drupal_get_path('module', 'media_gallery') . '/images/stack_bg.png" />' . theme('media_gallery_item', $link_vars) . '</div>';

  // Set the variables to theme the meta data if there is a term on the node
  if (isset($node->term)) {
    $term = $node->term;
    $meta_vars = array();
    $meta_vars['location'] = $term->media_gallery_image_info_where[LANGUAGE_NONE][0]['value'];
    $meta_vars['title'] = $node->title;
    $meta_vars['body'] = $node->media_gallery_description[LANGUAGE_NONE][0]['value'];
    $meta_vars['link_path'] = $link_vars['link_path'];
    // Organize the file count by type. We only expect images and videos for
    // now, so we put those first and group the others together into a general
    // category at the end.
    $type_count = media_gallery_get_media_type_count($node, 'media_gallery_media_original');
    $description = array();
    if (isset($type_count['image'])) {
      $count = $type_count['image'];
      $description[] = format_plural($count, '<span>@num image</span>', '<span>@num images</span>', array('@num' => $count));
      unset($type_count['image']);
    }
    if (isset($type_count['video'])) {
      $count = $type_count['video'];
      $description[] = format_plural($count, '<span>@num video</span>', '<span>@num videos</span>', array('@num' => $count));
      unset($type_count['video']);
    }
    if (!empty($type_count)) {
      $count = array_sum($type_count);
      $description[] = format_plural($count, '<span>@num other item</span>', '<span>@num other items</span>', array('@num' => $count));
    }
    $meta_vars['description'] = implode(', ', $description);

    // Add the meta information
    $output .= theme('media_gallery_meta', $meta_vars);
  }

  return $output;
}


/**
 * Theme the meta data for a media gallery item
 *
 * @param string $display
 *   Which meta data fields to display
 * @param string $location
 *   The location to place the meta data on the media item
 * @param string $title
 *   The title to display (if applicable)
 * @param string $license
 *   The license information for the media item
 * @param string $description
 *   A description to display with the title (if applicable).
 */
function fyi_media_gallery_meta($variables) {
  $location = $variables['location'];
  $title = $variables['title'];
  $body = isset($variables['body']) ? $variables['body'] : "";
  $description = $variables['description'];
  $link_path = $variables['link_path'];
  // Add a top sliding door to the meta info
  $meta = '<span class="top slider"><span class="top-inner slider"></span></span>';

  // Open the content sliding door for the meta info
  $meta .= '<span class="meta-outer slider"><span class="meta-inner slider">';

  // If we display nothing, nothing else matters
  if ($location != 'nothing') {
    // Add a wrapper around the meta data
    #$meta .= '<div class="meta-wrapper ' . $location . '">';
    // Add title
    $attributes = array('class' => array('meta-wrapper', 'cbEnabled', $location));
    $meta .= $title ? '<span class="media-title">' . $title . '</span>' : '';
    if ($body) {
      $meta .= '<span class="media-body">' . $body . '</span>';
    }
    if ($description) {
      $meta .= '<span class="media-description">' . $description . '</span>';
    }
    // Close the content sliding door
    $meta .= '</span></span>';

    // Add a bottom sliding door
    $meta .= '<span class="bottom slider"><span class="bottom-inner slider"></span></span>';

    // Close the wrapper around the meta data
    $meta_link = $location == 'hover' ? l($meta, $link_path, array('attributes' => $attributes, 'html' => TRUE)) : '<span class="meta-wrapper">' . $meta . '</span>';
  }

  return isset($meta_link) ? $meta_link : NULL;
}

function fyi_media_gallery_media_item_lightbox($variables) {
  $element = $variables['element'];
  $gallery_node = new FieldsRSIPreventor($element['#media_gallery_entity']);
  $file = $element['#file'];

  // The lightbox JavaScript requires width and height attributes to be set on
  // the displayed image, but if we're displaying an image derivative, we need
  // to create it in order to know its width and height.
  // @todo Improve the JavaScript to not require this.
  if ($element['file']['#theme'] == 'image_style') {
    $style_name = $element['file']['#style_name'];
    $style_path = image_style_path($style_name, $file->uri);
    if (!file_exists($style_path)) {
      $style = image_style_load($style_name);
      image_style_create_derivative($style, $file->uri, $style_path);
    }
    $info = image_get_info($style_path);
    $element['file'] += array('#attributes' => array());
    $element['file']['#attributes'] += array('width' => $info['width'], 'height' => $info['height']);
  }

  $image = drupal_render($element['file']);

  $matches = NULL;
  if (preg_match('@<img .*?/>@', $image, $matches)) {
    $image = $matches[0];
  }
  else {

  }

  $gallery_id = $element['#media_gallery_entity']->nid;
  $media_id = $element['#file']->fid;

  // Create an array of variables to be added to the main image link.
  $link_vars = array();
  $link_vars['image'] = $image;
  $link_vars['link_path'] = "media-gallery/detail/$gallery_id/$media_id";
  $link_vars['no_link'] = $element['#bundle'] != 'image' ? TRUE : FALSE;

  if ($gallery_node->getValue('media_gallery_allow_download') == TRUE) {
    $download_link = $element['#bundle'] == 'image' ? theme('media_gallery_download_link', array('file' => $file)) : l(t('View detail page'), $link_vars['link_path']);
  }

  else {
    // Very ugly fix: This prevents the license info from being either hidden
    // or causing scrollbars (depending on the browser) in cases where a
    // download link is not being shown. There may be a CSS-only fix for this,
    // but we haven't found one yet.
    $download_link = '&nbsp;';
  }

  $media_gallery_detail =
      '<div class="lightbox-stack">' .
      theme('media_gallery_item', $link_vars) .
      '</div>';
  // The license info has been themed already, keep it from being rendered as a child
  $element['field_license']['#access'] = FALSE;

  $output = 'Error';
  // If the format is to have the description as well, we add it here
  if (!empty($gallery_node->media_gallery_lightbox_extras[LANGUAGE_NONE][0]['value'])) {
    $output =
      $media_gallery_detail .
      // '<strong>' . drupal_render($element['media_title']) . '</strong>' .
      drupal_render($element['media_description']);
      // '<div class="media-gallery-detail-info">' .
      //   $download_link .
      // '</div>';
  } else {
    $output = $media_gallery_detail;
  }

  return $output;
}

function fyi_menu_tree__menu_footer_menu($variables){
  $footer_nav = explode("</li><li>", $variables['tree']);
  $footer_nav = menu_navigation_links('menu-footer-menu');
  $footer_nav = array_chunk($footer_nav, (count($footer_nav) / 2));
  $output = "";
  foreach($footer_nav as $links) {
    $output .= theme('links', array(
      'links' => $links,
      'attributes' => array(
        'class' => array('left'),
      ),
      'heading' => array(
        'text' => t('Footer Nav'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));
  }

  return $output;
}
/**
 * Overrides theme_progress_bar().
 *
 * Use the Bootstrap progress bar component.
 */
function fyi_progress_bar($variables) {
  $variables['attributes']['class'][] = 'progress';
  $variables['attributes']['class'][] = 'progress-striped';

  return "<div". drupal_attributes($variables['attributes']) .">
  <div class=\"bar\"
       style=\"width: ". $variables['percent'] ."%;\"></div>
  </div>";
}
