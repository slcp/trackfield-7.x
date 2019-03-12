<?php

function trackfield_trackdata_load ($nid = NULL, $vid = NULL, $field_name = NULL, $delta = 0, $settypes = array()) {
  
  $data = array();
  
  foreach($settypes as $settype) {
  	
  		$table_name = 'trackfield_dataset_' . $settype;
  
  		$result = db_query(
  			"SELECT setdata 
  			 from $table_name 
  			 WHERE nid = :nid and vid = :vid and field_name = :fd and delta = :delta", 
  			 array(':nid' => $nid, ':vid' => $vid, ':fd' => $field_name, ':delta' =>$delta));
  
  		foreach ($result as $sd) {
          $data[$settype] = explode(',', $sd->setdata);
        	}
    }
  
  return $data;
  
 }   
  
function trackfield_trackdata_save ($nid, $vid, $field_name, $delta, $settype, $setdata) {
  
  if(!db_table_exists('trackfield_dataset_' . $settype)) {
  	   $table_name = 'trackfield_dataset_' . $settype;
  		$table_definition = array(
			'description' => 'Storage table for trackfield track ' . $settype . ' data.',
			'fields' => array(
				'nid' => array(
					'type' => 'int',
					'unsigned' => TRUE,
					'not null' => TRUE,
					'default' => '0',
				),
				'vid' => array(
					'type' => 'int',
					'unsigned' => TRUE,
					'not null' => TRUE,
					'default' => '0',
				),
				'field_name' => array(
					'type' => 'varchar',
					'length' => 32,
					'not null' => TRUE,
					'default' => '',
				),
				'delta' => array(
					'type' => 'int',
					'unsigned' => TRUE,
					'not null' => TRUE,
					'default' => '0',
				),
				'setdata' => array(
					'type' => 'text',
					'size' => 'big',
					'not null' => TRUE,
				),
			),
			'primary_key' => array('nid', 'vid', 'field_name', 'delta'),
		);
		
  		db_create_table($table_name, $table_definition); 
  	}
  		
  db_insert('trackfield_dataset_' . $settype)
              ->fields(array(
            	  'nid' => $nid,
            	  'vid' => $vid,
            	  'field_name' => $field_name,
            	  'delta' => $delta,
            	  'setdata' => $setdata))
              ->execute();
  
  return TRUE;
              
  } 