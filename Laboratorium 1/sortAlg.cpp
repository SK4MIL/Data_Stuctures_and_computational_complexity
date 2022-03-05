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
