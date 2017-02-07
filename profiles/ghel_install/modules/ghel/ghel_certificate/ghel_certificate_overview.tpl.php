<div>
<?php
  if (!empty($links)) {
    print '<ul class="certificates">';
    foreach ($links as $link) {
      print '<li>';
      print $link;
      print '</li>';
    }
    print '</ul>';
  }
?>
</div>
