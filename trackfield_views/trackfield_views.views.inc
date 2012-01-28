<?php

function trackfield_views_views_data() {
  // The 'group' index will be used as a prefix in the UI for any of this
  // table's fields, sort criteria, etc. so it's easy to tell where they came
  // from.
  $data['latitude']['table']['group'] = t('Trackfield');
   
  // This table references the {node} table.
  // This creates an 'implicit' relationship to the node table, so that when 'Node'
  // is the base table, the fields are automatically available.
  $data['latitude']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'node' => array(
      'left_field' => 'nid', 
      'field' => 'nid',
      'table' => 'trackfield_datasets',
    ),
  );

  $data['latitude']['latitudedata'] = array(
    'title' => t('Latitude data'), 
    'help' => t('Just latitude.'),
    'real field' => 'setdata', 
    'field' => array(
      'handler' => 'views_handler_field_trackfield_setdata', 
      'click sortable' => TRUE,
    ),
  );
  
  $data['longitude']['table']['group'] = t('Trackfield');
   
  // This table references the {node} table.
  // This creates an 'implicit' relationship to the node table, so that when 'Node'
  // is the base table, the fields are automatically available.
  $data['longitude']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'node' => array(
      'left_field' => 'nid', 
      'field' => 'nid',
      'table' => 'trackfield_datasets',
    ),
  );

  $data['longitude']['longitudedata'] = array(
    'title' => t('Longitude data'), 
    'help' => t('Just latitude.'),
    'real field' => 'setdata', 
    'field' => array(
      'handler' => 'views_handler_field_trackfield_setdata', 
      'click sortable' => TRUE,
    ),
  );
  
  return $data; 
}