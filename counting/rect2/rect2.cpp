#include <bits/stdc++.h>
using namespace std;

int n;
int x[2][22], y[2][22];

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> x[0][i] >> y[0][i] >> x[1][i] >> y[1][i];
    
    long long ans = 0;
    for(int mask=1;mask<(1<<n);mask++){
        int min_x = 0, max_x = (int) 1e9, min_y = 0, max_y = (int) 1e9;
        for(int bit=0;bit<n;bit++){
            if ((mask>>bit)&1){
                min_x = max(min_x, x[0][bit]);
                max_x = min(max_x, x[1][bit]);
                min_y = max(min_y, y[0][bit]);
                max_y = min(max_y, y[1][bit]);
            }
        }
        if (min_x > max_x || min_y > max_y)
                continue;

        if (__builtin_popcount(mask) % 2)   // so bit bat cua mask
            ans += 1ll * (max_x - min_x) * (max_y - min_y);
        else
            ans -= 1ll * (max_x - min_x) * (max_y - min_y);
    }
    cout << ans;
}