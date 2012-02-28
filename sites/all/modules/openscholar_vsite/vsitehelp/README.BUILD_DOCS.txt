vsitehelp's help files can be built from the build_docs (bd) drush command provided by this module.

build_docs gathers advanced help (AH) documentation scattered across OpenScholar and deposits it in 
vsitehelp.  Individual modules include fragments of AH ini files as os_help.ini.  These files are
collected and appended to vsitehelp's vsitehelp.template.ini file.  These files can be placed anywhere
but convention dicates that they live in a module's help folder.  

HTML files that share a base name with an ini file are also copied to vsitehelp.  For instance, if
you have module.os_help.ini, build_docs will try to include module.html along with it.

Finally, the entire contents of the images subdirectory is copied into vsitehelp's images directory
(which will be created if it doesn't already exist).  Please include the module name in each image's
file name - build_docs does not prevent images with similar names from clobbering each other when
they're copied.  As with AH, you should link to images with src="path:/images/IMAGE_NAME.EXT", with
double quotes so that path gets replaced.

For reference, please see os_mailchimp and os_l10n modules.