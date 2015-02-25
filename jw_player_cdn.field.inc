<?php

/**
 * @file
 * Implement a JW Player CDN field.
 */

/**
 * Implements hook_field_info().
 */
function jw_player_cdn_field_info() {
  return array(
    // We name our field as the associative name of the array.
    'jw_player_cdn_video_series' => array(
      'label' => t('JW Player CDN Video Entries'),
      'description' => t('Video Series Playlist'),
      'settings' => array(),
      'default_widget' => 'jw_player_cdn_video_series_widget',
      'default_formatter' => 'jw_player_cdn_video_series_formatter',
    ),
  );
}

/**
 * Implements hook_field_is_empty().
 */
function jw_player_cdn_field_is_empty($item, $field) {
  //return empty($item['video']);
  return FALSE;
}

/**
 * Implements hook_field_formatter_info().
 */
function jw_player_cdn_field_formatter_info() {
  return array(
    // This formatter just displays the hex value in the color indicated.
    'jw_player_cdn_video_series_formatter' => array(
      'label' => t('Simple text-based formatter'),
      'field types' => array('jw_player_cdn_video_series'),
    ),
  );
}

/**
 * Implements hook_field_widget_info().
 */
function jw_player_cdn_field_widget_info() {
  return array(
    'jw_player_cdn_video_series_widget' => array(
      'label' => t('Video Series Information'),
      'field types' => array('jw_player_cdn_video_series'),
      'settings' => array(),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_DEFAULT
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function jw_player_cdn_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  // Make this a fieldset with five fields.
  $element += array(
    '#type' => 'fieldset',
  );
  $element['video_segment_title'] = array(
    '#type' => 'textfield',
    '#title' => 'Segment Title',
    '#size' => 100,
    '#default_value' => isset($items[$delta]['video_segment_title']) ? $items[$delta]['video_segment_title'] : '',
    '#attributes' => array('class' => array('video-segment-title')),
    '#description' => 'Title of this video segment or chapter',
  );
  $element['video_segment_description'] = array(
    '#type' => 'textfield',
    '#title' => 'Segment Description',
    '#size' => 100,
    '#default_value' => isset($items[$delta]['video_segment_description']) ? $items[$delta]['video_segment_description'] : '',
    '#attributes' => array('class' => array('video-segment-description')),
    '#description' => 'Description of this video segment or chapter',
  );
  $element['video_segment_legth'] = array(
    '#type' => 'textfield',
    '#title' => 'Segment Length',
    '#attributes' => array('class' => array('video-segment-description')),
    '#description' => 'Length of this video segment or chapter. This is a HMS field type provided by HMS_field module. Format hh:mm:ss',
    '#default_value' => isset($items[$delta]['video_segment_legth']) ? $items[$delta]['video_segment_legth'] : '',
    //'#format' => 'h:mm:ss',
  );
  foreach (array('video' => t('Video URL'), 'thumb' => t('Thumbnail URL')) as $key => $title) {
    if ($key == 'video') {
      $description = t('Provide the URL to the video.');
    }
    if ($key == 'thumb') {
      $description = t('Provide the URL to the thumbnail for this video.');
    }
    $element[$key] = array(
      '#type' => 'textfield',
      '#title' => $title,
      '#size' => 100,
      '#default_value' => isset($items[$delta][$key]) ? $items[$delta][$key] : '',
      '#attributes' => array('class' => array('video-entry')),
      '#description' => $description,
    );
    // Since Form API doesn't allow a fieldset to be required, we
    // have to require each field element individually.
    if ($instance['required'] == 1) {
      $element[$key]['#required'] = 1;
    }
  }
  return $element;
}

/**
 * Implements hook_field_formatter_view().
 */
function jw_player_cdn_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  foreach ($items as $delta => $item) {
    kpr($item);
    /* $element[$delta] = array(
      // We create a render array to produce the desired markup,
      // "<p style="color: #hexcolor">The color code ... #hexcolor</p>".
      // See theme_html_tag().
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#attributes' => array(
      'style' => 'color: ' . $item['rgb'],
      ),
      '#value' => t('The color code in this field is @code', array('@code' => $item['rgb'])),
      ); */
  }

  return $element;
}
