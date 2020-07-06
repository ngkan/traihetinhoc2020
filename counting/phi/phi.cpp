#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    vector <int> prime;

    int tmp = x;
    for(int i=2; i*i <= tmp; i++){
        if (tmp % i == 0){
            prime.push_back(i);
            while (tmp % i == 0)
                tmp /= i;
        }
    }

    if (tmp > 1)
        prime.push_back(tmp);
    
    for(int v: prime)
        x = x / v * (v-1);
    
    cout << x;
}