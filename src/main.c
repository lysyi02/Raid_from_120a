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

int frequency[ASCII_END];

char top_five_symbols[5] = {0, 0, 0, 0, 0};

/* Общее кол-ва проверенных символов */
int text_length = 0;


/**
Функція main: задає масив, його розміри та значення і передає все до функції findNumb.
*/

int main() {
/*Открытие файла*/
  FILE *stream;
  if ((stream = fopen("test.htm", "rt"))==NULL) {
    /* Если не открывается - выходим из программы */
    printf("Cannot open file.\n");
    return 1;
  }

  /* Обнуление словаря вхождений*/
  memset(frequency, 0, ASCII_END * sizeof(unsigned));

  /* Заполнение словаря вхождений*/
  count_symbols(stream);

  /* Вывод частоты для англ. букв*/
  symbols_freq('e');

  printf("\n");

  /* Вывод частоты для небукв. символов*/
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

