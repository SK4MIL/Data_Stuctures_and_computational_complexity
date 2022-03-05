#include "sortAlg.h"
using namespace std;

int main(){
    int RANGE[] = {10, 50, 100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 300000, 500000, 700000, 900000, 1000000};
    float nRuns = 1;
    int * toSort= new int[1000000];
    time_t start, t_end;
    double meanRunTime = 0.0;
    ofstream outFile;
    outFile.open("measqTime.csv",ios::app);
    if(!outFile.is_open()){cout<<"ERROR: outFile\n"; return -1;};
    outFile << "Zakres, Czas trwania"<< endl;  

    for (int r = 5; r >= 0; r--){
        for (int i = 0; i < nRuns; i++)
        {
        const int size_toSort = sizeof(toSort)/sizeof(toSort[0]);
        for (int i=0; i <size_toSort ; i++){toSort[i]=0;};

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
        time(&start);
        //bbSort(toSort, RANGE[r]);
        qsort(toSort, 0, size_toSort);

        time(&t_end);
        meanRunTime += double(t_end - start);
        };
        meanRunTime = double(meanRunTime/nRuns);
    std::cout<<"Czas trwania: "<<meanRunTime<<" Zakres: "<<RANGE[r]<<"\n";
    outFile << RANGE[r]<<','<< meanRunTime <<endl;
    meanRunTime=0.0;
    };

//print sorted array
for (int l = 0; l<RANGE[3]; l++){
   std::cout<<toSort[l]<<" : "<<l<<", ";
}

outFile.close();
system("pause");
return 0;
}
