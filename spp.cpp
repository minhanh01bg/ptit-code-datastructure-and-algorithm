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
int a[1001][1001],n,u;
void init(){
	int V;
    cin>>n>>V;
	int u,v;
	FOR(i,1,n)
		FOR(j,1,n)
			a[i][j]=0;
	FOR(i,1,V){
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=1;
	}	
}
bool ktra(){
    int i,j,s,d;
    d=0;
    FOR(i, 1, n){
        s=0;
        FOR(j, 1, n){
            s += a[i][j];
        }
        if(s%2) return false;
    }
    return true;
}
bool kmtra(){
    int i,j,s,d;
    d=0;
    FOR(i,1,n){
        s=0;
        FOR(j,1,n){
            s+=a[i][j];
        }
        if(s%2) d++;
    }
    if(d!=2) return false;
    return true;
}

int main(){
    FAST()
	BEGIN(){
		init();
		if(ktra()){
			cout<<1<<endl;	
			continue;
		}
		cout<<0<<endl;
	}
}