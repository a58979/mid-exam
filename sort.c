#include <stdio.h>
#include <stdlib.h>
#include <time.h> // �]�����o���ɶ����B��A�ҥH�n�[�W�o�� 

int main()
{
	int i, j, N, *V, temp; // �U���X�{����J���n�O�o�g�b�o�� 
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
	
	for(i=0;i<N-1;++i) //�ѥ��ܥk�]�A����T���u�|���N-1�ӡA�]�N�O��10�ӥu�|����9�� 
	{
		if(V[i]>V[i+1]) // ��� (v[0],v[1]).....(v[8],v[9])�A�]�N�O�۳s����� 
		{
			temp = V[i]; // ���F�����쥻���N����m�Q�\���A�ҥH�n�h�g�@�ӳo�ӲĤT�̡A�~�i�洫�A�p�G��W�u�g�U��31,32�|�]���X�� 
			V[i] = V[i+1]; // ����j�����k�� 
			V[i+1] = temp; 
		} 
	}
	for(i=0;i<N;++i)
	{
		printf("%d,",V[i]);
	} 
	printf("\n");
	
	for(i=0;i<N-2;++i) //�ѥ��ܥk�]�A����T���u�|���N-1�ӡA�]�N�O��10�ӥu�|����9�� 
	{
		if(V[i]>V[i+1]) // ��� (v[0],v[1]).....(v[8],v[9])�A�]�N�O�۳s����� 
		{
			temp = V[i]; // ���F�����쥻���N����m�Q�\���A�ҥH�n�h�g�@�ӳo�ӲĤT�̡A�~�i�洫�A�p�G��W�u�g�U��31,32�|�]���X�� 
			V[i] = V[i+1]; // ����j�����k�� 
			V[i+1] = temp; 
		}
	}
	
	for(i=0;i<N;++i)
	{
		printf("%d,",V[i]);
	} 
	printf("\n"); // �`����@���ƻs�K�W...�o�˷|�ܷQ��... 
	//�ҥH�b���U�h�[�@��for�j��
	
	for(j=1;j<N;++j)
	{   // �b�o��W�[�@��for�j��A�ݭn��u����������M���tab��A�|�������Ჾ�@�� 
	
		for(i=0;i<N-j;++i) //�ѥ��ܥk�]�A����T���u�|���N-1�ӡA�]�N�O��10�ӥu�|����9�� 
		{
			if(V[i]>V[i+1]) // ��� (v[0],v[1]).....(v[8],v[9])�A�]�N�O�۳s����� 
			{
				temp = V[i]; // ���F�����쥻���N����m�Q�\���A�ҥH�n�h�g�@�ӳo�ӲĤT�̡A�~�i�洫�A�p�G��W�u�g�U��31,32�|�]���X�� 
				V[i] = V[i+1]; // ����j�����k�� 
				V[i+1] = temp; 
			} 
		}
		for(i=0;i<N;++i)
		{
			printf("%d,",V[i]);
		} 
		printf("\n");
	}
}
