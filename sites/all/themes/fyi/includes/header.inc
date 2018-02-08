<header id="header" role="banner"><div class="container">
  <?php if ($site_name): ?>
    <?php if ($title): ?>
      <div id="site-name">
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
      </div>
    <?php else: /* Use h1 when the content title is empty */ ?>
      <h1 id="site-name">
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
      </h1>
    <?php endif; ?>
  <?php endif; ?>

  <?php if ($site_slogan): ?>
    <div id="site-slogan"><?php print $site_slogan; ?></div>
  <?php endif; ?>
  
  <?php if ($secondary_nav): ?>
    <nav id="secondary" role="secondary-nav"><?php print $secondary_nav; ?></nav>
  <?php endif; ?>

  <?php print render($page['header']); ?>

</div></header> <!-- /.inner, /#header -->