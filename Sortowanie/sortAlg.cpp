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

void mgsort(int data[], int firstNumber, int lastNumber){
    int middle;
    if (firstNumber < lastNumber){
        middle =  (firstNumber + (lastNumber))/2;
        cout<<"??rodek: "<<data[middle]<<"\n";
        mgsort( data, firstNumber, middle);
        mgsort( data, middle+1, lastNumber);
    }
    merge(data, firstNumber, middle, lastNumber);

}
void merge(int data[], int firstStart, int middle, int secondEnd){
    int subSize1= middle - firstStart +1;
    int subSize2= secondEnd - middle;
    

    //subarray creation and assigment:
    // int firstArr[subSize1];
    // int secondArr[subSize2];
    int * firstArr = new int[subSize1];
    int * secondArr = new int[subSize2];

    for (int i = 0; i<subSize1; i++ ){
        firstArr[i]=data[firstStart+i];
    }
    for (int i = 0; i<subSize2; i++ ){
        secondArr[i]=data[middle+1+i];
    }

    int i =0,j=0,k=firstStart;
    //sorting itself, comparing pieces between arrays and putting them in the right order.
    while (i < subSize1 && j < subSize2) {
        if (firstArr[i] <= secondArr[j]) {
            data[k] = firstArr[i];
            i++;
        } else {
            data[k] = secondArr[j];
            j++;
        }
        k++;
    }

    //reconstruction of data[];
    while( i < subSize1){
        data[k]=firstArr[i];
        i++;
        k++;
    }

    while (j < subSize2){
        data[k]=secondArr[j];
        j++;
        k++;
    }
    // delete [] firstArr;
    // delete [] secondArr;

}