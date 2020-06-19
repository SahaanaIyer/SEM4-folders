/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include<stdio.h>
#define max 50
void insertion(int[],int);
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
   insertion(A,n);
  
   printf("The sorted array is\n");
   for(i=0;i<n;i++)
      printf("%d\t",A[i]);  
   return 0;
}

void insertion(int A[],int n)
{
   int key,i,j;
   for(i=0;i<n;i++)
   {
     key=A[i];
     j=i-1;
     while(A[j]>key && j>=0)
     {
        A[j+1]=A[j];
        j--;
     }
     A[j+1]=key;
   }
} 

/*OUTPUT :
Enter number of elements of array :
5
Enter the elements-
4  10  -3  26  140
The sorted array is
-3      4       10      26      140
*/
