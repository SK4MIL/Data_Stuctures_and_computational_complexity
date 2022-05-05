#include <fstream>
#include <time.h>
#include <string>

#define N_RUNS 1
// Dostępne funkcje: bbSort;  insertsort; qsort; mixedBucket; heapSort;
#define FUNKCJA mixedBucket
//                  Z jakiego pliku pobierać dane
#define INPUT_FILE "data/liczby.txt"
//      Czy zapisać posortowaną tablice. 
#define SAVE 1
//                  W jakim pliku zapisać posortowane dane
#define OUTPUT_FILE "time/path.csv"
//                  Gdzie zapisać zmierzone czasy.
#define TIME_FILE "time/djikstra.csv"


