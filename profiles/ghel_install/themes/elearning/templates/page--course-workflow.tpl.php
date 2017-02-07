<div id="page" class="<?php print $classes; ?>">
    <div id="header">
        <div class="page-width">
            <hgroup id="branding">
                <h1>
                    <?php print $site_name; ?>
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
                <?php if ($page['util_nav']): ?>
                    <div id="util_nav" class="clearfix">
                        <?php print render($page['util_nav']); ?>
                    </div>
                <?php endif; ?>

                <?php if ($site_slogan): ?><h2 id="site-slogan"><?php print $site_slogan; ?></h2><?php endif; ?>
            </hgroup>
            <?php if ($page['utility']): ?>
                <div id="utility">
                    <div class="container"><?php print render($page['utility']); ?></div>
                </div>
            <?php endif; ?>
            <?php if ($page['header']): ?>
                <?php print render($page['header']); ?>
            <?php endif; ?>
        </div>
    </div>
    <?php if ($page['navigation']): ?>
        <div id="navigation" class="clearfix">
            <div class="page-width">
                <?php print render($page['navigation']); ?>
            </div>
        </div>
    <?php endif; ?>
    <div id="main-wrapper">
        <?php if (render($tabs)): ?>
            <div class="tabcontainer clearfix">
                <div id="tabs">
                    <?php print render($tabs); ?>
                </div>
            </div>
        <?php endif; ?>
        <?php if ($page['course_navigation']): ?>
            <div id="course-navigation">
                <?php print render($page['course_navigation']); ?>
            </div>
        <?php endif; ?>
        <div id="main">
            <?php if ($page['above_content']): ?>
                <div id="above-content">
                    <div class="page-width">
                        <?php print render($page['above_content']); ?>
                    </div>
                </div>
            <?php endif; ?>
            <?php if ($messages): ?>
                <div id="messages">
                    <?php print $messages; ?>
                </div>
            <?php endif; ?>
            <div id="main-content" class="clearfix">
                <div id="content">
                    <?php if ($page['highlighted']): ?>
                        <div id="highlighted">
                            <div class="container">
                                <?php print render($page['highlighted']); ?>
                            </div>
                        </div>
                    <?php endif; ?>

                    <?php if (!$is_front && strlen($title) > 0): ?>
                        <h1 class="page-title"><?php print $title; ?></h1>
                    <?php endif; ?>
                    <?php if ($page['help']): ?>
                        <div id="help">
                            <?php print render($page['help']); ?>
                        </div>
                    <?php endif; ?>
                    <?php print render($page['content']); ?>
                </div>
            </div>
            <?php if ($page['below_content_course_one']): ?>
                <div id="below-content">
                    <div class="container clearfix">
                        <?php print render($page['below_content_course_one']); ?>
                    </div>
                </div>
            <?php endif; ?>
            <?php if ($page['below_content_course_two']): ?>
                <div id="below-content">
                    <div class="container">
                        <?php print render($page['below_content_course_two']); ?>
                    </div>
                </div>
            <?php endif; ?>
        </div>
        <?php if ($page['#has_tabbed_regions']): ?>
            <div id="tabbed-regions">
                <?php print render($page['tabbed_regions']); ?>
            </div>
        <?php endif; ?>
    </div>
</div>

<div id="footer">
    <div class="page-width">
        <?php print render($page['footer']); ?>
    </div>
</div>

<?php if ($page['admin_footer']): ?>
    <div id="admin-footer">
        <div class="page-width">
            <?php print render($page['admin_footer']); ?>
        </div>
    </div>
<?php endif; ?>
