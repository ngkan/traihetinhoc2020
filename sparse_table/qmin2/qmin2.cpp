#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100005];
pair<int,int> f[100005][20];

int main(){
    iostream::sync_with_stdio(0);
    a[0] = (int) 2e9;

    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i],
        f[i][0] = {i, 0};
    

    for(int k=1;k<20;k++)
        for(int i=1;i+(1<<k)-1<=n;i++){
            set <pair<int,int>> s;
            s.insert({a[f[i][k-1].first], f[i][k-1].first});
            s.insert({a[f[i][k-1].second], f[i][k-1].second});
            s.insert({a[f[i+(1<<(k-1))][k-1].first], f[i+(1<<(k-1))][k-1].first});
            s.insert({a[f[i+(1<<(k-1))][k-1].second], f[i+(1<<(k-1))][k-1].second});

            f[i][k].first = (*s.begin()).second;
            s.erase(s.begin());
            f[i][k].second = (*s.begin()).second;
        }
    
    auto get = [&](int l,int r){
        int k = (int) log2(r - l + 1);
        set <pair<int,int>> s;
        s.insert({a[f[l][k].first], f[l][k].first});
        s.insert({a[f[l][k].second], f[l][k].second});
        s.insert({a[f[r-(1<<k)+1][k].first], f[r-(1<<k)+1][k].first});
        s.insert({a[f[r-(1<<k)+1][k].second], f[r-(1<<k)+1][k].second});
        s.erase(s.begin());
        return (*s.begin()).first;
    };

    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << get(l, r) << '\n';
    }
}