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
?>

<div class="jw-player-cdn">
  <div class="jw-player-cdn-video-series">
    <div class="jw-player-cdn-video-series-title">
      <?php print $segment_title; ?>
    </div>
    <div class="jw-player-cdn-video-series-desc">
      <?php print $segment_desc; ?>
    </div>
    <div class="jw-player-cdn-video-series-lenth">
      <?php print $segment_length; ?>
    </div>
    <div class="jw-player-cdn-video-series-thumb">
      <?php print $segment_title; ?>
    </div>
  </div>
</div>