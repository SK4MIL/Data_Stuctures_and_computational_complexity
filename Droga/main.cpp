#include "defines.h"
#include "dijkstra.h"

using namespace std;



int main(){
    //check if you want to save sorted array into a csv file.
    int RANGE[] = {10, 20, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int saved_range = 12;
    //cout<<"dzialam"<<endl;
    //int * toSort = new int[1000000];
    //int adjMatrix[1000][1000];
    int rowCount=1000;
    int colCount=1000;
    int** adjMatrix = new int*[rowCount];
        for(int i = 0; i < rowCount; ++i)
        adjMatrix[i] = new int[colCount];
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
     for (int r =0; r <=13; r++){
    //for (int r = 16; r >= 0; r--){
        //printf("Macierz dla zakresu %d:\n", RANGE[r]);
        for (int i = 0; i < N_RUNS; i++)
        {    
        //File handling
        std::fstream inFile;
        inFile.open(INPUT_FILE);
        if (!inFile.is_open()){ std::cout<<"ERROR";return -1;};
        int x, iter=0;
        while (iter <= RANGE[r]){
            for (int j =0; j<= RANGE[r]; j++){
                inFile >> x;
                if (x == ',') break;
                if ( iter != j) adjMatrix[iter][j]=x;
                else adjMatrix[iter][j]=0;
                //printf("%d ", adjMatrix[iter][j]);  
            }
            //printf("\n");
            // if it's a number save it to toSort array.
            iter++;
            // check if next character is a number or a comma, if so skip
            //if(inFile.peek() == ','){inFile.ignore();};
        };
        //close file access. 
        inFile.close();
        //time is measured only for the duration of the sorting algorithm
        time(&start);

        DijkstraAlgo(adjMatrix,0);

        time(&end);

        meanRunTime += double(end - start);
        }
    meanRunTime = double(meanRunTime/N_RUNS);

    std::cout<<"Zakres: "<<RANGE[r]<<" Czas trwania: "<<meanRunTime<<"\n";
    outFile << RANGE[r]<<','<< meanRunTime<<','<<N_RUNS <<endl;
    meanRunTime=0;
    };
    
// outFile.close();

//print sorted array
//  for (int l = 0; l<RANGE[1]; l++){
//     std::cout<<toSort[l]<<" : "<<l<<"\t ";
//  }

//delete [] toSort;
system("pause");
return 0;

}
    
