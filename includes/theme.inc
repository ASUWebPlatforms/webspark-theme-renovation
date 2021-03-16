<?php

/**
 * @file
 * Custom theme hooks.
 */

/**
 * Implements hook_library_info_build().
 * Automatically creates components libraries (Not visible in theme's libraries.yml file)
 * You can directly use the component name as a library, f.x
 *  {{ attach_library('SUBTHEME_MACHINE_NAME/block') }}.
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

  global $base_url;
  $variables['base_url'] = $base_url;
}
