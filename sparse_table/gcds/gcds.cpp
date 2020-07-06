#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100005];
int f[100005][20];
map<int,long long> g;

int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i],
        f[i][0] = a[i];
    
    for(int k=1;k<20;k++)
        for(int i=1;i+(1<<k)-1<=n;i++){
            f[i][k] = __gcd(f[i][k-1], f[i+(1<<(k-1))][k-1]);
        }
    
    auto get = [&](int l,int r){
        int k = (int) log2(r - l + 1);
        return __gcd(f[l][k], f[r-(1<<k)+1][k]);
    };

    for(int i=1;i<=n;i++){
        int idx = i;
        do{
            int cur_gcd = get(i, idx);
            int l = idx, r = n+1;
            while(l + 1 < r){
                int mid = (l + r) / 2;
                if (get(i, mid) == cur_gcd)
                    l = mid;
                else
                    r = mid;
            }
            g[cur_gcd] += r - idx;
            idx = r;
        } while(idx != n+1);
    }

    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << g[x] << '\n';
    }
}