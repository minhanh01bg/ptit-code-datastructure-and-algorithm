#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i <= n; ++i)
using namespace std;
bool isSquarePossible(int arr[], int n, int l)
{
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= l)
            cnt++;
        if (cnt >= l)
            return true;
    }
    return false;
}
int maxArea(int arr[], int n)
{
    int l = 0, r = n;
    int len = 0;
    while (l <= r) {
        int m = l + ((r - l) / 2);
        if (isSquarePossible(arr, n, m)) {
            len = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return (len * len);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        // int arr[] = {5, 2 ,4, 3, 3, 1, 4};
        int n;
        cin>>n;
        int arr[n];
        FOR(i,0,n-1) cin>>arr[i];
        cout << sqrt(maxArea(arr, n))<<endl;
    }
    return 0;
}