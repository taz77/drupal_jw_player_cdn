<?php
// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
?>
<article<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
    <header>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
    <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
    <?php endif; ?>  

  <div<?php print $content_attributes; ?>>
    <?php
    // Get our URL query variables.
    $options = drupal_get_query_parameters();
    // Build our video player that will load the initial segment.
    // Print the description of the Video Series.
    print render($content['jw_player_cdn_video_desc']);
    // Print all of the segments for this video.
    print render($content['jw_player_cdn_video_series']);
    ?>
  </div>
</article>