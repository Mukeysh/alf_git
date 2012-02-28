<?php

/**
  Available variables in the theme include:

  1) an array of $tweets, where each tweet object has:
      $tweet->id
      $tweet->username
      $tweet->userphoto
      $tweet->text
      $tweet->timestamp

  2) $twitkey string containing initial keyword.

  3) $title

*/

//drupal_add_css (drupal_get_path('module', 'twitter_pull') . '/twitter-pull-listing.css');

?>

  <?php if (is_array($tweets)): ?>
    <ul>
    <?php foreach ($tweets as $tweet):  ?>
      <li>
        <?php if (substr($twitkey,0,1) == "#"):?>
         <img src="<?php print $tweet->userphoto; ?>">
         <span class="tweet-author"><?php print l($tweet->username, 'http://twitter.com/' . $tweet->username); ?></span>
        <?php endif;?>
        <span class="tweet-text"><?php print twitter_pull_add_links($tweet->text); ?></span>
        <div class="tweet-time"><?php print l(format_interval(time() - $tweet->timestamp) . ' ' . t('ago'), 'http://twitter.com/' . $tweet->username . '/status/' . $tweet->id);?></div>
      </li>
    <?php endforeach; ?>
    </ul>
  <?php endif; ?>