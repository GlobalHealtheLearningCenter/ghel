var baseURL = window.location.hostname;

(function ($) {
  $(document).ready(function(){
    //Set heights of lis in list to accommodate largest height.
    var h=0;  
    $('.view-certificate-programs .views-row .views-field .item-list li').each(function(index) {
       h=$(this).height()>h?$(this).height():h;
     });
     $('.view-certificate-programs .views-row .views-field .item-list li').height(h);

    $('#block-ghel-study-group-add-content .links li a').prepend('Create ');
    $('#block-ghel-program-group-add-content .links li a').prepend('Create ');
    $('#search-block-form .form-actions input.form-submit ').attr('value', '');

    $("#lang-dropdown-select-language").chosen({disable_search_threshold: 10});

    // Add mobile navigation.
    if($('.region-navigation').length > 0) {
      createTabbedContent($('.region-navigation > .block'), 'nav-touch', false);
    }

    // Add course navigation flyout.
    if($('#tabbed-regions').length > 0) {
      var tabbedRegions = $('#tabbed-regions');
      var tabCount = tabbedRegions.find('ul.tabbed-navigation .nav-item').size();
      var currentTabIndex = $.cookie('tabbed_navigation_active_index');

      createTabbedContent(tabbedRegions.find('.region'), 'nav-stacked nav-tabs', true, true);
      createFlyoutNav(tabbedRegions);

      // Set default tab if cookie hasn't been set before
      if (currentTabIndex == null) {
        $.cookie('tabbed_navigation_active_index', '0', { expires: 100, path: '/', domain: baseURL });
      }

      // Set default shown tab & highlighted
      // Make sure the current tab isn't greater than the current number of tabs on the page.
      if (tabCount - 1 < currentTabIndex) {
        $.cookie('tabbed_navigation_active_index', '0', { expires: 100, path: '/', domain: baseURL });
      }

      setCurrentTab(tabbedRegions, currentTabIndex).trigger('tabSet');
      tabbedRegions.find('ul.tabbed-navigation .nav-item').eq(currentTabIndex).addClass('active');

      // If cookie hasn't been set, set it to 'has-expanded-tabs'...this will usually be on the first page load
      if ($.cookie('tabbed_navigation_state') == null) {
        $.cookie('tabbed_navigation_state', 'has-expanded-tabs', { expires: 100, path: '/', domain: baseURL });
      }

      // Hide comments
      // @todo move this into preprocess to prevent it from loading on every page.
      createFlyoutComments($('#block-views-ghel-course-feedback-block'));
    }

    // Potentially delicate code to float a ul next to an image in the wysiwyg
    $('.image-medium_left').parent().next('ul').css('float', 'left').next().css('clear', 'left');
    $('.image-large_left').parent().next('ul').css('float', 'left').next().css('clear', 'left');

     //Creates toggle animation for drawer content
    $('#help-button').bind('click', function() {
       $('.help-text').toggleClass('open');
       $(this).toggleClass('open');
       event.preventDefault();
    });

    $('.comment-form-wrapper h2.title.comment-form').bind('click', function(){
      $('.comment-form-wrapper').toggleClass('open');

    });

    $('#close-help-button').bind('click', function() {
       $('.help-text').removeClass('open');
       event.preventDefault();
    });

    // Bind a click handler to the login link to focus the name field
    $('#login-link').bind('click', function() {
      $('#edit-name').focus();
    });
    // Focus the name element (triggers if /user/login is the path)
    $('#edit-name').focus();

    // Bind a click handler to the register link to focus the name field
    $('#register-link').bind('click', function() {
      $('#edit-mail').focus();
    });
    // Focus the name element (triggers if /user/register is the path)
    $('#edit-mail').focus();

    // Add Google Events for Course Download.
    var title=document.title;
    $('.epub-file a').click( function(event) {GA_submit(title,'EPUB Download');});
    $('.mobi-file a').click( function (event) {GA_submit(title,'MOBI Download');});
    $('.pdf-course a').click(function (event) {GA_submit(title,'PDF Download');});
    $('.print-course a').click(function(event) {GA_submit(title,'PRINT Download');});

  }); // END document.ready


  // Submit to GA - See above.
  function GA_submit(category,action) {
    ga('send', 'event', category, action);
  }

  function createTabbedContent(t, orientationClass, persist, navtitle) {
    if (typeof navtitle === 'undefined') {navtitle=false;}
    t.wrapAll('<div class="tabbed-content"></div>');
    var container = t.eq(0).parent();
    var nav = $('<ul class="tabbed-navigation nav ' + orientationClass + '"></ul>');
    t.each(function(index){
      $(this).addClass('tabbed');
      var title = $(this).find('.tab-title').text();
      var item = $('<li class="nav-item"></li>');
      var classEnd=navtitle?'t'+index:title.split(' ').join('-').toLowerCase();
      var search = 'region-tab-';
      if ($(this).attr('class').indexOf(search) !== -1) {
        var classes = $(this).attr('class').split(' ');
        $.each(classes, function(index, value) {
          if (value.indexOf(search) !== -1) {
            // Change title to be used for class assignment 
            title = value.split('-').pop();
            title = title.charAt(0).toUpperCase() + title.slice(1);
         }
        });
      }
      //var className = 'nav-link--' + title.split(' ').join('-').toLowerCase();
      var className = 'nav-link--' + classEnd;
      var link = $('<a href="#" class="nav-link tab ' + 'tab'+title + ' ' + className + '">' + title + '</a>').click(function(){
        if(persist) {
          // Use the function that tracks current tabs.
          setCurrentTab(container, index).trigger('tabSet');
        } else {
          // Otherwise just toggle tabs.
          toggleTab(container, index);
        }
      });
      item.append(link);
      item.appendTo(nav);
    });

    container.before(nav);
  }

  // Sets the current tab and tracks with a cookie.
  function setCurrentTab(t, i) {
    var nav = t.parent().find('ul.tabbed-navigation');
    var currentTab = $();
    t.find('.tabbed').each(function(index){
      var tabbed = $(this);
      $(this).removeClass('shown');
      if(index == i) {
        $(this).addClass('shown');
        currentTab = $(this);
        //Set the select tab index
        if(tabbed.hasClass('region')) {
          $.cookie('tabbed_navigation_active_index', index, { expires: 100, path: '/', domain: baseURL });
        }
      }
    });
    return currentTab;
  }

  // Toggles the current tab and hides all others.
  function toggleTab(t, i) {
    var nav = t.parent().find('ul.tabbed-navigation');
    nav.find('.nav-link').each(function(index){
      if(index == i) {
        $(this).toggleClass('active');
      } else {
        $(this).removeClass('active');
      }
    });
    t.find('.tabbed').each(function(index){
      if(index == i) {
        $(this).toggleClass('shown');
      } else {
        $(this).removeClass('shown');
      }
    });
  }

  function createFlyoutNav(t) {

    var page = $('#main-wrapper');

    //If the 'has-expanded-tabs' add a few classes otherwise, the tabs are collapsed
    if ($.cookie('tabbed_navigation_state') == 'has-expanded-tabs') {
      // Add flyout classes and collapse it by default.
      t.addClass('is-expanded');
      // Add flyout classes to the #page;
      page.addClass('has-expanded-tabs');
    }
    else {
      t.addClass('is-collapsed');
      page.addClass('has-collapsed-tabs');
    }

    // Add flyout classes and collapse it by default.
    t.addClass('flyout');
    // Move the element to #main-wrapper.
    //t.detach().appendTo(page);
    // Create close link.
    var closeLink = $('<a href="#" class="button-close">close</a>').click(function(){
      toggleFlyout(t);
      return false;
    });
    // Prepend the close link to the flyout.
    t.prepend(closeLink);

    // Add an event handler for when this tab is selected.
    t.find('.region').bind('tabSet', function(){
      var tab = $(this);
      // Removed explicit setting of height, because then content overruns if items are expanded within a tab
      // tab.find('.region-content').height(tab.height() - tab.find('.tab-title').outerHeight(true));
    });

    // Have tabs expand the flyout.
    t.find('.tabbed-navigation .nav-link').click(function(){
      if (($(this).parent().hasClass('active') && $.cookie('tabbed_navigation_state') == 'has-collapsed-tabs') || ($(this).parent().hasClass('active') && $.cookie('tabbed_navigation_state') == 'has-expanded-tabs')) {
        toggleFlyout(t);
      }
      else {
        $('.tabbed-navigation .nav-item').removeClass('active');
        $(this).parent().addClass('active');
        if ($.cookie('tabbed_navigation_state') == 'has-collapsed-tabs') {
          toggleFlyout(t);
        }
      }
      return false;
    });
  }

  function toggleFlyout(t) {
    var page = $('#main-wrapper');

    if ($.cookie('tabbed_navigation_state') == 'has-collapsed-tabs') {
      t.addClass('is-expanded').removeClass('is-collapsed');
      page.addClass('has-expanded-tabs').removeClass('has-collapsed-tabs');
      $.cookie('tabbed_navigation_state', 'has-expanded-tabs', { expires: 100, path: '/', domain: baseURL });
    }
    else {
      t.removeClass('is-expanded').addClass('is-collapsed');
      page.removeClass('has-expanded-tabs').addClass('has-collapsed-tabs');
      $.cookie('tabbed_navigation_state', 'has-collapsed-tabs', { expires: 100, path: '/', domain: baseURL });
    }
  }

  function createFlyoutComments(t) {
    // Hide comment bodies.
    t.find('.comment-content').hide();

    // Create the markup for the containers.
    var commentContainer = $('<div id="comment-container" class="is-collapsed"></div>');
    var commentBack = $('<a id="comment-back" href="">Back</a>');
    var commentTitle = $('<h3 id="comment-title"></h3>');
    var commentBody = $('<div id="comment-content"></div>');

    // Add the markup to the page.
    commentContainer.prepend(commentBody);
    commentContainer.prepend(commentTitle);
    commentContainer.prepend(commentBack);
    commentContainer.prependTo($('.region-tab-feedback .region-content'));

    // Add click functionality to comment headings.
    t.find('.comment-title').click(function(){
      // Empty the title and body.
      commentTitle.empty();
      commentBody.empty();

      // Add the title and body from the existing comment.
      $(this).contents().clone().prependTo(commentTitle);
      $(this).siblings('.comment-content').contents().clone().prependTo(commentBody);

      // Expand the container.
      commentContainer.toggleClass('is-collapsed is-expanded')

      return false;
    });

    // Add back button functionality.
    commentBack.click(function(){
      // Collapse the container.
      commentContainer.toggleClass('is-collapsed is-expanded')

      return false;
    });
  }
})(jQuery); //$
