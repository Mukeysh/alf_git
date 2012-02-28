                        repec_meta.module

Author:  Joe Weiner (jweiner@hmdc.harvard.edu) Harvard MIT Data Center
Released under the GPL


Description:
============
This module is designed to work in conjunction with the biblio module and was
tested in Drupal 5. The module is compatible with both MySQL and PostgreSQL databases.

The main function of the module is to automate the creation of rdf templates files used by
RePEc (Research Papers in Economics) and place them in a local archive, which is collected
by a RePEc automated process.

NOTE: To use this module you must FIRST register your meta data archive with
RePEc. Information regarding registration can be found at: http://repec.org/


Requirements:
=============
Drupal 5.x.


Installation:
=============
This module will install all the needed repec_meta database tables upon
enabling the module from the Drupal admin/modules page.

NOTE: An uninstall function is included with this module which will automatically drop the
tables and remove the module's system-wide variables from Drupal's 'variables' table


Settings:
==========
There are three main settings for which this module can run. By default the module is set to
API mode, which give the developer the option when to call the function to update the archive.
The function is called repec_meta_api(), which will update all meta data in your archive at once.


API Mode -  does nothing by default, but lets the developer decide when to call the module's functions.
Batch Mode -  is intended to be run by cron and will update all meta files at once in a batch process.
Per Submission Mode - is a "real time" update mode which will update or create a meta files whenever content for RePEc is submitted or updated.


IMPORTANT: In order for this module to work correctly you must FIRST enter the required data into the
module's 'Configuration' settings, which can be found at: admin/settings/repec_meta/info

These two pieces of information cannot have pre-set default settings. So you the administrator must
supply this information so the module will know the directory names and where your archive is located.

1) Archive Code
2) Archive Root Path
 
(You obtain your 'Archive Code' from RePEc, so if you don't have one yet, you'll need to email them to request one.)



Additional Features:
=====================
The repec_meta module is designed to be flexible and scalable.

The module's admin settings gives the administrator the option to:

1) Reassign biblio to RePEc template mappings. For example, the biblio 'Web Article' will create a 'journl' rdf file by default,
but it can be changed to create a 'sftwre' rdf file if deemed appropriate. Keep in mind that template mapping changes are global,
not on a per submission basis, although I had considered this originally.

2) Manage the identifier fields within the rdf files. You can choose to include or exclude specific identifier fields,
(although required fields which are always included).

Also the module comes with a test link called "Test RePEc Meta API Function" (repec_meta/test/api) which will call the module's 
API function. It is a good idea to use this link to test the module this after configuring the settings.  This will be available 
in Drupal's default navigation bar for the site administrator only. 


Access Control:
===============
Access to all module settings menu's are controlled by user access permission

'administer repec settings'

This setting is found a Drupal's admin/user/access page. By default, no roles are check, meaning only the
site administrator has access.


Troubleshooting:
===============
If your get an error message 'Test Failed' when testing the module (repec_meta/test/api) it probably means
'Archive Code' and 'Archive Root Path' have not been set.

You can set these in the 'Configuration' settings page, which can be found at: admin/settings/repec_meta/info

The administrator must supply this information in order for the module to work properly.








