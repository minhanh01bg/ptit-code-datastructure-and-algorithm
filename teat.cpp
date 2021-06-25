#include<bits/stdc++.h>
#define ll long long
	// test
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
	// acronym
#define pob pop_back
#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
using namespace std;
int a[1001][1001];
bool ok[1001];
int U,V;
void kt(){
    FOR(i,1,U)
        ok[i]=false;
}
bool x=false;
void DFS(int u){
    ok[u]=true;
    FOR(i, 1, U){
        if(a[u][i]==1&&ok[i])
            x=true;
        else if(a[u][i]==1 &&!ok[i])
            DFS(i);  
    }
}
int main(){
    fast()
    run(){
        cin>>U>>V;
        int u,v;
        kt();
        FOR(i,1,U){
            FOR(j,1,U)
                a[i][j]=0;
        }
        FOR(i,1,V){
            cin >> u >> v; 
            a[u][v]=1;
            a[v][u]=1;
        }
        x=false;
        int d=0;
        FOR(i,1,U){
            kt();
            DFS(i);
            if(x==true) {
                cout<<"YES";
                break;
            }
        }
        if(x==false) cout<<"NO";
        cout<<endl;
    }
}