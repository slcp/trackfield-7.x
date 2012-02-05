<?php

function trackfield_views_views_data() {
  // Collect the types of data trackfield currently has. Should we use the
  // variable table to store this?
  $settypes = db_select('trackfield_datasets', 'td')
    ->fields('td', array('settype'))
    ->distinct(TRUE)
    ->execute()
    ->fetchAllAssoc('settype');

  // Tell views about each type of field. Each type must be a pseudo-field
  // because they are stored on separate rows in the database. This has the
  // potential to produce a large amount of JOINs. Can this be done another way?
  foreach($settypes as $settype => $v) {
    // The 'group' index will be used as a prefix in the UI for any of this
    // table's fields, sort criteria, etc. so it's easy to tell where they came
    // from.
    $data[$settype]['table']['group'] = t('Trackfield');

    // This table references the {node} table.
    // This creates an 'implicit' relationship to the node table, so that when
    // 'Node' is the base table, the fields are automatically available.
    $data[$settype]['table']['join'] = array(
      // Index this array by the table name to which this table refers.
      // 'table' is specified here because $settype is used as an alias above.
      'node' => array(
        'left_field' => 'nid', 
        'field' => 'nid',
        'table' => 'trackfield_datasets',
      ),
    );

    $data[$settype][$settype . 'data'] = array(
      'title' => t($settype . ' data'), 
      'help' => t('The ' . $settype . ' data of the track.'),
      'real field' => 'setdata',
      'field' => array(
        'handler' => 'views_handler_field_trackfield_setdata', 
        'click sortable' => TRUE,
      ),
    );
  }

  return $data; 
}