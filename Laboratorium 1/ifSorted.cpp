#include <iostream>
#include <fstream>
using namespace std;
 
// Function that returns true if array is
// sorted in non-decreasing order.
bool arraySortedOrNot(int a[], int n)
{
     
    // Base case
    if (n == 1 || n == 0)
    {
        return true;
    }
     
    // Check if present index and index
    // previous to it are in correct order
    // and rest of the array is also sorted
    // if true then return true else return
    // false
    return a[n - 1] >= a[n - 2] &&
     arraySortedOrNot(a, n - 1);
}
 
// Driver code
int main()
{
    int * arr = new int[1000000];
    //File handling
    std::fstream inFile;
    inFile.open("data/posortowane_insert.txt");
    if (!inFile.is_open()){ std::cout<<"ERROR";return -1;};
    int x, iter=0;;
    while ( inFile >> x && iter < 10000){
        // if it's a number save it to toSort array.
        arr[iter]=x;
        iter++;
        // check if next character is a number or a comma, if so skip
        if(inFile.peek() == ','){inFile.ignore();};
        };
    //close file access. 
    inFile.close();
    
    // const int n = sizeof(arr) / sizeof(arr[0]);
    // cout<< n<<endl;
     
    // Function Call
    if (arraySortedOrNot(arr, 10000))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
     
    return 0;
}
 
// This code is contributed by avanitrachhadiya2155