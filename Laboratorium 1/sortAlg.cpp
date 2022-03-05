#include "sortAlg.h"

void bbSort ( int data[], int aSize){
    if (aSize <=1) return;
    int nchanges;
    int tmp;
    do{
        nchanges=0;
        for (int i=0; i<aSize; i++){
            if (data[i] > data[i+1]){
                // if first number is greater, change their places
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
                nchanges++;
            }
        }
        aSize--;
    }while( nchanges > 0);
    return;
};

void qsort(int data[], int left, int right){
    if (right <=1) return;
    int tmp;
    int pivot = data[(left+right)/2];
    int i=left-1, j = right+1;

    while (1){
        while(pivot > data[++i]);
        while(pivot < data[--j]);

        if (i <= j){
            // tmp=data[i];
            // data[i]=data[j];
            // data[j]=tmp;
            std::swap(data[i], data[j]);
        }
        else{
            break;
        }
    }
    if(j > left) qsort(data, left, j);
    if(i < right) qsort(data, i, right);
return;
};