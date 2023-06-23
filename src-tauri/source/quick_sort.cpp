#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;
long long int a[maxn];
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    m > n ? m = n : m = m;
    for (int i = n - 1; i >= n - m; i--)
    {
        printf("%lld%c", a[i], i == n - m ? '\n' : ' ');
    }
    return 0;
}