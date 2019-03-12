# Trackfield - Druapl Module - Drupal 7

## Description
This is a port of [Trackfield][1] Drupal module and it's associated modules for Drupal 7. The module was originally created by [raintonr][2] to whom all praise and lauding should be directed. There is currently no custom code or extensions to this D7 version of the module.

## Motivation
When learning Drupal 6 and exploring the use and display of GPX/TCX tracks I found myself using the. After Drupal 7 was released I moved my tinkering and learning onto Drupal 7 but did not find any solutions that served my needs quite as well as Trackfield did. The Trackfield author and maintainer whilst being open to a Drupal 7 version of the module was unable to dedicate the resources to it so I ported myself.

## Installation
In a Drupal 7 installation place the Trackfield folder into your contrib modules folder and then install/enable it in within the Drupal Admin. Trackfield Field Types will be availble within content creation and Trackfield settings are available in the admin screens.

## Roadmap
* Trackfield does not currently update the Location data for the Node as it does in D6, a patch for this is welcome.
* Trackfield graph currently requires the graph configurations form to be saved once after install to assign timestamps and renders to the formatter, otherwise undefined index errors will thrown and the module will not function properly.
* Views integration is done as a proof of concept but as this was not a feature of the existing Drupal 6 module it has not been a priority.

[1]: http://drupal.org/project/trackfield
[2]: http://drupal.org/user/27877