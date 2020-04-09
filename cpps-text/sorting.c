//排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *array(int num[],int n){
    srand((unsigned int)time(0));
    /*
        int n;
        scanf("%d",&n);
    */
    for (int i = 0; i < n; i++)
    {
        num[i] = rand() % 100; //限定在100范围内
    }
    return num;
}

int* bubble(int *,int);//冒泡排序
int* selection(int *,int);//选择排序
int* insertion(int *,int);//插入排序
int* shell(int *,int);//希尔排序
int* merge(int *,int);//归并排序
int* fast(int *,int);//快速排序


int main()
{
    int n;
    int *num=NULL;
    num=array(num,n);
   


    return 0;
}

int* bubble(int num[],int n){
    for(int i=0;i<n;i++){
    //for(int i=n;i>1;i--)
    //for(int j=0;j<i-1;j++)
        for(int j=0;j<n;j++){
            if(num[j]>num[j+1]){
                int temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    return num;
}

int* selection(int num[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]>num[j]){
                int temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
    }
    return num;
}

int* insertion(int num[],int n){
    int j,temp;
    for(int i=1;i<n;i++){
        temp=num[i];
        for(j=i;(j>0)&&(num[j-1]>temp);j--){
            num[j]=num[j-1];
        }
        num[j]=temp;
    }
    return num;
}

int* shell(int num[],int n){
    int g=n;
    int i=0;
    int j;
    for(g>>=1;g>0;g>>=1){
        for(i=g;i<n;i++){
            int temp=num[i];
            for(j=i-g;j<n&&num[j]>temp;j-=g)
                num[g]=num[j];
            num[j]=temp;
        }
    }    

}