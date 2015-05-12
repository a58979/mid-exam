#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int Generate_N(int p, int q, int r);
int Print_Complex_Vector(double *y_r, double *y_i, int N);
int FFTm(double *x_r, double *x_i, double *y_r, double *y_i, int p,int q,int r,int N);

int main()
{
	int N, p, q, r;
	double *y_r, *y_i, *x_r, *x_i;
	clock_t t1, t2;
	printf("Please input p q r=");
	scanf("%d %d %d", &p, &q, &r);
	N = Generate_N(p, q, r);
	printf("N=2^%d 3^%d 5^%d = %d\n",p,q,r,N);
	x_r = (double *) malloc(N*sizeof(double));
	x_i = (double *) malloc(N*sizeof(double));
	y_r = (double *) malloc(N*sizeof(double));
	y_i = (double *) malloc(N*sizeof(double));
	
	for(int n=0;n<N;++n)
	{	x_r[n] = n;	}

	t1 = clock();
	FFTm(x_r, x_i, y_r, y_i,p,q,r, N);
	t2 = clock();
	printf("Fast FT3: %f secs\n", 1.0*(t2-t1)/CLOCKS_PER_SEC);	
	return 0;
}
int Generate_N(int p, int q, int r)
{
	int N = 1;
	for(;p>0;p--) N*=2; //N*=2 => N=N*2
	for(;q>0;q--) N*=3;
	for(;r>0;r--) N*=5;
	return N;
}

int Print_Complex_Vector(double *y_r, double *y_i, int N)
{
	int n;
	for(n=0;n<N;++n)
	{
		if (y_i[n] >=0) printf("%d : %f +%f i\n", n, y_r[n], y_i[n]);
		else printf("%d : %f %f i\n", n, y_r[n], y_i[n]);
	}
	return 0;
}

int FFTm(double *x_r, double *x_i, double *y_r, double *y_i,int p,int q,int r, int N)
{
	int i,j,k,n,group=1;
	int size=N;
	double t_r,t_i;

	for(n=0;n<N;++n)
	{
		y_r[n] = x_r[n];
		y_i[n] = x_i[n];
	}

	while(r>0)
	{
	for(i=0;i<group;i++)
		{
		for(j=0;j<5;j++)
			{
			for(k=0;k<size/5;k++)
				{
				y_r[i*size+j*size/5+k]=x_r[5*k+(i*size)+j];
				printf("i=%d,j=%d,k=%d",i,j,k);
				printf("i*size+j*size/5+k=%d,5*k+(i*size)+j=%d\n",i*size+j*size/5+k,5*k+(i*size)+j);
				}
			}
		}
		
		for(n=0;n<N;++n)
		{
		x_r[n]=y_r[n];
		x_i[n]=y_i[n];
		}

		r--;
		group=group*5;
		size=size/5;
		for(int z=0;z<N;z++)
		{printf("y_r[%d]=%f,x_r[%d]=%f \n",z,y_r[z],z,x_r[z]);}
	}
	while(q>0)
	{
	for(i=0;i<group;i++)
		{
		for(j=0;j<3;j++)
			{
			for(k=0;k<size/3;k++)
				{
				y_r[i*size+j*size/3+k]=x_r[3*k+(i*size)+j];
				printf("i=%d,j=%d,k=%d",i,j,k);
				printf("i*size+j*size/3+k=%d,3*k+(i*size)+j=%d\n",i*size+j*size/3+k,3*k+(i*size)+j);
				}
			}
		}
		
		for(n=0;n<N;++n)
		{
		x_r[n]=y_r[n];
		x_i[n]=y_i[n];
		}

		q--;
		group=group*3;
		size=size/3;
		for(int z=0;z<N;z++)
		{printf("y_r[%d]=%f,x_r[%d]=%f \n",z,y_r[z],z,x_r[z]);}

	}

	while(p>0)
	{
	for(i=0;i<group;i++)
		{
		for(j=0;j<2;j++)
			{
			for(k=0;k<size/2;k++)
				{
				y_r[i*size+j*size/2+k]=x_r[2*k+(i*size)+j];
				printf("i=%d,j=%d,k=%d",i,j,k);
				printf("i*size+j*size/2+k=%d,2*k+(i*size)+j=%d\n",i*size+j*size/2+k,2*k+(i*size)+j);
				}
			}
		}
		
		for(n=0;n<N;++n)
		{
		x_r[n]=y_r[n];
		x_i[n]=y_i[n];
		}
		p--;
		group=group*2;
		size=size/2;
	}

		for(int z=0;z<N;z++)
		{printf("y_r[%d]=%f,x_r[%d]=%f \n",z,y_r[z],z,x_r[z]);}


/*
	n = 2;
	while(n <= N)
	{
		for(k=0;k<n/2;k++)
		{
			theta = -2.0*k*M_PI/n;
			w_r = cos(theta);
			w_i = sin(theta);
			for(p=k;p<N;p+=n)
			{
				q = p+n/2;
				t_r = w_r*y_r[q]-w_i*y_i[q];
				t_i = w_r*y_i[q]+w_i*y_r[q];
				y_r[q] = y_r[p] - t_r;
				y_i[q] = y_i[p] - t_i;
				y_r[p] += t_r;
				y_i[p] += t_i;
			}
		}
		n <<= 1;
	}
*/
}
