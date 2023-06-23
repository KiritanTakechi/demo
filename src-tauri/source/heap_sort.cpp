#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int st[100010], en[100010];
int get(string s)
{
    return ((s[0] - '0') * 10 + s[1] - '0') * 3600 + ((s[3] - '0') * 10 + s[4] - '0') * 60 + (s[6] - '0') * 10 + s[7] - '0';
}
void ok(int a)
{
    int h = a / 3600, m = a % 3600 / 60, c = a % 60;
    if (h < 10)
        cout << 0;
    cout << h << ':';
    if (m < 10)
        cout << 0;
    cout << m << ':';
    if (c < 10)
        cout << 0;
    cout << c;
}
int cnt;
int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        string s;
        getline(cin, s);
        string a = s.substr(0, 8), b = s.substr(11, 8);

        st[cnt] = get(a);
        en[cnt++] = get(b);
    }
    sort(st, st + cnt);
    sort(en, en + cnt);
    int op = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (op < st[i])
            ok(op), cout << " - ", ok(st[i]), cout << endl;
        op = en[i];
    }
    if (op != 23 * 3600 + 59 * 60 + 59)
        ok(op), cout << " - 23:59:59" << endl;
    return 0;
}