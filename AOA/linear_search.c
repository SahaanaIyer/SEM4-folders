/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include <stdio.h>
int main()
{
  int a[10], key, i=0, n;
  printf("Enter number of elements in the array - ");
  scanf("%d", &n);
  printf("Enter %d elements : \n", n);
  for (i=0; i<n; i++)
    scanf("%d", &a[i]);

  printf("Enter a number to be searched - \n");
  scanf("%d", &key);

  for (i=0; i<n; i++)
  {
    if (a[i] == key)    
    {
      printf("%d is present at location %d\n", key,i+1);
      break;
    }
  }
  if (i == n)
    printf("%d isn't present in the array\n", key);
  return 0;
}

/* OUTPUT :
Enter number of elements in the array - 5
Enter 5 elements :
15
7
68
60
14
Enter a number to be searched - 68
68 is present at location 3 */

