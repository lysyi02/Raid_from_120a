#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * @file main.c
 * @brief Create a dictionary of frequencies for all characters in file.
 * @author КІТ-120а.
 * @date 22-dec-2020
 * @version 1.0
 */

/**
 * @param  - ;
 * @param  - ;
 * @param  - ;
 * @param  - ;
 */

/**
Функція main: задає масив, його розміри та значення і передає все до функції findNumb.
*/

int main() {

        char top_fife_symbols[] = "asdfg";
        float percentage_of_occurrence[] = {25.0f, 10.5f, 9.8f, 9.0f, 0.1f};
        int width = 33;
        int height = 10;
        char filler = 'X';
        draw_histogram(top_fife_symbols, percentage_of_occurrence, width, height, filler);
        return 0;
}

