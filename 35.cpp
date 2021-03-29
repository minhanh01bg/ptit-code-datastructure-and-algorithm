// 35	DSA03013	SẮP ĐẶT XÂU KÝ TỰ 2
#include<bits/stdc++.h>
using namespace std;
int isPossible(string str,int k) 
{ 
  
    // To store the frequency of 
    // each of the character 
    unordered_map<char, int> freq; 
  
    // To store the maximum frequency so far 
    int max_freq = 0; 
    for (int j = 0; j < (str.length()); j++) { 
        freq[str[j]]++; 
        if (freq[str[j]] > max_freq) 
            max_freq = freq[str[j]]; 
    } 
  
    // If possible 
    if ((max_freq)*(k-1) <= (str.length() - max_freq + 1)) 
        return true; 
    return false; 
} 
  
// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        string s;
        cin>>s;
        
        if(isPossible(s,k)) cout<<1;
        else cout<<-1;
        cout<<endl;
    }
    return 0; 
}