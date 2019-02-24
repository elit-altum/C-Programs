//To print the representation of a sparse matrix in C
//10/1/19

#include<stdio.h>
#include<process.h>
#include<stdbool.h>

main(){
    //Alphabetical variables are loopers

   int rows, coloumns, ctr = 0, nonZeroctr = 0, i,j,l=1;
   printf("Enter rows of matrix \n");
   scanf("%d", &rows);
   printf("Enter coloumns of matrix \n");
   scanf("%d", &coloumns);
   int sparseRows = (rows*coloumns)/2;
   int sparseMatrix[sparseRows][3];

   //Gets the elements of the matrix

   int Array[rows][coloumns];
   printf("Enter elements of Array \n");
   for(i = 0; i < rows; i++){
       for(j = 0; j < coloumns; j++){
           scanf("%d", &Array[i][j]);
           if (Array[i][j] == 0) {
               ctr++;
           }
           else{
               nonZeroctr++;
               sparseMatrix[l][0] = i;
               sparseMatrix[l][1] = j;
               sparseMatrix[l][2] = Array[i][j];
               l++;
           }
       }
   }

   //To check if the input matrix is a sparse matrix or not
   
   bool ifSparse;
   if (ctr > (rows*coloumns)/2) {
       printf("Array is a sparse matrix with %d number of zeroes \n", ctr);
       ifSparse = true;
   }
   else{
       printf("Array isn't a sparse matrix and has %d number of zeroes \n", ctr);
       ifSparse = false;
   }
   
   //If the matrix is a sparse matrix. Log's it's representation on the console

   if (ifSparse) {
       sparseMatrix[0][0] = rows;
       sparseMatrix[0][1] = coloumns;
       sparseMatrix[0][2] = nonZeroctr;
       for( i = 0; i <= nonZeroctr; i++){
           for(j = 0; j < 3; j++){
               printf("%d \t", sparseMatrix[i][j]);
           }
           printf("\n");
       }
   }
}
