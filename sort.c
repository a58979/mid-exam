#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, N, *V;
	
	//Create N random integers
	
	N= 10;
	V=(int *) malloc(N *sizeof(int) );
	for(i=0;i<N;++i)
	{
		V[i] = rand() % 100;
		printf("%d,",V[i]);
		
	}
	printf("\n");
	
}
