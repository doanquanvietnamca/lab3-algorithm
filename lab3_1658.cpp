#include <bits/stdc++.h>
using namespace std;
int dp[910][8110];
int state[910][8110];
void build_table(){
    memset(dp, 101,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= 900; i++){
        for(int j = i; j <= 8100; j++){
            for(int k = 1; k<=9&&k<=i&&k*k<=j; k++){
                if(i-k > j-k*k)
                    break;
                if(dp[i][j] > dp[i-k][j-k*k]+1){
                    dp[i][j] = dp[i-k][j-k*k]+1;
                    state[i][j] = k;
                }
            }
        }
    }
}
int main(){
    build_table();
    int n, m;
    int T;
    cin >>T;
    while(T--){
        scanf("%d %d",&n, &m);
        if(n>m ||  n > 900 || m > 8100 || dp[n][m] > 100 ){
            cout<<"No solution"<<endl;
            continue;
        }
        int t;
        while(n&&m){
            t = state[n][m];
            printf("%d",t);
            n -= t; m -= t*t;
        }
        cout<<endl;
    }
    return 0;
}
