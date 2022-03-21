#include "sortAlg.h"

using namespace std;

int main(){

    cout<<"\n\n";
    int toSort[]={7,4,23,31,22,0,9,1};
    int * pointer = toSort;
    //int toSort[]={-1,-2,-2312,-4,7,9,1,2,3,4,6};
    int sizeToSort=sizeof(toSort)/sizeof(toSort[0]) - 1;
    // bucketSort(toSort, sizeToSort);
    mixedBucket(toSort, sizeToSort);

    for (int i=0; i<sizeToSort; i++){
        cout<<toSort<<", ";
    }
system("pause");
return 0;
}