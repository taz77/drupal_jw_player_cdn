<?php

/**
 * @file
 * Provides admin settings form(s) for Freshdesk module.
 */

/**
 * The form to provide admin settings for the SS Newsletter Module.
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
  $form['jw_player_cdn_cloudfront']['jw_player_cdn_cloudfront_akey'] = array(
    '#type' => 'textfield',
    '#size' => '100',
    '#title' => t('Access Key ID'),
    '#default_value' => variable_get('jw_player_cdn_cloudfront_akey', ''),
    '#description' => t('Obtain this from the AWS IAM console.'),
  );
  $form['jw_player_cdn_cloudfront']['jw_player_cdn_cloudfront_skey'] = array(
    '#type' => 'textfield',
    '#size' => '150',
    '#title' => t('Secret Access Key'),
    '#default_value' => variable_get('jw_player_cdn_cloudfront_skey', ''),
    '#description' => t('Obtain this from the AWS IAM console.'),
  );
  $form['jw_player_cdn_static_url_intro'] = array(
    '#markup' => '<strong>' . t('The following URLs must be in a separate distribution from your video files. This distribution is not protected with signed URLs.') . '</strong>',
  );
  $form['jw_player_cdn_static_url_jwplayer'] = array(
    '#type' => 'textfield',
    '#size' => '100',
    '#title' => t('JW Player 6 Path'),
    '#description' => t('Location of JS API File and SWF file provided to you by JW Player. Contained here MUST be jwplayer.js and player.swf and exactly those file names.'),
    '#default_value' => variable_get('jw_player_cdn_static_url_jwplayer', ''),
  );
  $form['jw_player_cdn_static_url_logo'] = array(
    '#type' => 'textfield',
    '#size' => '100',
    '#title' => t('URL of your logo'),
    '#description' => t('Logo to display on your video player. Full URL including filename.'),
    '#default_value' => variable_get('jw_player_cdn_static_url_logo', ''),
  );
  $form['jw_player_cdn_static_url_skin'] = array(
    '#type' => 'textfield',
    '#size' => '100',
    '#title' => t('URL of the skin.'),
    '#description' => t('URL of the skin including the filename.'),
    '#default_value' => variable_get('jw_player_cdn_static_url_skin', ''),
  );

  return system_settings_form($form);
}
