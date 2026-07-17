#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool check(int *arr, int row, int column);
bool solve_n_queens(int *arr, int n, int current_row);
void printBoard(int *arr, int n);

int main(){
    int n;
    printf("enter number of queens:");
    scanf("%d", &n);
    if(n<1 || n==2|| n==3){
        printf("Error gotta be exactly 1 or 4 and above. ");
        return 0;
    }
    //using malloc creating an array
    int *arr = malloc(n*sizeof(int)); // index is row and arr[index] is the column. so (0,2) would be arr[0] = 2.
    solve_n_queens(arr,n,0);
    printBoard(arr,n);
    free(arr);
    return 0;
}

//checks if the (row, column) safe for a queen.
bool check(int *arr, int row, int column){
    
    for(int i=0; i<row;i++){
        if((abs(i-row) == abs(arr[i]-column)) || column == arr[i]){
            return false; // not safe
        }
    }
    
    return true; //safe
}

//the recursion itself 
bool solve_n_queens(int *arr, int n, int current_row){

    if(current_row == n){ //all rows are filled with queens so theres a solution.
        return true;
    }

    for(int col = 0; col<n;col++){
        //checking each column on current row to see if we can put a queen.
        if(check(arr,current_row,col)){
            //if safe,saving column number onarray
            arr[current_row] = col;

            //recursion for next line.
            if(solve_n_queens(arr,n,current_row+1)){
                return true;

            }// recursive if

        }// if 

    }//for loop
    
    //whole loop finished
    return false;
}// whole function


//printing function
void printBoard(int *arr, int n){
    for(int i=0; i<n;i++){
        for(int j =0; j<n;j++){
            if(j == arr[i]){
                printf("[Q]");// printing a queen
            }
            else{
            printf("[ ]");// printing empty square
            }
        }
        printf("\n");
    }
}