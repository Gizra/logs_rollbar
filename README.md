[![Build Status](https://travis-ci.org/Gizra/logs_rollbar.svg?branch=master)](https://travis-ci.org/Gizra/logs_rollbar)

# Logs Rollbar

> Provides JSON event pushing to Logs via the tag/http endpoint.

This module depends on composer_manager.

# Installation

* Enable the module
* Go to ```admin/config/system/composer-manager``` and make sure Rollbar library is available.
* Go to ```admin/config/services/logs-http-client``` and set the settings

### For live env add to settings PHP something like this:
```php
if (!empty($_ENV)) {
  $conf['logs_rollbar_url'] = 'http://api.rollbar.com/api/1/';
  $conf['logs_rollbar_uuid'] = $_ENV['PANTHEON_SITE_NAME'] . '-' . $_ENV['PANTHEON_ENVIRONMENT'];
```


## Make file

```make
projects[logs_rollbar][type] = "module"
projects[logs_rollbar][subdir] = "contrib"
projects[logs_rollbar][download][type] = "git"
projects[logs_rollbar][download][branch] = "master"
projects[logs_rollbar][download][url] = "https://github.com/Gizra/logs_rollbar.git"
```