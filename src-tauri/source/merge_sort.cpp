#include <stdio.h>
#include <stdlib.h>

int a[110];
int n;

void merge(int a[], int tem[], int p, int q, int r)
{
    int i = p;
    int j = q + 1;
    int pos = p;
    while (i <= q && j <= r)
    {
        if (a[i] < a[j])
        {
            tem[pos++] = a[i++];
        }
        else
            tem[pos++] = a[j++];
    }
    while (i <= q)
        tem[pos++] = a[i++];
    while (j <= r)
        tem[pos++] = a[j++];
    while (p <= r)
    {
        a[p] = tem[p];
        p++;
    }
}
void print(int s[], int n)
{
    int t = 0;
    for (t = 0; t < n; t++)
    {
        printf("%d", s[t]);
        if (t == n - 1)
            printf("\n");
        else
            printf(" ");
    }
}
void msort(int a[], int tem[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        msort(a, tem, p, q);
        msort(a, tem, q + 1, r);
        merge(a, tem, p, q, r);
        print(a, n);
    }
}
void merge_sort(int a[], int n)
{
    int tem[n];
    msort(a, tem, 0, n - 1);
}
int main()
{
    int i = 0;
    while (~scanf("%d", &n))
    {
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        merge_sort(a, n);
    }
    return 0;
}