#include "sortAlg.h"

using namespace std;

int main(){

    cout<<"\n\n";
    int toSort[]={9,1,2,3,4,6};
    int sizeToSort=sizeof(toSort)/sizeof(toSort[0]) - 1;
    mgsort(toSort, 0, sizeToSort);

     for (int i =0; i <= sizeToSort; i++){
         cout<<toSort[i]<<" ";
     } 
system("pause");
return 0;
}