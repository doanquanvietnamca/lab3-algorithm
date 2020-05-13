#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 4007;

char st[maxn];
bool parolime[maxn][maxn], check[maxn];
int len, dp[maxn], par[maxn];

void parolime_func()
{
    int l, r;

    for (int i = 1; i <= len; i++)
    {
        parolime[i][i] = true;
        l = i - 1, r = i + 1;
        while ((l >= 1) && (r <= len) && (st[l] == st[r]))
        {
            parolime[l][r] = true;
            l--;
            r++;
        }
        l = i;
        r = i + 1;
        while ((l >= 1) && (r <= len) && (st[l] == st[r]))
        {
            parolime[l][r] = true;
            l--;
            r++;
        }
    }
}
void dynmic_program()
{
    dp[0] = 0;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (parolime[j][i] && (dp[i] > dp[j - 1] + 1))
            {
                par[i] = j - 1;
                dp[i] = dp[par[i]] + 1;
            }
        }
    }
    printf("%d\n", dp[len]);
}

void config()
{
    memset(parolime, false, sizeof(parolime));
    memset(check, false, sizeof(check));
    memset(par, 0, sizeof(par));
    memset(dp, INF, sizeof(dp));
}
void print()
{
    int vid = par[len];
    while (vid)
    {
        check[vid] = true;
        vid = par[vid];
    }
    for (int i = 1; i <= len; i++)
    {
        printf("%c", st[i]);
        if (check[i])
            printf(" ");
    }
    printf("\n");
}
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%s", st + 1);
    config();
    len = strlen(st + 1);
    parolime_func();
    dynmic_program();
    print();
    return 0;
}
