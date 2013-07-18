<?php
/**
 * @file
 * basic_site_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function basic_site_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_main_menu';
  $context->description = '';
  $context->tag = 'Superfish';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => 1,
          'region' => 'main_menu',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Superfish');
  $export['site_main_menu'] = $context;

  return $export;
}
