#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int m,n,max=20;
void getsparse(int arr[MAX][3])
{
    int row,col,vals;
    printf("Enter the rows and columns : ");
    scanf("%d %d",&row, &col);
    printf("Enter the non-zero triplets : ");
    scanf("%d",&vals);

    arr[0][0] = row;
    arr[0][1] = col;
    arr[0][2] = vals;
    for(int i=1;i<=vals;i++)
    {
        printf("Enter the triplets (row,column,value) : ");
        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
}
void addsparse(int a[m][3],int b[n][3],int c[max][3])
{
    int static i=1,j=1,k=1,m,n;
    if(a[0][0] != b[0][0] || a[0][1] != b[0][1])
    {
        printf("XX Matrix are not of same dimension XX");
        exit(0);
    }
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    m = a[0][2];
    n = b[0][2];
    while(i<=m && j<=n)
    {
        if(a[i][0]<b[j][0])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k++;
            i++;
        }
        else if(a[i][0]>b[j][0])
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k++;
            j++;            
        }
        else
        {
            if(a[i][1]<b[j][1])
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                k++;
                i++;
            }
            else if(a[i][1]>b[j][1])
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                k++;
                j++;
            }
            else
            {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = a[i][2]+b[j][2];
            i++;
            j++; 
            k++;
            }
            
        }
        
    }
    while(i<=m)
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }
    while(j<=n)
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }
    c[0][2] = k-1;
    for(int z=1;z<=c[0][2];z++)
    {
        printf("Addition Matrix (row,column,value) : %d %d %d\n",c[z][0],c[z][1],c[z][2]);
    }
}
int main()
{
    
    printf("Enter the max values in matrix A :");
    scanf("%d",&m);
    printf("Enter the max values in matrix B :");
    scanf("%d",&n);
    int a[m][3], b[n][3], c[max];
    getsparse(a);
    getsparse(b);
    addsparse(a,b,c);
}
