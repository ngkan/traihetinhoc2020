#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9+7;
int n, q;
int a[100005];
int f[100005][20];

int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i],
        f[i][0] = a[i];
    
    for(int k=1;k<20;k++)
        for(int i=1;i+(1<<k)-1<=n;i++){
            f[i][k] = 1ll * f[i][k-1] * f[i+(1<<(k-1))][k-1] % MOD;
        }
    
    auto get = [&](int l,int r){
        int k = r - l + 1;
        int res = 1;
        for(int bit=0;bit<20;bit++){
            if ((k>>bit)&1){
                res = 1ll * res * f[l][bit] % MOD;
                l += (1<<bit);
            }
        }
        return res;
    };

    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << get(l, r) << '\n';
    }
}