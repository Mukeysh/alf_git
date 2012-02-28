<?php
class biblio_handler_sort_biblio_title extends views_handler_sort {
  function query() {
     $sort_title =" CASE
                    WHEN SUBSTR(node.title,1,1)='\"'   THEN LOWER(SUBSTR(node.title,2))
                    WHEN SUBSTR(node.title,1,1)='\''   THEN LOWER(SUBSTR(node.title,2))
                    WHEN SUBSTR(node.title,1,2)='A '   THEN LOWER(SUBSTR(node.title,3))
                    WHEN SUBSTR(node.title,1,3)='An '  THEN LOWER(SUBSTR(node.title,4))
                    WHEN SUBSTR(node.title,1,4)='The ' THEN LOWER(SUBSTR(node.title,5))
                    ELSE LOWER(node.title)
                 END ";

    $this->query->add_orderby(NULL, $sort_title, 'ASC', 'clean_title');
  }
}