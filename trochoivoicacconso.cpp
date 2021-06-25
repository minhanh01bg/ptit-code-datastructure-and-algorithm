#include<bits/stdc++.h>

#define Nothing					"mikey"
#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define MAX 20
 
int n;
int Bool[MAX] = { 0 };
int A[MAX];

void xuat() {
    for (int i = 1; i < n; i++)
        if(A[i]==A[i+1]-1||A[i]==A[i+1]+1) return;
    FOR(i,1,n) cout<<A[i];
    cout<<endl;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (!Bool[i]) {
            A[k] = i; 
            Bool[i] = 1;
            if (k == n)
                xuat();
            else
                Try(k + 1);
            Bool[i] = 0;
        }
    }
}
 
int main() {
    int t;
    cin>>t;
    while(t--){
        cin >> n;
        Try(1);
    }
}