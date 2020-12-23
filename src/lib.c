#include "lib.h"

/**
* @file lib.c
* @brief Function implementation for file main.c.
* @author КІТ-120а.
* @date 22-dec-2020
* @version 1.0
*/

/**
 * @param  - ;
 * @param  - ;
 * @param  - ;
 * @param  - ;
 * @param  - ;
 * @param  - ;
 */

/**
Функція makeGist: .

*/
void
draw_histogram(char top_fife_symbols[5], float percentage_of_occurrence[5], int histogram_width, int histogram_height,
               char filler) {
        const int minimal_width = 12;

        float maximal_value_for_percent = roundf(max_value_in_array(percentage_of_occurrence, 5) + 10);
        if (maximal_value_for_percent > 100) maximal_value_for_percent = 100.0f;
        float weight_of_percent = maximal_value_for_percent / (histogram_height - 1);

        int right_indent = 1;
        int left_indent = right_indent;
        int *indents_between_indicators = (int *) calloc(5, sizeof(int));

        if (histogram_width >= minimal_width) {

                int indicator_width = calculate_indicator_width(histogram_width);
                calculate_indents_between_indicators(indents_between_indicators, indicator_width, histogram_width);
                printf("    ^\n");

                int height_weight_step = 10;
                int count_of_steps_for_output_weight = calculate_count_of_steps_for_output_weight(height_weight_step,
                                                                                                  weight_of_percent,
                                                                                                  maximal_value_for_percent);
                int step = count_of_steps_for_output_weight;

                float value_for_percent = maximal_value_for_percent;
                int indent_index = 0;

                for (int height_index = histogram_height - 1; height_index >= 1; height_index--) {
                        if (step == count_of_steps_for_output_weight) {
                                if (value_for_percent >= 10.0f && value_for_percent < 100.0f) {
                                        printf(" ");
                                } else {
                                        printf("  ");
                                }

                                printf("%d%%| ", (int) value_for_percent);
                                step--;
                        } else {
                                printf("    | ");
                                step--;
                                if (step == 0) step = count_of_steps_for_output_weight;
                        }

                        for (int percentage_of_occurrence_index = 0;
                             percentage_of_occurrence_index < 5; percentage_of_occurrence_index++) {
                                if (percentage_of_occurrence[percentage_of_occurrence_index] >= value_for_percent) {
                                        for (int filler_index = 1; filler_index <= indicator_width; filler_index++) {
                                                printf("%c", filler);
                                        }
                                        for (int space_index = 1; space_index <= *(indents_between_indicators +
                                                                                   indent_index); space_index++) {
                                                printf("%c", ' ');
                                        }
                                        indent_index++;
                                } else {
                                        if (height_index == 1) {
                                                for (int filler_index = 1;
                                                     filler_index <= indicator_width; filler_index++) {
                                                        printf("%c", filler);
                                                }
                                                for (int space_index = 1; space_index <= *(indents_between_indicators +
                                                                                           indent_index); space_index++) {
                                                        printf("%c", ' ');
                                                }
                                                indent_index++;
                                        } else {
                                                break;
                                        }

                                }
                        }
                        value_for_percent -= weight_of_percent;
                        indent_index = 0;
                        printf("%c", '\n');
                }

                printf("    +");
                for (int width_index = 1; width_index <= histogram_width - 1; width_index++) {
                        printf("-");
                }
                printf(">\n");

                int left_indent_for_symbol = indicator_width / 2;
                int right_indent_for_symbol = indicator_width - left_indent_for_symbol - 2;

                printf("    ");
                for (int index_of_indicator = 1; index_of_indicator <= 5; index_of_indicator++) {
                        if (index_of_indicator == 1) {
                                printf(" ");
                        }
                        for (int space_index = 1; space_index <= left_indent_for_symbol; space_index++) {
                                printf(" ");
                        }
                        printf(" %c", top_fife_symbols[index_of_indicator - 1]);
                        for (int space_index = 1; space_index <= right_indent_for_symbol; space_index++) {
                                printf(" ");
                        }
                        for (int space_index = 1;
                             space_index <= *(indents_between_indicators + index_of_indicator - 1); space_index++) {
                                printf(" ");
                        }
                }
                printf("\n");
                printf("    ");
                for (int index_of_indicator = 1; index_of_indicator <= 5; index_of_indicator++) {
                        int left_indent_for_occurrence = 0;
                        if (percentage_of_occurrence[index_of_indicator - 1] == 100.0f) {
                                left_indent_for_occurrence = 6;
                        } else if (percentage_of_occurrence[index_of_indicator - 1] >= 10.0f) {
                                left_indent_for_occurrence = 5;
                        } else {
                                left_indent_for_occurrence = 4;
                        }
                        if (left_indent_for_occurrence >= indicator_width) left_indent_for_occurrence = 1;
                        else left_indent_for_occurrence = indicator_width - left_indent_for_occurrence;

                        for (int space_index = 1; space_index <= left_indent_for_occurrence; space_index++) {
                                printf(" ");
                        }
                        printf("%.1f%%", percentage_of_occurrence[index_of_indicator - 1]);
                        for (int space_index = 1;
                             space_index <= *(indents_between_indicators + index_of_indicator - 1); space_index++) {
                                printf(" ");
                        }
                }
                printf("\n");
        } else {
                printf("Error: Слишком маленькая ширина гистограммы\n");
        }
        free(indents_between_indicators);
}

float max_value_in_array(float *array, size_t array_size) {
        float max_value = 0.0f;
        for (int i = 0; i < array_size; i++) {
                if (*(array + i) > max_value) {
                        max_value = *(array + i);
                }
        }

        return max_value;
}

void calculate_indents_between_indicators(int *indents_between_indicators, int indicator_width, int histogram_width) {
        int right_indent = 1;
        int left_indent = 2;

        int free_width = (histogram_width - right_indent - left_indent) - indicator_width * 5;
        for (int i = 0; i < 4; i++) {
                *(indents_between_indicators + i) = free_width / 4;
        }
        if (free_width % 4 == 1) *(indents_between_indicators) = *(indents_between_indicators) + 1;
}

int calculate_indicator_width(int histogram_width) {
        int left_indent = 1;
        int right_indent = 2;

        int free_width = histogram_width - left_indent - right_indent;
        int indicator_width = free_width / 4;

        int width_for_indent;

        while (true) {
                width_for_indent = free_width - indicator_width * 5;
                if (width_for_indent >= 4 && (width_for_indent % 4 == 0 || width_for_indent % 4 == 1)) {
                        break;
                } else {
                        indicator_width--;
                }
        }
        return indicator_width;
}

int calculate_count_of_steps_for_output_weight(int height_weight_step, float weight_of_percent,
                                               float maximal_value_for_percent) {
        int count_of_steps = 1;
        while (true) {
                if (roundf(weight_of_percent * count_of_steps) >= height_weight_step) return count_of_steps;
                else count_of_steps++;
        }

}

int five_max(int *arr, int A) {
        int max = *arr;
        for (int i = 1; i < A; i++) {
                if (*(arr + i) > max) {
                        max = *(arr + i);
                }
        }
        for (int i = 0; i < A; i++) {
                if (*(arr + i) == max) {
                        *(arr + i) = 0;
                }
        }
        return max;
}