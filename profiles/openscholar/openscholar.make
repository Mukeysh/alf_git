; $Id$

;Core Version
core = "6.x"
api = "2"
   
;Drupal Core
projects[drupal][version] = "6.20"
projects[drupal][type] = "core" 

; Install Profile
; projects[openscholar][version] = "6.1" 

; Contrib projects 

projects[addthis][subdir] = "contrib"
projects[addthis][version] = "3.0-beta1"
projects[addthis][patch][] = "http://drupal.org/files/issues/addthis_config_class-1264382-1.patch"

projects[admin][subdir] = "contrib"
projects[admin][version] = "2.0"

projects[advanced_help][subdir] = "contrib"
projects[advanced_help][version] = "1.2"

projects[auto_nodetitle][subdir] = "contrib"
projects[auto_nodetitle][version] = "1.2"

projects[better_formats][subdir] = "contrib"
projects[better_formats][version] = "2.x-dev"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.9"

projects[coder][subdir] = "contrib"
projects[coder][version] = "2.0-beta1"

projects[conditional_styles][subdir] = "contrib"
projects[conditional_styles][version] = "1.1"

projects[content_profile][subdir] = "contrib"
projects[content_profile][version] = "1.0"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0"

projects[contextual_annotation][subdir] = "contrib"
projects[contextual_annotation][version] = "1.0-alpha1"

projects[crayon][subdir] = "contrib"
projects[crayon][version] = "1.0-beta2"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.8"

projects[cvs_deploy][subdir] = "contrib"
projects[cvs_deploy][version] = "1.1"

projects[data][subdir] = "contrib"
projects[data][version] = "1.0-alpha14"

projects[date][subdir] = "contrib"
projects[date][version] = "2.7"

projects[diff][subdir] = "contrib"
projects[diff][version] = "2.3"

projects[dyntextfield][subdir] = "contrib"
projects[dyntextfield][version] = "1.0-beta1"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0"

projects[filefield][subdir] = "contrib"
projects[filefield][version] = "3.10"

projects[filefield_paths][subdir] = "contrib"
projects[filefield_paths][version] = "1.4"

projects[image_resize_filter][subdir] = "contrib"
projects[image_resize_filter][version] = "1.9"

projects[imageapi][subdir] = "contrib"
projects[imageapi][version] = "1.9"

projects[imagefield][subdir] = "contrib"
projects[imagefield][version] = "3.10"

projects[imagefield_crop][subdir] = "contrib"
projects[imagefield_crop][version] = "1.0"
projects[imagefield_crop][patch][] = "http://drupal.org/files/issues/imagefield_crop.patch"

projects[insert][subdir] = "contrib"
projects[insert][version] = "1.1"

projects[install_profile_api][subdir] = "contrib"
projects[install_profile_api][version] = "2.1"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "1.0-beta3"

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = "1.5"

projects[ldap_integration][subdir] = "contrib"
projects[ldap_integration][version] = "1.0-beta2"

projects[link][subdir] = "contrib"
projects[link][version] = "2.9"

projects[shadowbox][subdir] = "contrib"
projects[shadowbox][version] = "4.2"

projects[luceneapi][subdir] = "contrib"
projects[luceneapi][version] = "2.2"

projects[luceneapi_dym][subdir] = "contrib"
projects[luceneapi_dym][version] = "1.0-beta4"

projects[menu_node][subdir] = "contrib"
projects[menu_node][version] = "1.3"

projects[mollom][subdir] = "contrib"
projects[mollom][version] = "1.15"

projects[nodeorder][subdir] = "contrib"
projects[nodeorder][version] = "1.1"

projects[nodeformcols][subdir] = "contrib"
projects[nodeformcols][version] = "1.6"

projects[nodereference_url][subdir] = "contrib"
projects[nodereference_url][version] = "1.10"

projects[og][subdir] = "contrib"
projects[og][version] = "2.1"

projects[og_vocab][subdir] = "contrib"
projects[og_vocab][version] = "1.1"

projects[override_node_options][subdir] = "contrib"
projects[override_node_options][version] = "1.12"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.5"

projects[prepopulate][subdir] = "contrib"
projects[prepopulate][version] = "2.1"

projects[schema][subdir] = "contrib"
projects[schema][version] = "1.7"

projects[shorten][subdir] = "contrib"
projects[shorten][version] = "1.11"
projects[shorten][patch][] = "http://drupal.org/files/issues/full_url_cache_duration-1215550-1.patch"

