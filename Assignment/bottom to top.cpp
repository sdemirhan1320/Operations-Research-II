#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include<time.h>
//Bottom up

int max(int a, int b) {
	 return (a > b)? a : b;
	 }
// Returns the maximum value 
int knapsack(int W, int wt[], int val[], int n)
{
   int i, j;
   int K[n+1][W+1];
   
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (wt[i-1] <= j)
                 K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
   }
 
   return K[n][W];
}
 
int main()
{
    int val1[10] ; 
    int wt1[10] ;
    int  W1 = 150;
     int val2[25] ; 
    int wt2[25] ;
    int  W2 = 450;
     int val3[100] ; 
    int wt3[100] ;
    int  W3 = 1250;
    int i;
    srand(2330);
    for(i=0;i<10;i++){
		
		val1[i]=rand()%21 + 1;
		wt1[i]=rand()%31+9;
	}
	 for(i=0;i<25;i++){
		
		val2[i]=rand()%21 + 1;
		wt2[i]=rand()%31+9;
	}
	 for(i=0;i<100;i++){
		
		val3[i]=rand()%21 + 1;
		wt3[i]=rand()%31+9;
	}

	
	for(i=0;i<10;i++){
		
		printf("%d  ",val1[i]);     
		printf("%d\n",wt1[i]); 
	}
    int n1 = 10;
    int n2=25;
    int n3=100;
    printf("Value1 = %d\n", knapsack(W1, wt1, val1, n1));
    printf("Value2 = %d\n", knapsack(W2, wt2, val2, n2));
    printf("Value3 = %d", knapsack(W3, wt3, val3, n3));
    
    
    return 0;
    
    
    
    
    
}
