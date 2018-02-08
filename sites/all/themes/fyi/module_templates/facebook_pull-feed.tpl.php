<ul class="facebook-feed social-feed">

<?php foreach ($items as $item): ?>
  <li class="item">
    <span class="message">
      <?php echo isset($item->message) ? $item->message : ""; ?>
      <?php echo isset($item->story) ? $item->story : ""; ?>
      <?php if ($item->type === 'link'): ?>
        <?php echo $item->description; ?>
        <?php echo l($item->name, $item->link, array("attributes" => array("target" => "_blank"))); ?>
      <?php endif; ?>
    </span>
    <span class="facebook-feed-time time"><?php echo t('!time ago.', array('!time' => format_interval(time() - strtotime($item->created_time)))); ?></span>
    
  </li>
<?php endforeach; ?>
</ul>
