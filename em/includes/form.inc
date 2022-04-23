<?php

/**
 * @file
 * form.inc
 */

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_FORM_ID_alter.
 */
function em_form_search_block_form_alter(&$form, FormStateInterface $form_state, $form_id) {
  $form['keys']['#attributes']['placeholder'] = t(theme_get_setting('pd_search_field_placeholder_text'));
  $form['actions']['submit']['#value'] = t(theme_get_setting('pd_search_button_text'));
}


/**
 * Altering comment form.
 *
 * Implements hook_form_alter().
 */
function em_form_comment_form_alter(&$form, FormStateInterface $form_state, $form_id) {
  $form['actions']['preview']['#access'] = FALSE;
}