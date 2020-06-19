/*Sahaana Iyer
SE Comp
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int m,n,i,j,k;
	char x[10], y[10], P[10];
    int c[10][10]={0};
	char b[10][10];
    
    printf("Enter the length of the string X :\t");
    scanf("%d",&m);
    printf("Enter the string X :\t");
    scanf("%s",&x);
   
	printf("Enter the length of the string Y :\t");
    scanf("%d",&n);
    printf("Enter the string Y :\t");
    scanf("%s",&y);
    
    for(i=0; i<=m; i++)
    {
    	 c[i][0]=0;
    	 b[i][0]='.';
	}
    for(i=0; i<=n; i++)
    {
    	c[0][i]=0;
    	b[0][i]='.';
	}
    
    for(i=1; i<=m; i++)
    {
    	for(j=1; j<=n; j++)
        {
        	if(x[i-1]==y[j-1])
        	{
        		c[i][j]=c[i-1][j-1] + 1;
        		b[i][j]='\\' ; 
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='|';
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='-';
			}
		}
	}
    
    for(i=0; i<=m; i++)
    {
    	for(j=0; j<=n; j++)
            printf("%d \t",c[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=0; i<=m; i++)
    {
    	for(j=0; j<=n; j++)
            printf("%c \t",b[i][j]);
        printf("\n");
    }
    i=0;
    while(1)
    {
    	if(b[m][n]=='.')
    	   break;
    	else if(b[m][n]=='\\')
    	{
    		P[i]=x[m-1];
    		i++;
    		m--;
    		n--;
		}
		else if(b[m][n]=='|')
			m--;
		else if(b[m][n]=='-')
		    n--;
	}
	int len=strlen(P);
	printf("\nThe Longest Common Subsequence is : \n");
	for(i=len;i>=0;i--)
	    printf("%c",P[i]);
	return 0;
}

/* OUTPUT :
Enter the length of the string X :      6
Enter the string X :    acbaed
Enter the length of the string Y :      6
Enter the string Y :    abcabe
0       0       0       0       0       0       0
0       1       1       1       1       1       1
0       1       1       2       2       2       2
0       1       2       2       2       3       3
0       1       2       2       3       3       3
0       1       2       2       3       3       4
0       1       2       2       3       3       4

.       .       .       .       .       .       .
.       \       -       -       \       -       -
.       |       |       \       -       -       -
.       |       \       |       |       \       -
.       \       |       |       \       |       |
.       |       |       |       |       |       \
.       |       |       |       |       |       |

The Longest Common Subsequence is : 
acbe   */
