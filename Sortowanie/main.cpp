#include "sortAlg.h"
using namespace std;

int main(){
    //check if you want to save sorted array into a csv file.
    bool save = false;

    int RANGE[] = {10, 50, 100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 300000, 500000, 700000, 900000, 1000000};
    float nRuns = 10;

    int * toSort = new int[1000000];
    // time
    time_t start, t_end;
    double meanRunTime = 0.0;

    ofstream outFile;
    outFile.open("time/insertsortTime.csv",ios::app);
    if(!outFile.is_open()){cout<<"ERROR: outFile\n"; return -1;};
    outFile << "Zakres, Czas trwania, Liczba iteracji"<< endl;  
    for (int r = 0; r <=16; r++){
    // for (int r = 16; r >= 14; r--){
        for (int i = 0; i < nRuns; i++)
        {    
        //File handling
        std::fstream inFile;
        inFile.open("data/liczby.txt");
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

        // bbSort(toSort, RANGE[r]);

        // insertsort(toSort, RANGE[r]);

        qsort(toSort, 0, RANGE[r]);

        time(&t_end);

        meanRunTime += double(t_end - start);
        }
    meanRunTime = double(meanRunTime/nRuns);

    // Save to file
    if (r == 16 && save == true){
        fstream sortedFile;
        sortedFile.open("data/posortowane_bb.txt", ios::app);
        if (!sortedFile.is_open()) {cout<<"ERROR: sortedFile\n"; return 0;};
        for (int i = 0; i<RANGE[16]; i++){
        sortedFile << toSort[i]<<", ";
        }
    }
    std::cout<<"Zakres: "<<RANGE[r]<<" Czas trwania: "<<meanRunTime<<"\n";
    outFile << RANGE[r]<<','<< meanRunTime<<','<<nRuns <<endl;
    
    meanRunTime=0.0;
    };
outFile.close();

//print sorted array
// for (int l = 0; l<RANGE[1]; l++){
//    std::cout<<toSort[l]<<" : "<<l<<"\t ";
// }

delete [] toSort;
system("pause");
return 0;
}
