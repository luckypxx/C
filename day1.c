#include <stdio.h>
#include <math.h>
int main ()
{
	int i=0,j=0;
	for (i=1000;i<=2000;i++)
		{
			if (i%4==0)
			printf ("%d\n",i);
		}
	/*int i=0,j=0;
	for(i=1;i<10;i++)
		{
			for (j=1;j<10;j++)
				{
					if (j<=i)
						printf("%d*%d=%2d ",i,j,i*j);
				}
			printf("\n");
		}*/
	/*int i=0,j=0;
	for (i=101;i<201;i+=2)
		{
			for (j=3;j<=sqrt(i);j++)
				{
					if (i%j==0)
					break;
				}
			if (j>sqrt(i))
			printf("%d\n",i);
		}*/
	return 0;
}
