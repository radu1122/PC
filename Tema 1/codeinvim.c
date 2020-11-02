#include <stdio.h>

int readArray (int v[100], int c[100], int n, int *p)
{
    int i, x = -1, pos[100], a, y, s = 0;
    int k = -1;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == 10)
        {
            x++;
            pos[x] = i;
        }
        else
        {
            k++;
            v[k] = a;
        }
    }
    y = 0;
    k = -1;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (pos[y] == i)
        {
            y++;
            s = s + a*10;
        }
        else
        {
            k++;
            c[k] = 10*a - a*v[k];
            s = s + a*v[k];
        }
    }
    *p = s;
    k++;
    return k;
}
void selectionSort(int v[100], int n)
{
    int i, j, min_idx, x;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (v[j] < v[min_idx])
            {
                min_idx = j;
            }
        }
        x = v[min_idx];
        v[min_idx] = v[i];
        v[i] = x;
    }
}
int checkMin (int c[100], int n, int p_min, int p)
{
    int i = n - 1, m = 0;
    if (p_min <= p)
    {
        return 0;
    }
    while (i >= 0)
    {
        p = p + c[i];
        m++;
        if (p_min <= p)
        {
            return m;
        }
        i--;
    }
    return -1;
}
int main()
{
    int n, v[100], c[100], p = 0, p_min;
    scanf("%d", &n);
    n = readArray(v, c, n, &p);
    scanf("%d", &p_min);
    selectionSort(c, n);
    printf("%d", checkMin(c, n, p_min, p));
    return 0;
}
