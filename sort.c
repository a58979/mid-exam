#include <stdio.h>
#include <stdlib.h>
#include <time.h> // �]�����o���ɶ����B��A�ҥH�n�[�W�o�� 

int main()
{
	int i, N, *V;
	time_t T=1;  
	
	//Create N random integers
	
	srand(time(&T));  //�]���̭����ݭn�@�ӫ��СA�ҥH�n�b�W����8��A�W�]�@���ܼƪ����� 
	N= 10;
	V=(int *) malloc(N *sizeof(int) );
	for(i=0;i<N;++i)
	{
		V[i] = rand() % 100;
		printf("%d,",V[i]);
		
	}
	printf("\n");
	
	// Bubble Sort�G���v[i]�Mv[j]�A�p�G v[i]>v[j]�A�h��ƥ洫
	// �N�O���ѥ���k�A�۾F������A���j�̩��k���A�̫�̤j�ȷ|�X�{�b�}�C�k�ݡC���j�B�z�|���ƧǪ� N-1 �Ӥ����C
	
	
}
