#include <bits/stdc++.h>
using namespace std;
int dp[112345];
int state[112345];
int card[101];
bool flag[101];
int v,n;
int main(){
    //FILE* ip = freopen("input.txt","r", stdin);
    scanf("%d%d",&v,&n);// input data
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        scanf("%d",&card[i]);
        for(int j = v-card[i]; j >= 0; --j){
            if(dp[j]){
                if(!dp[j+card[i]] && dp[j]+1){
                    dp[j+card[i]] = 1;
                    state[j+card[i]] = i;
                }
                else dp[j+card[i]] = -1;
            }
        }
    }
    if(dp[v] > 0){
        while(v){
            flag[state[v]] = 1;
            v -= card[state[v]];
        }
        for(int i = 1; i <= n; ++i){
            if(flag[i]) continue;
            printf("%d ",i);
        }
    }
    else printf("%d",dp[v]);
    printf("\n");
    return 0;
}
