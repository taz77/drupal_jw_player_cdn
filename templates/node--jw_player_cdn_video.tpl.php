<article<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
    <header>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <div<?php print $content_attributes; ?>>
    <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    // Get our URL query variables.
    $options = drupal_get_query_parameters();
    ?>
    <div class="jwplayer-video">
      <video id="<?php print $html_id ?>" width="<?php print $width ?>" height="<?php print $height ?>" controls="controls" preload="none"<?php if (isset($image)) : ?> poster="<?php print $image ?>"<?php endif ?>>
        <source src="<?php print $file_url ?>" />
      </video>
    </div>
    <?php
    // Display our video player that will load the initial segment.
    print render($jw_player_markup);
    // Print the description of the Video Series.
    print render($content['jw_player_cdn_video_desc']);
    // Print all of the segments for this video.
    print render($content['jw_player_cdn_video_series']);
    ?>
  </div>
</article>