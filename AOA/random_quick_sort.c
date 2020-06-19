/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include<stdio.h>
int partition(int [], int, int);
void quicksort(int [], int, int);
int main()
{
   int n, a[10], i;
   printf("Enter no. of elements\n");
   scanf("%d", &n);
   printf("Enter the elements\n");
   for(i=0; i<n; i++)
   scanf("%d", &a[i]);
   quicksort(a, 0, n-1);
   printf("The elements in sorted list are : \n");
    for(i=0; i<n; i++)
    printf("%d   ", a[i]);
    return 0;
}

void quicksort(int a[], int l, int h)
{
   if(l<h)
   {
      int j = partition(a, l, h);
      quicksort(a, 0, j-1);
      quicksort(a, j+1, h);
   }
}

int partition(int a[], int l, int h)
{
   int i,j,pivot,temp;
   int r = rand()%(h-l) + l;

   temp = a[l];
   a[l] = a[r];
   a[r] = temp;
   pivot = a[l];  
   i = l;
   j = h;
   while(i<j)
   {
      while(a[i] <= pivot && i<h)
          i++;
      while(a[j] > pivot)
          j--;
      if(i<j)
      {
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }  
   }
   temp = a[j];
   a[j] = a[l];
   a[l] = temp;
   return j;
}

/*OUTPUT:
Enter no. of elements
5
Enter the elements
5 2 10 12 7
The elements in sorted list are :
2  5  7  10  12
*/

Displaying quicksort.c.
