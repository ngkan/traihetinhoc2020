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
        assert(l < r);
        // find min
        int pos = l;
        for(int i=l;i<=r;i++){
            if (a[i] < a[pos])
                pos = i;
        }
        int res = (int) 2e9;
        for(int i=l;i<=r;i++)
            if (i != pos)
                res = min(res, a[i]);
        cout << res << '\n';
    }
}