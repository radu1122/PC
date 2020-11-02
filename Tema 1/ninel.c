#include <stdio.h>

int main()
{
    int n, i, xmax_impar = 0, x1, x2, x3;
    int xmin_par = 10000000;
    unsigned long int s = 0;
    double m_a = 0, m_s = 0;
    scanf("%d", &n);
    scanf("%d", &x1);
    scanf("%d", &x2);

    for (i = 2; i < n; i++)
    {
        scanf("%d", &x3);
        if (x1 < x2 && x2 > x3)
        {
            m_s++;
            s = s + x2;
            if (x2 > xmax_impar && (i - 1) % 2 == 1)
            {
                xmax_impar = x2;
            }
            if (x2 < xmin_par && (i - 1) % 2 == 0)
            {
                xmin_par = x2;
            }
        }
        x1 = x2;
        x2 = x3;
    }
    if (xmin_par == 10000000)
    {
        xmin_par = -1;
    }
    if (s != 0 && m_s != 0)
    {
        m_a = s / m_s;
    }
    else
    {
        xmin_par = 0;
    }
    printf ("%ld \n", s);
    printf ("%.7f \n", m_a);
    printf ("%d \n", xmax_impar);
    printf ("%d \n", xmin_par);

    return 0;
}
