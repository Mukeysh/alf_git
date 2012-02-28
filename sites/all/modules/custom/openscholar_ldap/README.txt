// $Id;

This module redirects the site/register page such that unauthorized users can't 
create a site for themselves. It is intended for use with LDAP Integration 
(http://drupal.org/project/ldap_integration) or other seamless authentication systems.

Unauthenticated users attempting to create a virtual site will be redirected 
to a standard login form. Submitting it will bring them back to site/register
after authenticating them. 

There are no configuration options.