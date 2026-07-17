#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Updated prototypes: solve_n_queens is now void and takes a counter pointer
int check(int *arr, int row, int column);
void solve_n_queens(int *arr, int n, int current_row, int *solution_count);
void printBoard(int *arr, int n);

int main(){
    int n;
    printf("enter number of queens:");
    scanf("%d", &n);
    if(n<1 || n==2 || n==3){
        printf("Error gotta be exactly 1 or 4 and above. ");
        return 0;
    }
    
    int *arr = malloc(n*sizeof(int)); 
    int solution_count = 0; // Tracks the total number of solutions found
    
    // Pass the address of the counter (&) into the void recursion
    solve_n_queens(arr, n, 0, &solution_count);
    
    printf("Total solutions found: %d\n", solution_count);
    
    free(arr);
    return 0;
}

// Checks if the (row, column) safe for a queen (returns 1 for true, 0 for false)
int check(int *arr, int row, int column){
    for(int i=0; i<row;i++){
        if((abs(i-row) == abs(arr[i]-column)) || column == arr[i]){
            return 0; // not safe
        }
    }
    return 1; // safe
}

// The recursion itself - now void to find ALL solutions, because when returning void it just 
//keep looping through  the previouses rows and find ALL POSSIBLE SOLUTIONS
void solve_n_queens(int *arr, int n, int current_row, int *solution_count){

    if(current_row == n){ // All rows filled means a complete solution is found
        (*solution_count)++;
        printf("--- Solution #%d ---\n", *solution_count);
        printBoard(arr, n); // Prints each solution immediately
        return; // Forces backtracking to find more layouts
    }

    for(int col = 0; col<n;col++){
        if(check(arr, current_row, col)){
            arr[current_row] = col;

            // Dive deeper to the next line without any "if" stops
            solve_n_queens(arr, n, current_row + 1, solution_count);
        }
    }
}

// Printing function
void printBoard(int *arr, int n){
    for(int i=0; i<n;i++){
        for(int j =0; j<n;j++){
            if(j == arr[i]){
                printf("[Q]"); // printing a queen
            }
            else{
                printf("[ ]"); // printing empty square
            }
        }
        printf("\n");
    }
    printf("\n"); // Extra newline between distinct solutions
}