<?php


/**
 * Implements hook_template_preprocess_default_variables_alter
 */
function em_preprocess(&$variables, $hook) {


  // Check if the modules required by the theme are enabled.
  $moduleHandler = \Drupal::service('module_handler');

  $variables['pd']['modules'] = array(
    'search' => false,
    'twig_tweak' => false,
    'twig_field_value' => false,
    'masonry' => false,
    'commerce_cart' => false,
  );

  foreach ($variables['pd']['modules'] as $module => $val) {
    if ($moduleHandler->moduleExists($module)) {
      $variables['pd']['modules'][$module] = true;
    }
  }

  // Drupal Base Paht
  if(isset($variables['base_path'])) {
    $variables['pd']['base_path'] = $variables['base_path'];
  }

  // Branding - Logo.
  $variables['pd']['logo']['light'] = theme_get_setting('pd_logo_light');
  $variables['pd']['logo']['dark'] = theme_get_setting('pd_logo_dark');


  // Header
  $variables['pd']['header']['sticky_header'] = theme_get_setting('pd_sticky_header');
  $variables['pd']['header']['show_cart_button'] = theme_get_setting('pd_show_cart_button');
  $variables['pd']['header']['show_search_button'] = theme_get_setting('pd_show_search_button');
  $variables['pd']['header']['show_hamburger_menu'] = theme_get_setting('pd_show_hamburger_menu');



  // Social media pages.
  $social_media_pages = array (
    'facebook' => array(
      'name' => 'Facebook',
      'fa_icon' => 'fab fa-facebook-f',
    ),
    'twitter' => array(
      'name' => 'Twitter',
      'fa_icon' => 'fab fa-twitter',
    ),
    'google-plus' => array(
      'namae' => 'Google+',
      'fa_icon' => 'fab fa-google-plus-g',
    ),
    'youtube' => array(
      'name' => 'YouTube',
      'fa_icon' => 'fab fa-youtube',
    ),
    'instagram' => array(
      'name' => 'Instagram',
      'fa_icon' => 'fab fa-instagram',
    ),
    'pinterest' => array(
      'name' => 'Pinterest',
      'fa_icon' => 'fab fa-pinterest-p',
    ),
    'tumblr' => array(
      'name' => 'Tumblr',
      'fa_icon' => 'fab fa-tumblr'
    ),
    'linked-in' => array(
      'name' => 'LinkedIn',
      'fa_icon' => 'fab fa-linkedin-in'
    ),
    'mail' => array(
      'name' => 'Mail',
      'fa_icon' => 'fa fa-envelope-o'
    ),
  );

  foreach ($social_media_pages as $page_key => $page) {
    $social_media_page_url = theme_get_setting('pd_' . $page_key);

    if(isset($social_media_page_url) && $social_media_page_url != "") {
      $variables['pd']['social_media_pages'][$page_key]['url'] = theme_get_setting('pd_' . $page_key);
      $variables['pd']['social_media_pages'][$page_key]['title'] = theme_get_setting('pd_' . $page_key . '_link_title');
      $variables['pd']['social_media_pages'][$page_key]['icon'] = '<i class="'. $page['fa_icon'] .'"></i>';
    }
  }

  // ========================
  // Hook Block
  // ========================

  // MailChimp signup block
  //
  if($hook == 'block') {
    if ($moduleHandler->moduleExists('mailchimp')) {
      $variables['pd']['mailchimp']['signup_headline'] = theme_get_setting('pd_mailchimp_signup_headline');
      $variables['pd']['mailchimp']['signup_text'] = theme_get_setting('pd_mailchimp_signup_text');
    }
  }

  // -----------------
  // Hook Node
  // -----------------

  // Teaser
  if($hook == 'node') {
    $variables['pd']['teaser']['uppercase_title'] = theme_get_setting('pd_teaser_uppercase_title');
    $variables['pd']['teaser']['show_post_date'] = theme_get_setting('pd_teaser_show_post_date');
    $variables['pd']['teaser']['show_author_info'] = theme_get_setting('pd_teaser_show_author_info');
  }

  // -----------------
  // Hook Page
  // -----------------

  if($hook == 'page') {
    // Put Commerce Cart block in variable
    if(\Drupal::service('module_handler')->moduleExists('commerce_cart')) {
      $commerce_cart_block = \Drupal::service('plugin.manager.block')
        ->createInstance('commerce_cart', []);
      $variables['pd']['block']['commerce_cart'] = $commerce_cart_block->build();
    }

    // Put Search block in variable
    if(\Drupal::service('module_handler')->moduleExists('search')) {
      $search_block = \Drupal::service('plugin.manager.block')
        ->createInstance('search_form_block', []);
      $variables['pd']['block']['search'] = $search_block->build();
    }
  }


  // -----------------
  // Hook HTML
  // -----------------

  // Additional JavaScripts and CSS.
  // Variables accessible only in html.html.twig.
  if($hook == 'html') {
    $variables['pd']['additional_css'] = theme_get_setting('pd_additional_css');
    $variables['pd']['additional_head_javascript'] = theme_get_setting('pd_additional_head_javascript');
    $variables['pd']['additional_body_javascript'] = theme_get_setting('pd_additional_body_javascript');
  }
}
