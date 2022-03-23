#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>


#define N_MAX 65000


using namespace std;

void bbSort ( int data[], int aSize);
void insersort(vector<int> data, int aSize);
void insertsort (int data[], int aSize);
void qsort(int data[], int firstNumber, int lastNumber);
void bucketSort(vector<int> data, const int aSize);
void mixedBucket(int data[], int aSize);
// void merge(int data[], int firstStart, int middle, int secondEnd);
// void mgsort(int data[], int firstNumber, int lastNumber);

