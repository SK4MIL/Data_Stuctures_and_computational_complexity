#include "heapSort.h"
using namespace std;

void heapify(int data[], int node, int aSize){
    int max = node;
    int left = 2 * node + 1;
    int right = 2* node + 2;

    if (left < aSize && data[left] > data[max]){
        max = left;
    }
    if ( right < aSize && data[right] > data[max]){
        max = right;
    }
    if ( max != node){
        swap(data[node], data[max]);
        heapify(data, max, aSize);
    }
}
void heapSort( int data[], int aSize){
    for (int i = ((aSize/2) - 1); i >= 0; i--){
        heapify(data, i, aSize);
    }

    for(int i = aSize-1; i >0; i--){
        swap(data[0], data[i]);
        heapify(data, 0, i);
    }
}