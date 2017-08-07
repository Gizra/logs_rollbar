<?php

/**
 * @file
 * Logs HTTP module admin page.
 */

/**
 * Logs HTTP POST API Configuration Form.
 */
function logs_rollbar_admin_settings($form, &$form_state) {
  $form['logs_rollbar_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log to Rollbar enabled'),
    '#description' => t('Enable Logs Rollbar POST'),
    '#default_value' => variable_get('logs_rollbar_enabled', FALSE),
  );

  $form['logs_rollbar_url'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Endpoint'),
    '#description' => t('The URL to POST the data to.'),
    '#default_value' => variable_get('logs_rollbar_url', 'http://api.rollbar.com/api/1/'),
  );

  $form['logs_rollbar_rollbar_access_token'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Rollbar Server Access Token, from https://rollbar.com/USERID/PROJECTID/settings/access_tokens/'),
    '#default_value' => variable_get('logs_rollbar_rollbar_access_token', NULL),
  );

  $form['logs_rollbar_rollbar_access_token_js'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Rollbar Client Access Token (javascript)'),
    '#description' => t('Type 0 to disable, or add your client access token from https://rollbar.com/USERID/PROJECTID/settings/access_tokens/'),
    '#default_value' => variable_get('logs_rollbar_rollbar_access_token_js', 0),
  );

  $options = array(
    WATCHDOG_EMERGENCY => t('Emergency'),
    WATCHDOG_ALERT => t('Alert'),
    WATCHDOG_CRITICAL => t('Critical'),
    WATCHDOG_ERROR => t('Error'),
    WATCHDOG_WARNING => t('Warning'),
    WATCHDOG_NOTICE => t('Notice'),
    WATCHDOG_INFO => t('Info'),
    WATCHDOG_DEBUG => t('Debug'),
  );

  $form['logs_rollbar_severity_level'] = array(
    '#type' => 'select',
    '#title' => t('Watchdog Severity'),
    '#options' => $options,
    '#default_value' => variable_get('logs_rollbar_severity_level', WATCHDOG_ERROR),
    '#description' => t('The minimum severity level to be reached before an event is pushed to Logs.'),
  );

  $form['logs_rollbar_uuid'] = array(
    '#type' => 'textfield',
    '#title' => t('Unique ID'),
    '#description' => t('An arbitrary ID that will identify the environment.'),
    '#default_value' => variable_get('logs_rollbar_uuid', drupal_get_profile() . '-local'),
  );

  return system_settings_form($form);
}

