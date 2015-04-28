#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
    srand(time(NULL));
    int n =rand()%10;  //n : 0~9
    int N=2*n+1;       //N=1~19
    int data[N]; /*宣告data陣列，用來存放所輸入的5個整數 */
    int i, j, t;
    int nn = (N+1)/2 ;
    
    printf("== 氣泡排序法(由小到大排序)==\n\n");
    printf("共有%d個數字 \n",N);
    //printf("...請輸入五個數值(資料間空一格)...\n\n");
    /*輸入排序前的資料 */
    printf("排序前:");
    for (i=0;i<N;i++) /* 輸入的整數會依序存放在data[0]~data[4] */
    {
        //scanf("%d", &n); /* scanf_s() for C++ */
        data[i]=rand()%1000+1;
        printf("%d,", data[i]);
    }
    /*氣泡排序法 */    
    for(i=nn; i>=0;i--)
    {
             for(j=0;j<=i;j++)
             {
                              if (data[j]>data[j+1])
                              {
                                                    t=data[j];   /*交換資料*/
                                                    data[j]=data[j+1];
                                                    data[j+1]=t;
                              }
             }
    }
    /*印出排序後的資料*/
    printf("\n 排序後: \n");
    for(i=0; i<N;i++)
    {
                    printf("%d,", data[i]);
    }
    
    
    printf("中位數=%d ", data[nn-1]); 
    
    printf("\n\n");
    system("PAUSE");
    return 0;
} 

