<?php
  $theme_path = drupal_get_path('theme', 'fyi');
?>
<?php include_once($theme_path . '/includes/header.inc'); ?>

<div id="main" class="container clearfix<?php if ($main_menu) { print ' with-navigation'; } ?>">
    <section id="content" role="main">

      <?php if (isset($section_title) && $title): ?>
        <div id="page-title" class="inline">
          <span><?php print $section_title; ?></span> &rsaquo;
          <h1 class="title"><?php print $title; ?></h1>
        </div>
      <?php endif; ?>

      <?php print render($title_prefix); ?>
      <?php if (!isset($section_title) && $title): ?>
        <div id="page-title" class="inline">
          <h1 class="title"><?php print $title; ?></h1>
        </div>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      
      <div class="inner">
      <?php if ($page['highlighted']): ?>
        <div id="highlighted"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      
      <?php print $messages; ?>
      
      <?php if ($tabs): ?>
        <div class="tabs"><?php print render($tabs); ?></div>
      <?php endif; ?>
      
      <?php print render($page['help']); ?>
      
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      
      <?php print render($page['content']); ?>
      
      <?php print $feed_icons; ?>
    
      </div> <!-- /.inner -->
    </section> <!-- /#content -->

    <aside id="sidebar-first" class="column sidebar" role="complementary">
      <?php print render($page['sidebar_first']); ?>
    </aside> <!-- /#sidebar-first -->

    <?php if ($page['sidebar_second']): ?>
      <aside id="sidebar-second" class="column sidebar" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside> <!-- /.section, /#sidebar-second -->
    <?php endif; ?>

</div> <!-- /#main -->

<?php include_once($theme_path . '/includes/footer.inc'); ?>
