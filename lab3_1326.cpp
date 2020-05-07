#include <bits/stdc++.h>
using namespace std;
struct storeSet
{
    int value;
    int price;
} store[300];
int dp[2100000];
int taps = INT_MAX;
int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < 2100000; ++i)
    {
        dp[i] = INT_MAX;
    };
    int n;
    cin >> n;
    int count = n;
    int u, v, val, tmp, id = 0;
    for (int i = 1; i <= n; i++, id++)
    {
        cin >> val;
        store[id] = {(1 << i), val};
        dp[(1 << i)] = min(dp[(1 << i)], val);
    }
    int m;
    cin >> m;
    count += m;
    for (int i = 1; i <= m; i++, id++)
    {
        u = 0;
        cin >> val >> tmp;
        for (int k = 0; k < tmp; k++)
        {
            cin >> v;
            u = u | (1 << v);
        }
        dp[u] = min(dp[u], val);
        store[id] = {u, val};
    }
    cin >> tmp;
    int t = 0;
    for (int k = 0; k < tmp; k++)
    {
        cin >> v;
        t = t | (1 << v);
    }
    for (int i = 0; i < count; i++)
    {
        for (int k = 1; k < (1 << (n + 1)); ++k)
        {
            if (dp[k] != INT_MAX)
            {
                dp[(k | store[i].value)] = min(dp[(k | store[i].value)], dp[k] + store[i].price);
            }
        }
    }

    for (int i = 1; i < (1 << (n + 1)); ++i)
    {
        if ((i & t) == t)
        {
            taps = min(taps, dp[i]);
        }
    }
    cout << taps << "\n";
    return 0;
}
