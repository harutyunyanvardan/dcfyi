<?php
/**
 * @file
 * taoti_faceted_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function taoti_faceted_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'taoti_faceted_search_global';
  $context->description = 'Always on context provided by the Taoti: Faceted Search feature';
  $context->tag = 'Taoti: Faceted Search';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search_api_page-default' => array(
          'module' => 'search_api_page',
          'delta' => 'default',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Always on context provided by the Taoti: Faceted Search feature');
  t('Taoti: Faceted Search');
  $export['taoti_faceted_search_global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'taoti_faceted_search_page';
  $context->description = 'Default search page provided by the Taoti: Faceted Search feature.';
  $context->tag = 'Taoti: Faceted Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk' => array(
          'module' => 'facetapi',
          'delta' => 'zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Default search page provided by the Taoti: Faceted Search feature.');
  t('Taoti: Faceted Search');
  $export['taoti_faceted_search_page'] = $context;

  return $export;
}
