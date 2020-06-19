/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include<stdio.h>
#define max 50
void mergesort(int[],int,int);
void Merge(int[],int,int,int);
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
   mergesort(A,l,h);
  
   printf("The sorted array is\n");
   for(i=0;i<n;i++)
      printf("%d\t",A[i]);  
    return 0;
}

void mergesort(int A[],int l,int h)
{
   if(l<h)
   {
      int mid=(l+h)/2;
      mergesort(A,l,mid);
      mergesort(A,mid+1,h);
      Merge(A,l,mid,h);
   }
}

void Merge(int A[],int l,int mid,int h)
{
   int n1,n2,i,j,k;
   n1=mid-l+1;
   n2=h-mid;
   int Left[n1],Right[n2];
   for(k=0;k<n1;k++)
      Left[k]=A[l+k];
      
   for(k=0;k<n2;k++)
      Right[k]=A[mid+1+k];
      
   i=0,j=0,k=l;
   while(i<n1&&j<n2)
   {
     if(Left[i]<=Right[j])
        A[k++]=Left[i++];
     else
        A[k++]=Right[j++];
   }
   while(i<n1)
      A[k++]=Left[i++];
   while(j<n2)
      A[k++]=Right[j++];
}

/*OUTPUT :
Enter number of elements of array :
5
Enter the elements-
4  10  -3  26  140
The sorted array is
-3      4       10      26      140
*/
