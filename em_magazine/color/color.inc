<?php

/**
 * @file
 * Lists available colors and color schemes for the EM theme.
 */

$info = [
  // Available colors and color labels used in theme.
  'fields' => [
    'base' => t('Primary color'),
    'text' => t('Articles text color'),
    'link' => t('Articles link color'),
    'button_primary' => t('Button - Primary color'),
  ],
  // Pre-defined color schemes.
  'schemes' => [
    'default' => [
      'title' => t('EM Magazine (default)'),
      'colors' => [
        'base' => '#7b1fa2',
        'text' => '#263239',
        'link' => '#7b1fa3',
        'button_primary' => '#263238',
      ],
    ],
  ],

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => [
    'color/colors.css',
  ],

  // Preview files.
  'preview_html' => 'color/preview.html',

];
