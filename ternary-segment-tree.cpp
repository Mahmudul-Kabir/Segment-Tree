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
    void build(ll a,ll b,ll node){
        if(a == b){
            str[node] = id[a];
            return;
        }
        ll left = node * 3;
        if(b - a == 1){
            build(a,a,left + 1);
            build(b,b,left + 2);
        }else{
            ll m1 = a + (b - a)/3;
            ll m2 = b - (b - a)/3;
            if(m2 == b) m2--;
            build(a,m1,left+1);
            build(m1+1,m2,left+2);
            build(m2+1,b,left+3); 
        }
        str[node] = fun(str[left + 1],str[left + 2],str[left + 3]);
        return;

    }
    ll query(ll a,ll b,ll l,ll r,ll node){
        if(b < l || a > r) return def;
        if(a >= l && b <= r){
            return str[node];
        }
        ll left = node * 3;
        if(b - a == 1) return fun(query(a,a,l,r,left + 1),query(b,b,l,r,left + 2));
        ll m1 = a + (b - a)/3;
        ll m2 = b - (b - a)/3;
        if(m2 == b) m2--;
        return fun(query(a,m1,l,r,left+1),query(m1+1,m2,l,r,left+2),query(m2+1,b,l,r,left+3)); 
    }
    tern_str(ll x,vector<ll > &v) : id(v){
        str.assign(x * 4,def);
        build(0,x-1,0);
        return;
    }
};
