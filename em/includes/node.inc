<?php

/**
 * Implements template_preprocess_node
 */
function em_preprocess_node(&$variables) {

  $node = $variables['node'];
  $variables['attributes'] = new Drupal\Core\Template\Attribute($variables['attributes']);

  /*
   * Adding classes to the node attributes
   */
  $classes = array('node');
  $classes[] = 'node--type--'  . $node->bundle();
  $classes[] = 'node--view-mode--' . str_replace('_', '-', $variables['elements']['#view_mode']);
  if($node->isPromoted()) { $classes[] = 'promoted'; }
  if($node->isSticky()) { $classes[] = 'sticky'; }
  if(!$node->isPublished()) { $classes[] = 'unpublished'; }

  $variables['attributes']->addClass($classes);


  /*
   * Use theme settings to set Teaser date format.
   */
  $teaser_date_format = theme_get_setting('pd_teaser_date_format');
  $variables['date'] = \Drupal::service('date.formatter')
    ->format($variables['node']->getCreatedTime(), $teaser_date_format);


  /*
   * We're create node variable with paragraph's bundle name that are used in the node.
   * This will allow us to show what type of content which contains the certain article.
   * e.g. If the article contains video paragraph, a video icon will appear on the article teaser.
   */
   if($node->hasField('field_answer')) {
		$variables['questionblock'] = views_embed_view('em_popular_content', 'block_4');
		/*ob_start();
		var_dump($variables['questionblock']);
		$dumpy = ob_get_clean();				
		\Drupal::logger('eye')->notice('questionblock: '.$dumpy);*/
   }
  if($node->hasField('field_paragraphs')) {
    $paragraph = $node->field_paragraphs->getValue();
    if(!empty($paragraph)) {

      $paragraph_bundles = array();
      $media_contained_html = '';

      foreach ( $paragraph as $element ) {
        $p = \Drupal\paragraphs\Entity\Paragraph::load( $element['target_id'] );
        $paragraph_bundle_name = $p->bundle();
        $paragraph_bundles[] = $paragraph_bundle_name;
      }

      if(in_array('video', $paragraph_bundles) || in_array('embed_video', $paragraph_bundles)) {
        $media_contained_html .= '<i class="fas fa-play"></i>';
      }
      if(in_array('gallery', $paragraph_bundles) || in_array('gallery_grid', $paragraph_bundles)) {
        $media_contained_html .= '<i class="far fa-images"></i>';
      }

      $variables['pd']['article']['paragraph_bundles'] = array_unique($paragraph_bundles);
      $variables['pd']['article']['media_contained']['html'] = $media_contained_html;
    }
  }
}
