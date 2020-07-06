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

int fact[200005];
int inv[200005];

int main(){
    iostream::sync_with_stdio(0);
   
    fact[0] = 1;
    for(int i=1;i<=200000;i++)
        fact[i] = 1ll * fact[i-1] * i % MOD;
    for(int i=0;i<=200000;i++)
        inv[i] = binpow(fact[i], MOD - 2);

    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        cout << 1ll * fact[n+m] * inv[n] % MOD * inv[m] % MOD << '\n';
    }
}