<?php
/**
 * @file
 * Defines the CTools Export UI plugin for JW Player presets.
 */
$plugin = array(
  'schema' => 'jw_player_cdn_preset',
  'access' => 'administer jwplayer cdn module',
  'menu' => array(
    'menu item' => 'jw_player_cdn',
    'menu title' => 'JW Player CDN Presets',
    'menu prefix' => 'admin/config/media',
    'menu description' => 'Administer JW Player CDN presets.',
  ),

  'title singular' => t('preset'),
  'title plural' => t('presets'),
  'title singular proper' => t('JW Player CDN preset'),
  'title plural proper' => t('JW Player CDN presets'),

  'form' => array(
    'settings' => 'jw_player_cdn_ctools_export_ui_form',
    'validate' => 'jw_player_cdn_ctools_export_ui_form_validate',
  ),
);

/**
 * Implements hook_ctools_export_ui_form().
 */
function jw_player_cdn_ctools_export_ui_form(&$form, &$form_state) {
  $preset = $form_state['item'];
  $settings = $preset->settings;

   // This is a hack. CTools adds a hierarchy for export_key in form of
   // $form['info][$export_key] (see line 1007 of
   // ctools/plugins/export_ui/ctools_export_ui.class.php).
   // The FAPI machine name object doesn't seem to work well with fields present
   // in different levels of hierarchy, hence we move the fields over to the same
   // level in the hierarchy.
  unset($form['info']);

  $form['preset_name'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#maxlength' => 255,
    '#title' => t('Preset name'),
    '#description' => t('Enter name for the preset.'),
    '#default_value' =>  $preset->preset_name,
    '#required' => TRUE,
    '#weight' => 0,
  );

  $form['info']['machine_name'] = array(
    '#title' => t('Machine name'),
    '#type' => 'machine_name',
    '#default_value' => $preset->machine_name,
    '#machine_name' => array(
      'exists' => 'jw_player_preset_load',
      'source' => array('preset_name'),
    ),
    '#weight' => 1,
    '#description' => t('Enter the machine name for the preset. It must be unique and contain only alphanumeric characters and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#size' => 10,
    '#title' => t('Description'),
    '#description' => t('Summary for the preset.'),
    '#default_value' => $preset->description,
    '#weight' => 2,
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => 'Settings',
    '#tree' => TRUE,
    '#weight' => 5,
  );

  $form['settings']['mode'] = array(
    '#type' => 'radios',
    '#title' => t('Embed mode'),
    '#description' => t('Select your primary embed mode. Choosing HTML5 primary means that modern browsers that also support flash will use the HTML5 player first where possible. While this is desirable, the Flash based player supports more features and is generally more reliable.'),
    '#options' => array(
      'flash' => t('Flash primary, HTML5 failover'),
      'html5' => t('HTML5 primary, Flash failover'),
    ),
    '#default_value' => isset($settings['mode']) ? $settings['mode'] : 'html5',
  );

  $form['settings']['width'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#title' => t('Width'),
    '#description' => t('Enter the width for this player.'),
    '#field_suffix' => ' ' . t('pixels'),
    '#default_value' => $settings['width'],
    '#required' => TRUE,
    '#weight' => 5,
  );

  $form['settings']['height'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#title' => t('Height'),
    '#description' => t('Enter the height for this player.'),
    '#field_suffix' => ' ' . t('pixels'),
    '#default_value' => $settings['height'],
    '#required' => TRUE,
    '#weight' => 6,
  );

  $form['settings']['controlbar'] = array(
    '#title' => t('Controlbar Position'),
    '#type' => 'select',
    '#description' => t('Where the controlbar should be positioned.'),
    '#default_value' => !empty($settings['controlbar']) ? $settings['controlbar']: 'none',
    '#options' => array(
      'none' => t('None'),
      'bottom' => t('Bottom'),
      'top' => t('Top'),
      'over' => t('Over')
    ),
    '#weight' => 7,
  );

  $form['settings']['autoplay'] = array(
    '#title' => t('Autoplay'),
    '#type' => 'checkbox',
    '#description' => t('Set the video to autoplay on page load'),
    '#default_value' => !empty($settings['autoplay']) ? $settings['autoplay']: 'false',
    '#weight' => 4,
  );

}

/**
 * Valdiator for jw_player_ctools_export_ui_form().
 */
function jw_player_cdn_ctools_export_ui_form_validate($form, &$form_state) {
  $vals = $form_state['values'];
  if (!is_numeric($vals['settings']['width'])) {
    form_set_error('width', 'Only numeric values allowed for width' );
  }
  if (!is_numeric($vals['settings']['height'])) {
    form_set_error('width', 'Only numeric values allowed for height' );
  }
}