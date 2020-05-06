#include <bits/stdc++.h>
long double dp[500][500], ans = 0;
int nums;

int main()
{
    scanf("%d", &nums);
    nums -= 2;
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= 400; i++)
        dp[0][i] = dp[1][i] = 1;
    for (int i = 2; i <= nums; i++)
        for (int k = 2; k <= nums; k++)
            if (k < i)
                for (int j = 1; j <= i; j++)
                    dp[i][k] += (1 / ((long double)i)) * (dp[i - j][k - 1] * dp[j - 1][k - 1]);
            else
                dp[i][k] = 1;

    for (int i = 1; i <= nums; i++)
        ans += i * (dp[nums][i] - dp[nums][i - 1]);
    std::cout<<std::setprecision(12)<<10 * ans;
    return 0;
}
