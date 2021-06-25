// #include <bits/stdc++.h>
// #define FOR(i,a,b)                    	for (int i=a; i<=b; i++)
// #define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

// using namespace std;

// bool isParenthesis(char c) {
//     return ((c == '(') || (c == ')'));
// }

// bool isValidString(string str) {
//     int cnt = 0;
//     for (int i = 0; i < str.length(); i++) {
//         if (str[i] == '(')
//             cnt++;
//         else if (str[i] == ')')
//             cnt--;
//         if (cnt < 0)
//             return false;
//     }
//     return (cnt == 0);
// } 
// int test(string str){
//     int dem=0;
//     stack<int>st;
//     st.push(-1);
//     for(int i=0;i<str.size();i++){
//         if(str[i]=='(') st.push(i);
//         else
//         {
//             st.pop();
//             if(st.size()>0){
//                 dem=max(dem,i-st.top());
//             }
//             if(st.size()==0) st.push(i);
//         }
//     }
//     return dem;
// }
// bool test11(string str){
//     FOR(i,0,str.length()-1)
//         if(str[i]==')'||str[i]=='(')
//             return true;
//     return false;
// }
// int x=0;
// void removeInvalidParenthesis(string str) {
//     if (str.empty())
//         return ;
//     set<string> visit;
//     queue<string> q;
//     string temp;
//     bool level;
//     q.push(str);
//     visit.insert(str);
//     while (!q.empty()) {
//         str = q.front();  q.pop();
//         if (isValidString(str)) { 
//             cout << str << " ";
//             if(str!="") x=1;
//             level = true;
//         }
//         if (level)
//             continue;
//         for (int i = 0; i < str.length(); i++) {
//             if (!isParenthesis(str[i]))
//                 continue;
//             temp = str.substr(0, i) + str.substr(i + 1);
//             if (visit.find(temp) == visit.end()) {
//                 q.push(temp);
//                 visit.insert(temp);
//             }
//         }
//     }  
// }

// main(){
//     int t;
//     cin>>t;string str;
//     cin.ignore();
//     while(t--){
//         getline(cin,str);
//         int dem=0;
//         FOR(i,0,str.size()-1){
//             if(str[i]!=')'&&str[i]!='(')
//                 dem++;
//         }
//         if(test(str)==str.size()-dem||str==""||test11(str)==0) {
//             cout<<-1<<endl;
//             continue;
//         }
//         removeInvalidParenthesis(str);
//         if(x==0) cout<<-1;
//         cout<<endl;
//     }
// }
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)                    	for (int i=a; i<=b; i++)

class Solution {
public:
   string s;
   map <string ,int> m;
   void solve(int pos, int left, int right,int l, int r, vector <string> &res, string temp=""){
      if(pos == s.size()){
         if(left==0 && right==0 && l==r){
            if(!m[temp])
               res.push_back(temp);
            m[temp] = 1;
         }
         return;
      }
      if(s[pos] =='(' && right>0 ){
         solve(pos+1,left,right-1,l,r,res,temp+"");
      } else if(s[pos] ==')' && left>0) {
         solve(pos+1,left-1,right,l,r,res,temp+"");
      }
      if(s[pos] =='(')solve(pos+1,left,right,l+1,r,res,temp+"(");
      else if(s[pos] == ')' && l>r)solve(pos+1,left,right,l,r+1,res,temp+')');
      if(s[pos]!='(' && s[pos]!=')')solve(pos+1,left,right,l,r,res,temp+s[pos]);
   }
   vector<string> removeInvalidParentheses(string s) {
      vector <string > res;
      int l = 0;
      int r=0;
      this->s = s;
      for(int i =0;i<s.size();i++){
         if(s[i] == '('){
            r++;
         } else if(s[i]==')') {
            if(r)r--;
            else l++;
         }
      }
      solve(0,l,r,0,0,res);
      return res;
   }
};
int test(string str){
    int dem=0;
    stack<int>st;
    st.push(-1);
    for(int i=0;i<str.size();i++){
        if(str[i]=='(') st.push(i);
        else
        {
            st.pop();
            if(st.size()>0){
                dem=max(dem,i-st.top());
            }
            if(st.size()==0) st.push(i);
        }
    }
    return dem;
}
bool test11(string str){
    FOR(i,0,str.length()-1)
        if(str[i]==')'||str[i]=='(')
            return true;
    return false;
}
void print_vector(vector<string> v){
    int x=0;
    sort(v.begin(),v.end());
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
        if(v[i]!="")
            x=1;
    }
   if(x==0) cout<<-1;
   cout << endl;
}
main(){
    int t;
    cin>>t;string str;
    cin.ignore();
    while(t--){
        getline(cin,str);
        int dem=0;
        FOR(i,0,str.size()-1){
            if(str[i]!=')'&&str[i]!='(')
                dem++;
        }
        if(test(str)==str.size()-dem||str==""||test11(str)==0) {
            cout<<-1<<endl;
            continue;
        }
        Solution ob;
        print_vector(ob.removeInvalidParentheses(str));
    }   
}