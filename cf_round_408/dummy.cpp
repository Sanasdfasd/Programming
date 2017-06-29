#include <stdio.h>
int fact(int N) {            
    return (N * fact(N-1));     
    }   
int  main() {  
    int N=5;   
    int factorial = fact(N);      
    printf("%d",factorial);
    return 0;
    }  