<?php


/**
 * Implements hook_theme_suggestions_MEDIA_alter().
 */
function em_theme_suggestions_media_alter(array &$suggestions, array $variables) {

  $media = $variables['elements']['#media'];
  $media_bundle = $media->bundle();
  $media_view_mode = $variables['elements']['#view_mode'];

  // Ensures Thunder media compatibility
  if (Drupal::installProfile() == 'thunder') {
    if($media_bundle == 'video') {
      // Unset "media__video" suggestion and set "media__embed_video" instead.
      unset($suggestions[array_search('media__video', $suggestions)]);
      unset($suggestions[array_search('media__video__default', $suggestions)]);
      array_splice($suggestions, 1, 0, 'media__embed_video');
      array_splice($suggestions, 2, 0, 'media__embed_video__' .$media_view_mode);
    }
  }
}
