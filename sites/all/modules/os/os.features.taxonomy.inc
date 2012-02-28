<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function os_taxonomy_default_vocabularies() {
  return array(
    'interests' => array(
      'name' => 'Related Interests',
      'description' => 'A comma-separated list of topics that may relate to the content of your site. ex.(zoology, evolutionary biology, casual inference)',
      'help' => 'A comma-separated list of topics that may relate to the content of your site. ex.(zoology, evolutionary biology, casual inference)',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_interests',
      'weight' => '0',
      'nodes' => array(
        'vsite' => 'vsite',
      ),
    ),
  );
}
