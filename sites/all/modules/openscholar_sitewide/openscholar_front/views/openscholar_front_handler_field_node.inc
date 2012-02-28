<?php

class openscholar_front_handler_field_node extends spaces_handler_field_node {

  /**
   * Override of render_link().
   * Add purl options to link if 'frontpage' option is enabled. Note that
   * the PURL url is generated using 'absolute' to keep from overriding *all*
   * of render_as_link().
   */
  function render_link($data, $values) {
    parent::render_link($data, $values);
    if ($data !== NULL && $data !== '' && !empty($this->options['spaces']['frontpage']) && !empty($this->options['spaces']['type'])) {
      $this->options['alter']['path'] = url('<front>', array(
        'absolute' => TRUE,
        'purl' => array(
          'provider' => $this->get_provider($values->{$this->aliases['nid']},$this->options['spaces']['type']),
          'id' => $values->{$this->aliases['nid']},
        )
      ));
    }
    return $data;
  }
  
  /**
   * Get the purl provider for this site
   *
   * @param nid $gid
   * @param string $type
   */
  private function get_provider($gid, $type){
    
    $valid_providers = array();
    $result = db_query("SELECT provider FROM {purl} WHERE id = %d ", $gid);
    while ($provider = db_result($result)) $valid_providers[] = $provider;

    if(in_array('vsite_domain',$valid_providers)){
      //This site has a domain provider
      return 'vsite_domain';
    }elseif (in_array($type,$valid_providers)){
      //This site has a default provider
      return $type;
    }//Set from db
    
    //None found return default
    return $type;
  }
}
