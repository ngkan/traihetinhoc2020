#include <bits/stdc++.h>
using namespace std;

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
        int ans = a[l];
        for(int i=l;i<=r;i++)
            ans = min(ans, a[i]);
        cout << ans << '\n';
    }
}