#include <stdio.h>
#include <stdlib.h>

int noZerosEnding(int n);

int main()
{
	int n = 0;
	printf("Input an integer: ");
	scanf("%d", &n);

	printf("No zeros ending value: %d\n", noZerosEnding(n));

	return 0;
}

int noZerosEnding(int n)
{
	if (n != 0)
	{
		// Until there is no zeros divide by 10
		while(n % 10 == 0)
		{
			n /= 10;
			printf("%d\n", n);
		}
	}

	return n;
}
