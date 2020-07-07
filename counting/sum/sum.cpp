#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9+7;

int binpow(int x,int p){
    if (p == 0)
        return 1;
    int t = binpow(x, p / 2);
    if (p % 2 == 0)
        return 1ll * t * t % MOD;
    else
        return 1ll * t * t % MOD * x % MOD;
}

int fact[300005];
int inv[300005];

int C(int k,int n){
    return 1ll * fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main(){
    iostream::sync_with_stdio(0);
   
    fact[0] = 1;
    for(int i=1;i<=300000;i++)
        fact[i] = 1ll * fact[i-1] * i % MOD;
    for(int i=0;i<=300000;i++)
        inv[i] = binpow(fact[i], MOD - 2);

    int test;
    cin >> test;
    while(test--){
        int n, S;
        cin >> n >> S;
        if (n > S)
            cout << 0 << '\n';
        else
            cout << C(n-1, S-1) << '\n';
    }
}