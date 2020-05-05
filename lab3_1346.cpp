#include <bits/stdc++.h>
using namespace std;
int a, b, n, x, state[100007], dp[100007];
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
bool check_monoton(int i)
{
    if (sgn(state[i] - state[i - 1])*sgn(state[i - 1]-state[i - 2])>0)
        return true;
    else
        return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &a, &b);
    int index = 0;
    n = b - a + 1;
    state[0] = -1000007;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (x != state[index])
            state[++index] = x;
    }
    memset(dp, 0, sizeof(dp));
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= index;)
    {
        if (check_monoton(i))
        {
            dp[i++] = dp[i - 1];
        }
        else
        {
            dp[i + 1] = dp[i] = dp[i - 1] + 1;
            i += 2;
        }
    }
    printf("%d\n", dp[index]);
    return 0;
}
