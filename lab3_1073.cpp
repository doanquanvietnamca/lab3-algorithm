#include <bits/stdc++.h>
int main(){
    int n , x=0;
    scanf("%d", &n);
    int * square = new int [n+1];
    square[0]=0;
    square[1] = 1;
    square[2] = 2;
    square[3] = 3;
    for (int i=4; i<= n;i++){
        square[i] = i;
        for (int j = 1; j <= ceil(sqrt(i)) ; j++){
            int temp = j*j;
            if(temp>i)break;
            else{
                square[i] = std::min(square[i], 1+ square[i - temp]);
            }
        }
    }
    printf("%d\n",square[n]);
}
