#include <stdio.h>

//冒泡排序（英语：Bubble Sort）是一种简单的排序算法。它重复地走访过要排序的数列，
//一次比较两个元素，如果他们的顺序（如从大到小、首字母从A到Z）错误就把他们交换过来。

/*inline int swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

    return 0;
}
*/

int bubble_sort(int *array)
{

    for (int i = sizeof(array) / sizeof(array[0]); i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {

            if (array[j] > array[j + 1])
            {
                // swap(array[j],array[j+1]);
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return 0;
}

//选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。
//首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
//然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。

int selection_sort(int *array)
{
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        for (int j = i + 1; j <= sizeof(array) / sizeof(array[0]); j++)
        {

            if (array[j] < array[i])
            {
                // swap(array[j],array[i]);
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    return 0;
}

//插入排序（英语：Insertion Sort）是一种简单直观的排序算法。
//它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
//插入排序在实现上，通常采用in-place排序
//（即只需用到 {\displaystyle O(1)} {\displaystyle O(1)}的额外空间的排序），
//因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。
int insertion_sort(int *array)
{
    for (int i = 1; i <= sizeof(array) / sizeof(array[0]); i++)
    {
        for (int j = i - 1; j >= 0 && array[j] < array[i]; j--)
        {
            // for循环是一个&还是两个个&&
            // swap(array[j],array[i]);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    return 0;
}

int *insertion(int num[], int n)  //更快
{
    int j, temp;
    for (int i = 1; i < n; i++)
    {
        temp = num[i];

        for (j = i; (j > 0) && (num[j - 1] > temp); j--)
        {
            num[j] = num[j - 1];
        }
        num[j] = temp;
    }
    return num;
}


//希尔排序，也称递减增量排序算法，是插入排序的一种更高效的改进版本。希尔排序是非稳定排序算法
//希尔排序在数组中采用跳跃式分组的策略，通过某个增量将数组元素划分为若干组，
//然后分组进行插入排序，随后逐步缩小增量，继续按组进行插入排序操作，直至增量为1。
//希尔排序通过这种策略使得整个数组在初始阶段达到从宏观上看基本有序，小的基本在前，
//大的基本在后。然后缩小增量，到增量为1时，其实多数情况下只需微调即可，不会涉及过多的数据移动。

int shell_sort(int *array)
{
    for (int interval = (sizeof(array) / sizeof(array[0])) >> 1; interval > 0; interval >>= 1)
    {
        for (int t = 0; t < interval; t++)
        {
            for (int i = interval + t; i <= sizeof(array) / sizeof(array[0]); i+=interval)
            {
                for (int j = i - interval; j >= 0 && array[j] < array[i]; j-=interval)
                {
                    // for循环是一个&还是两个个&&
                    // swap(array[j],array[i]);
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
            }
        }
    }
    return 0;
}

//归并排序
//把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行。

//快速排序：在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，
//大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。

int main(void)
{

    return 0;
}