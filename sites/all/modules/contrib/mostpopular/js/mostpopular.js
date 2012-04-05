// $Id: mostpopular.js,v 1.1 2010/12/09 19:31:15 czingerline Exp $
/*
 * Drupal Most Popular - Showcase the most popular content across your Drupal website and engage your audience.
 * Copyright © 2010 New Signature
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * You can contact New Signature by electronic mail at labs@newsignature.com –or- by U.S. Postal Service at 1100 H St. NW, Suite 940, Washington, DC 20005.
 */
/**
 * @file Adds javascript actions to the most popular block.
 * 
 * @author Andrew Marcus
 * @since Dec 18, 2009
 */
if (Drupal.jsEnabled) {
  Drupal.behaviors.mostpopular = function(context) {

    // Get the configuration options
    var options = $.extend(Drupal.behaviors.mostpopular.defaultOptions,
        Drupal.settings.mostpopular);

    // Attach to all the most popular blocks on the page
    var parent = $(options.blockSelector, context);
    parent.each(function() {
      var serviceTabs = parent.find(options.servicesSelector);
      var intervalTabs = parent.find(options.intervalsSelector);

      // Keep track of the page we're currently looking at
      var selected = { 'sid' : null, 'iid' : null };

      // Create a content container
      var content = parent.find(options.contentSelector);
      var wrapper = content.wrap("<div />").parent()
      .css({
        position : 'relative'
      });

      // Create a throbber image
      if (options.showThrobber) {
        var throbber = $(Drupal.theme('MostPopularThrobber'))
        .css({
          position : 'absolute',
          zIndex : 100
        }).appendTo(wrapper).hide();

        // Redefine the show function for the throbber to center it
        throbber.centerAndShow = function() {
          var top = parseInt((wrapper.outerHeight({margin: true}) - throbber.height()) / 2);
          var left = parseInt((wrapper.outerWidth({margin: true}) - throbber.width()) / 2);
          throbber.css({
            top : top,
            left : left
          }).show();
        };
      }

      // -----------------------------------------------------
      // Bind all the links to services
      serviceTabs.find("a").each(function() {
        var link = $(this).click(onClick);

        // Parse the service and interval from the URL
        var parts = parseLink(link.attr('href'));
        link.data('url', parts);
        link.data('service', true);
        link.attr('sid', parts.sid);

        if (link.parent().hasClass(options.selectedClass)) {
          selected.sid = parts.sid;
        }
      });

      // -----------------------------------------------------
      // Bind all the links to intervals
      intervalTabs.find("a").each(function() {
        var link = $(this).click(onClick);

        // Parse the service and interval from the URL
        var parts = parseLink(link.attr('href'));
        link.data('url', parts);
        link.data('interval', true);
        link.attr('iid', parts.iid);

        if (link.parent().hasClass(options.selectedClass)) {
          selected.iid = parts.iid;
        }
      });

      /**
       * Parses a URL to a mostpopular/items/%/% page and returns the
       * service and interval ids.
       * 
       * @return An array containing:
       *   - prefix: The site prefix (the basepath after the domain name).
       *   - sid: The service ID.
       *   - iid: The interval ID.
       */
      function parseLink(url) {
        var p = /(.*)\/mostpopular\/items\/(\d+)\/(\d+)/;
        var match = p.exec(url);
        if (match.length == 4) {
          return {
            'prefix' : match[1],
            'sid' : match[2],
            'iid' : match[3]
          };
        }
        return {};
      }

      /**
       * This function is called whenever a service or interval tab is clicked.
       * It loads the new most popular items via AJAX rather than the link's 
       * default URL.
       */
      function onClick() {
        var link = $(this);
        startReload();

        // Construct the appropriate URL to use
        var parts = link.data('url');
        var url = parts.prefix + "/mostpopular/ajax/";
        if (link.data('service')) {
          selected.sid = parts.sid;
        }
        else if (link.data('interval')) {
          selected.iid = parts.iid;
        }
        url += selected.sid + "/" + selected.iid;

        // Fetch the content via AJAX
        $.get(url, function(data) {
          onGet(link, data);
        });
        return false;
      }

      /**
       * This function is called when there is new data from the AJAX call.
       * 
       * @param link
       *   The link object that clicked.
       * @param data
       *   The new HTML sent back from Drupal.
       */
      function onGet(link, data) {
        var response = Drupal.parseJson(data);
        finishReload(response);

        // Select the appropriate tabs
        if (link.data('service')) {
          serviceTabs.removeClass(options.selectedClass);
        }
        else if (link.data('interval')) {
          intervalTabs.removeClass(options.selectedClass);
        }
        link.parent().addClass(options.selectedClass);
        return false;
      }

      /**
       * Starts the process of reloading the most popular items, by hiding
       * the existing content and showing the throbber, if necessary.
       * 
       * The hideContent() method defined in the options will be called.
       */
      function startReload() {
        // Show the throbber and dim the content
        if (throbber) {
          throbber.centerAndShow();
        }
        options.hideContent(content);
      }

      /**
       * Finishes the process of reloading the most popular items, by showing
       * the new content and hiding the throbber, if necessary.
       * 
       * The showContent() method defined in the options will be called.
       * 
       * @param response
       *   A JSON response from Drupal.  It contains one key, 'data', whose
       *   value is an HTML string to render.
       */
      function finishReload(response) {
        // Replace the content, fade it back in and hide the throbber
        options.showContent(content, response.data);
        if (throbber) {
          throbber.hide();
        }
      }
      
      // If Authcache is enabled, load the initial page based on the cookies
      if (typeof(Authcache) != 'undefined' && Authcache.isEnabled) {
        var cookie = $.cookie('mostpopular');
        var p = /(\d+)\/(\d+)/;
        var match = p.exec(cookie);
        selected.sid = match[1];
        selected.iid = match[2];
        
        // Find the current links and select them.
        var service = serviceTabs.find('a[sid=' + selected.sid + ']');
        var interval = intervalTabs.find('a[iid=' + selected.iid + ']');
        service.parent().addClass(options.selectedClass);        
        interval.parent().addClass(options.selectedClass);
        
        // Trigger a refresh on the selected interval link.
        interval.trigger('click');
      }
    });
    
  };

  /**
   * Defines the default options. Override these options in
   * Drupal.settings.mostpopular.
   */
  Drupal.behaviors.mostpopular.defaultOptions = {
    'hideContent' : function(content) {
      content.fadeTo(200, 0.5);
    },
    'showContent' : function(content, html) {
      content.html(html).fadeTo(200, 1.0);
    },
    'showThrobber' : true,
    'blockSelector' : '.mostpopular--widget',
    'servicesSelector' : 'ul.mostpopular--services li',
    'intervalsSelector' : 'ul.mostpopular--intervals li',
    'contentSelector' : 'div.mostpopular--content',
    'selectedClass' : 'selected'
  };

  /**
   * Provides a default theme for the throbber that appears when content is
   * reloading.   You can override this in your own theme.
   * 
   * @return An HTML string to render the throbber.
   */
  Drupal.theme.prototype.MostPopularThrobber = function() {
    return '<div class="ahah-progress ahah-progress-throbber"><div class="throbber">&nbsp;</div></div>';
  };
}