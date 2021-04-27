<?php

/**
 * Implements hook_preprocess_HOOK().
 */
function renovation_preprocess_paragraph(&$variables) {
  /* @var \Drupal\paragraphs\Entity\Paragraph */
  $paragraph = $variables['elements']['#paragraph'];
  $bundle = $paragraph->getType();

  // CTA Paragraph.
  if ($bundle == 'cta') {
    // Set button type to default or icon.
    if ($paragraph->get('field_icon')->isEmpty()) {
      $variables['has_icon'] = FALSE;
    }
    else {
      $variables['has_icon'] = TRUE;
    }
  }
  // CTAs paragraph.
  if ($bundle == 'cta') {
    $variables['button_action'] = TRUE;
  }

  // Card Paragraph.
  if ($bundle == 'accordion_panel') {
    $parent = $paragraph->getParentEntity();
    // Value used to associate accordion panel with its data-parent.
    $variables['parent_label'] = $parent->info->value;
  }
}
