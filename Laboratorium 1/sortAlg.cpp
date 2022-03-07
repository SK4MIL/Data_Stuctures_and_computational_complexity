#include "sortAlg.h"


void bbSort ( int data[], int aSize){
    if (aSize <=1) return;
    int nchanges;
    int tmp;
    do{
        nchanges=0;
        for (int i=0; i<=aSize; i++){
            if (data[i] > data[i+1]){
                // if first number is greater, change their places
                std::swap(data[i],data[i+1]);
                nchanges++;
            }
        }
        aSize--;
    }while( nchanges > 0);
    return;
};

void insertsort (int data[], int aSize){
    int key;
    for (int i = 1; i <= aSize; i++){
        key = data[i];
        int j = i-1;
        while( j >= 0 && data[j] > key){
            data[j+1]=data[j];
            j = j-1;
        }
        data[j+1] = key; 
    }

}

void qsort(int data[], int firstNumber, int lastNumber){
    if (lastNumber <=1) return;

    //choose pivot by median of the three method
    if (data[firstNumber] > data[(firstNumber+lastNumber)/2]){
        swap(data[firstNumber], data[(firstNumber+lastNumber)/2]);
        
    }
    if (data[firstNumber] > data[lastNumber]){
        swap(data[firstNumber], data[lastNumber]);
    }
    if ( data[(firstNumber+lastNumber)/2] > data[lastNumber]){
            swap(data[(firstNumber+lastNumber)/2], data[lastNumber]);
    }

    //asigning pivot as a middle vlue of the three. 
    int pivot = data[(firstNumber+lastNumber)/2];
    // cout <<"Pivot: "<< pivot<<" index: "<<(firstNumber+lastNumber)/2<<"\t";

    int left=firstNumber-1, right = lastNumber+1;
    // cout<<"Left przed: "<<left;
    // cout<<"\tRight przed: "<<right<<endl;
    
    while (1){
        while(pivot > data[++left]);
        while(pivot < data[--right]);

        if (left <= right){swap(data[left], data[right]);}
        else{
            break;
        }
    }
    // cout<<"Left po przejsciu: "<<left;
    // cout<<"\tRight po przejsciu: "<<right<<endl;

    if(right > firstNumber) {qsort(data, firstNumber, right);}
    if(left < lastNumber) {qsort(data, left, lastNumber);}
return;
};

void mgsort(int data[], int aSize){

}