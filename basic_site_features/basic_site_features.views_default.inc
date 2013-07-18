<?php
/**
 * @file
 * basic_site_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function basic_site_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mods_records';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'MODS Records';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Login Required';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Persons in charge of data collection */
  $handler->display->display_options['fields']['field_creator_name']['id'] = 'field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['table'] = 'field_data_field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['field'] = 'field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['label'] = '';
  $handler->display->display_options['fields']['field_creator_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_creator_name']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_creator_name] / [field_description] ';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_mods_style';
  $handler->display->display_options['style_options']['schema'] = 'mods';
  $handler->display->display_options['style_options']['root_element'] = 'mods';
  $handler->display->display_options['style_options']['top_child_object'] = 'titleInfo';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['header'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: dateIssued start */
  $handler->display->display_options['fields']['field_date_of_collection']['id'] = 'field_date_of_collection';
  $handler->display->display_options['fields']['field_date_of_collection']['table'] = 'field_data_field_date_of_collection';
  $handler->display->display_options['fields']['field_date_of_collection']['field'] = 'field_date_of_collection';
  $handler->display->display_options['fields']['field_date_of_collection']['ui_name'] = 'dateIssued start';
  $handler->display->display_options['fields']['field_date_of_collection']['label'] = 'dateIssuedStart';
  $handler->display->display_options['fields']['field_date_of_collection']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_of_collection']['settings'] = array(
    'format_type' => 'w3cdtf',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: dateIssued stop */
  $handler->display->display_options['fields']['field_date_of_collection_1']['id'] = 'field_date_of_collection_1';
  $handler->display->display_options['fields']['field_date_of_collection_1']['table'] = 'field_data_field_date_of_collection';
  $handler->display->display_options['fields']['field_date_of_collection_1']['field'] = 'field_date_of_collection';
  $handler->display->display_options['fields']['field_date_of_collection_1']['ui_name'] = 'dateIssued stop';
  $handler->display->display_options['fields']['field_date_of_collection_1']['label'] = 'dateIssuedStop';
  $handler->display->display_options['fields']['field_date_of_collection_1']['settings'] = array(
    'format_type' => 'w3cdtf',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: titleInfo */
  $handler->display->display_options['fields']['nothing_6']['id'] = 'nothing_6';
  $handler->display->display_options['fields']['nothing_6']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_6']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_6']['ui_name'] = 'titleInfo';
  $handler->display->display_options['fields']['nothing_6']['label'] = 'titleInfo';
  $handler->display->display_options['fields']['nothing_6']['alter']['text'] = '[title]|title';
  $handler->display->display_options['fields']['nothing_6']['element_label_colon'] = FALSE;
  /* Field: Content: Persons in charge of data collection */
  $handler->display->display_options['fields']['field_creator_name']['id'] = 'field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['table'] = 'field_data_field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['field'] = 'field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['label'] = 'name_of_creator';
  $handler->display->display_options['fields']['field_creator_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_creator_name']['element_label_colon'] = FALSE;
  /* Field: name_of_creator_name */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['ui_name'] = 'name_of_creator_name';
  $handler->display->display_options['fields']['nothing_3']['label'] = 'name';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = '[field_creator_name]|displayForm;;creator|roleTerm';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  /* Field: Content: Institution & Department */
  $handler->display->display_options['fields']['field_institution_department']['id'] = 'field_institution_department';
  $handler->display->display_options['fields']['field_institution_department']['table'] = 'field_data_field_institution_department';
  $handler->display->display_options['fields']['field_institution_department']['field'] = 'field_institution_department';
  $handler->display->display_options['fields']['field_institution_department']['label'] = 'InstitutionAndDepartment';
  $handler->display->display_options['fields']['field_institution_department']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_institution_department']['alter']['text'] = '[field_institution_department]';
  $handler->display->display_options['fields']['field_institution_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_institution_department']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_institution_department']['settings'] = array(
    'view_mode' => 'token',
  );
  /* Field: institution_department_name */
  $handler->display->display_options['fields']['nothing_7']['id'] = 'nothing_7';
  $handler->display->display_options['fields']['nothing_7']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_7']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_7']['ui_name'] = 'institution_department_name';
  $handler->display->display_options['fields']['nothing_7']['label'] = 'corporate';
  $handler->display->display_options['fields']['nothing_7']['alter']['text'] = '[field_institution_department]';
  $handler->display->display_options['fields']['nothing_7']['element_label_colon'] = FALSE;
  /* Field: Content: Funding Agency */
  $handler->display->display_options['fields']['field_funding_agency']['id'] = 'field_funding_agency';
  $handler->display->display_options['fields']['field_funding_agency']['table'] = 'field_data_field_funding_agency';
  $handler->display->display_options['fields']['field_funding_agency']['field'] = 'field_funding_agency';
  $handler->display->display_options['fields']['field_funding_agency']['label'] = 'funding_agency';
  $handler->display->display_options['fields']['field_funding_agency']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_funding_agency']['element_label_colon'] = FALSE;
  /* Field: funding_agency_name */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'funding_agency_name';
  $handler->display->display_options['fields']['nothing']['label'] = 'corporate';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_funding_agency]|displayForm;;funding agency|roleTerm';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Data Format/File Type */
  $handler->display->display_options['fields']['field_data_format_type']['id'] = 'field_data_format_type';
  $handler->display->display_options['fields']['field_data_format_type']['table'] = 'field_data_field_data_format_type';
  $handler->display->display_options['fields']['field_data_format_type']['field'] = 'field_data_format_type';
  $handler->display->display_options['fields']['field_data_format_type']['label'] = 'dataformat';
  $handler->display->display_options['fields']['field_data_format_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_data_format_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_data_format_type']['delta_offset'] = '0';
  /* Field: originInfo */
  $handler->display->display_options['fields']['nothing_4']['id'] = 'nothing_4';
  $handler->display->display_options['fields']['nothing_4']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_4']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_4']['ui_name'] = 'originInfo';
  $handler->display->display_options['fields']['nothing_4']['label'] = 'originInfo';
  $handler->display->display_options['fields']['nothing_4']['alter']['text'] = '[field_date_of_collection]|dateCreated';
  $handler->display->display_options['fields']['nothing_4']['element_label_colon'] = FALSE;
  /* Field: Content: Short Description */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['label'] = 'note';
  $handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = 'abstract';
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_creator_name] / [field_description] ';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_keywords']['id'] = 'field_keywords';
  $handler->display->display_options['fields']['field_keywords']['table'] = 'field_data_field_keywords';
  $handler->display->display_options['fields']['field_keywords']['field'] = 'field_keywords';
  $handler->display->display_options['fields']['field_keywords']['label'] = 'topic';
  $handler->display->display_options['fields']['field_keywords']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_keywords']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_keywords']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_keywords']['delta_offset'] = '0';
  /* Field: subject */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'subject';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'subject';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_keywords]|topic';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Content: Link to data */
  $handler->display->display_options['fields']['field_data_link']['id'] = 'field_data_link';
  $handler->display->display_options['fields']['field_data_link']['table'] = 'field_data_field_data_link';
  $handler->display->display_options['fields']['field_data_link']['field'] = 'field_data_link';
  $handler->display->display_options['fields']['field_data_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_data_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_data_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_data_link']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_data_link']['delta_offset'] = '0';
  /* Field: Content: Equipment used in data collection */
  $handler->display->display_options['fields']['field_equip_data_coll']['id'] = 'field_equip_data_coll';
  $handler->display->display_options['fields']['field_equip_data_coll']['table'] = 'field_data_field_equip_data_coll';
  $handler->display->display_options['fields']['field_equip_data_coll']['field'] = 'field_equip_data_coll';
  $handler->display->display_options['fields']['field_equip_data_coll']['label'] = 'note';
  $handler->display->display_options['fields']['field_equip_data_coll']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_equip_data_coll']['alter']['text'] = 'Equipment used in data collection: [field_equip_data_coll]';
  /* Field: Content: Programs needed to analyze the data */
  $handler->display->display_options['fields']['field_prgrams_to_analyze_data']['id'] = 'field_prgrams_to_analyze_data';
  $handler->display->display_options['fields']['field_prgrams_to_analyze_data']['table'] = 'field_data_field_prgrams_to_analyze_data';
  $handler->display->display_options['fields']['field_prgrams_to_analyze_data']['field'] = 'field_prgrams_to_analyze_data';
  $handler->display->display_options['fields']['field_prgrams_to_analyze_data']['label'] = 'note';
  $handler->display->display_options['fields']['field_prgrams_to_analyze_data']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_prgrams_to_analyze_data']['alter']['text'] = 'Programs needed to analyze the data: [field_prgrams_to_analyze_data]';
  /* Field: Content: Programs needed to open the data */
  $handler->display->display_options['fields']['field_prog_to_open_data']['id'] = 'field_prog_to_open_data';
  $handler->display->display_options['fields']['field_prog_to_open_data']['table'] = 'field_data_field_prog_to_open_data';
  $handler->display->display_options['fields']['field_prog_to_open_data']['field'] = 'field_prog_to_open_data';
  $handler->display->display_options['fields']['field_prog_to_open_data']['label'] = 'note';
  $handler->display->display_options['fields']['field_prog_to_open_data']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_prog_to_open_data']['alter']['text'] = 'Programs needed to open the data: [field_prog_to_open_data]';
  /* Field: Content: Sharing Attributes */
  $handler->display->display_options['fields']['field_sharing_attributes']['id'] = 'field_sharing_attributes';
  $handler->display->display_options['fields']['field_sharing_attributes']['table'] = 'field_data_field_sharing_attributes';
  $handler->display->display_options['fields']['field_sharing_attributes']['field'] = 'field_sharing_attributes';
  $handler->display->display_options['fields']['field_sharing_attributes']['label'] = 'restriction';
  /* Field: location */
  $handler->display->display_options['fields']['nothing_5']['id'] = 'nothing_5';
  $handler->display->display_options['fields']['nothing_5']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_5']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_5']['ui_name'] = 'location';
  $handler->display->display_options['fields']['nothing_5']['label'] = 'location';
  $handler->display->display_options['fields']['nothing_5']['alter']['text'] = '[field_data_link]|url';
  $handler->display->display_options['fields']['nothing_5']['element_label_colon'] = FALSE;
  /* Field: Content: Date of Registration */
  $handler->display->display_options['fields']['field_registration_date']['id'] = 'field_registration_date';
  $handler->display->display_options['fields']['field_registration_date']['table'] = 'field_data_field_registration_date';
  $handler->display->display_options['fields']['field_registration_date']['field'] = 'field_registration_date';
  $handler->display->display_options['fields']['field_registration_date']['label'] = 'recordCreationDate';
  $handler->display->display_options['fields']['field_registration_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registration_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'recordChangeDate';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'U';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'recordIdentifier';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: recordInfo */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'recordInfo';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'recordInfo';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'University of California Los Angeles Library|recordContentSource;;[field_registration_date]|recordCreationDate;;[changed]|recordChangeDate;;[nid]|recordIdentifier;;machine generated|recordOrigin';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'record/%/mods.xml';
  $export['mods_records'] = $view;

  $view = new view();
  $view->name = 'update_registry';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Update Registry';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Login Required';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Persons in charge of data collection */
  $handler->display->display_options['fields']['field_creator_name']['id'] = 'field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['table'] = 'field_data_field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['field'] = 'field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['label'] = '';
  $handler->display->display_options['fields']['field_creator_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_creator_name']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_creator_name] / [field_description] ';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'data' => 'data',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'List of Your Projects';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Persons in charge of data collection */
  $handler->display->display_options['fields']['field_creator_name']['id'] = 'field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['table'] = 'field_data_field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['field'] = 'field_creator_name';
  $handler->display->display_options['fields']['field_creator_name']['label'] = '';
  $handler->display->display_options['fields']['field_creator_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_creator_name']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_creator_name] / [field_description] ';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/record/[nid]/mods.xml">MODS XML</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'update-registry';
  $export['update_registry'] = $view;

  return $export;
}
