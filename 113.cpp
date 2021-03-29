// 113	DSA01012	MÃ GRAY 1
#include<bits/stdc++.h>
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
#define endl "\n"
#define FOR(i,l,r) for(int i=l;i<=r;i++)
//code by vu minh anh
using namespace std;
void GreyCode(int n) {
    FOR(i,1,(1 << n)-1) {
        
        int val = (i ^ (i >> 1));

        bitset<32> r(val);

        string s = r.to_string();
        cout << s.substr(32 - n) << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    run(){  
        int n;
        cin>>n;
        GreyCode(n);
        cout<<endl;
    }
}