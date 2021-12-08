<?php
/**
 * @file
 * Theme and preprocess functions for blocks.
 */

use Drupal\paragraphs\Entity\Paragraph;
use Drupal\file\Entity\File;
use Drupal\Core\Link;
use Drupal\Core\Url;

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

  $plugin_id = $variables['base_plugin_id'] ?? '';

  if ($plugin_id == 'inline_block') {
    $variables['block'] = $variables['content']['#block_content'];
  }

  // Preprocess tabs for tabbed content.
  if ($block_id == 'tabbed_content') {
    $block_content = $variables['content']['#block_content'];
    $paragraphs = $block_content->field_tab->referencedEntities();

    // Create an array of tabs.
    $tabs = [];
    foreach ($paragraphs as $paragraph) {
      $tabs[] = [
        'heading' => $paragraph->get('field_heading')->value,
        'copy' => $paragraph->get('field_body')->view(),
        'blocks' => $paragraph->get('field_blocks')->view(),
      ];
    }
    $variables['tabs'] = $tabs;
  }



}
