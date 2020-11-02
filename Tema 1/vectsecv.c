#include <stdio.h>

void printArray(int v[100], int n, int x)
{
    int i;
    for (i = x; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}
void selectionSort(int v[9], int n)
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
int getCif (int v[9], int n)
{
    int i = -1;
    while (n != 0)
    {
        i++;
        v[i] = n % 10;
        n = n / 10;
    }
    i++;
    return i;
}
int findInArray (int secv[100], int x, int n)
{
    int i = 0;
    while (i < n)
    {
        if (secv[i] == x)
        {
            return i;
        }
        i++;
    }
    return -1;
}
int main()
{
    int n, n_crescator, n_descrescator, dif = -1, cif[9], secv[100], sw = 1, cifNr = 0, i, x = -1;
    scanf("%d", &n);
    while (sw)
    {
        cifNr = getCif (cif, n);
        selectionSort (cif, cifNr);
        n_crescator = 0;
        n_descrescator = 0;
        for (i = 0; i < cifNr; i++)
        {
            n_crescator = n_crescator * 10 + cif[i];
            n_descrescator = n_descrescator * 10 + cif[cifNr-1-i];
        }
        n = n_descrescator - n_crescator;
        x++;
        secv[x] = n;
        if (x != 0)
        {
            dif = findInArray(secv, n, x);
        }
        if (dif != -1)
        {
            printf("%d \n", dif);
            printArray(secv, x, dif);
            sw = 0;
        }
    }
    return 0;
}
