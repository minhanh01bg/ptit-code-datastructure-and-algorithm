#include<bits/stdc++.h>
    #define ll long long
// test

    #define BEGIN() int t;cin>>t;while(t--)
    #define FAST() ios_base::sync_with_stdio(0);cin.tie(0);
	
// acronym
    #define pob pop_back
    #define EL printf("\n")
    #define pb push_back
    #define FOR(i,l,r) for (int i=l;i<=r;i++)
    #define FORD(i,r,l) for (int i=r;i>=l;i--)
    
    using namespace std;
#define MAX 11
int n;
int Bool[MAX] = { 0 };
int A[MAX];
int a[11],z=0;
ll k;
void read_data(){
    cin>>n>>k;
    FOR(i,1,n)
        cin>>a[i];
}
void xuat() {
    int b[11];
    ll s=a[1];
    FOR(i,1,n-1){
        if(A[i]==1&&A[i+1]!=3||a[n-1]==1){
            s+=a[i+1];
        }
        else if(A[i]==1&&A[i+1]==3){
            ll x=a[i+1];
            while(i<=n&&A[i+1]==3){
                x=x*a[i+2];
                i++;
            }
            s+=x;
        }
        else if(A[i]==2&&A[i+1]!=3){
            s-=a[i+1];
        }
        else if(A[i]==2&&A[i+1]==3){
            ll x=a[i+1];
            while(i<=n&&A[i+1]==3){
                x=x*a[i+2];
                i++;
            }
            s-=x;
        }
        else if(A[1]==3){
            while(i<n&&A[i]==3){
                s*=a[i+1];
                i++;
            }
            i--;
        }
    }
    if(s==k){
        z=1;
        FOR(i,1,n) {
            if(a[i]<0)
                cout<<"("<<a[i]<<")";
            else cout<<a[i];
            if(i==n) continue;
            if(A[i]==1) cout<<"+";
            else if(A[i]==2) cout<<"-";
            else cout<<"*";
        }
        cout<<"="<<k;
        cout<<endl;
    }
}
 
void Try(int k) {
    for (int i = 1; i <= 3; i++) {
            A[k] = i; 
            if (k == n-1) xuat();
            else Try(k + 1);
    }
}
 
int main() {
    read_data();
    Try(1);
    if(z==0) cout<<"IMPOSSIBLE";
}