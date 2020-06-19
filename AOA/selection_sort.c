/* Sahaana Iyer
SE Computer
Batch B 
8609*/

#include<stdio.h>
void sel(int[],int);
int main()
{
    int a[10],n,i,j;
    printf("Enter the number of elements - \n");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sel(a,n);
    printf("The elements in sorted order is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
    
void sel(int a[],int n)
{
    int i,j,temp,min;
    for(i=0;i<n-1;i++)
    {
		min=i;
        for(j=i+1;j<n;j++)
        {
             if(a[j]<a[min])
             {
	     min=j;
              }
          }
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
    }
}

/* OUTPUT :
Enter the number of elements -
5
Enter the elements :
24 33 19 45 13
The elements in sorted order is :
13      19      24      33      45  */

