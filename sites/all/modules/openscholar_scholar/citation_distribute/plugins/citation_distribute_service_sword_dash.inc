<?php 

/*
 * @ file defines dash as a sword destination
*/

class citation_distribute_service_sword_dash extends citation_distribute_service_sword {
	public $name = 			'dash';
	public $title = 		'DASH';
	public $location = 	'http://dash.harvard.edu';
	public $username = 	'swap@lists.iq.harvard.edu';
	public $password =  'citation_distribute_dash_password';    //variable to fetch for this password
	public $root_in  =  '/tmp/sword';
	public $subdir_in = 'dash';
	public $root_out =  '/tmp/sword';
	public $file_out =  'dash_files.zip';
	public $obo  	   =  '';
	
	//variable or function for determining school.
	
	// optional validate function
	// note that this take's nodeapi's $a3 arg (which is the $form during validation)
	// OR it can take a nid, depending on when the validation takes place.
	public function validate($a3) {
	  
	  if (is_array($a3)) {
	    $files = $a3['#post']['files'];
	  } elseif (is_int($a3) && $node = node_load($a3)) {
	    $files = $node->files;
	  } else {
	    //not sure what a3 is anymore, so bail.
	    return FALSE;
	  }
	  
		if (count($files) > 0) { // or body-> full text?
			return TRUE;
		} else {
			form_set_error('files', $this->title . ' requires the full text document be attached.');
			return FALSE;
			
			//TODO: check if a user has set his affiliation.  if not, send them to where that setting can be adjusted.
			//TODO: add a harvard affiliation setting.  can plugins modify admin pages I wonder?
		} 
		
	}

  /* 
	 * get_deposit_url($workspace)
	 * returns deposit url
	 * given workspaces/collections, try to figure out the correct collection.
	 */
	public function get_deposit_url($workspaces, $nid) {
		//get email address
		$query = 'SELECT u.mail FROM {node} n INNER JOIN {users} u ON n.uid=u.uid WHERE n.nid = "%d" LIMIT 1';
		$email = db_result(db_query($query, $nid));
		
		//get department of email domain
		$department = $this->department_domains[ array_pop(explode('@', $email)) ];
		if (!$department) {
			//maybe check for any harvard style domain before defaulting...
			$department = $this->department_domains['harvard.edu'];
		}
		
		//
		foreach ($workspaces as $workspace) {
			foreach ($workspace->sac_collections as $collection) {
				if ($collection->sac_colltitle == $department) {
					//yes this is a simplexmlelement.  yes curl and/or sword can read it
					$deposit_url = $collection->sac_href;
				}
			}
		}
		
		if (isset($deposit_url)) {
			return $deposit_url;
		} else {
			return false;
		}
	}

	// DASH has no interest in metadata only submissions.  Other sword repos may feel otherwise.
	// $node->body is where biblio keeps full text of articles.  maybe that could be saved...
	// service_sword should check
	//public $document_required = true;
	
	/******************* 
	 * r. engel's list of minimum data:
	 * 
	 * submitter info:
	 * name, email, primary affiliation (which school)
	 * 
	 * article info:
	 * authors, title, journal/proceedings/etc, year
	 * ****************/
	
	/* mapping of email domains to harvard departments by collection name */
	public $department_domains = array(
		'fas.harvard.edu' => 'FAS Scholarly Articles',
		'harvard.edu' =>  'FAS Scholarly Articles',
		'iq.harvard.edu' =>  'FAS Scholarly Articles',
		'lists.iq.harvard.edu' =>  'FAS Scholarly Articles',
		'hmdc.harvard.edu' =>  'FAS Scholarly Articles',
		
		'hsps.harvard.edu' => 'HSPH Scholarly Articles',	
		
		'hms.harvard.edu' => 'HMS Scholarly Articles',
		
		'law.harvard.edu' => 'HLS Scholarly Articles',
		'mail.law.harvard.edu' => 'HLS Scholarly Articles',
		'llm11.law.harvard.edu' => 'HLS Scholarly Articles',
		'jd13.law.harvard.edu' => 'HLS Scholarly Articles',
	
		'hds.harvard.edu' => 'HDS Scholarly Articles',
		
		'gse.harvard.edu' => 'GSE Scholarly Articles',
	
		'gsd.harvard.edu' => 'GSD Scholarly Articles',
	);
	/* unknown domains:
	 * wjh
	 * post
	 * gov
	 * seas
	 * mail
	 * wcfia
	 * hks
	 * rwj
	 * mcb
	 * law
	 * hksphd
	 * harvardd.edu do we do typo correction?  (see also: fass.)
	 * schepens
	 * math
	 * ksg
	 * jbcc
	 * hulmail 
	 * hbsp
	 * eecs
	 * college
	 * chemistry
	 * cga
	 * bwh
	 * bidmc
	 * mgh
	 * oeb
	 * cfa
	 * 
	 * other schools/colleections:
	 * 
'Harvard Business School'
'Harvard Central Administration'




'John F. Kennedy School of Government'

	 */
}
