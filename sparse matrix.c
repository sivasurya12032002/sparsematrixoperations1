#include<stdio.h>

main(){

//variables required
int i,j,rows,columns,rows2,columns2,a[100][100],b[100][100], num = 1, num2 = 1, k= 1, x= 1, y = 1,
sum[3][100],sparse[3][100] ,sparse2[3][100] , temp;

//=========================================Input Matrix 1 =========================================================

//getting the no of rows of first matrix
printf("Enter the number of rows in the matrix 1 \n");
scanf ("%d",&rows);

//getting the no of columns of first matrix
printf("Enter the number of columns in the matrix 1 \n");
scanf("%d",&columns);

//getting the input  of first matrix
for (i = 1;i <=rows;++i){
    for (j = 1;j <=columns; ++j){
            printf("Enter the element of row %d and column %d :    ",i,j);
         scanf("%d",&a[i][j]);

    //counting the non zero elements and forming the sparse of first matrix
    if(a[i][j] != 0){
        sparse[1][num] = i;
        sparse[2][num] = j;
        sparse[3][num] = a[i][j];
        num +=1;
    }
    }
}

//=============================================Input Matrix 2 =========================================================

//getting the no of rows of second matrix
printf("Enter the number of rows in the matrix 2 \n");
scanf ("%d",&rows2);

//getting the no of columns of second matrix
printf("Enter the number of columns in the matrix 2 \n");
scanf("%d",&columns2);

//getting the input  of second matrix
for (i = 1;i <=rows2;++i){
    for (j = 1;j <=columns2; ++j){
            printf("Enter the element of row %d and column %d :    ",i,j);
         scanf("%d",&b[i][j]);

    //counting the non zero elements and forming the sparse of second matrix
    if(b[i][j] != 0){
        sparse2[1][num2] = i;
        sparse2[2][num2] = j;
        sparse2[3][num2] = b[i][j];
        num2 +=1;
    }
    }
}

//==============================================Printing sparse matrices===================================

//printing the sparse of the first matrix
printf("The Sparse of the first matrix is: \n");
for (i = 1;i <=3;++i){
    for (j = 1;j <=num - 1; ++j){
            printf("%d \t",sparse[i][j]);
    }
    printf("\n");
}

//printing the sparse of the second matrix
printf("The Sparse of the second matrix is: \n");
for (i = 1;i <=3;++i){
    for (j = 1;j <=num2 - 1; ++j){
            printf("%d \t",sparse2[i][j]);
    }
    printf("\n");
}

//============================================adding 2 sparse matrices =============================

//checking if we can add
if(rows == rows2 && columns == columns2) {
//looping until any one of the columns ends
while(k <= (num - 1) && x <= (num2-1)){
        //checking if the rows of the 2 sparse matrices are equal
    if (sparse[1][k] ==  sparse2[1][x]){

      //checking if the columns are also equal
        if (sparse[2][k] == sparse2[2][x]){
            sum[1][y] = sparse[1][k];
            sum[2][y] = sparse[2][k];
            sum[3][y] = sparse[3][k] + sparse2[3][x];
               k+=1;
               x+=1;
               y+=1; //common variable for iteration of the resultant matrix
        }

        //if the columns are not equal
        else{
            //checking which element is smaller and adding it to the summation matrix
            if (sparse[2][k] < sparse2[2][x]){
                sum[1][y] = sparse[1][k];
            sum[2][y] = sparse[2][k];
            sum[3][y] = sparse[3][k] ;
                k+=1;
                y+=1;
            }

            else{
                sum[1][y] = sparse2[1][x];
            sum[2][y] = sparse2[2][x];
            sum[3][y] =  sparse2[3][x];
                x+=1;
                y+=1;        }
        }

    }

    //if rows are not equal
    else {

    //checking the smallest and add it to the resultant matrix
     if (sparse[1][k] < sparse2[1][x]){
                sum[1][y] = sparse[1][k];
            sum[2][y] = sparse[2][k];
            sum[3][y] = sparse[3][k] ;
                k+=1;
                y+=1;
            }

            else{
                sum[1][y] = sparse2[1][x];
            sum[2][y] = sparse2[2][x];
            sum[3][y] =  sparse2[3][x];
                x+=1;
                y+=1;
            }

        }
    }



  //printing the remaining elements
if (x>num2-1){
           while(k<=(num-1)){
        sum[1][y] = sparse[1][k];
       sum[2][y] = sparse[2][k];
       sum[3][y] = sparse[3][k];
       ++y;
       ++k;
    }

}
else{
 while(x<=(num2-1)){
        sum[1][y] = sparse2[1][x];
       sum[2][y] = sparse2[2][x];
       sum[3][y] = sparse2[3][x];
       ++x;
       ++y;
    }
}
}

else{
        printf("You  can't add different dimensional matrices");
}

//printing the summation of the 2 matrices
printf("The addition of the sparse matrices: \n");
for(i=1;i<=3;++i){
    for(j=1;j<= y-1;++j)
    {
        printf("%d \t",sum[i][j]);
    }
    printf("\n");
}

//==============================================transpose of the sparse matrix==============================

//transpose of the resultant matrix
for(j=1;j<= y-1;++j){
        temp = sum[1][j];
    sum[1][j] =sum[2][j];
sum[2][j] = temp;
}

//printing the transpose of the summation matrix
printf("The transpose of the added matrix \n");
for(i=1;i<= 3;++i){
    for(j=1;j<= y-1;++j)
    {
       printf("%d\t",sum[i][j]);
    }
    printf("\n");
}

//============================================sorting the sparse matrix=======================================

    for(i=1;i<= y-2;++i){

        if(sum[1][i] == sum[1][i+1]){
            if(sum[2][i] >sum[2][i+1]){
                    temp = sum[1][i] ;
            sum[1][i] = sum[1][i+1];
            sum[1][i+1] = temp;
            temp = sum[2][i] ;
            sum[2][i] = sum[2][i+1];
            sum[2][i+1] = temp;
            temp = sum[3][i] ;
            sum[3][i] = sum[3][i+1];
            sum[3][i+1] = temp;
            }
        }

        else{
            if(sum[1][i] >sum[1][i+1]){
                   temp = sum[1][i] ;
            sum[1][i] = sum[1][i+1];
            sum[1][i+1] = temp;
            temp = sum[2][i] ;
            sum[2][i] = sum[2][i+1];
            sum[2][i+1] = temp;
            temp = sum[3][i] ;
            sum[3][i] = sum[3][i+1];
            sum[3][i+1] = temp;
            }
        }
    }

    //printing the sorted transpose of the matrix
printf("The sorted transpose of the added matrix:\n");
for(i=1;i<= 3;++i){
    for(j=1;j<= y-1;++j)
    {
       printf("%d\t",sum[i][j]);
    }
    printf("\n");
}
}
