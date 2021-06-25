#include <bits/stdc++.h>

#define ll        long long

#define Unique(C)       C.erase(unique(C.begin(), C.end()), C.end())
#define FOR(i, m, n)    for(int i = m; i < n; ++i)
#define FORx(i,m,n,x)   for(int i = m; i < n; i += x)
#define FORD(i, m, n)   for(int i = m; i >= n; --i)
#define get(C,a)        FOR(i, 0, a) cin >> C[i]
#define print(C,a)      FOR(i, 0, a) cout << C[i]
#define faster()        cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()           int t; cin >> t; while (t--)

using namespace std; 
struct val  
{ 
    int first; 
    int second; 
}; 
  
map<pair<int, int>, int> m; 
   
int findMaxChainLen(struct val p[], int n, int prev, int pos) { 
      
    if (m.find({ pos, prev }) != m.end())  { 
        return m[{ pos, prev }]; 
    } 
  
    if (pos >= n) 
        return 0; 

    if (p[pos].first <= prev)  { 
        return findMaxChainLen(p, n, prev, pos + 1); 
    } 
  
    else { 
        int ans = max(findMaxChainLen(p, n,  p[pos].second, 0) + 1,  findMaxChainLen(p, n,  prev, pos + 1)); 
        m[{ pos, prev }] = ans; 
        return ans; 
    } 
} 
int maxChainLen(struct val p[], int n) { 
    m.clear(); 

    int ans = findMaxChainLen(p, n, 0, 0); 
    return ans; 
} 
int main() { 
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n; 
        val p[n]; 
        for(int i = 0;i < n; i++){
            cin >> p[i].first >> p[i].second;
        }
        cout << maxChainLen(p, n) << endl; 
    }
    
    return 0; 
}
// #include<bits/stdc++.h>
// using namespace std;
// bool cmp(pair<int,int>a,pair<int,int>b){
//     return a.first<b.first;
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int x[n],y[n];
//         pair<int,int>a[n];
//         for(int i=0;i<n;i++){
//             cin>>a[i].first>>a[i].second;
//         }
//         sort(a,a+n,cmp);
//         int lis[n];
//         for(int i=0;i<n;i++) 
//             lis[i]=1;

//         for(int i=0;i<n;i++){
            
//             for(int j=0;j<n;j++){
//                 if(a[i].second<a[j].first && lis[j]<lis[i]+1){
//                     lis[j]=lis[i]+1;
//                 }    
//             }
//         }
//         cout<<*max_element(lis,lis+n)<<endl;
//     }
// }