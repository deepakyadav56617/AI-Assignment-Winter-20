#include<stdio.h>
#include<stdlib.h>
int floor(int A[], float x)
{
    if(x>=0)
    {
        x=(int)(x);
        return x;
    }
    if(x<0)
    {
        x--;
        x=(int)(x);

        return x;
    }
}
int ceiling(int A[],int x)
{
    if(x>=0)
    {
        x=(int)(x);
        x=x+1;
        return x;
    }
    if(x<0)
    {
        x=(int)(x);
        return x;
    }
}
int main()
{
    int n,i,j,k,count1=0,count2=0;
    printf("How many element you want to enter in array:\n");
    scanf("%d",&n);
    int A[n];
    float x;
    printf("Enter the values of array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("for which value you want to find floor and ceiling:\n");
    scanf("%f",&x);
    j=floor(A,x);
    for(i=0;i<n;i++)
    {
        if(j==A[i])
        {
            count1++;
            printf("Floor is %d\n",A[i]);
        }
    }
    if(count1==0)
    {
        printf("Floor is not in array\n");
    }
    k=ceiling(A,x);
    for(i=0;i<n;i++)
    {
        if(k==A[i])
        {
            count2++;
            printf("Ceiling is %d\n",A[i]);
        }
    }
    if(count2==0)
    {
        printf("Ceiling is not in array\n");

    }

    return 0;


}
