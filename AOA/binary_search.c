/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include <stdio.h>
int main()
{
  int i, l, h, mid, n, key, a[10];
  printf("Enter the number of elements - \n");
  scanf("%d", &n);
  printf("Enter %d elements : \n", n);
  for (i=0; i<n; i++)
    scanf("%d", &a[i]);
  printf("Enter the value to be searched - \n");
  scanf("%d", &key);
  l = 0;
  h = n-1;
  mid = (l+h)/2;
  while (l <= h) 
  {
    if(a[mid] < key)
      l = mid+1;
    else if (a[mid] == key)
    {
      printf("%d found at location %d\n", key, mid+1);
      break;
    }
    else
      h = mid-1;
    mid = (l+h)/2;
  }
  if(l > h)
    printf("%d is not present in the array\n", key);
  return 0;
}

/*OUTPUT :
Enter the number of elements -
5
Enter 5 elements :
14
68
71
5
90
Enter the value to be searched -
68
68 found at location 2  */

