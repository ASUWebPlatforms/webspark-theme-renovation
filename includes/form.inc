<?php
/**
 * @file
 * Theme and preprocess functions for forms.
 */


function renovation_form_alter(&$form, &$form_state, $form_id) {

  // Add classes to cancel button on Layout Builder discard/revert changes.
  if ($form_id == 'layout_builder_discard_changes' || $form_id == 'layout_builder_revert_overrides') {
    $form['actions']['cancel']['#attributes']['class'][] = 'btn btn-dark';
  }

  if ($form_id == 'editor_media_dialog') {
    // Change selection caption on media edit form to true by default.
    $form['caption']['#default_value'] = TRUE;
  }
  // Add the class required for all the forms in front theme.
  $form['#attributes']['class'][] = 'uds-form';
}

/**
 * Implements hook_preprocess_HOOK().
 */
function renovation_preprocess_input__submit(&$variables) {

  // Adds class to submit buttons.
  $variables['attributes']['class'][] = 'btn-maroon';
}
