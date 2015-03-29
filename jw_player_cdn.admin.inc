<?php

/**
 * @file
 * Provides admin settings form(s) for JW Player CDN module.
 */
function jw_player_cdn_admin($form, &$form_state) {

  $form = array();
  $form['jw_player_cdn_license'] = array(
    '#type' => 'fieldset',
    '#title' => t('JW Player License Key'),
    '#collapsible' => FALSE,
  );
  $form['jw_player_cdn_license']['jw_player_cdn_license_key'] = array(
    '#type' => 'textfield',
    '#size' => '100',
    '#title' => t('Key'),
    '#default_value' => variable_get('jw_player_cdn_license_key', ''),
    '#description' => t('This is required to use the advanced functions of JW Player such as Ads and Analytics. Also required if you are using this on a commercial website.'),
  );
  $form['jw_player_cdn_cloudfront_intro'] = array(
    '#markup' => t('This module is built to only use AWS Cloudfront at this time and is based on a specific use case which may not fulfil your needs.'),
  );
  $form['jw_player_cdn_cloudfront'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cloudfront Signed URL Configuration'),
    '#collapsible' => FALSE,
  );
  $form['jw_player_cdn_cloudfront']['jw_player_cdn_cloudfront_intro'] = array(
    '#markup' => t('Configure you Cloudfront Signed URL settings in this section. Get these credentials') . ' ' . l('here', 'http://aws-portal.amazon.com/gp/aws/developer/account/index.html?action=access-key') . ' ' . t('This protects your video files from being downloaded by anyone with a link.'),
  );
  $form['jw_player_cdn_cloudfront']['cf_signed_notice_2'] = array(
    '#markup' => '<p>' . t('If you have not created a Cloudfront Key Pair.  You must stop this process and go complete those steps first. Note: creating and setting up Cloudfront distribution changes can take a long time.') . ' ' . l('Link to AWS Security Credentials page', 'https://console.aws.amazon.com/iam/home?#security_credential', array('external' => TRUE)) . '</p>',
  );
  $form['jw_player_cdn_cloudfront']['jw_player_cdn_cloudfront_cf_key_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Cloudfront key pair ID'),
    '#default_value' => variable_get('jw_player_cdn_cloudfront_cf_key_id', FALSE) ? variable_get('jw_player_cdn_cloudfront_cf_key_id') : '',
    '#description' => t('This is the Key Pair ID provided by Amazon for your Cloudfront key that you have created.'),
    '#required' => TRUE,
  );
  $form['jw_player_cdn_cloudfront']['jw_player_cdn_cloudfront_cf_key_contents'] = array(
    '#type' => 'textarea',
    '#title' => t('Cloudfront Private key contents'),
    '#default_value' => variable_get('jw_player_cdn_cloudfront_cf_key_contents', FALSE) ? variable_get('jw_player_cdn_cloudfront_cf_key_contents') : '',
    '#description' => t('This is the contents of the Private Key downloaded from Amazon.  Paste in the ENTIRE contents of the downloaded PEM file. The file should start with "-----BEGIN RSA PRIVATE KEY-----" and end with "-----END RSA PRIVATE KEY-----".'),
    '#required' => TRUE,
  );
  $form['jw_player_cdn_cloudfront']['jw_player_cdn_cloudfront_timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('Timeout for Assets'),
    '#default_value' => variable_get('jw_player_cdn_cloudfront_timeout', FALSE) ? variable_get('jw_player_cdn_cloudfront_timeout') : '300',
    '#description' => t('Timeout used for signing of URLs. This number will specify - in seconds - how long a URL is valid.'),
    '#required' => TRUE,
  );
  $form['jw_player_cdn_static_url_intro'] = array(
    '#markup' => '<strong>' . t('The following URLs must be in a separate distribution from your video files. This distribution is not protected with signed URLs.') . '</strong>',
  );
  $form['jw_player_cdn_static_url_logo'] = array(
    '#type' => 'textfield',
    '#size' => '100',
    '#title' => t('URL of your logo'),
    '#description' => t('Logo to display on your video player. Full URL including filename.'),
    '#default_value' => variable_get('jw_player_cdn_static_url_logo', ''),
  );
  $form['jw_player_cdn_static_url_skin_pro'] = array(
    '#type' => 'select',
    '#title' => t('Pro Skin'),
    '#description' => t('Pro Skins are available in all paid versions of JW Player 6. Select a Pro Skin to use. Six is the default skin.'),
    '#options' => jw_player_cdn_pro_skin_list(),
    '#default_value' => variable_get('jw_player_cdn_static_url_skin_pro', 0),
  );
  $form['jw_player_cdn_static_url_skin_custom'] = array(
    '#type' => 'textfield',
    '#size' => '100',
    '#title' => t('URL of the skin'),
    '#description' => t('URL of the custom skin including the filename. If you define this it will override the pro skin selection above.'),
    '#default_value' => variable_get('jw_player_cdn_static_url_skin_custom', ''),
  );
  $form['jw_player_cdn_thumbnail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Video Segment Thumbnail Settings'),
    '#collapsible' => FALSE,
  );
  $form['jw_player_cdn_thumbnail']['jw_player_cdn_thumbnail_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Thumbnail Width'),
    '#default_value' => variable_get('jw_player_cdn_thumbnail_width', FALSE) ? variable_get('jw_player_cdn_thumbnail_width') : '120',
  );
  $form['jw_player_cdn_thumbnail']['jw_player_cdn_thumbnail_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Thumbnail Height'),
    '#default_value' => variable_get('jw_player_cdn_thumbnail_height', FALSE) ? variable_get('jw_player_cdn_thumbnail_height') : '80',
  );
  return system_settings_form($form);
}
