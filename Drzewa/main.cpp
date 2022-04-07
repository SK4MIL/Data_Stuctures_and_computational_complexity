
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

#include "defines.h"
using namespace std;




int main(){
    //check if you want to save sorted array into a csv file.
    int RANGE[] = {10, 20, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

    //int * toSort = new int[1000000];
    int toSort[100][100];
    // time measuring
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
     for (int r =0; r <=0; r++){
    //for (int r = 16; r >= 0; r--){
        for (int i = 0; i < N_RUNS; i++)
        {    
        //File handling
        std::fstream inFile;
        inFile.open(INPUT_FILE);
        if (!inFile.is_open()){ std::cout<<"ERROR";return -1;};
        int x, row=0;;
        while ( inFile >> x && row <= RANGE[r]){
            // if it's a number save it to toSort array.
            for (int col =0; col < RANGE[r]; col++){
                if (row == col){x=0;};
                toSort[row][col]=x;
            }
            row++;
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
 for (int l = 0; l<RANGE[0]; l++){
     for (int col =0; col < RANGE[0]; col++){
        std::cout<<toSort[l][col]<<" ";//<<" : "<<l<<" , "<<col<<"\t ";
     }
     cout<<"\n";
  }

//delete [] toSort;
system("pause");
return 0;
}
