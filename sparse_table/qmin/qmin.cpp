#include <bits/stdc++.h>
using namespace std;

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
            f[i][k] = min(f[i][k-1], f[i+(1<<(k-1))][k-1]);
        }
    
    auto get = [&](int l,int r){
        int k = (int) log2(r - l + 1);
        return min(f[l][k], f[r-(1<<k)+1][k]);
    };

    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << get(l, r) << '\n';
    }
}