<?php

function trackfield_views_data() {
	
	$data = array();
	
	$data['trackfield_dataset_latitude']['table'] = array(
	    'group' => t('Content'),
	    'help' => 'This is data that has been stored by the Trackfield module.',
	    );
	    
	$data['trackfield_dataset_latitude']['table']['join']['node'] = array(
		 'left_field' => 'nid',
		 'field' => 'nid',
		 );
	
	$data['trackfield_dataset_latitude']['nid'] = array(
		 'title' => 'NID',
		 'help' => 'The Node to which this Track data belongs.',
		 'field' => array(
		 		'handler' => 'views_handler_field_numeric',
		 		),
		 );	
	
	$data['trackfield_dataset_latitude']['vid'] = array(
		 'title' => 'VID',
		 'help' => 'The revision of the Node to which this Track data belongs.',
		 'field' => array(
		 		'handler' => 'views_handler_field_numeric',
		 		),
		 );
		 
	$data['trackfield_dataset_latitude']['field_name'] = array(
		 'title' => 'Field Name',
		 'help' => 'The field from which this Track Data was taken from.',
		 'field' => array(
		 		'handler' => 'views_handler_field',
		 		),
		 );
		 
	$data['trackfield_dataset_latitude']['delta'] = array(
		 'title' => 'Delta',
		 'help' => 'The delta of the field from which this Track Data was taken from.',
		 'field' => array(
		 		'handler' => 'views_handler_field_numeric',
		 		),
		 );
		 
	$data['trackfield_dataset_latitude']['setdata'] = array(
		 'title' => 'Trackfield: Latitude',
		 'help' => 'The type of data this is (eg. Latitude, Longitude, Altititude).',
		 'field' => array(
		 		'handler' => 'views_handler_field',
		 		),
		 );
		 
	$data['trackfield_dataset_longitude']['table'] = array(
	    'group' => t('Content'),
	    'help' => 'This is data that has been stored by the Trackfield module.',
	    );
	    
	$data['trackfield_dataset_longitude']['table']['join']['node'] = array(
		 'left_field' => 'nid',
		 'field' => 'nid',
		 );
	
	$data['trackfield_dataset_longitude']['nid'] = array(
		 'title' => 'NID',
		 'help' => 'The Node to which this Track data belongs.',
		 'field' => array(
		 		'handler' => 'views_handler_field_numeric',
		 		),
		 );	
	
	$data['trackfield_dataset_longitude']['vid'] = array(
		 'title' => 'VID',
		 'help' => 'The revision of the Node to which this Track data belongs.',
		 'field' => array(
		 		'handler' => 'views_handler_field_numeric',
		 		),
		 );
		 
	$data['trackfield_dataset_longitude']['field_name'] = array(
		 'title' => 'Field Name',
		 'help' => 'The field from which this Track Data was taken from.',
		 'field' => array(
		 		'handler' => 'views_handler_field',
		 		),
		 );
		 
	$data['trackfield_dataset_longitude']['delta'] = array(
		 'title' => 'Delta',
		 'help' => 'The delta of the field from which this Track Data was taken from.',
		 'field' => array(
		 		'handler' => 'views_handler_field_numeric',
		 		),
		 );
		 
	$data['trackfield_dataset_longitude']['setdata'] = array(
		 'title' => 'Trackfield: Longitude',
		 'help' => 'The type of data this is (eg. Latitude, Longitude, Altititude).',
		 'field' => array(
		 		'handler' => 'views_handler_field',
		 		),
		 );		 
		 
	return $data;
		 
 }
