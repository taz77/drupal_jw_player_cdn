<?php
/**
 * @file
 * Default theme implementation to display the video series information.
 *
 * Variables available:
 * - $segment_title: The URL of the video to display embed code for
 * - $segment_desc: The style name of the embed code to use
 * - $segment_length: The style settings for the embed code
 * - $segment_thumb: The name of the video handler
 */

// Build a url query string for the linking of the video segements.
$query = array();
$query['vid'] = $vid;
?>
<div class="jw-player-cdn">
  <div class="jw-player-cdn-video-series">
    <div class="jw-player-cdn-video-series-title">
      <a href="<?php echo url(current_path(), array('query' => $query)); ?>"><?php print $segment_title; ?></a>
    </div>
    <div class="jw-player-cdn-video-series-desc">
      <?php print $segment_desc; ?>
    </div>
    <div class="jw-player-cdn-video-series-lenth">
      <?php print $segment_length; ?>
    </div>
    <div class="jw-player-cdn-video-series-thumb">
      <a href="<?php print $segment_thumbnail; ?>">Thumbnail Link</a>
    </div>
  </div>
</div>