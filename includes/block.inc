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

  if ($variables['plugin_id'] == 'webspark_module_asu_breadcrumb') {
    // As we cannot pass a config var through the breadcrumb the only option is
    // to add the page title through the block to the array of links.
    $request = \Drupal::request();
    $route_match = \Drupal::routeMatch();
    $page_title = \Drupal::service('title_resolver')->getTitle($request, $route_match->getRouteObject());

    $variables['content']['#links'][] = Link::fromTextAndUrl($page_title, Url::fromRoute('<nolink>'));
  }

}
