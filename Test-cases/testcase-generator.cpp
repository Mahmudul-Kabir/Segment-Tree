/*
              Testcase generator. Change the seed in srand() function to get a different testcase.
*/

#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"

using namespace std;
using ll = long long; 

const ll mod = 100000000007;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("output.txt","w",stdout);
#endif
    srand(3);                         // change seed. 
    int n = 100000, q = 1000000; 
    ll xx = rand() % n; 
    ll c = rand() % mod,cur = 1; 
    cout<<n sp<<q el; 
    for(int i = 0; i < n; i++) cout<<rand() % mod sp; 
    while(q--){
        cur = ((cur * xx) + c) % n;
        while(cur == 0) cur = ((cur * xx) + c) % n; 
        ll a,b; b = cur; a = rand() % b;
        cout<<a sp<<b el; 
    }
    return 0;
}
