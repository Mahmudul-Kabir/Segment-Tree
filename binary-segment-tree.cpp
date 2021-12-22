#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct bin_str{
    vector<ll> str,&id;
    ll default = 0;
    ll fun(ll a,ll b){
        return a + b;                             // change this function according to query types. 
    }
    ll fun(ll a,ll b,ll c){
        return fun(a,fun(b,c));
    }
    void make(ll a,ll b,ll node){
        if(a == b){
            str[node] = id[a];
            return;
        }
        ll left = node * 2, mid = a + (b - a)/2;
        make(a,mid,left);
        make(mid+1,b,left+1);
        str[node] = fun(str[left],str[left + 1]);
        return;
    }
    ll que(ll a,ll b,ll l,ll r,ll node){
        if(b < l || a > r) return default;
        if(a >= l && b <= r) return str[node];
        ll left = node * 2, mid = a + (b - a)/2;
        return fun(que(a,mid,l,r,left),que(mid+1,b,l,r,left+1));
    }
    bin_str(ll x,vector<ll > &v) : id(v){
        str.assign(x * 4,default);
        make(0,x-1,1);
        return;
    }
};

