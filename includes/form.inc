<?php
/**
 * @file
 * Theme and preprocess functions for forms.
 */


function renovation_form_alter(&$form, &$form_state, $form_id) {

  // Add classes to cancel button on Layout Builder discard changes.
  if ($form_id == 'layout_builder_discard_changes') {
    $form['actions']['cancel']['#attributes']['class'][] = 'btn btn-dark';
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function renovation_preprocess_input__submit(&$variables) {

  // Adds class to submit buttons.
  $variables['attributes']['class'][] = 'btn-maroon';
}


