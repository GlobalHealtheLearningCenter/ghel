<?php
/**
 * @file
 * Display Suite Article template.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 *
 * Regions:
 *
 * - $header: Rendered content for the "Header" region.
 * - $header_classes: String of classes that can be used to style the "Header" region.
 *
 * - $figure: Rendered content for the "Figure" region.
 * - $figure_classes: String of classes that can be used to style the "Figure" region.
 *
 * - $section: Rendered content for the "Content" region.
 * - $section_classes: String of classes that can be used to style the "Content" region.
 *
 * - $aside: Rendered content for the "Content" region.
 * - $aside_classes: String of classes that can be used to style the "Content" region.
 *
 * - $footer: Rendered content for the "Footer " region.
 * - $footer_classes: String of classes that can be used to style the "Footer " region.
 */
?>
<article class="<?php print $classes; ?>">

  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($header && $hgroup): ?>
    <header class="ds-header<?php print $header_classes; ?>">
      <hgroup class="ds-hgroup<?php print $hgroup_classes; ?>">
        <?php print $hgroup; ?>
      </hgroup>
      <?php print $header; ?>
    </header>
  <?php elseif ($header): ?>
    <header class="ds-header<?php print $header_classes; ?>">
      <?php print $header; ?>
    </header>
  <?php elseif ($hgroup): ?>
    <hgroup class="ds-hgroup<?php print $hgroup_classes; ?>">
      <?php print $hgroup; ?>
    </hgroup>
  <?php endif; ?>

  <?php if ($main_content): ?>
    <div class="ds-content<?php print $main_content_classes; ?>">
      <?php print $main_content; ?>

      
      <?php if ($highlight_1 || $highlight_2): ?>
        <aside class="highlights">
          <?php if ($highlight_1) { print $highlight_1; } ?>
          <?php if ($highlight_2) { print $highlight_2; } ?>
        </aside>
      <?php endif; ?>

    </div>
  <?php endif; ?>

  <?php if ($figure): ?>
    <figure class="ds-figure<?php print $figure_classes; ?>">
      <?php print $figure; ?>
    </figure>
  <?php endif; ?>

  <?php if ($aside): ?>
    <aside class="ds-aside<?php print $aside_classes; ?>">
      <?php print $aside; ?>
    </aside>
  <?php endif; ?>

  <?php if ($footer): ?>
    <footer class="ds-footer<?php print $footer_classes; ?>">
      <?php print $footer; ?>
    </footer>
  <?php endif; ?>

</article>
