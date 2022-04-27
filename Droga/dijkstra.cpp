
#include "dijkstra.h"
#include "defines.h"

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<6;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int **graph,int src) // adjacency matrix 
{
    int distance[1000]; // // array to calculate the minimum distance for each node                             
    bool Tset[1000];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<6; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<6; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }

    ofstream outFile;
    ifstream f;
    f.open(OUTPUT_FILE);
    outFile.open(OUTPUT_FILE,ios::app);
    if(!outFile.is_open()){cout<<"ERROR: outFile\n";};
        if (!f){
        outFile << "Vertex ,Distance from source vertex"<<endl;
    }
    f.close();

    for(int k = 0; k<1000; k++)                      
    { 
        //string str=65+k; 
        outFile <<k<<", "<<distance[k]<<endl;;
    }
}