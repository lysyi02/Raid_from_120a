#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* @file lib.h
* @brief Preset function.
* @author КІТ-120а.
* @date 22-dec-2020
* @version 1.0
*/

#ifndef RAID_FROM_120A_LIB_H
#define RAID_FROM_120A_LIB_H

void
draw_histogram(char top_fife_symbols[5], float percentage_of_occurrence[5], int histogram_width, int histogram_height,
               char filler);

float max_value_in_array(float *array, size_t array_size);

int calculate_indicator_width(int histogram_width);

void calculate_indents_between_indicators(int *indents_between_indicators, int indicator_width, int histogram_width);

int calculate_count_of_steps_for_output_weight(int height_weight_step, float weight_of_percent,
                                               float maximal_value_for_percent);

int five_max(int *arr, int A);

#endif //RAID_FROM_120A_LIB_H
