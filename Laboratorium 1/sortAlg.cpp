#include "sortAlg.h"
#include <iostream>

void bbSort ( int data[], int size){
    if (size <=1) return;

    int nchanges=0;
    do{
        int tmp;
        for (int i=0; i<size; i++){
            if (data[i] > data[i+1]){
                // if first number is greater, change their places
                tmp = data[i];
                data[i]=data[i+1];
                data[i+1]=tmp;
                nchanges++; 
            }
        }
    }while( nchanges > 0);

    return;
}
