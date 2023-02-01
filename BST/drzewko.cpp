#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#define TIME_FILE "time/bstbuild.csv"
using namespace std;

struct Node{
    string data;
    Node* left;
    Node* right;
};

Node* GetNewNode(string data){
    Node* newNode = new Node();
    newNode->data=data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* rootPtr,string data){
    if(rootPtr == NULL){
        rootPtr = GetNewNode(data);
        return rootPtr;
    }
    else if(data<= rootPtr->data){
        rootPtr->left = Insert(rootPtr->left,data);
    }
    else {
        rootPtr->right = Insert(rootPtr->right,data);
    }
    return rootPtr;
}

int main() {
int n_runs=1;
int Range[]={10, 20, 50, 100, 500, 1000, 2000, 5000, 10000,20000, 50000, 100000, 200000, 400000};
int count;
time_t start, stop;
double buildTime=0;
string word;
ifstream inFile;

ofstream outFile;
ifstream f;
f.open(TIME_FILE);
outFile.open(TIME_FILE,ios::app);
if(!outFile.is_open()){cout<<"ERROR: outFile\n"; return -1;};
if (!f){
     outFile << "Zakres, Czas trwania, Liczba iteracji"<< endl;  
}
f.close();

// for (int ile = 0; ile < n_runs; ile ++){
//     cout<<ile<<endl;
for (int r = 0; r < 13; r++){
//for (int r = 14; r > 0; r-- ){
for (int ile = 0; ile < n_runs; ile ++){
Node* rootPtr = NULL; // Pointer to the root node
time(&start);
inFile.open("Data/english3.txt");
if (!inFile) {
cout << "Unable to open text file";
}
count =0;
while (count < Range[r]) {
    count++;
    inFile >> word;
    if (word != "#")
    {
    rootPtr = Insert(rootPtr,word.substr(0,10));
    }
    else
        break;
}
time(&stop);
buildTime += double(stop - start);
inFile.close();
}
buildTime = double(buildTime/n_runs);
outFile << count<<','<< buildTime<<','<<n_runs <<endl;
cout<<"Tyla wierzcholkow: "<<count<<" W tyla czasu: " <<buildTime<<endl;
//outFile << count <<", "<< buildTime<<", "<<n_runs<<"\n";
buildTime=0;
}
}