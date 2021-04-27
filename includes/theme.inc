<?php

/**
 * @file
 * Custom theme hooks.
 */

/**
 * Implements hook_library_info_build().
 * Automatically creates components libraries (Not visible in theme's libraries.yml file)
 * This allows us to add js files/behaviours to components within the components own folder.
 * Note that the component should have the same name as the folder.
 *  {{ attach_library('renovation/block') }}.
 */
function renovation_library_info_build() {
  $extensions = ['css', 'js'];
  $theme_path = \Drupal::service('theme.manager')->getActiveTheme()->getPath();
  $directory = $theme_path . '/src/components';
  $extensions = array_map('preg_quote', $extensions);
  $extensions = implode('|', $extensions);
  if (!is_dir($directory)) {
    return [];
  }
  $file_scan = \Drupal::service('file_system')->scanDirectory($directory, "/{$extensions}$/");
  $libraries = [];
  foreach ($file_scan as $file) {
    $parts = explode('.', $file->filename);
    $extension = end($parts);
    switch ($extension) {
      case 'css':
        $libraries[$file->name][$extension] = [
          'component' => [
            '/' . $file->uri => [],
          ],
        ];
        break;

      case 'js':
        $libraries[$file->name][$extension] = [
          '/' . $file->uri => [],
        ];
        break;
    }
  }
  return $libraries;
}

/**
 * Preprocess variables for all templates.
 * @param $variables
 */
function renovation_preprocess(&$variables) {
  // Inject the current language into every template
  $language = \Drupal::languageManager()->getCurrentLanguage()->getId();
  $variables['language'] = $language;

  // Inject the base url into every template
  global $base_url;
  $variables['base_url'] = $base_url;
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function renovation_theme_suggestions_image_style_alter(array &$suggestions, array $variables) {
  $suggestions[] = $variables['theme_hook_original'] . '__' . $variables['style_name'];
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function renovation_theme_suggestions_image_alter(array &$suggestions, array $variables) {
  $suggestions[] = $variables['theme_hook_original'] . '__' . $variables['style_name'];
}
