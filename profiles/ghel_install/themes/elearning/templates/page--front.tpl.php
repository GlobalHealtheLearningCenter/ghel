<div id="page" class="<?php print $classes; ?>">

  <div id="header">
    <div class="page-width">
      <hgroup id="branding">
        <h1><?php print $site_name; ?>
          <?php if ($logo): ?>
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
          <?php else: ?>
            <a href="<?php print $base_path; ?>"><?php print $site_name; ?></a>
          <?php endif; ?>
          <?php if ($site_name): ?>
            <a href="<?php print $front_page; ?>" rel="home" id="site-name">
             <?php print $site_name; ?>
            </a>
          <?php endif; ?>
        </h1>
        <?php if ($page['util_nav']) { ?>
          <div id="util_nav" class="clearfix">
            <?php print render($page['util_nav']); ?>
          </div>
        <?php } // end navigation?>

        <?php if ($site_slogan): ?>
          <h2 id="site-slogan">
           <?php print $site_slogan; ?>
          </h2>
        <?php endif; ?>
      </hgroup>
      <?php if ($page['utility']) { ?>
        <div id="utility">
          <div class="container">
            <?php print render($page['utility']); ?>
          </div>
        </div>
      <?php } // end utility ?>
      <?php if ($page['header']) { ?>
          <?php print render($page['header']); ?>
      <?php } // end header ?>
    </div>
  </div>
  <?php if ($page['navigation']) { ?>
    <div id="navigation" class="clearfix"><div class="page-width">
      <?php print render($page['navigation']); ?>
    </div></div>
  <?php } // end navigation?>
<!-- ******************************** END HEADER  / START TITLE  *********************************** -->


      <?php if (!$is_front && strlen($title) > 0) { ?>
        <div class="title-header">
          <div class="page-width">
              <h1 <?php print $title_attributes; ?>><?php print $title; ?></h1>
              <div class="arrow-shaddow"></div>
              <div class="arrow-up"></div>
          </div>
        </div>
      <?php } ?>

<!-- ******************************** END TITLE  /   *********************************** -->




  <?php if ($page['above_content']) { ?>
    <div id="above-content">
      <div class="page-width">
        <?php print render($page['above_content']); ?>
      </div>
    </div>
  <?php } // end Above Content ?>

  <div id="main">
    <div class="page-width">

      <?php if ($messages) { ?>
        <div id="messages">
            <?php print $messages; ?>
        </div>
      <?php } // end messages ?>

      <div id="main-content" class="clearfix">
        <?php if (render($tabs)) { ?>
          <div id="tabs">
            <?php print render($tabs); ?>
          </div>
        <?php } // end tabs ?>
        
        <div id="content">


          <?php if ($page['highlighted']) { ?>
            <div id="highlighted">
              <div class="container">
                <?php print render($page['highlighted']); ?>
              </div>
            </div>
          <?php } // end highlighted ?>



          <?php if ($page['help']) { ?>
            <div id="help">
              <?php print render($page['help']); ?>
            </div>
          <?php } // end help ?>

          <?php print render($page['content']); ?>

          <?php if ($page['#has_tabbed_regions']) { ?>
            <div id="tabbed-regions">
              <?php print render($page['tabbed_regions']); ?>
            </div>
          <?php } // end tabbed regions ?>
        </div>

        <?php if ($page['sidebar_first']) { ?>
          <div id="sidebar-first" class="aside">
            <?php print render($page['sidebar_first']); ?>
          </div>
        <?php } // end sidebar_first ?>

        <?php if ($page['sidebar_second']) { ?>
          <div id="sidebar-second" class="aside clearfix">
            <?php print render($page['sidebar_second']); ?>
          </div>
        <?php } // end sidebar_second ?>
        
      </div>

      <?php if ($page['course_blocks_dashboard']) { ?>
        <div id="course_blocks_dashboard">
          <div class="container">
            <h2>Your Progress</h2>
            <?php print render($page['course_blocks_dashboard']); ?>
          </div>
        </div>
      <?php } // end course_blocks_dashboard Content ?>

      <?php if ($page['author_blocks_dashboard']) { ?>
        <div id="author_blocks_dashboard">
          <div class="container">
            <h2>Author Tools</h2>
            <?php print render($page['author_blocks_dashboard']); ?>
          </div>
        </div>
      <?php } // end author_blocks_dashboard Content ?>

    </div>
  </div>
  <div id="below-main">
    <div class="page-width">
      <?php if ($page['below_content']) { ?>
        <div id="below-content">
          <div class="container">
            <?php print render($page['below_content']); ?>
          </div>
        </div>
      <?php } // end Below Content ?>

    </div>
  </div>


  <div id="footer">
    <div class="page-width">
      <?php print render($page['footer']); ?>
    </div>
  </div>

  <?php if ($page['admin_footer']) { ?>
    <div id="admin-footer">
      <div class="page-width">
        <?php print render($page['admin_footer']); ?>
      </div>
    </div>
  <?php } // end admin_footer ?>

</div>
