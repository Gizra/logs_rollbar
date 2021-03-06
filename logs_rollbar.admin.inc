<?php

/**
 * @file
 * Logs HTTP module admin page.
 */

/**
 * Logs HTTP POST API Configuration Form.
 */
function logs_rollbar_admin_settings($form, &$form_state) {
  $uuid = logs_rollbar_get_env_uuid();

  $form['logs_rollbar_uuid'] = array(
    '#markup' => "<label>UUID:</label><strong>$uuid</strong><div>The ID that will identify the environment.</div></br>",
  );

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
    '#default_value' => variable_get('logs_rollbar_url', 'https://api.rollbar.com/api/1/'),
  );

  $form['logs_rollbar_rollbar_access_token'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Rollbar Server Access Token (Server PHP)'),
    '#description' => t('Server access token from https://rollbar.com/USERID/PROJECTID/settings/access_tokens/'),
    '#default_value' => variable_get('logs_rollbar_rollbar_access_token', NULL),
  );

  $form['logs_rollbar_rollbar_access_token_js'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#title' => t('Rollbar Client Access Token (javascript)'),
    '#description' => t('Type 0 to disable, or add your client access token from https://rollbar.com/USERID/PROJECTID/settings/access_tokens/'),
    '#default_value' => variable_get('logs_rollbar_rollbar_access_token_js', 0),
  );

  $form['logs_rollbar_auto_disable_on_local'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically disable on local'),
    '#default_value' => variable_get('logs_rollbar_auto_disable_on_local', TRUE),
  );

  $form['logs_rollbar_ignored_clientside_messages'] = array(
    '#type' => 'textarea',
    '#title' => t('Ignored Client Side Exception Messages'),
    '#description' => t('Client-side exceptions messages which Rollbar ignores (one on each line). Regular expressions are supported.'),
    '#default_value' => variable_get('logs_rollbar_ignored_clientside_messages', ''),
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

  return system_settings_form($form);
}

