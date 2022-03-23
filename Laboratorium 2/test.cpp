#include "sortAlg.h"

using namespace std;

int main(){

    cout<<"\n\n";
    int toSort[]={-2,-5,7,4,23,31,22,9,1,0,2,3};
    //int toSort[]={-1,-2,-2312,-4,7,9,1,2,3,4,6};
    int sizeToSort=sizeof(toSort)/sizeof(toSort[0]);
    cout<<sizeToSort;
    // bucketSort(toSort, sizeToSort);
    mixedBucket(toSort, sizeToSort);

    for (int i=0; i<sizeToSort; i++){
        cout<<toSort[i]<<": " <<i<<", ";
    }

system("pause");
return 0;
}