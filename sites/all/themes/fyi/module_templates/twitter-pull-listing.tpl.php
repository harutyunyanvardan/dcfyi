<?php

/**
 * @file
 * Theme template for a list of tweets.
 *
 * Available variables in the theme include:
 *
 * 1) An array of $tweets, where each tweet object has:
 *   $tweet->id
 *   $tweet->username
 *   $tweet->userphoto
 *   $tweet->text
 *   $tweet->timestamp
 *   $tweet->time_ago
 *
 * 2) $twitkey string containing initial keyword.
 *
 * 3) $title
 *
 */
?>

<?php if (is_array($tweets)): ?>
  <ul class="tweets-pulled-listing social-feed">
  <?php foreach ($tweets as $tweet_key => $tweet): ?>
    <li class="item clearfix">
      <span class="tweet-text message"><?php print twitter_pull_add_links($tweet->text); ?></span>
    </li>
  <?php endforeach; ?>
  </ul>
<?php endif; ?>