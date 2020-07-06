#include <bits/stdc++.h>
using namespace std;

const long long MOD = (long long) 1e9+7;

long long lcm(long long a, long long b){
    return a / __gcd(a, b) * b;
}
int main(){
    iostream::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--){
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        cout << n/a + n/b + n/c - n/lcm(a, b) - n/lcm(b,c) - n/lcm(c,a) + n/lcm(a,lcm(b,c)) << '\n';
    }
}