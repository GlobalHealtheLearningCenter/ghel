<div>
<?php
  if (!empty($links)) {
    print '<ul class="certificates article-list">';
    foreach ($links as $link) {
      print '<li class="article-item is-bulleted">';
      print $link;
      print '</li>';
    }
    print '</ul>';
  }
?>
</div>
