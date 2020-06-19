/*Sahaana Iyer
SE Computer
Batch B
8609*/
#include<stdio.h>

struct minmax
{
   int min,max;
};
struct minmax mL,mR,mfinal;
struct minmax mm(int[], int, int);

int main()
{
   int A[50],n,i;
   struct minmax res;
   printf("Enter no. of elements\n");
   scanf("%d",&n);
   printf("Enter elements\n");
   for(i=0; i<n; i++)
   {
      scanf("%d",&A[i]);
   }
   res=mm(A, 0, n-1);
   printf("Min element is %d\n", res.min);
   printf("Max element is %d\n", res.max);
   return 0;
}

struct minmax mm(int A[], int l, int h)
{
   int mid;
   if(l==h)
   {
      mfinal.min=A[l];
      mfinal.max=A[h];
      return mfinal;
   }
   else if(l+1==h)
   {
      if(A[l]<A[h])
      {
         mfinal.min=A[l];
         mfinal.max=A[h];
      }
      else
      {
         mfinal.min=A[h];
         mfinal.max=A[l];
      }
      return mfinal;
   }
   else
   {
      mid=(l+h)/2;
      mL=mm(A,l,mid);
      mR=mm(A,mid+1,h);
      
      if(mL.min<mR.min)
      {
          mfinal.min=mL.min;
      }
      else
      {
          mfinal.min=mR.min;
      }
      
      if(mL.max>mR.max)
      {
          mfinal.max=mL.max;
      }
      else
      {
          mfinal.max=mR.max;
      }
      return mfinal;
    }
}
/*OUTPUT :
Enter no. of elements
6
Enter elements
8 2 10 12 7 3 
Min element is 2
Max element is 12
*/

