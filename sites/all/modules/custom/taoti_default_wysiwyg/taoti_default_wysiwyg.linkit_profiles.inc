<?php
/**
 * @file
 * taoti_default_wysiwyg.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function taoti_default_wysiwyg_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'default';
  $linkit_profile->admin_title = 'Default';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'filtered_html' => 'filtered_html',
      'full_html' => 'full_html',
      'plain_text' => 0,
    ),
    'search_plugins' => array(
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_page' => 0,
        'comment_node_article' => 0,
        'comment_node_carousel' => 0,
        'comment_node_contact' => 0,
        'comment_node_event' => 0,
        'comment_node_faq' => 0,
        'comment_node_home_concept' => 0,
        'comment_node_one_page' => 0,
        'comment_node_our_history' => 0,
        'comment_node_parallax' => 0,
        'comment_node_portfolio' => 0,
        'comment_node_team' => 0,
        'comment_node_testimonials' => 0,
        'comment_node_twitter_feed' => 0,
        'comment_node_video_background' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'page' => 0,
        'article' => 0,
        'carousel' => 0,
        'contact' => 0,
        'event' => 0,
        'faq' => 0,
        'home_concept' => 0,
        'one_page' => 0,
        'our_history' => 0,
        'parallax' => 0,
        'portfolio' => 0,
        'team' => 0,
        'testimonials' => 0,
        'twitter_feed' => 0,
        'video_background' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'audio' => 0,
        'image' => 0,
        'video' => 0,
        'default' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'tags' => 0,
        'parallax' => 0,
        'portfolio' => 0,
        'skills' => 0,
        'team' => 0,
        'video_background' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'imce' => 1,
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['default'] = $linkit_profile;

  return $export;
}
