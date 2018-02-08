<?php
  $theme_path = drupal_get_path('theme', 'fyi');
?>
<?php include_once($theme_path . '/includes/header.inc'); ?>

<div id="main" class="container clearfix<?php if ($main_menu) { print ' with-navigation'; } ?>">
    <?php print $donate_link; ?>
    <div id="rotator">
      <?php print render($page['home_rotator']); ?>
    </div>

    <section id="content" role="main">
      <?php print $messages; ?>

      <?php if ($page['highlighted']): ?>
        <div id="highlighted" class="inner"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>

      <div class="home-news">
        <div class="intro">
          <p>Connecting <span>TEENS</span> Creating Families, Changing Lives</p>
        </div>
          <?php $viewName = 'home_page_news';
                print views_embed_view($viewName);
          ?>
        
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
