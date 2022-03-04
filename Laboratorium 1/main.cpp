//#include "sortAlg.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

void bbSort ( int data[], int size){
    if (size <=1) return;

    int nchanges;
    do{
        nchanges=0;
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

int main(){
    std::ifstream data;
    data.open("data/liczby.txt");
    std::string stringToSort="";
    //int toSort[1000000];
    if (!data.good()){ std::cout<<"ERROR WHILE READING A FILE"; return -1;};
    while(getline(data, stringToSort, ','));
    data.close();
    //TODO: Convert string to int array...

    int toSort[1000000];
    int RANGE[17] = {10, 50, 100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 300000, 500000, 700000, 900000, 1000000};
    int nRuns = 10;
    time_t start, end;
    double meanRunTime = 0;

   // std::cout<<sizeof(toSort)/sizeof(toSort[0])<<std::endl;

    for (int i = 0; i < nRuns; i++)
    {
        time(&start);

        bbSort(toSort, (sizeof(toSort)/sizeof(toSort[0])));

        time(&end);
        meanRunTime += double(end - start);
    };
    meanRunTime = double(meanRunTime/nRuns);
    std::cout<<meanRunTime<<"\n";
    
    //wyswietlanie posortowanej tablicy
    for (int i =0; i<(sizeof(toSort)/sizeof(toSort[0])); i++){
        std::cout<<toSort[i]<<" ";
    }
std::cin>>nRuns;

return 0;
}