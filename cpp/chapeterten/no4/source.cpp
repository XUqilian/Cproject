#include"head.h"

namespace ns
{
    // uninteraction version  非交互版本
    sales_st::sales_st(const double *ar, int n)
    {
        max = min = ar[n - 1];
        average = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            sales_d[i] = ar[i];
            average += sales_d[i] / n;
            if (sales_d[i] > max)
                max = sales_d[i];
            if (sales_d[i] < min)
                min = sales_d[i];
        }
    }

    // interactive version 交互版本
    void sales_st::setsales_st()
    {
        max = min = 0;
        for (int i = Quarters - 1; i >= 0; i--)
        {
            scanf("%f\t", &sales_d[i]);
            average += sales_d[i] / Quarters;
            if (0 == max && 0 == min)
                max = min = sales_d[i];
            else
            {
                if (sales_d[i] > max)
                    max = sales_d[i];
                if (sales_d[i] < min)
                    min = sales_d[i];
            }
        }
        // scanf("\naverage:%f\nmax:%f\nmin:%f\n",&average,&max,&min);
    }

    void sales_st::display()const
    {
        for (int i = Quarters; i; i--)
            printf("%f\t", sales_d[i]);
        printf("\naverage:%f\nmax:%f\nmin:%f\n", average, max, min);
    }
}
