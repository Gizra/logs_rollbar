[![Build Status](https://travis-ci.org/Gizra/logs_rollbar.svg?branch=master)](https://travis-ci.org/Gizra/logs_rollbar)

# Logs Rollbar

> Provides JSON event pushing to Logs via the tag/http endpoint.

This module depends on the `rollbar` library, preferably installed using composer.

A simple method of installing it is using the `composer_manager` module.

OR adding `rollbar/rollbar` to your existing `composer.json`:

```json
{
    "require": {
        "rollbar/rollbar": "0.18.2"
    }
}

```

# Installation

* Enable the module
* Go to ```admin/config/system/composer-manager``` (if installed) and make sure Rollbar library is available.
* Go to ```admin/config/services/logs-rollbar-settings``` and set the settings

### For live env uuid
For platform sh and pantheon hosts env uuids are set automatically.
see logs_rollbar_get_env_uuid().

## Make file

```make
projects[logs_rollbar][type] = "module"
projects[logs_rollbar][subdir] = "contrib"
projects[logs_rollbar][download][type] = "git"
projects[logs_rollbar][download][branch] = "master"
projects[logs_rollbar][download][url] = "https://github.com/Gizra/logs_rollbar.git"
```
