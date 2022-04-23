<?php

/**
 * @file
 * Advanced theme settings.
 */

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function em_form_system_theme_settings_alter(&$form, FormStateInterface &$form_state, $form_id = NULL) {

  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  // Get default theme.
  $theme = Drupal::config('system.theme')->get('default');

  // Drupal module handler
  $module_handler = \Drupal::service('module_handler');


  // Create vertical tabs for all TheMAG related settings.
  $form['pd'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => -10,
  );


  // ========================
  // Logo Image
  // ========================

  $form['logo_image'] = array(
    '#type' => 'details',
    '#title' => t('Branding'),
    '#description' => t('The theme uses different logo versions depending on the page style. For best visual experience please provide both light and dark version of your logo.'),
    '#group' => 'pd',
  );

  $form['logo_image']['pd_logo_light'] = array(
    '#type' => 'textfield',
    '#title'  => t('Path to light logo version'),
    '#description' => t('Examples: logo-light.svg, themes/'. $theme .'/logo-light.svg.'),
    '#default_value' => theme_get_setting('pd_logo_light'),
  );

  $form['logo_image']['pd_logo_dark'] = array(
    '#type' => 'textfield',
    '#title'  => t('Path to dark logo version'),
    '#description' => t('Examples: logo-dark.svg, themes/'. $theme .'/logo-dark.svg.'),
    '#default_value' => theme_get_setting('pd_logo_dark'),
  );


  // ========================
  // General
  // ========================

  $form['general'] = array(
    '#type' => 'details',
    '#title' => t('General'),
    '#group' => 'pd',
  );

  $form['general']['pd_scroll_to_top'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Scroll to Top Button'),
    '#description' => t('When a user scrolls past a certain point on the website,
        this helpful button appears, enabling users to easily return to the top of a page.'),
    '#default_value' => theme_get_setting('pd_scroll_to_top'),
  );

  $form['general']['pd_sticky_sidebars'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Sticky Sidebars'),
    '#default_value' => theme_get_setting('pd_sticky_sidebars'),
    '#description' => t('Sticky elements taller than the viewport can scroll
        independently up and down, meaning you don\'t have to worry about your content
        being cut off. This feature will be automatically disabled on all pages where
        the IPE editor (drag & drop page builder) is enabled.'),
  );


  // ========================
  // Social Media Pages
  // ========================

  $form['social_media_pages'] = array(
    '#type' => 'details',
    '#title' => t('Social media pages'),
    '#group' => 'pd',
  );

  $social_media_pages = array (
    'facebook' => 'Facebook',
    'twitter' => 'Twitter',
    'google-plus' => 'Google+',
    'youtube' => 'YouTube',
    'instagram' => 'Instagram',
    'pinterest' => 'Pinterest',
    'tumblr' => 'Tumblr',
    'linked-in' => 'LinkedIn',
    'mail' => 'Mail',
  );

  foreach ($social_media_pages as $sm_page => $sm_name) {

    $form['social_media_pages']['pd_' . $sm_page] = array (
      '#type' => 'url',
      '#title'  => t($sm_name),
      '#description' => t('Your ' . $sm_name . ' profile.'),
      '#attributes' => array('placeholder' => 'http://'),
      '#default_value' => theme_get_setting('pd_' . $sm_page),
    );
	//Baher
	if ( $sm_page == 'mail'){
		$form['social_media_pages']['pd_' . $sm_page]['#type']="email";
	}
  }


  // ========================
  // Header
  // ========================

  $form['header'] = array(
    '#type' => 'details',
    '#title' => t('Header'),
    '#group' => 'pd',
  );

  $form['header']['options'] = array(
    '#type' => 'details',
    '#title' => t('Options'),
    '#open' => TRUE,
  );

  $form['header']['options']['pd_sticky_header'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Sticky Header'),
    '#description' => t('The sticky header can help to make it easier
        for visitors to navigate through a site as they can quickly access
        the navigation menu rather than having to scroll back to the top of
        the page.'),
    '#default_value' => theme_get_setting('pd_sticky_header'),
  );

  $form['header']['action_menu'] = array(
    '#type' => 'details',
    '#title' => t('Action Menu'),
    '#open' => TRUE,
  );

  // Toggle Cart Button.
  $form['header']['action_menu']['pd_show_cart_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Cart Button'),
    '#description' => t('Show the Shopping Cart button in the header.'),
    '#default_value' => theme_get_setting('pd_show_cart_button'),
  );
  // Disable "Show Cart Button" option if Commerce Cart module is not installed.
  if(!$module_handler->moduleExists('commerce_cart')) {
    $form['header']['action_menu']['pd_show_cart_button']['#disabled'] = 'disabled';
  }

  // Toggle Search Button.
  $form['header']['action_menu']['pd_show_search_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Search Button'),
    '#description' => t('Show the search button in the header.'),
    '#default_value' => theme_get_setting('pd_show_search_button'),
  );
  // Disable "Show search button" option if Search module is not installed.
  if(!$module_handler->moduleExists('search')) {
    $form['header']['action_menu']['pd_show_search_button']['#disabled'] = 'disabled';
  }

  // Toggle Hamburger Menu.
  $form['header']['action_menu']['pd_show_hamburger_menu'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the Hamburger Menu on a Large Devices'),
    '#description' => t('This option will allow you to use Off-Canvas
          navigation on the large devices. Otherwise, it will only be
          available on small devices. '),
    '#default_value' => theme_get_setting('pd_show_hamburger_menu'),
  );



  // ========================
  // Search Form
  // ========================

  $form['search'] = array(
    '#type' => 'details',
    '#title' => t('Search form'),
    '#group' => 'pd',
  );

  $form['search']['pd_search_button_text'] = array(
    '#type' => 'textfield',
    '#title'  => t('Search button text'),
    '#default_value' => theme_get_setting('pd_search_button_text'),
  );

  $form['search']['pd_search_field_placeholder_text'] = array(
    '#type' => 'textfield',
    '#title'  => t('Search field placeholder text'),
    '#default_value' => theme_get_setting('pd_search_field_placeholder_text'),
  );


  // ========================
  // Content
  // ========================

  $form['teaser'] = array(
    '#type' => 'details',
    '#title' => t('Teaser'),
    '#group' => 'pd',
  );

  $form['teaser']['pd_teaser_show_author_info'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show author info'),
    '#description' => '',
    '#default_value' => theme_get_setting('pd_teaser_show_author_info'),
  );

  $form['teaser']['pd_teaser_show_post_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show post date'),
    '#description' => '',
    '#default_value' => theme_get_setting('pd_teaser_show_post_date'),
  );

  // Date formats
  $date_format = \Drupal::entityTypeManager()->getStorage('date_format')
    ->loadMultiple();
  $date_format_options = array();
  foreach ($date_format as $format) {
    $date_format_options[$format->id()] = date($format->getPattern(), time());
  }

  $form['teaser']['pd_teaser_date_format'] = array(
    '#type' => 'select',
    '#title' => t('Date format'),
    '#options' => $date_format_options,
    '#default_value' => theme_get_setting('pd_teaser_date_format'),
    '#description' => t('To create a custome date format go to <a href="' . base_path() . 'admin/config/regional/date-time">Date and time formats</a> page.'),
  );


  // ========================
  // Mailchimp Signup Block
  // ========================

  $form['mailchimp'] = array(
    '#type' => 'details',
    '#title' => t('Mailchimp Signup block'),
    '#group' => 'pd',
  );

  $form['mailchimp']['pd_mailchimp_signup_headline'] = array(
    '#type' => 'textfield',
    '#title' => t('Signup Headline'),
    '#default_value' => theme_get_setting('pd_mailchimp_signup_headline'),
    '#disabled' => (\Drupal::service('module_handler')->moduleExists('mailchimp') ? '' : 'disabled'),
  );

  $form['mailchimp']['pd_mailchimp_signup_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Signup Text/Description'),
    '#default_value' => theme_get_setting('pd_mailchimp_signup_text'),
    '#disabled' => (\Drupal::service('module_handler')->moduleExists('mailchimp') ? '' : 'disabled'),
  );

  // ========================
  // Advanced.
  // ========================

  $form['advanced'] = array(
    '#type' => 'details',
    '#title' => t('Advanced'),
    '#group' => 'pd',
  );

  // Additional CSS.
  $form['advanced']['additional_css'] = array(
    '#type' => 'details',
    '#title' => t('Additional CSS Style'),
    '#weight' => 10,
    '#open' => TRUE,
  );

  $form['advanced']['additional_css']['pd_additional_css'] = array(
    '#type' => 'textarea',
    '#title' => t('Additional CSS'),
    '#default_value' => theme_get_setting('pd_additional_css'),
    '#description' => t('Use this field to make small theme tweaks,
      or to add some custom CSS styles. If you plan to make more significant
      style changes please use "<strong>' . drupal_get_path('theme', $theme) . '/assets/css/custom.css</strong>".
      The style from this field will override custom.css styles. Use the code with &lt;style&gt; tag included.'),
  );

  $form['advanced']['additional_css']['pd_custom_css_file'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable custom.css'),
    '#description' => t('You can override existing styles by writing extra CSS in the "' . drupal_get_path('theme', $theme) . '/assets/css/custom.css" file.'),
    '#default_value' => theme_get_setting('pd_custom_css_file'),
  );

  // Additional JavaScript Code.
  $form['advanced']['js'] = array(
    '#type' => 'details',
    '#title' => t('Java Script'),
    '#weight' => 10,
    '#open' => TRUE,
  );

  $form['advanced']['js']['pd_additional_head_javascript'] = array(
    '#type' => 'textarea',
    '#title' => t('Additional JavaScript'),
    '#default_value' => theme_get_setting('pd_additional_head_javascript'),
    '#description' => t('The JavaScript from this field is placed inside &lt;head&gt tag of the page. Use the code with &lt;script&gt; tag included'),
  );

  $form['advanced']['js']['pd_additional_body_javascript'] = array(
    '#type' => 'textarea',
    '#title' => t('JavaScript Tracking/SDK code snipets'),
    '#default_value' => theme_get_setting('pd_additional_body_javascript'),
    '#description' => t('The content of this field is inserted directly after the opening &lt;body&gt; tag on each page. Use this field to add JavaScript tracking code snippets or JavaScript SDK code snippets (example: Facebook SDK for JavaScript). Use the code with &lt;script&gt; tag included.
'),
  );
}
