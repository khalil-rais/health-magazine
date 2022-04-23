<?php

/**
 * Implements hook_page_attachments_alter().
 */
function em_page_attachments_alter(array &$variables) {

  $variables['#attached']['drupalSettings']['em'] = array();

  /**
   * Custom meta tag which represents the theme version.
   * This is useful for the theme's author in order to provide
   * an appropriate support.
   */
  $base_themes = \Drupal::service('theme.manager')->getActiveTheme()->getBaseThemes();
  if(isset($base_themes['em']->getExtension()->info['version'])) {
    $em_theme_version = $base_themes['em']->getExtension()->info['version'];
  } else {
    $theme_version = 'Unknown';
  }
  $theme_info = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'theme-info',
      'content' => 'EM v.' . $em_theme_version . '',
    ),
  );
  $variables['#attached']['html_head'][] = [$theme_info, 'theme-info'];

  /*
   * Attach Sticky Header library
   */
  if(theme_get_setting('pd_sticky_header')) {
    $variables['#attached']['library'][] = 'em/sticky-header';
  }

  /*
   * Attach Scroll to Top library
   */
  if(theme_get_setting('pd_scroll_to_top')) {
    $variables['#attached']['library'][] = 'em/scroll-to-top-button';
  }

  /*
   * Attach Sticky-Kit library
   */
  if(theme_get_setting('pd_sticky_sidebars')) {
    $variables['#attached']['library'][] = 'em/sticky-sidebars';
  }

  /*
   * Make some variables available in drupalSettings
   */
  $variables['#attached']['drupalSettings']['em']['header']['stickyHeader']
    = theme_get_setting('pd_sticky_header');

}
