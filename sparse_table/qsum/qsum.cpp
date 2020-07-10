#include <bits/stdc++.h>
using namespace std;


int n;
int a[50005];
int f[50005][17][4];

int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        for(int t=0;t<4;t++)
            f[i][0][t] = a[i];
    }
    for(int k=1;k<17;k++)
        for(int i=1;i+(1<<k)-1<=n;i++){
            // sum
            f[i][k][0] = f[i][k-1][0] + f[i+(1<<(k-1))][k-1][0];
            // left
            f[i][k][1] = max(f[i][k-1][1], f[i][k-1][0] + f[i+(1<<(k-1))][k-1][1]);
            // right
            f[i][k][2] = max(f[i+(1<<(k-1))][k-1][2], f[i][k-1][2] + f[i+(1<<(k-1))][k-1][0]);
            // largest
            f[i][k][3] = max(max(f[i][k-1][3], f[i+(1<<(k-1))][k-1][3]), f[i][k-1][2] + f[i+(1<<(k-1))][k-1][1]);
        }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int len = r-l+1;

        int h[] = {-(int) (2e9+123), 0, 0 ,0};

        for(int k=0;k<17;k++){
            if ((len >> k) & 1){
                if (h[0] == -(int) (2e9+123)){
                    for(int t=0;t<4;t++)
                        h[t] = f[l][k][t];
                }
                else{
                    int tmp[] = {h[0], h[1], h[2], h[3]};
                    #define g f[l][k]
                    tmp[0] = h[0] + g[0];
                    tmp[1] = max(h[1], h[0] + g[1]);
                    tmp[2] = max(g[2], h[2] + g[0]);
                    tmp[3] = max(max(h[3], g[3]), h[2] + g[1]);
                    #undef g

                    for(int t=0;t<4;t++)
                        h[t] = tmp[t];
                }

                l += (1<<k);
            }
        }

        cout << h[3] << '\n';
    }
}