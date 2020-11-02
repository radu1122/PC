#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void memFree (int n, int **a, int *v, unsigned char **ab)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(a[i]);
        free(ab[i]);
    }
    free (a);
    free (ab);
    free (v);
}
int *alocareVector(int n)
{
    int *a = malloc(n * sizeof(int *));
    return a;
}
int **alocareCitireMatrice(int n, int *v)
{
    int j;
    int **a = (int **) malloc(n * sizeof(int *));
    if (a == NULL)
    {
        free(a);
        return NULL;
    }
    for(int i = 0; i < n; i++)
    {

        scanf("%d", &v[i]);

        a[i] = malloc(v[i] * sizeof(int *));

        if (a[i] == NULL)
        {
            for (int j = 0; j < i ; j++)
            {
                free(a[j]);
            }
            free(a);
            return NULL;
        }
        for (j = 0; j < v[i]; j++)
        {
            scanf("%x", &a[i][j]);
        }
    }
    return a;
}
unsigned char **alocareMatriceChar(int n, int *v, int **a)
{
    int j, k;
    unsigned char bytes[4];
    unsigned char **ab = (unsigned char **) malloc(n * sizeof(unsigned char *));
    if (ab == NULL)
    {
        free(ab);
        return NULL;
    }
    for(int i = 0; i < n; i++)
    {
        ab[i] = malloc(v[i]*4 * sizeof(unsigned char *));

        if (ab[i] == NULL)
        {
            for (int j = 0; j < i ; j++)
            {
                free(ab[j]);
            }
            free(ab);
            return NULL;
        }
        k = 0;
        v[i] = v[i] * 4;
        for (j = 0; j < v[i]; j=j+4)
        {
            bytes[3] = (a[i][k] >> 24) & 0xFF;
            bytes[2] = (a[i][k] >> 16) & 0xFF;
            bytes[1] = (a[i][k] >> 8) & 0xFF;
            bytes[0] = a[i][k] & 0xFF;
            ab[i][j] = bytes[0];
            ab[i][j+1] = bytes[1];
            ab[i][j+2] = bytes[2];
            ab[i][j+3] = bytes[3];
            k++;
        }
    }
    return ab;
}
void scriereMatrice(int n, int **a, int *v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i]; j++)
        {
            printf("%08X ", a[i][j]);
        }
        printf("\n");
    }
}
double medieHarta(int n, int **a, int *v)
{
    unsigned char bytes[4];
    int k;
    double sum = 0, key = 0;
    char str[4];
    int x;
    for (int j = 0; j < v[0]; j++)
    {
        bytes[0] = ((int)a[0][j] >> 24) & 0xFF;
        bytes[1] = ((int)a[0][j] >> 16) & 0xFF;
        bytes[2] = ((int)a[0][j] >> 8) & 0xFF;
        bytes[3] = (int)a[0][j] & 0xFF;
        for (k = 0; k < 4; k++)
        {
            sprintf(str,"%x",bytes[k]);
            if (strlen(str) != 1)
            {
                if ( str[0] == '8' || str[0] == '9' || (str[0] >= 'a' && str[0] <= 'f' )) {
                    x = (int)bytes[k] - 256;
                }
                else
                {
                    x = (int)bytes[k];
                }
            } else
            {
                x = (int)bytes[k];
            }
            sum = sum + x;
        }
    }

    for (int j = 0; j < v[n-1]; j++)
    {
        bytes[0] = ((int)a[n-1][j] >> 24) & 0xFF;
        bytes[1] = ((int)a[n-1][j] >> 16) & 0xFF;
        bytes[2] = ((int)a[n-1][j] >> 8) & 0xFF;
        bytes[3] = (int)a[n-1][j] & 0xFF;
        for (k = 0; k < 4; k++)
        {
            sprintf(str,"%x",bytes[k]);
            if (strlen(str) != 1)
            {
                if ( str[0] == '8' || str[0]== '9' || (str[0] >= 'a' && str[0] <= 'f' )) {
                    x = (int)bytes[k] - 256;
                }
                else
                {
                    x = (int)bytes[k];
                }
            } else
            {
                x = (int)bytes[k];
            }
            sum = sum + x;
        }
    }

    for (int i = 1; i < n-1; i++)
    {
        bytes[0] = ((int)a[i][0] >> 24) & 0xFF;
        bytes[1] = ((int)a[i][0] >> 16) & 0xFF;
        bytes[2] = ((int)a[i][0] >> 8) & 0xFF;
        bytes[3] = (int)a[i][0] & 0xFF;
        sprintf(str,"%x",bytes[3]);
        if (strlen(str) != 1)
        {
            if ( str[0] == '8' || str[0]== '9' || (str[0] >= 'a' && str[0] <= 'f' )) {
                x = (int)bytes[3] - 256;
            }
            else
            {
                x = (int)bytes[3];
            }
        } else
        {
            x = (int)bytes[3];
        }
        sum = sum + x;
    }

    for (int i = 1; i < n-1; i++)
    {
        bytes[0] = ((int)a[i][v[i]-1] >> 24) & 0xFF;
        bytes[1] = ((int)a[i][v[i]-1] >> 16) & 0xFF;
        bytes[2] = ((int)a[i][v[i]-1] >> 8) & 0xFF;
        bytes[3] = (int)a[i][v[i]-1] & 0xFF;
        sprintf(str,"%x",bytes[0]);
        if (strlen(str) != 1)
        {
            if ( str[0] == '8' || str[0]== '9' || (str[0] >= 'a' && str[0] <= 'f' )) {
                x = (int)bytes[3] - 256;
            }
            else
            {
                x = (int)bytes[0];
            }
        } else
        {
            x = (int)bytes[0];
        }
        sum = sum + x;
    }
    key = 2 * n + 4 * (v[0] + v[n - 1]) - 4;
    return sum/key;
}
void actionDelete (int **a)
{
    char c;
    int pos, lin;
    unsigned char bytes[4];
    scanf("%c", &c);
    scanf("%c", &c);
    scanf("%d", &lin);
    scanf("%d", &pos);
    pos--;
    if (c == 'C') {
        bytes[3] = (a[lin][pos / 4] >> 24) & 0xFF;
        bytes[2] = (a[lin][pos / 4] >> 16) & 0xFF;
        bytes[1] = (a[lin][pos / 4] >> 8) & 0xFF;
        bytes[0] = a[lin][pos / 4] & 0xFF;
        bytes[pos%4] = 0x00;
        a[lin][pos/4] = *(int *)bytes;
    }
    else
    {
        if (c == 'S')
        {
            if (pos % 2 == 0)
            {
                bytes[3] = (a[lin][pos / 2] >> 24) & 0xFF;
                bytes[2] = (a[lin][pos / 2] >> 16) & 0xFF;
                bytes[1] = (a[lin][pos / 2] >> 8) & 0xFF;
                bytes[0] = a[lin][pos / 2] & 0xFF;
                bytes[0] = 0x00;
                bytes[1] = 0x00;
                a[lin][pos/2] = *(int *)bytes;
            }
            else
            {
                bytes[3] = (a[lin][pos / 2] >> 24) & 0xFF;
                bytes[2] = (a[lin][pos / 2] >> 16) & 0xFF;
                bytes[1] = (a[lin][pos / 2] >> 8) & 0xFF;
                bytes[0] = a[lin][pos / 2] & 0xFF;
                bytes[2] = 0x00;
                bytes[3] = 0x00;
                a[lin][pos/2] = *(int *)bytes;
            }
        }
        else
        {
            bytes[3] = (a[lin][pos] >> 24) & 0xFF;
            bytes[2] = (a[lin][pos] >> 16) & 0xFF;
            bytes[1] = (a[lin][pos] >> 8) & 0xFF;
            bytes[0] = a[lin][pos] & 0xFF;
            bytes[0] = 0x00;
            bytes[1] = 0x00;
            bytes[2] = 0x00;
            bytes[3] = 0x00;
            a[lin][pos] = *(int *)bytes;
        }
    }
}
void actionSwap (int **a)
{
    char c;
    int pos, lin;
    unsigned char bytes[4], aux;
    scanf("%c", &c);
    scanf("%c", &c);
    scanf("%d", &lin);
    scanf("%d", &pos);

    if (c == 'S')
    {
        if (pos % 2 == 0)
        {
            bytes[3] = (a[lin][pos / 2] >> 24) & 0xFF;
            bytes[2] = (a[lin][pos / 2] >> 16) & 0xFF;
            bytes[1] = (a[lin][pos / 2] >> 8) & 0xFF;
            bytes[0] = a[lin][pos / 2] & 0xFF;
            aux = bytes[0];
            bytes[0] = bytes[1];
            bytes[1] = aux;
            a[lin][pos/2] = *(int *)bytes;

        }
        else
        {
            bytes[3] = (a[lin][pos / 2] >> 24) & 0xFF;
            bytes[2] = (a[lin][pos / 2] >> 16) & 0xFF;
            bytes[1] = (a[lin][pos / 2] >> 8) & 0xFF;
            bytes[0] = a[lin][pos / 2] & 0xFF;
            aux = bytes[2];
            bytes[2] = bytes[3];
            bytes[3] = aux;
            a[lin][pos/2] = *(int *)bytes;
        }
    }
    else
    {
        if(c == 'I')
        {
            bytes[3] = (a[lin][pos] >> 24) & 0xFF;
            bytes[2] = (a[lin][pos] >> 16) & 0xFF;
            bytes[1] = (a[lin][pos] >> 8) & 0xFF;
            bytes[0] = a[lin][pos] & 0xFF;

            aux = bytes[0];
            bytes[0] = bytes[3];
            bytes[3] = aux;

            aux = bytes[1];
            bytes[1] = bytes[2];
            bytes[2] = aux;

            a[lin][pos] = *(int *)bytes;
        }
    }
}
void actionModifyAdd (int **a, int *v, char c, int lin, int pos, int x)
{
    int i, newPos;
    unsigned char bytes[4];
    if (c == 'C')
    {
        newPos = pos / 4;
    }
    else
    {
        if (c == 'S')
        {
            newPos = pos / 2;
        }
        else
        {
            newPos = pos;
        }
    }
    newPos++;
    a[lin] = (int *)realloc(a[lin], newPos * sizeof(int *));
    for (i = v[lin]; i < newPos-1; i++)
    {
        a[lin][i] = 0;
    }
    v[lin] = newPos;
    bytes[3] = (x >> 24) & 0xFF;
    bytes[2] = (x >> 16) & 0xFF;
    bytes[1] = (x >> 8) & 0xFF;
    bytes[0] = x & 0xFF;
    a[lin][newPos-1] = *(int *)bytes;
}
void actionModify (int **a, int *v)
{
    char c;
    int pos, lin, x;
    unsigned char bytes[4];
    scanf("%c", &c);
    scanf("%c", &c);
    scanf("%d", &lin);
    scanf("%d", &pos);
    scanf("%x", &x);
    pos--;
    if (c == 'C')
    {
        if (pos/4 + 1 > v[lin])
        {
            actionModifyAdd(a, v, c, lin, pos, x);
        }
        else
        {
            bytes[3] = (a[lin][pos/4] >> 24) & 0xFF;
            bytes[2] = (a[lin][pos/4] >> 16) & 0xFF;
            bytes[1] = (a[lin][pos/4] >> 8) & 0xFF;
            bytes[0] = a[lin][pos/4] & 0xFF;
            bytes[pos % 4] = x & 0xFF;
            a[lin][pos/4] = *(int *)bytes;
        }
    }
    else
    {
        if (c == 'S')
        {
            if (pos/2 + 1 > v[lin])
            {
                actionModifyAdd(a, v, c, lin, pos, x);
            }
            else
            {
                bytes[3] = (a[lin][pos/2] >> 24) & 0xFF;
                bytes[2] = (a[lin][pos/2] >> 16) & 0xFF;
                bytes[1] = (a[lin][pos/2] >> 8) & 0xFF;
                bytes[0] = a[lin][pos/2] & 0xFF;
                if (pos % 2 == 0)
                {
                    bytes[0] = x & 0xFF;
                    bytes[1] = (x >> 8) & 0xFF;
                }
                else
                {
                    bytes[2] = x & 0xFF;
                    bytes[3] = (x >> 8) & 0xFF;
                }
                a[lin][pos/2] = *(int *)bytes;
            }
        }
        else
        {
            if (pos + 1 > v[lin])
            {
                actionModifyAdd(a, v, c, lin, pos, x);
            }
            else
            {
                bytes[3] = (x >> 24) & 0xFF;
                bytes[2] = (x >> 16) & 0xFF;
                bytes[1] = (x >> 8) & 0xFF;
                bytes[0] = x & 0xFF;
                a[lin][pos] = *(int *)bytes;
            }
        }
    }

}
void task2 (int **a, int *v)
{
    int k, i;
    char c;
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%c", &c);
        scanf("%c", &c);
        if (c == 'D')
        {
            actionDelete(a);
        }
        else
        {
            if (c == 'S')
            {
                actionSwap(a);
            }
            else
            {
                actionModify(a, v);
            }
        }
    }
}
int ElemCheck (int n, unsigned char **ab, int *v, int lin, int col)
{
    int sum = 0;
    if ((int)ab[lin][col] == 0)
    {
        sum++;
        ab[lin][col] = 1;
        if (col - 1 >= 0)
        {
            sum = sum + ElemCheck(n, ab, v, lin, col - 1);
        }
        if (col + 1 < v[lin])
        {
            sum = sum + ElemCheck(n, ab, v, lin, col + 1);
        }
        if ((lin - 1 >= 0) && (v[lin - 1] > col))
        {
            sum = sum + ElemCheck(n, ab, v, lin - 1, col);
        }
        if ((lin + 1 < n) && (v[lin + 1] > col))
        {
            sum = sum + ElemCheck(n, ab, v, lin + 1, col);
        }
    }
    else
    {
        return 0;
    }
    return sum;
}
void task3 (int n, unsigned char **ab, int *v, int *lin, int*col, int *sum)
{
    int i, j;
    int sumIntern = 0;
    *sum = 0;
    *lin = 0;
    *col = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < v[i]; j++)
        {
            sumIntern = ElemCheck(n, ab, v, i, j);
            if (sumIntern > *sum)
            {
                *sum = sumIntern;
                *lin = i;
                *col = j;
            }
        }
    }
}
int main()
{
    int n, **a, *v;
    unsigned char **ab;
    double m_a;
    int lin, col, sum;
    scanf("%d", &n);
    v = alocareVector(n);
    a = alocareCitireMatrice(n, v);
    m_a = medieHarta(n, a, v);
    task2(a, v);
    printf("task 1\n");
    printf("%.8lf", m_a);
    printf("\ntask 2\n");
    scriereMatrice(n, a, v);
    printf("task 3\n");
    ab = alocareMatriceChar(n, v, a);
    task3(n, ab, v, &lin, &col, &sum);
    printf("%d %d %d", lin, col, sum);
    memFree(n, a, v, ab);
    return 0;
}

