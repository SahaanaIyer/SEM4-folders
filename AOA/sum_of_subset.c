/*Sahaana Iyer
SE Computer
Batch B
8609*/
#include<stdio.h>
#define M 53

int check_cap(int sum, int rem_weight)
{
	if(sum <= M && rem_weight >= 0)
		return 1;
	return 0;
}

void print_set(int weights[], int set[], int N)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d ",set[i]);
	printf("-> ");
	printf("{");
	for(i=0;i<N;i++)
	{
		if(set[i])
			printf("%d,",weights[i]);
	}
	printf("\b}\n");
}

void subsets(int weights[], int set[], int i, int sum, int rem_weight, int N)
{
	if(sum == M)
		print_set(weights, set, N);
	else if(i<N)
	{
		if(check_cap(sum + weights[i], rem_weight - weights[i]))
		{
			set[i] = 1;
			subsets(weights, set, i+1, sum + weights[i], rem_weight - weights[i],N);
			set[i] = 0;
		}
		subsets(weights, set, i+1, sum, rem_weight - weights[i], N);
	}
}

int main()
{
	int i,n;
	int weights[10];
	int set[10]={0};
	int total_weight = 0;
    printf("Enter the number of weights :\t");
    scanf("%d",&n);
    printf("Enter %d weights :\n",n);
	for(i=0;i<n;i++)
	    scanf("%d",&weights[i]);	
	for(i=0;i<n;i++)
		total_weight += weights[i];

	printf("Subsets are : \n");
	subsets(weights, set, 0, 0, total_weight, n);
	return 0;
}

/* OUTPUT:
Enter the number of weights :   8
Enter 8 weights :
15 22 14 26 32 9 16 8
Subsets are :
1 1 0 0 0 0 1 0 -> {15,22,16}
1 0 1 0 0 0 1 1 -> {15,14,16,8}
0 1 1 0 0 1 0 1 -> {22,14,9,8}   */
