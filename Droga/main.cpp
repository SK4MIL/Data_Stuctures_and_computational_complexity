
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;
#include "defines.h"



int main(){
    //check if you want to save sorted array into a csv file.
    int RANGE[] = {10, 20, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

    int * toSort = new int[1000000];
    // time
    time_t start, end;
    double meanRunTime = 0.0;

    ofstream outFile;
    ifstream f;
    f.open(TIME_FILE);
    outFile.open(TIME_FILE,ios::app);
    if(!outFile.is_open()){cout<<"ERROR: outFile\n"; return -1;};
    if (!f){
        outFile << "Zakres, Czas trwania, Liczba iteracji"<< endl;  
    }
    f.close();
     for (int r =0; r <=16; r++){
    //for (int r = 16; r >= 0; r--){
        for (int i = 0; i < N_RUNS; i++)
        {    
        //File handling
        std::fstream inFile;
        inFile.open(INPUT_FILE);
        if (!inFile.is_open()){ std::cout<<"ERROR";return -1;};
        int x, iter=0;;
        while ( inFile >> x && iter <= RANGE[r]){
            // if it's a number save it to toSort array.
            toSort[iter]=x;
            iter++;
            // check if next character is a number or a comma, if so skip
            if(inFile.peek() == ','){inFile.ignore();};
        };
        //close file access. 
        inFile.close();
        //time is measured only for the duration of the sorting algorithm
        time(&start);

        //TODO: GRAF

        time(&end);

        meanRunTime += double(end - start);
        }
    meanRunTime = double(meanRunTime/N_RUNS);

    // Save to file
    if (r == 16 && SAVE == true ){
        fstream sortedFile;
        sortedFile.open(SORTED_FILE, ios::app);
        if (!sortedFile.is_open()) {cout<<"ERROR: sortedFile\n"; return 0;};
        for (int i = 0; i<RANGE[16]; i++){
        sortedFile << toSort[i]<<", ";
        }
    }
    std::cout<<"Zakres: "<<RANGE[r]<<" Czas trwania: "<<meanRunTime<<"\n";
    outFile << RANGE[r]<<','<< meanRunTime<<','<<N_RUNS <<endl;
    
    meanRunTime=0.0;
    };
outFile.close();

//print sorted array
//  for (int l = 0; l<RANGE[1]; l++){
//     std::cout<<toSort[l]<<" : "<<l<<"\t ";
//  }

delete [] toSort;
system("pause");
return 0;
}
