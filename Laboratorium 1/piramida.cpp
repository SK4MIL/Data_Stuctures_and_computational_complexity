#include <iostream>
#include <stdio.h>


int main()
{
    int K = 5;

    for (int i=1; i<=K; i++ ){
        for (int j=1; j<=i; j++){
            std::cout<<j;
        }
        std::cout<<std::endl;
    }
    std::cin>>K;

    return 0;
}