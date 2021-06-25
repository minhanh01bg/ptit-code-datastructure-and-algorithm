#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define f first
#define s second
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define run() int test; cin>>test; cin.ignore(); while(test--)

#define FOR(i,a,b)                    	for (int i=a; i<=b; i++)
#define FOR2(i,a,b)                   	for (ll i=a; i<=b; ++i)
#define FORD(i,a,b) 					for (int i=a; i>=b; i--)
#define FORA(x,C) 						for (auto x:C)

#define reset(C) 						memset(C,0,sizeof(C))
#define clearQueue(C, x) 				C = queue<x> ()
#define Fill(C,a) 						fill(C.begin(), C.end(), a)


#define SORTC(C,check) 					sort(C.begin(), C.end(), check)

#define um(x,y) 				unordered_map<x,y> 
#define m(x,y) 					map<x,y> 
#define p(x,y) 					pair<x,y> 
#define us(x) 					unordered_set<x> 
#define vec(x) 					vector<x> 
#define vec2(C,x,y,token) 		vector<vector<token> > C(x, vector<token> (y, 0))
#define pq(x) 					priority_queue<x>
#define reverse_pq(x) 			priority_queue<x, vector<x>, greater<x> >

	// System

#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pause() system("pause");
using namespace std;
bool test[1001];int n,m;int a[1001][1001];
void DFS(int u){
    test[u]=true;
    FOR(i,1,n)
        if(a[u][i]&&!test[i])
            DFS(i);
}
bool tes(){
    FOR(i,1,n){
        if(!test[i]) return true;
    }
    return false;
}
void init(){
    FOR(i,1,n)
        test[i]=false;
}
void mi(){
    FOR(i,1,n){
        FOR(j,i+1,n){
            if(a[i][j]){
                a[i][j]=0;a[j][i]=0;
                DFS(1);if(tes()) cout<<i<<' '<<j<<" ";
                a[i][j]=1;a[j][i]=1;
                init(); 
            }
        }
    }
}
main(){
    faster();
    run(){
        
        cin>>n>>m;
        
        FOR(i,1,n)
            FOR(j,1,n)
                a[i][j]=0;
        int u,v;
        FOR(i,0,m-1){
            cin>>u>>v;
            a[u][v]=1;
            a[v][u]=1;
        }
        init();
        mi();
        cout<<endl;
    }
}