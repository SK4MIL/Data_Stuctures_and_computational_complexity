#include "sortAlg.h"

using namespace std;

int main(){

    cout<<"\n\n";
    int toSort[]={-46304, 34149, -13115, 12543, 15517, 55369, -29806, -10757, 38089, 7826, -52066};
    int sizeToSort=sizeof(toSort)/sizeof(toSort[0]) - 1;
    cout<<"sizeToSort: "<<sizeToSort<<"\n";
    qsort(toSort, 0, sizeToSort);

     for (int i =0; i <= sizeToSort; i++){
         cout<<toSort[i]<<" ";
     } 
system("pause");
return 0;
}