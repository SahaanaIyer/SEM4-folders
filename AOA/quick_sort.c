/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include<stdio.h>
#define max 50
void quicksort(int[],int,int);
int partition(int[],int,int);

int main() 
{ 
   int A[max];
   int i,n,ch,l,h;
   printf("Enter number of elements of array :\n");
   scanf("%d",&n);
 
   printf("Enter the elements-\n");
   for(i=0;i<n;i++)
      scanf("%d",&A[i]);
      
   l=0;
   h=n-1;
   quicksort(A,l,h);
  
   printf("The sorted array is\n");
   for(i=0;i<n;i++)
      printf("%d\t",A[i]);
}

void quicksort(int A[],int l,int h)
{
   if(l<h)
   {
      int j=partition(A,l,h);
      quicksort(A,l,j-1);
      quicksort(A,j+1,h);
   }
}

int partition(int A[],int l,int h)
{
   int pivot,i,j,temp;
   pivot=A[l];
   i=l-1,j=h+1;
   while(i<j)
   {
      do{
         i++;
      }while(A[i]<pivot&&i<j);
      do{
         j--;
      }while(A[j]>pivot);
      
      if(i<j)
      {
         temp=A[i];
         A[i]=A[j];
         A[j]=temp;
      }
    }
    if(A[j]<=pivot)
    {
      temp=A[l];
      A[l]=A[j];
      A[j]=temp;
    }
   return j;
}

/*OUTPUT :
Enter number of elements of array :
5
Enter the elements-
4  10  -3  26  140
The sorted array is
-3      4       10      26      140
*/
