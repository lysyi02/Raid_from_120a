#ifndef RAID_FROM_120A_LIB_H
#define RAID_FROM_120A_LIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define ASCII_START 33
#define ASCII_END 127

/**
* @file lib.h
* @brief Preset function.
* @author КІТ-120а.
* @date 22-dec-2020
* @version 1.0
*/

int count_symbols(FILE *stream, int *frequency);

void output(int start, int fin, int *frequency, int text_length);

void symbols_freq(char command, int* frequency, int text_length);

float get_percent(int num, int text_length);

int most_common(int frequency[ASCII_END], int call, char *top_five_symbols);

int already_checked(int N, char *top_five_symbols);

void draw_histogram(char top_five_symbols[5], float percentage_of_occurrence[5], int histogram_width, int histogram_height, char filler);

float max_value_in_array(float *array, size_t array_size);

int calculate_indicator_width(int histogram_width);

void calculate_indents_between_indicators(int *indents_between_indicators, int indicator_width, int histogram_width);

int calculate_count_of_steps_for_output_weight(int height_weight_step, float weight_of_percent, float maximal_value_for_percent);

#endif //RAID_FROM_120A_LIB_H
