<?php 

/**
 * @file
 * google scholar class provides publication methods to theme biblio nodes with google metadata
 */

class citation_distribute_service_googlescholar extends citation_distribute_service {

	
  public function save($nid, $plugin) {
  	/* google_scholar themes a node if it has an entry in {citation_distribute} with type=google_scholar
  	 * to reach this point that must have happened, so the change is already saved.
  	 */
		return true;
  }

  public function map_metadata($nid) {
  	$node = node_load($nid);
  	
   /* returns array of author names formatted for google scholar */
  	function _googlescholar_list_authors($contributors = array()) {
  		$authors = array();
  		foreach($contributors as $cont) {
  			$authors[] = $cont['name'];
  		}
  		return $authors;
  	}
  	
  	/* returns $date in YYYY/M/D if possible.  just year if not.  'submitted' is not a year */
  	function _googlescholar_date($year, $date) {

  		if ($date) {
					return date('Y/m/d', strtotime($date));
  		}
  		
  		if ($year) {
  			return $year;
	  	}
	  	
	  	return false;
  	}
  	
    $metadata = array(
      'citation_journal_title'        => $node->biblio_secondary_title,
      'citation_publisher'            => $node->biblio_publisher,
      'citation_title'                => $node->title,
      'citation_year'                 => $node->biblio_year,
      'citation_volume'               => $node->biblio_volume,
      'citation_issue'                => $node->biblio_issue,
      'citation_issn'                 => $node->biblio_issn,
      'citation_isbn'                 => $node->biblio_isbn,
      'citation_language'             => $node->biblio_language,
      'citation_abstract'             => $node->biblio_abstract,
      'citation_abstract_html_url'    => $node->biblio_url,
    
    	'citation_keywords'							=> implode(';', $node->biblio_keywords),
    	'citation_publication_date'			=> _googlescholar_date((int)$node->biblio_year, $node->biblio_date),
    );
    if (count($node->biblio_contributors[1])) {
     $metadata['citation_author'] = _googlescholar_list_authors($node->biblio_contributors[1]);
    }
    

    
    return $metadata;
  }

  public function render($metadata) {
		return theme('googlescholar', $metadata);
  }


}

