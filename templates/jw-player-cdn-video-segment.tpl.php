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
 * - $vid: Delta of the video to load
 * - $thumbnail_height: Thumbnail height
 * - $thumbnail_width: Thumbnail width
 */
// Build a url query string for the linking of the video segements.
$query = array();
$query['vid'] = $vid;

// Process the thumbnail.
$variables = array(
  'path' => $segment_thumbnail,
  'alt' => $segment_title,
  'title' => 'Video Thumbnail',
  'width' => $thumbnail_width,
  'height' => $thumbnail_height,
  'align' => 'absmiddle',
  'attributes' => array('style' => 'vertical-align: middle'),
);
$image = theme('image', $variables);
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
      <?php print $image; ?>
    </div>
  </div>
</div>