	// 19	DSA02001	DÃY SỐ 1
    #include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            cout<<"[";
            for(int j=0;j<n-i;j++){
                if(j==n-i-1)
                cout<<a[j];
                 else cout<<a[j]<<" ";
                a[j]+=a[j+1];
            }
            cout<<"]"<<endl;
        }   
    }
}