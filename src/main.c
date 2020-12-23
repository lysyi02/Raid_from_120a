#include "lib.h"

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
/* Frequency table(Таблица частот) */


/**
The main: function specifies the array, its size and value, and passes everything to the function findNumb.
*/

int main() {
  char top_five_symbols[5] = {0, 0, 0, 0, 0};
/*Opening file (Открытие файла)*/
  FILE *stream;
  if ((stream = fopen("test.htm", "rt"))==NULL) {
    /* If doesn't open - exit from programm (Если не открывается - выходим из программы) */
    printf("Cannot open file.\n");
    return 1;
  }

  /* Resetting the dictionary of entries(Обнуление словаря вхождений) */
  int frequency[ASCII_END];
  memset(frequency, 0, ASCII_END * sizeof(unsigned));

  /* Feeling the dictionary of entries(Заполнение словаря вхождений) */
  int text_length = count_symbols(stream, frequency);
  
  /* Output for frequency of english letters(Вывод частоты для англ. букв) */
  symbols_freq('e', frequency, text_length);

  printf("\n");

  /* Output for non-alphabetical symbols (Вывод частоты для небукв. символов) */
  symbols_freq('s', frequency, text_length);

  float percentage_of_occurrence[5] = {0, 0, 0, 0, 0};
  for(int i = 0; i < 5; i++){
      percentage_of_occurrence[i] = get_percent(most_common(frequency, i, top_five_symbols),text_length);
  }

  int width = 127;
  int height = 10;
  char filler = 'X';

  draw_histogram(top_five_symbols, percentage_of_occurrence, width, height, filler);

  return 0;
}