projects[stringoverrides][subdir] = "contrib"
projects[stringoverrides][version] = "1.8"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[token][subdir] = "contrib"
projects[token][version] = "1.15"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "3.0"

projects[twitter_pull][subdir] = "contrib"
projects[twitter_pull][version] = "1.2"
projects[twitter_pull][patch][] = "http://drupal.org/files/issues/1100270-twitter_pull-cache.patch"

projects[ucreate][subdir] = "contrib"
projects[ucreate][version] = "1.0-beta4"

projects[vertical_tabs][subdir] = "contrib"
projects[vertical_tabs][version] = "1.0-rc2"

projects[views][subdir] = "contrib"
projects[views][version] = "2.13"
projects[views][patch][] = "http://drupal.org/files/issues/views_cached_pager.patch"

projects[views_attach][subdir] = "contrib"
projects[views_attach][version] = "2.2"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "1.11"

projects[views_content_cache][subdir] = "contrib"
projects[views_content_cache][version] = "2.2"

projects[wysiwyg][subdir]="contrib"
projects[wysiwyg][version]= "2.2"

projects[wysiwyg_imagefield][subdir]="contrib"
projects[wysiwyg_imagefield][version]= "1.x-dev"

;Contrib (Drupal Modules without official Releases - Pulling from stable tested revision)

