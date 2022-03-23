#include "sortAlg.h"
#include "defines.h"

void bbSort ( int data[], int aSize){
    if (aSize <=1) return;
    int nchanges;
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
void insersort(std::vector<int> data, int aSize){
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

void bucketSort(vector<float> *data, int aSize){
    // TODO: Sprawdzić czy da się alokować aSize 1000000
    vector<float> bucket[1000000];
    // Przydzielamy liczby do odpowiednich wiaderek. 
    for (int i=0; i < aSize; i++)
    {
        int buckid = (int)(aSize*(data->at(i)/N_MAX));
        bucket[buckid].push_back(data->at(i));
        //cout<<"pushed back at bucket "<<buckid<<" value: "<<data->at(i)<<"\n";
    }
    //Rozdzielilem liczby
    //Sortujemy używajac insert sorta. 
    for (int  i=0; i<aSize; i++){
        sort(bucket[i].begin(), bucket[i].end());
    }

    data -> clear();
    for (int i=0; i<aSize; i++){
        for (int j=0; j<bucket[i].size(); j++){
            data -> push_back(bucket[i][j]);
        }
    }

}

/*
void mixedBucket(int data[], int aSize){
    vector<float>* Positive = new vector<float>[1000000];
    vector<float>* Negative = new vector<float>[1000000];
    
    for (int i=0; i<aSize; i++){
        if (data[i] < 0)
            Negative->push_back(data[i]*-1);
        else
            Positive->push_back(data[i]);
    }

    bucketSort(Negative, (int)Negative->size());
    bucketSort(Positive, (int)Positive->size());
   
    for (int i=0; i < Negative->size(); i++){
        data[i] = -1 * (Negative->at(Negative->size() -1 - i));
    }
    for (int i=Negative->size(); i<aSize; i++){
        data[i] = Positive->at(i - Negative->size());
    }
}
*/

void mixedBucket(int data[], int aSize){
    vector<float> Positive;
    Positive.reserve(1000000);
    vector<float> Negative;
    Negative.reserve(1000000);
    
    for (int i=0; i<aSize; i++){
        if (data[i] < 0)
            Negative.push_back(data[i]*-1);
        else
            Positive.push_back(data[i]);
    }

    bucketSort(&Negative, (int)Negative.size());
    bucketSort(&Positive, (int)Positive.size());
   
    for (int i=0; i < Negative.size(); i++){
        data[i] = -1 * (Negative[Negative.size() -1 - i]);
    }
    for (int i=Negative.size(); i<aSize; i++){
        data[i] = Positive[i - Negative.size()];
    }
}



// void mgsort(int data[], int firstNumber, int lastNumber){
//     int middle;
//     if (firstNumber < lastNumber){
//         middle =  (firstNumber + (lastNumber))/2;
//         cout<<"Środek: "<<data[middle]<<"\n";
//         mgsort( data, firstNumber, middle);
//         mgsort( data, middle+1, lastNumber);
//     }
//     merge(data, firstNumber, middle, lastNumber);

// }
// void merge(int data[], int firstStart, int middle, int secondEnd){
    
//     int subSize1= middle - firstStart +1;
//     int subSize2= secondEnd - middle;
    

//     //subarray creation and assigment:
//     // int firstArr[subSize1];
//     // int secondArr[subSize2];
//     int * firstArr = new int[subSize1];
//     int * secondArr = new int[subSize2];

//     for (int i = 0; i<subSize1; i++ ){
//         firstArr[i]=data[firstStart+i];
//     }
//     for (int i = 0; i<subSize2; i++ ){
//         secondArr[i]=data[middle+1+i];
//     }

//     int i =0,j=0,k=firstStart;
//     //sorting itself, comparing pieces between arrays and putting them in the right order.
//     while (i < subSize1 && j < subSize2) {
//         if (firstArr[i] <= secondArr[j]) {
//             data[k] = firstArr[i];
//             i++;
//         } else {
//             data[k] = secondArr[j];
//             j++;
//         }
//         k++;
//     }

//     //reconstruction of data[];
//     while( i < subSize1){
//         data[k]=firstArr[i];
//         i++;
//         k++;
//     }

//     while (j < subSize2){
//         data[k]=secondArr[j];
//         j++;
//         k++;
//     }
//     // delete [] firstArr;
//     // delete [] secondArr;

// }