<?php

/**
 * Implementation of hook_strongarm().
 */
function vsite_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_widget_version';
  $strongarm->value = 200;

  $export['addthis_widget_version'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_long';
  $strongarm->value = 'l, F j, Y, g:ia';

  $export['date_format_long'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_medium';
  $strongarm->value = 'F j, Y';

  $export['date_format_medium'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_short';
  $strongarm->value = 'n/j/Y';

  $export['date_format_short'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_vsite_field_vsite_logo';
  $strongarm->value = 0;

  $export['ffp_vsite_field_vsite_logo'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'itweak_upload_thumbnail_link_default';
  $strongarm->value = 'shadowboxgrouped';

  $export['itweak_upload_thumbnail_link_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_custom_strings_en';
  $strongarm->value = array(
    'Your message will be sent to all members of this group.' => 'Your message will be sent to all members of this web site.',
    'You may not leave this group because it is a <em>closed</em> group. You should request removal from a group administrator.' => 'You may not leave this web site because it is a <em>closed</em> web site. You should request removal from a web site administrtor.',
    'Leave this group' => 'Leave this web site',
    'In order to join this group, you must login or register a new account. After you have successfully done so, you will need to request membership again.' => 'In order to join this web site, you must login or register a new account. After you have successfully done so, you will need to request membership again.',
    'Are you sure you want to join the group %title?' => 'Are you sure you want to join the web site %title?',
    'Membership request to the %group group awaits approval by an administrator.' => 'Membership request to the %group web site awaits approval by an administrator.',
    'Membership request to the %group group was rejected, only group administrators can add users to this group.' => 'Membership request to the %group web site was rejected, only group administrators can add users to this group.',
    'Are you sure you want to remove !name from the group %title?' => 'Are you sure you want to remove !name from the web site %title?',
    'Add one or more usernames in order to associate users with this group. Multiple usernames should be separated by a comma.' => 'Add one or more usernames in order to associate users with this web site. Multiple usernames should be separated by a comma.',
    'No groups available.' => 'No web sites available.',
    'No posts in this group.' => 'No posts in this web site.',
    'No public posts in this group.' => 'No public posts in this web site.',
    'A brief description for the group details block and the group directory.' => 'A brief description for the web site details block and the group directory.',
    'Admin: Create' => 'Make administrator',
    'Admin: Remove' => 'Remove administrator status',
    'How should membership requests be handled in this group? When you select <em>closed</em>, users will not be able to join <strong>or</strong> leave.' => 'How should membership requests be handled in this web site? When you select <em>closed</em>, users will not be able to join <strong>or</strong> leave.',
    'May users join this web site during registration? If checked, a corresponding checkbox will be added to the registration form.' => 'May users join this group during registration? If checked, a corresponding checkbox will be added to the registration form.',
    'List in groups directory' => 'List in web site directory',
    'Should this group appear on the <a href=\\"@url\\">list of groups page</a> (requires OG Views module)? Disabled if the group is set to <em>private group</em>.' => 'Should this web site appear on the <a href=\\"@url\\">list of groups page</a> (requires OG Views module)? Disabled if the web site is set to <em>private group</em>.',
    'Group language' => 'Web site language',
    'Selecting a different locale will change the interface language for all group pages and emails. Users who have chosen a preferred language always see their chosen language.' => 'Selecting a different locale will change the interface language for all web site pages and emails. Users who have chosen a preferred language always see their chosen language.',
    'Selecting a different theme will change the look and feel of the group.' => 'Selecting a different theme will change the look and feel of the web site.',
    'You must <a href=\\"@join\\">join a group</a> before posting on this web site.' => 'You must <a href=\\"@join\\">join a web site</a> before posting on this web site.',
    'A welcome greeting for your group home page. Consider listing the group objectives and mission.' => 'A welcome greeting for your web site home page. Consider listing the web site objectives and mission.',
    'Group manager' => 'Web site manager',
    'Sticky at top of group home page and other lists.' => 'Sticky at top of web site home page and other lists.',
    'OG audience & Public checkbox.' => 'Web site audience & Public checkbox.',
    'OG audience.' => 'Web site audience.',
    'Group description.' => 'Web site description.',
    'Handling of group membership requests.' => 'Handling of web site membership requests.',
    'The default interface language for this group.' => 'The default interface language for this web site.',
    'Delete all group posts which don\'t also belong to another group.' => 'Delete all web site posts which don\'t also belong to another group.',
    'Move all group posts to the group listed below.' => 'Move all web site posts to the web site listed below.',
    'Move all group posts and memberships to the group listed below.' => 'Move all web site posts and memberships to the web site listed below.',
    'In addition to deleting this group, you choose how to disposition the posts and memberships within it' => 'In addition to deleting this web site, you choose how to disposition the posts and memberships within it',
    'Target group' => 'Target web site',
    'If you chose <strong>Move all group posts</strong> above, specify a destination group.' => 'If you chose <strong>Move all web site posts</strong> above, specify a destination web site.',
    'Delete group' => 'Delete web site',
    'My groups' => 'My web sites',
    'Other groups' => 'Other groups',
    'You must <a href=\\"@join\\">join a group</a> before posting a %type.' => 'You must <a href=\\"@join\\">join a web site</a> before posting a %type.',
    '@type \'@subject\' by @username\\n\\n@node_teaser\\n\\n!read_more: !content_url\\nPost reply: !reply_url\\n\\n--\\nYou are subscribed from the group \'@group\' at @site.\\nTo manage your subscription, visit !group_url' => '@type \'@subject\' by @username\\n\\n@node_teaser\\n\\n!read_more: !content_url\\nPost reply: !reply_url\\n\\n--\\nYou are subscribed from the web site \'@group\' at @site.\\nTo manage your subscription, visit !group_url',
    '@body\\n\\n--\\nThis message was sent by an administrator in the \'@group\' group at @site. To visit this group, browse to !url_group. To unsubscribe from this group, visit !url_unsubscribe' => '@body\\n\\n--\\nThis message was sent by an administrator in the \'@group\' web site at @site. To visit this web site, browse to !url_group. To unsubscribe from this web site, visit !url_unsubscribe',
    'You may now post messages in this group located at !group_url' => 'You may now post messages in this web site located at !group_url',
    'Invitation to join the group \'@group\' at @site' => 'Invitation to join the web site \'@group\' at @site',
    'Hi. I\'m a member of \'@group\' and I welcome you to join this group as well. Please see the link and message below.\\n\\n@group\\n@description\\nJoin: !group_url\\n@body' => 'Hi. I\'m a member of \'@group\' and I welcome you to join this web site as well. Please see the link and message below.\\n\\n@group\\n@description\\nJoin: !group_url\\n@body',
    'You are now an administrator for the group \'@group\'' => 'You are now an administrator for the group \'@group\'',
    '@username, you are now an administrator for the group \'@group\'.\\n\\nYou can administer this group by logging in here:\\n !group_url' => '@username, you are now an administrator for the web site \'@group\'.\\n\\nYou can administer this group by logging in here:\\n !group_url',
    'May not be posted into a group.' => 'May not be posted into a web site.',
    'New groups' => 'New Web sites',
    'You may specify which types of group members appear in the listing.' => 'You may specify which types of web site members appear in the listing.',
    'Maximum number of groups to show' => 'Maximum number of web sites to show',
    'This group offers a <a href=\\"@subscription\\">subscription option</a>.' => 'This web site offers a <a href=\\"@subscription\\">subscription option</a>.',
    'Browse the newest groups.' => 'Browse the newest web sites.',
    'You must <a href=\\"!register\\">register</a>/<a href=\\"!login\\">login</a> in order to post into this group.' => 'You must <a href=\\"!register\\">register</a>/<a href=\\"!login\\">login</a> in order to post into this web site.',
    'This is an <em>invite only</em> group. The group administrators add/remove members as needed.' => 'This is an <em>invite only</em> web site. The web site administrators add/remove members as needed.',
    'This is a <em>closed</em> group. The group administrators add/remove members as needed.' => 'This is a <em>closed</em> web site. The web site administrators add/remove members as needed.',
    'Add a new !type in this group.' => 'Add a new !type in this web site.',
    'Add a user to a group.' => 'Add a user to a web site.',
    'All members for a given group.' => 'All members for a given web site.',
    'Retrieve the group memberships for a given user.' => 'Retrieve the web site memberships for a given user.',
    'Title of top group' => 'Title of top web site',
    'Unfiltered title of top group. WARNING - raw user input.' => 'Unfiltered title of top web site. WARNING - raw user input.',
    'ID of top group' => 'ID of top web site',
    '1 user added to the group.' => '1 user added to the web site.',
    '@count users added to the group.' => '@count users added to the web site.',
    '1 group' => '1 web site',
    '@count groups' => '@count web sites',
    'Show this post in this group.' => 'Show this post in this group.',
    'Show this post in these groups.' => 'Show this post in these groups.',
    'Create group administrator' => 'Create web site administrator',
    'Delete group administrator' => 'Delete  web site administrator',
    'Group activity' => ' Web site activity',
    'Stores information about each group.' => 'Stores information about each web site.',
    'The default page for this space.' => 'The default page for this web site.',
    'Node in current space' => 'Node in current web site',
    'Posts in current space.' => 'Posts in current web site.',
    'User in current space' => 'User in current web site',
    'Users in current space' => 'Users in current web site',
    'Group settings' => 'Web site settings',
    'Please setup your group by choosing a homepage setting.' => 'Please setup your web site by choosing a homepage setting.',
    'This content is not assigned to a group and is not visible to non-administrative users.' => 'This content is not assigned to a web site and is not visible to non-administrative users.',
    'This form should only be submitted within a properly configured group. Continue at your own risk.' => 'This form should only be submitted within a properly configured web site. Continue at your own risk.',
    'Private group' => 'Private web site',
    'Controlled group' => 'Controlled web site',
    'Public group' => 'Public web site',
    'Groups' => 'Web Sites',
    'Your group membership settings were saved successfully.' => 'Your web site membership settings were saved successfully.',
    'All users may view public content from this group. User may join this group at will.' => 'All users may view public content from this web site. User may join this web site at will.',
    'Only members will be able to access this group. Membership is strictly managed by admins.' => 'Only members will be able to access this web site Membership is strictly managed by adminstrators.',
    'Join this group' => 'Join this web site',
    'The space configuration has been saved successfully.' => 'The web site configuration has been saved successfully.',
    'Spaces preset defaults were saved successfully.' => 'Web site preset defaults were saved successfully.',
    'Customizations saved for space !title.' => 'Customizations saved for web site !title.',
    'Biblio' => 'Publication',
    'Secondary Title' => 'Publication Type',
    'Browse by Secondary Title' => 'Browse by Publication Type',
    'Biblio: Filter by Secondary Title' => 'Biblio: Filter by Publication Type',
    'Delete node' => 'Delete',
    'book' => 'booklet',
    'Book' => 'Booklet',
    'Book Page' => 'Booklet',
  );

  $export['locale_custom_strings_en'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_primary_links_source';
  $strongarm->value = 'features';

  $export['menu_primary_links_source'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_vsite';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_vsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_vsite';
  $strongarm->value = 'group';

  $export['og_content_type_usage_vsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_hyphen';
  $strongarm->value = 1;

  $export['pathauto_punctuation_hyphen'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_underscore';
  $strongarm->value = 2;

  $export['pathauto_punctuation_underscore'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_update_action';
  $strongarm->value = '0';

  $export['pathauto_update_action'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scholar_content_type';
  $strongarm->value = 'vsite';

  $export['scholar_content_type'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scholar_site_menus';
  $strongarm->value = array(
    'features' => 'Primary Menu',
    'scholar_secondary_menu' => 'Secondary Menu',
  );

  $export['scholar_site_menus'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shadowbox_resize_duration';
  $strongarm->value = '0.15';

  $export['shadowbox_resize_duration'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_extensions_default';
  $strongarm->value = 'jpg jpeg gif png txt doc docx gz xls pdf ppt pptx pps odt ods odp tex tgz xml zip';

  $export['upload_extensions_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_list_default';
  $strongarm->value = '1';

  $export['upload_list_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_uploadsize_default';
  $strongarm->value = '128';

  $export['upload_uploadsize_default'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_usersize_default';
  $strongarm->value = '2048';

  $export['upload_usersize_default'] = $strongarm;
  return $export;
}
