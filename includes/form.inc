<?php
/**
 * @file
 * Theme and preprocess functions for forms.
 */


/**
 * Implements hook_preprocess_HOOK().
 */
function renovation_preprocess_input__submit(&$variables) {
  $variables['attributes']['class'][] = 'btn-maroon';
}


