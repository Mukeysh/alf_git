<?php 

/**
 * @file vsitehelp.drush.inc 
 */

/**
 * implementation of hook_drush_help
 */
function vsitehelp_drush_help($section) {
  switch ($section){
    case 'drush:build_docs':
      return dt('Build advanced help documentation from os_help files.');
  }
}

/**
 * implementation of hook_drush_command
 */
function vsitehelp_drush_command() {
  $cmds = array(
    'build_docs' => array(
      'description' => 'Generate advanced help .ini files for boxes.',
      'options' => array(
        '--help-readme' => 'Displays the build_docs readme, which includes information on setting up help files for build_docs.'
      ),
      'examples' => array(
        'drush @site build_docs' => 'Scan OpenScholar source for os_help files and attach them to vsitehelp.',
      ),
      'aliases' => array('bd'),
      'bootstraph' => 'DRUSH_BOOTSTRAPH_DRUPAL_DATABASE',
    ),
  );
  
  return $cmds;
}

/**
 * implementation of drush_hook_command
 * finds os_help files, includes them in vsitehelp
 */
function drush_vsitehelp_build_docs() {
  define( 'DIR', drupal_get_path('module', 'vsitehelp') . '/help/'  );  //destination for ini and html files
  define( 'BR', "\n");                                                  //newline shortcut
  
  //addtional help from readme file
  if ($readme = drush_get_option('help-readme')) {
    echo BR . file_get_contents(drupal_get_path('module','vsitehelp') . '/README.BUILD_DOCS.txt') . BR.BR;
    return;
  }
  
  // create images dir if necessary.
  if (!is_dir(DIR.'/images/')) {
    mkdir(DIR.'/images', 0775);
  }
  
  // get all os_help files
  $files = drupal_system_listing('.*\.os_help\.ini$', 'modules');
    
  // start with the default template
  $ini = file_get_contents(drupal_get_path('module', 'vsitehelp') . '/vsitehelp.template.ini') . BR . BR;
  $done = array();
  
  //loop over all os_help.ini files
  foreach($files as $name => $o_file) {
    $helpfile = str_replace('os_help', 'html', $name);
    $path = str_replace($o_file->basename, '', $o_file->filename);
    
    // append fragment of ini file
    $file = trim(file_get_contents($o_file->filename)) . BR;
    $file .= BR.BR;    
    $ini .= $file;
   
    //copy html help file
    copy($path.$helpfile, DIR . $helpfile);
       
    //copy images folder
    foreach( file_scan_directory($path . '/images/', '.') as $i => $img ) {
      copy( $path . 'images/' . $img->basename, DIR.'/images/'.$img->basename);
    }
    
    $done[] = str_replace('.os_help', '', $o_file->name);
  }
  
  echo 'Included documentation for ' . implode(', ', $done);
  file_put_contents(DIR . '/vsitehelp.help.ini', $ini);
}


