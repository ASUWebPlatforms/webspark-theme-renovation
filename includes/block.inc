<?php
/**
 * @file
 * Theme and preprocess functions for blocks.
 */

use Drupal\paragraphs\Entity\Paragraph;
use Drupal\file\Entity\File;

/**
 * Implements hook_preprocess_HOOK().
 */
function renovation_preprocess_block(&$variables) {

  $block_id = $variables['derivative_plugin_id'];

  if ($block_id == 'hero') {
    // Get the key of the selected value from the background color field.
    /** @var Drupal\block_content\ $block_content */
    $block_content = $variables['content']['#block_content'];
    $variables['heading_background_color'] = $block_content->field_hero_background_color->value;
  }

}
