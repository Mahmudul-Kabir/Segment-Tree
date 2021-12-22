#include "bits/stdc++.h"

using namespace std;
using ll = long long;


struct tern_str{
    vector<ll> str,&id;
    ll def = 0;                                                 // default value
    ll fun(ll a,ll b){
        return a + b;                                           // change this function according to the query types.
    }
    ll fun(ll a,ll b,ll c){
        return fun(a,fun(b,c));
    }
    void make(ll a,ll b,ll node){
        if(a == b){
            str[node] = id[a];
            return;
        }
        ll left = node * 3;
        if(b - a == 1){
            make(a,a,left + 1);
            make(b,b,left + 2);
        }else{
            ll m1 = a + (b - a)/3;
            ll m2 = b - (b - a)/3;
            if(m2 == b) m2--;
            make(a,m1,left+1);
            make(m1+1,m2,left+2);
            make(m2+1,b,left+3); 
        }
        str[node] = fun(str[left + 1],str[left + 2],str[left + 3]);
        return;

    }
    ll que(ll a,ll b,ll l,ll r,ll node){
        if(b < l || a > r) return def;
        if(a >= l && b <= r){
            return str[node];
        }
        ll left = node * 3;
        if(b - a == 1) return fun(que(a,a,l,r,left + 1),que(b,b,l,r,left + 2));
        ll m1 = a + (b - a)/3;
        ll m2 = b - (b - a)/3;
        if(m2 == b) m2--;
        return fun(que(a,m1,l,r,left+1),que(m1+1,m2,l,r,left+2),que(m2+1,b,l,r,left+3)); 
    }
    tern_str(ll x,vector<ll > &v) : id(v){
        str.assign(x * 4,def);
        make(0,x-1,0);
        return;
    }
};
