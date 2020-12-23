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
int frequency[ASCII_END];

char top_five_symbols[5] = {0, 0, 0, 0, 0};

/* Ammount of checked symbols(Общее кол-ва проверенных символов) */
int text_length = 0;


/**
The main: function specifies the array, its size and value, and passes everything to the function findNumb.
*/

int main() {
/*Opening file (Открытие файла)*/
  FILE *stream;
  if ((stream = fopen("test.htm", "rt"))==NULL) {
    /* If doesn't open - exit from programm (Если не открывается - выходим из программы) */
    printf("Cannot open file.\n");
    return 1;
  }

  /* Resetting the dictionary of entries(Обнуление словаря вхождений) */
  memset(frequency, 0, ASCII_END * sizeof(unsigned));

  /* Feeling the dictionary of entries(Заполнение словаря вхождений) */
  count_symbols(stream);

  /* Output for frequency of english letters(Вывод частоты для англ. букв) */
  symbols_freq('e');

  printf("\n");

  /* Output for non-alphabetical symbols (Вывод частоты для небукв. символов) */
  symbols_freq('s');

  float percentage_of_occurrence[5] = {0, 0, 0, 0, 0};
  for(int i = 0; i < 5; i++){
      percentage_of_occurrence[i] = get_percent(most_common(frequency, i));
  }

  int width = 127;
  int height = 10;
  char filler = 'X';

  draw_histogram(top_five_symbols, percentage_of_occurrence, width, height, filler);

  return 0;
}

