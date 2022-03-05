#include "sortAlg.h"

int main(){
    int RANGE[] = {10, 50, 100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 300000, 500000, 700000, 900000, 1000000};
    int nRuns = 1;
    time_t start, t_end;
    double meanRunTime = 0;

    for (int r = 0; r < 16; r++){
        for (int i = 0; i < nRuns; i++)
        {
        int toSort[500000];
        const int size_toSort = sizeof(toSort)/sizeof(toSort[0]);
        for (int i=0; i <size_toSort ; i++){toSort[i]=0;};

        //File handling
        std::fstream plik;
        plik.open("data/liczby.txt");
        if (!plik.is_open()){ std::cout<<"ERROR";};
        int x, iter=0;;
        while ( plik >> x && iter < size_toSort){
            // if it's a number save it to toSort array.
            toSort[iter]=x;
            iter++;
            // check if next character is a number or a comma, if so skip
            if(plik.peek() == ','){plik.ignore();};
        };
        //close file access. 
        plik.close();

        time(&start);

        bbSort(toSort, RANGE[r]);

        time(&t_end);
        meanRunTime += double(t_end - start);
        };
    meanRunTime = meanRunTime/nRuns;
    std::cout<<"Czas trwania: "<<meanRunTime<<" zakres: "<<RANGE[r]<<"\n";
    };

    //print sorted array
    //for (int l = 0; l<size_toSort; l++){
    //   std::cout<<toSort[l]<<":"<<l<<"\n";
    //}
std::cin>>nRuns;
return 0;
}
