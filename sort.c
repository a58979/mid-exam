#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 因為有牽扯到時間的運算，所以要加上這行 

int main()
{
	int i, N, *V;
	time_t T=1;  
	
	//Create N random integers
	
	srand(time(&T));  //因為裡面的需要一個指標，所以要在上面第8行再增設一個變數的指標 
	N= 10;
	V=(int *) malloc(N *sizeof(int) );
	for(i=0;i<N;++i)
	{
		V[i] = rand() % 100;
		printf("%d,",V[i]);
		
	}
	printf("\n");
	
	// Bubble Sort：比較v[i]和v[j]，如果 v[i]>v[j]，則兩數交換
	// 就是說由左到右，相鄰兩兩比較，較大者往右挪，最後最大值會出現在陣列右端。遞迴處理尚未排序的 N-1 個元素。
	
	
}
