// 41	DSA04002	LŨY THỪA ĐẢO
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dao(ll  n){
    ll d=0,m=n;
    while(m){
        d=d*10+m%10;
        m/=10;
    }
    return d;
}
ll power(ll base, ll exp,ll mod) {
    if(exp == 0)
        return 1;
    ll p=power(base, exp/2,mod);
    p=(p*p)% mod;
    return (exp%2 == 0)?p:(base * p)%mod;
}

ll chuyen(string s){
    ll d=0,x=10;
    for(int i=0;i<s.length();i++){
        d=(s[i]-'0')+d*10;
        x*=x;
    }
    return d;
}
int main(){
    int t;
    cin>>t;
    ll n;
    while(t--){
        cin>>n;
        ll p = 1e9+7;
        
        cout<<power(n,dao(n),p)<<endl;
    }
}