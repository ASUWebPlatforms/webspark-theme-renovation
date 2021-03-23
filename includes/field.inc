<?php
/**
 * @file
 * Theme and preprocess functions for fields.
 */
/**
 * Implements hook_preprocess_HOOK().
 */
function renovation_preprocess_field(&$variables) {

  $field_name = $variables['element']['#field_name'];

  // Background color.
  if ($field_name == 'field_background_color') {
    $variables['background_class'] = $variables['element']['#items']->value;
  }

  // Field CTA on banner.
  if ($field_name == 'field_cta') {
    $block_content = $variables['element']['#object'];
    $variables['bg_color'] = $block_content->get('field_background_color')->value;
  }



}