projects[luceneapi_biblio][subdir] = "contrib"
projects[luceneapi_biblio][type] = "module"
projects[luceneapi_biblio][download][type] = "svn"
projects[luceneapi_biblio][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/branches/SCHOLAR-2-0-BETA5/sites/all/modules/contrib/luceneapi_biblio/"

projects[luceneapi_og][subdir] = "contrib"
projects[luceneapi_og][type] = module
projects[luceneapi_og][download][type] = cvs
projects[luceneapi_og][download][module] = contributions/modules/luceneapi_og
projects[luceneapi_og][download][revision] = "HEAD:2010-06-10"

; To be released
projects[dialog][subdir] = "contrib"
projects[dialog][type] = "module"
projects[dialog][download][type] = "cvs"
projects[dialog][download][module] = "contributions/modules/dialog"
projects[dialog][download][revision] = "DRUPAL-6--1:2010-02-24"

projects[activity][subdir] = "contrib"
projects[activity][type] = "module"
projects[activity][download][type] = "cvs"
projects[activity][download][module] = "contributions/modules/activity"
projects[activity][download][revision] = "DRUPAL-6--2:2010-10-26"
projects[activity][patch][] = "http://drupal.org/files/issues/activity_warning.patch"

projects[imagecache][subdir] = "contrib"
projects[imagecache][type] = "module"
projects[imagecache][download][type] = "cvs"
projects[imagecache][download][module] = "contributions/modules/imagecache"
projects[imagecache][download][revision] = "DRUPAL-6--1:2010-05-26"

projects[signup][subdir] = "contrib"
projects[signup][type] = "module"
projects[signup][download][type] = "cvs"
projects[signup][download][module] = "contributions/modules/signup"
projects[signup][download][revision] = "DRUPAL-6--1:2010-09-17"
projects[signup][patch][] = "http://drupal.org/files/issues/signup-fieldset-weight-915104.patch"

;Contrib (Non-Patched Included but not enabled by default in the profile)
projects[devel][subdir] = "contrib"
projects[devel][version] = "1.23"

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "1.6"




; Contrib (patched modules)
projects[apachesolr][subdir] = "contrib"
projects[apachesolr][version] = "2.0-beta2"
projects[apachesolr][patch][] = "http://drupal.org/files/issues/804700-apachesolr_search2.module.patch"

projects[apachesolr_attachments][subdir] = "contrib"
projects[apachesolr_attachments][version] = "2.0-alpha2"

projects[apachesolr_og][subdir] = "contrib"
projects[apachesolr_og][version] = "2.x-dev"

projects[apachesolr_biblio][subdir] = "contrib"
projects[apachesolr_biblio][version] = "1.x-dev"
projects[apachesolr_biblio][patch][] = "http://drupal.org/files/issues/785370_features_integration.patch"
projects[apachesolr_biblio][patch][] = "http://drupal.org/files/issues/apachesolr_biblio-821660_1.patch"
projects[apachesolr_biblio][patch][] = "http://drupal.org/files/issues/785370_features_integration.get_fields.patch"
projects[apachesolr_biblio][patch][] = "http://drupal.org/files/issues/1128598.apachesolr_biblio.text_search.patch"

; @todo do we have some any uncommitted patches for biblio left?
projects[biblio][subdir] = "contrib"
projects[biblio][version] = "1.15"
projects[biblio][patch][] = "http://drupal.org/files/issues/683868.biblio_access_patch2.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/830770.biblio.path_alias.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/830726.endnote8_export.escape_urls3.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/biblio_update_date_teaser.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/export_hook.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/1127508.biblio.contributor_count.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/1127514.biblio.chicago.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/biblio.etal-override.1166426.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/biblio_default_sorting.1168676.patch"
projects[biblio][patch][] = "http://drupal.org/files/issues/spaces_og_filter.patch"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "1.0-beta12"
projects[file_aliases][patch][] = "http://drupal.org/files/issues/null_nodetype-625196-67.patch"

projects[file_aliases][subdir] = "contrib"
projects[file_aliases][version] = "1.1"
projects[file_aliases][patch][] = "http://drupal.org/files/issues/file_aliases_nodeFormDescription3.patch"
projects[file_aliases][patch][] = "http://drupal.org/files/issues/file_aliases_drupal_cache.patch"


projects[flag][subdir] = "contrib"
projects[flag][version] = "2.0-beta4"

projects[oembed][subdir] = "contrib"
projects[oembed][version] = "master"
projects[oembed][patch][] = patch_goes_where

projects[creativecommons][subdir] = "contrib"
projects[creativecommons][version] = "6.x-1.x"
projects[creativecommons][patch][] = "http://drupal.org/files/issues/creativecommons_install-1055080.patch"
projects[creativecommons][patch][] = "http://drupal.org/files/issues/creativecommons_class-1050180.patch"

;TODO Move Patch
projects[itweak_upload][subdir] = "contrib"
projects[itweak_upload][version] = "2.5"
projects[itweak_upload][patch][] = "http://drupal.org/files/issues/include_thumbs_in_node_object.patch"
projects[itweak_upload][patch][] = "http://drupal.org/files/issues/optional_jcarousel_0.patch"


projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "2.0-alpha1"
projects[jquery_update][patch][] = "http://drupal.org/files/issues/draggable-329797-4.patch"
projects[jquery_update][patch][] = "http://drupal.org/files/issues/tabledrag_after_draggable-329797.js_.patch"


projects[purl][subdir] = "contrib"
projects[purl][version] = "1.0-beta13"
;projects[purl][patch][] = "http://drupal.org/files/issues/dynamic_modifier.Beta12.patch"
projects[purl][patch][] = "http://drupal.org/files/issues/check_class.Beta13.patch"


projects[spaces][subdir] = "contrib"
projects[spaces][version] = "3.2"
projects[spaces][patch][] = "http://drupal.org/files/issues/maintain_openscholar_privacy_settings-1142684.patch"
projects[spaces][patch][] = "http://drupal.org/files/issues/og_vocab_compatibility-848638-4.patch"
projects[spaces][patch][] = "http://drupal.org/files/issues/preserve_block_subject_customizer-1160126.patch" 

; Custom modules
; TODO OS CUSTOM
projects[openscholar_features][location] = "modules"
projects[openscholar_features][type] = "module"
projects[openscholar_features][download][type] = "svn"
projects[openscholar_features][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/modules/openscholar_features/"

projects[openscholar_scholar][location] = "modules"
projects[openscholar_scholar][type] = "module"
projects[openscholar_scholar][download][type] = "svn"
projects[openscholar_scholar][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/modules/openscholar_scholar/"

projects[openscholar_sitewide][location] = "modules"
projects[openscholar_sitewide][type] = "module"
projects[openscholar_sitewide][download][type] = "svn"
projects[openscholar_sitewide][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/modules/openscholar_sitewide/"

projects[openscholar_projects][location] = "modules"
projects[openscholar_projects][type] = "module"
projects[openscholar_projects][download][type] = "svn"
projects[openscholar_projects][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/modules/openscholar_projects/"

projects[os][location] = "modules"
projects[os][type] = "module"
projects[os][download][type] = "svn"
projects[os][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/modules/os/"

; includes adminformcols, harvard, iqss, openscholar_ldap
projects[custom][location] = "modules"
projects[custom][type] = "module"
projects[custom][download][type] = "svn"
projects[custom][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/modules/custom/"


; Open Atrium modules
projects[litecal][subdir] = "contrib"
projects[litecal][location] = "http://code.developmentseed.org/fserver"
projects[litecal][version] = "1.0-alpha5"


; Themes


projects[tao][version] = "3.2"
projects[tao][subdir] = "contrib"

projects[rubik][version] = "3.0-beta2"
projects[rubik][subdir] = "contrib"

; TODO OS THEMES
;projects[openscholar_themes][subdir] = "openscholar"
projects[openscholar_themes][type] = "theme"
projects[openscholar_themes][download][type] = "svn"
projects[openscholar_themes][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/openscholar/"


; Custom themes
projects[fairbanks_center][subdir] = "custom"
projects[fairbanks_center][type] = "theme"
projects[fairbanks_center][download][type] = "svn"
projects[fairbanks_center][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/fairbanks_center"

projects[gking][subdir] = "custom"
projects[gking][type] = "theme"
projects[gking][download][type] = "svn"
projects[gking][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/gking"

projects[kshepsle][subdir] = "custom"
projects[kshepsle][type] = "theme"
projects[kshepsle][download][type] = "svn"
projects[kshepsle][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/kshepsle"

projects[leap][subdir] = "custom"
projects[leap][type] = "theme"
projects[leap][download][type] = "svn"
projects[leap][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/leap"

projects[openscholar_theme][subdir] = "custom"
projects[openscholar_theme][type] = "theme"
projects[openscholar_theme][download][type] = "svn"
projects[openscholar_theme][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/openscholar_theme"

projects[projects_harvard][subdir] = "custom"
projects[projects_harvard][type] = "theme"
projects[projects_harvard][download][type] = "svn"
projects[projects_harvard][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/projects_harvard"

projects[psr][subdir] = "custom"
projects[psr][type] = "theme"
projects[psr][download][type] = "svn"
projects[psr][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/psr"

projects[ptr][subdir] = "custom"
projects[ptr][type] = "theme"
projects[ptr][download][type] = "svn"
projects[ptr][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/ptr"

projects[rbates][subdir] = "custom"
projects[rbates][type] = "theme"
projects[rbates][download][type] = "svn"
projects[rbates][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/rbates"

projects[rcss][subdir] = "custom"
projects[rcss][type] = "theme"
projects[rcss][download][type] = "svn"
projects[rcss][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/rcss"

projects[scholar_jwe][subdir] = "custom"
projects[scholar_jwe][type] = "theme"
projects[scholar_jwe][download][type] = "svn"
projects[scholar_jwe][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/scholar_jwe"

projects[scholars_harvard][subdir] = "custom"
projects[scholars_harvard][type] = "theme"
projects[scholars_harvard][download][type] = "svn"
projects[scholars_harvard][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/scholars_harvard"

projects[starter_installation_theme][subdir] = "custom"
projects[starter_installation_theme][type] = "theme"
projects[starter_installation_theme][download][type] = "svn"
projects[starter_installation_theme][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/starter_installation_theme"

projects[starter_vsite_theme][subdir] = "custom"
projects[starter_vsite_theme][type] = "theme"
projects[starter_vsite_theme][download][type] = "svn"
projects[starter_vsite_theme][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/starter_vsite_theme"

projects[thedata][subdir] = "custom"
projects[thedata][type] = "theme"
projects[thedata][download][type] = "svn"
projects[thedata][download][url] = "https://scholar.svn.sourceforge.net/svnroot/scholar/trunk/sites/all/themes/custom/thedata"

; Libraries
libraries[luceneapi][destination] = "modules/contrib/luceneapi"
libraries[luceneapi][download][type] = "get"
libraries[luceneapi][download][url] = "http://downloads.sourceforge.net/project/luceneapi/luceneapi/6.x-2.0/luceneapi-lib-6.x-2.0.tar.gz"
libraries[luceneapi][directory_name] = "lib"

; TinyMCE 3.2.7
libraries[tinymce][download][type] = "get"
libraries[tinymce][download][url] = "http://downloads.sourceforge.net/project/tinymce/TinyMCE/3.3.8/tinymce_3_3_8.zip"
libraries[tinymce][directory_name] = "tinymce"

; jQuery UI
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery-ui-1.7.2.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

; SolrPhpClient
libraries[apachesolr][download][type] = "get"
libraries[apachesolr][download][url]  = "http://solr-php-client.googlecode.com/files/SolrPhpClient.r22.2009-11-09.tgz"
libraries[apachesolr][directory_name] = "SolrPhpClient"
libraries[apachesolr][destination]    = "modules/contrib/apachesolr"

