#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a[1000005];
int arr[1000005];
int ans;

int f[1000005][20];

vector <int> v[2000006];
int ptr[2000006];
int main(){
    iostream::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    s = '0' + s;
    //cerr << n << endl;
    v[1000000].push_back(0);

    for(int i=1;i<=n;i++){
        if (s[i] == '(')
            a[i] = a[i-1] + 1;
        else
            a[i] = a[i-1] - 1;
        f[i][0] = a[i];

        v[1000000+a[i]].push_back(i);
    }

    for(int k=1;k<20;k++)
        for(int i=0;i+(1<<k)-1<=n;i++){
            f[i][k] = min(f[i][k-1], f[i+(1<<(k-1))][k-1]);
        }
    auto get = [&](int l,int r){
        int k = (int) log2(r - l + 1);
        return min(f[l][k], f[r-(1<<k)+1][k]);
    };
    //cerr << "here\n";
    for(int i=0;i<n;i++){
        int x = 1000000 + a[i];

        if (ptr[x] >= v[x].size())
            continue;

        while(v[x][ptr[x]] < i)
            ptr[x] ++;
        
        

        int rep = 0;

        while(ptr[x] < v[x].size()){
            //cout << a[i] << ' '<< i << ' ' << v[x][ptr[x]] << ' ' << ptr[x] << ' ' << v[x].size() << endl;
            int low = get(i, v[x][ptr[x]]); 
            if (low < a[i])
                break;
            rep = v[x][ptr[x]] - i;
            arr[rep]++;
            ptr[x]++;
        }

        ans = max(ans, rep);
    }

    if (ans)
        cout << ans << ' ' << arr[ans];
    else
        cout << 0 << ' ' << 1;
}