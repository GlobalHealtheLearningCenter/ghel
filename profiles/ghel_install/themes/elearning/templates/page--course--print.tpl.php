<div id="page" class="<?php print $classes; ?>">
  <div id="header">
    <div class="page-width">
      <hgroup id="branding">
        <h1> Global Health eLearning Center</h1>
      </hgroup>
    </div>
  </div>

  <div id="main">
    <div class="page-width">

      <div id="main-content" class="clearfix">

        <div id="content">

          <?php if ($page['highlighted']) { ?>
            <div id="highlighted">
              <div class="container">
                <?php print render($page['highlighted']); ?>
              </div>
            </div>
          <?php } // end highlighted ?>

          <?php if (!$is_front && strlen($title) > 0) { ?>
            <h1 <?php print $title_attributes; ?>><?php print $title; ?></h1>
          <?php } ?>

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
          <div id="sidebar-second" class="aside">
            <?php print render($page['sidebar_second']); ?>
          </div>
        <?php } // end sidebar_second ?>
      </div>

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

</div>
