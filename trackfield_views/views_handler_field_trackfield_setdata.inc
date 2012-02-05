<?php

class views_handler_field_trackfield_setdata extends views_handler_field {
  function query() {
  	// Ensure the table_alias is set correctly here otherwise it seems to inherit the table_alias of the
  	// first instance of this handler in the query, I do not know how or why and that theory may be incorrect. 
  	$this->table_alias = $this->table;
  	
    $this->ensure_my_table();
    
    // Add the field.
    $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
    $this->field_alias = $this->query->add_field($this->table_alias, $this->real_field, NULL, $params);
    
    // If I do not add the relationship explicitly Views will only join to our table once using the first
    // aliased instance presented. It fails for every other, I am yet to figure out why. This works and is 
    // valid Views code.
    $join = $this->query->get_join_data($this->table_alias, $this->view->base_table);
    $this->query->add_relationship($this->table_alias, $join, $this->view->base_table, NULL);
    
    // Add the WHERE condition for the settype of data.
    $this->query->add_where(0, $this->table_alias . '.' . 'settype', $this->table_alias, NULL);

    $this->add_additional_fields();
  }
}