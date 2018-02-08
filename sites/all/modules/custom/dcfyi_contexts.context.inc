<?php
/**
 * @file
 * dcfyi_contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dcfyi_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_landing';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-events/dcfyi-blog' => 'news-events/dcfyi-blog',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-porto_blog-block' => array(
          'module' => 'views',
          'delta' => 'porto_blog-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['blog_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact-us' => 'contact-us',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'formblock-contact_site' => array(
          'module' => 'formblock',
          'delta' => 'contact_site',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nivo_slider-nivo_slider' => array(
          'module' => 'nivo_slider',
          'delta' => 'nivo_slider',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-latest_posts-block' => array(
          'module' => 'views',
          'delta' => 'latest_posts-block',
          'region' => 'content',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'our_story';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'who-we-are/our-story' => 'who-we-are/our-story',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-our_history-block' => array(
          'module' => 'views',
          'delta' => 'our_history-block',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['our_story'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_context';
  $context->description = '';
  $context->tag = '';
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
        //'block-8' => array(
        //  'module' => 'block',
        //  'delta' => '8',
        //  'region' => 'footer_1',
        //  'weight' => '-10',
        //),
        'views-twitter_feed-block' => array(
          'module' => 'views',
          'delta' => 'twitter_feed-block',
          'region' => 'footer_2',
          'weight' => '-10',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'footer_3',
          'weight' => '-10',
        ),
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'footer_4',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sitewide_context'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'team';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'who-we-are/team' => 'who-we-are/team',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-porto_team-block' => array(
          'module' => 'views',
          'delta' => 'porto_team-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['team'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'teen_foster_care';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'what-we-do/teen-foster-care' => 'what-we-do/teen-foster-care',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-faq-block' => array(
          'module' => 'views',
          'delta' => 'faq-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['teen_foster_care'] = $context;

  return $export;
}
