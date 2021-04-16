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

  // Card arrangements.
  if ($block_id == 'card_arrangement') {
    $variables['cards'] = [];
    $block_content = $variables['content']['#block_content'];
    if ($block_content) {
      if ($variables['content']['#block_content']->hasField('field_cards') && !$variables['content']['#block_content']->get('field_cards')
          ->isEmpty()) {
        $cards = $variables['content']['#block_content']->field_cards->referencedEntities();
        foreach ($cards as $card) {
          $cards_content[] = [
            'media' => getCardImage($card),
            'heading' => $card->get('field_heading')->value,
            'body' => strip_tags($card->get('field_body')->value),
            'location' => getCardLocation($card),
            'ctas' => getCardCta($card),
            'links' => getCardLinks($card),
            'tags' => getCardTags($card),
          ];
        }
        $variables['cards'] = $cards_content;
      }
    }
  }
}

/**
 * The event location.
 *
 * @param \Drupal\paragraphs\Entity\Paragraph $card
 *   A card paragraph.
 *
 * @return bool
 *   The location.
 */
function getCardLocation(Paragraph $card) {
  $location = FALSE;
  if ($card->hasField('field_card_location') && !$card->get('field_card_location')
      ->isEmpty()) {
    $location_term = $card->field_card_location->referencedEntities()[0];
    $location = $location_term->getName();
  }

  return $location;
}

/**
 * Get tags from card.
 *
 * @param \Drupal\paragraphs\Entity\Paragraph $card
 *   A card paragraph.
 *
 * @return array
 *   An array of tag values.
 */
function getCardTags(Paragraph $card) {
  $tags = [];
  if ($card->hasField('field_tags') && !$card->get('field_tags')->isEmpty()) {
    $items = $card->field_tags->referencedEntities();
    if ($items) {
      $aliasManager = \Drupal::service('path_alias.manager');
      foreach ($items as $item) {
        $tags[] = [
          'url' => $aliasManager->getAliasByPath('/taxonomy/term/' . $item->id()),
          'name' => $item->getName(),
        ];
      }
    }
  }
  return $tags;
}

/**
 * Get links from card.
 *
 * @param \Drupal\paragraphs\Entity\Paragraph $card
 *   A Paragraph containing links.
 *
 * @return array
 *   An array of link values.
 */
function getCardLinks(Paragraph $card) {
  $links = [];
  if ($card->hasField('field_link') && !$card->get('field_link')->isEmpty()) {
    $items = $card->get('field_link')->getValue();
    foreach ($items as $item) {
      $links[] = $item;
    }
  }
  return $links;
}

/**
 * Get Card CTAs
 *
 * @param \Drupal\paragraphs\Entity\Paragraph $card
 *   A Paragraph containing ctas.
 *
 * @return array
 *   An array of CTA button values.
 */
function getCardCta(Paragraph $card) {
  $ctas = [];
  if ($card->hasField('field_cta') && !$card->get('field_cta')->isEmpty()) {
    $items = $card->get('field_cta')->referencedEntities();
    $ctas = [];
    foreach ($items as $item) {
      if ($item->hasField('field_cta_link') && !$item->get('field_cta_link')
          ->isEmpty()) {
        $cta_links = $item->get('field_cta_link')->getValue();
        foreach ($cta_links as $cta_link) {
          $ctas[] = $cta_link;
        }
      }
    }
  }
  return $ctas;
}


function getCardImage(Paragraph $card) {

  if ($card->hasField('field_media') && !$card->get('field_media')->isEmpty()) {

    $card_image = [];

    // Load the file.
    /** @var \Drupal\media\Entity\Media $file */
    $media = $card->field_media->entity;
    /** @var \Drupal\file\Entity\File $file */
    $file = $media->field_media_image->entity;

    $variables = [
      'responsive_image_style_id' => 'cards',
      'uri' => $file->getFileUri(),
    ];

    if ($file) {
      // Validate the file with image factory service.
      $image = \Drupal::service('image.factory')->get($file->getFileUri());

      if ($image->isValid()) {
        $variables['width'] = $image->getWidth();
        $variables['height'] = $image->getHeight();
      }
      else {
        $variables['width'] = $variables['height'] = NULL;
      }
      // Build render array.
      $card_image = [
        '#theme' => 'responsive_image',
        '#width' => $variables['width'],
        '#height' => $variables['height'],
        '#responsive_image_style_id' => $variables['responsive_image_style_id'],
        '#uri' => $variables['uri'],
      ];
      // Ensure image changes when updated.
      $renderer = \Drupal::service('renderer');
      $renderer->addCacheableDependency($card_image, $file);
    }
  }

  // Return the render array as block content.
  return $card_image;
}
