#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include<time.h>
#define max(a,b) (a > b ? a : b)


#define max(a,b) (a > b ? a : b)



int knapsack(int index, int size, int weights[],int values[]){
	int matrix[100][100] = {0};
    int take,dontTake;

    take = dontTake = 0;

    if (matrix[index][size]!=0)
        return matrix[index][size];

    if (index==0){
        if (weights[0]<=size){
            matrix[index][size] = values[0];
            return values[0];
        }
        else{
            matrix[index][size] = 0;
            return 0;
        }
    }

    if (weights[index]<=size)
        take = values[index] + knapsack(index-1, size-weights[index], weights, values);

    dontTake = knapsack(index-1, size, weights, values);

    matrix[index][size] = max (take, dontTake);

    return matrix[index][size];

}
int main(){
	int val1[10] ; 
    int wt1[10] ;
    int  W1 = 100;
     int val2[25] ; 
    int wt2[25] ;
    int  W2 = 300;
     int val3[100] ; 
    int wt3[100] ;
    int  W3 = 800;
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
    
    printf("Max value1 = %d \n",knapsack(n1-1,W1,wt1,val1));
    printf("Max value2 = %d \n",knapsack(n2-1,W2,wt2,val2));
    printf("Max value3 = %d ",knapsack(n3-1,W3,wt3,val3));

    return 0;
}
