<?php

/**
 * Implements template_preprocess_tb_megamenu_row
 */
function em_preprocess_tb_megamenu_row(&$variables) {
  $variables['attributes']->removeClass('row-fluid')->addClass('row');
}

/**
 * Implements template_preprocess_tb_megamenu_column
 */
function em_preprocess_tb_megamenu_column(&$variables) {
  $col_config = $variables['col_config'];
  $variables['attributes']
    ->removeClass('span' . $col_config['width'])
    ->addClass('col-' . $col_config['width']);
}
