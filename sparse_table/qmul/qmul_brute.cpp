#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9+7;
int n, q;
int a[100005];

int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 1;
        for(int i=l;i<=r;i++)
            ans = 1ll * ans * a[i] % MOD;
        cout << ans << '\n';
    }
}