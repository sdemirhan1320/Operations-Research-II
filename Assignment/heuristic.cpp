#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include<time.h>


int max(int a, int b) {
	 return (a > b)? a : b;
	 }
// Returns the maximum value 
int knapsack(int W, int wt[], int val[], int n)
{
   int i, v1,w1,j;
   int a;
   int b=0;
   int k;
   v1=0;
   w1=0;
   
   for (i = 0; i <n; i++)
   {
   for(j=0;j<n;j++){
   
    a=val[j];
    if(a>b){
    	b=a;
    	k=j;
 		}
	}
	
	if(w1+wt[k]<=W){
		w1=w1+wt[k];
		v1=v1+b;
	}
	
	val[k]=0;
	
	b=0;
   }
   				
 
   return v1;
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
