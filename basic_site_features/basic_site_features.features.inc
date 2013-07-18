<?php
/**
 * @file
 * basic_site_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function basic_site_features_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function basic_site_features_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function basic_site_features_node_info() {
  $items = array(
    'data' => array(
      'name' => t('Data'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name of Project'),
      'help' => '',
    ),
  );
  return $items;
}
