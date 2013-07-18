<?php
/**
 * @file
 * basic_site_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function basic_site_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:node/add/data
  $menu_links['main-menu:node/add/data'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/data',
    'router_path' => 'node/add/data',
    'link_title' => 'Register New Data',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:search
  $menu_links['main-menu:search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Look Up Data',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '10',
  );
  // Exported menu link: main-menu:update-registry
  $menu_links['main-menu:update-registry'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'update-registry',
    'router_path' => 'update-registry',
    'link_title' => 'Update Registry',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Look Up Data');
  t('Register New Data');
  t('Update Registry');


  return $menu_links;
}
