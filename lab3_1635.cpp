#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e3+7;

char s[maxn];
bool is[maxn][maxn], vis[maxn];
int len, dp[maxn], ans[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    while(~scanf("%s", s+1))
    {
        memset(is, 0, sizeof(is));
        memset(vis, 0, sizeof(vis));
        getchar();
        len = strlen(s+1);
        for(int i = 1; i <= len; i++)
        {
            is[i][i] = true;
            int l = i - 1, r = i + 1;
            while(l>=1&&r<=len&&s[l] == s[r])
            {
                is[l][r] = true;
                l--; r++;
            }
            l = i; r = i+1;
            while(l>=1&&r<=len&&s[l] == s[r])
            {
                is[l][r] = true;
                l--; r++;
            }
        }
        memset(ans, 0, sizeof(ans));
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for(int l = 1; l <= len; l++)
        {
            for(int i = 1; i <= l; i++)
            {
                if(is[i][l]&&dp[l] > dp[i - 1] + 1)
                {
                    dp[l] = dp[i - 1] + 1;
                    ans[l] = i - 1;
                }
            }
        }
        printf("%d\n", dp[len]);
        int pre = ans[len];
        while(pre)
        {
            vis[pre] = true;
            pre = ans[pre];
        }
        for(int i = 1; i <= len; i++)
        {
            printf("%c", s[i]);
            if(vis[i]) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
