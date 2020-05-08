#include <bits/stdc++.h>
int seq[17];
long long calculate(const int n, const int k)
{
    seq[0] = 0;
    seq[1] = k - 1;
    for (int i = 2; i <= n; i++)
    {
        seq[i] = (seq[i - 2] + seq[i - 1]) * (k - 1);
    }
    return seq[n] + seq[n - 1];
}
using namespace std;
int main()
{
    FILE *up = freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    cout << calculate(n, k) << endl;
    return 0;
}
