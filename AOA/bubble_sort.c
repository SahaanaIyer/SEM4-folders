/* Sahaana Iyer
SE Computer
Batch B
8609 */

#include<stdio.h>
void bubble(int[],int);
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
    bubble(a,n);
    printf("The elements in sorted order is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
    
void bubble(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}

/* OUTPUT :
Enter the number of elements - 5
Enter the elements :
18 10 12 15 4
The elements in sorted order is :
4       10      12      15      18 */

