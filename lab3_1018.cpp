#include <iostream>
#include <vector>

using namespace std;
const int N = 105;
vector<int> node[N], weights[N];
int dp[N][N];
int remove_node(int u, int fa, int q)
{

    int weight = 0;
    for (int i = 0; i < node[u].size(); i++)
    {
        if (node[u][i] != fa)
        {
            weight += remove_node(node[u][i], u, q) + 1;
            for (int j = weight; j - 1; --j)
            {
                for (int k = j; k - 1; --k)
                {
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[node[u][i]][k - 1] + weights[u][i]);
                }

            }
        }
    }
    return weight;
}
void add_node(int x_tmp, int y_tmp, int z_tmp)
{
    node[x_tmp].push_back(y_tmp);
    node[y_tmp].push_back(x_tmp);
    weights[x_tmp].push_back(z_tmp);
    weights[y_tmp].push_back(z_tmp);
}
int main()
{
    //FILE *ip = freopen("input.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    
    int x_tmp, y_tmp, z_tmp;
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d%d", &x_tmp, &y_tmp, &z_tmp);
        add_node(x_tmp, y_tmp, z_tmp);
    }
    remove_node(1, -1, q);
    printf("%d\n", dp[1][q]);
    return 0;
}
