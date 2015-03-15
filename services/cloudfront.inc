<?php

/**
 * @file
 * Cloudfront functions for JW Player
 */

/**
 * Custom function to create a signed URL for cloudfront
 */
function jw_player_cdn_cloudfront_sign_url($source) {
  $query = array();
  $timeout = variable_get('jw_player_cdn_cloudfront_timeout', 1200);
  $expires = time() + $timeout;
  $keypairid = variable_get('jw_player_cdn_cloudfront_cf_key_id');
  $policy = '{"Statement":[{"Resource":"' . $source . '","Condition":{"DateLessThan":{"AWS:EpochTime":' . $expires . '}}}]}';
  $pkey = variable_get('jw_player_cdn_cloudfront_cf_key_contents');
  $key = openssl_get_privatekey($pkey);
  if (!$key) {
    watchdog('jw_player_cdn', 'Amazon CF error: Unable to get key from Cloudfront key file contents ID @id', array('@id' => $keypairid), WATCHDOG_ERROR);
    if (user_access('administer jwplayer cdn module'))
      drupal_set_message(t('Amazon CF error: Unable to get key from Cloudfront key file contents ID @id', array('@id' => $keypairid)), 'error');
    return FALSE;
  }
  if (!openssl_sign($policy, $signed_source, $key)) {
    watchdog('jw_player_cdn', 'Amazon CF error: Unable to create signature using Cloudfront key file contents ID @id', array('@id' => $keypairid), WATCHDOG_ERROR);
    if (user_access('administer jwplayer cdn module'))
      drupal_set_message(t('Amazon CF error: Unable to create signature using Cloudfront key file contents ID @id', array('@id' => $keypairid)), 'error');
    return FALSE;
  }
  openssl_free_key($key);
  // Create the query string for the signed URL.
  $query['Policy'] = str_replace(array('+', '=', '/'), array('-', '_', '~'), base64_encode($policy));
  $query['Signature'] = str_replace(array('+', '=', '/'), array('-', '_', '~'), base64_encode($signed_source));
  $query['Key-Pair-Id'] = $keypairid;

  return url($source, array('query' => $query));
}
