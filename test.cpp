#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define run() int N; cin>>N; cin.ignore(); while(N--)

	//Commands
	
// Loops
#define FOR(i,a,b) for (int i=a; i<=b; i++)
// Clear containers

#define reset(C) memset(C,0,sizeof(C))
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;


int test(string str){
    int x=0,y=0;
    bool k[str.size()];
    memset(k,0,sizeof(k));
    FOR(i,0,str.size()-1){
        if(str[i]=='('){
            x++;
        }
        else {
            for(int j=i-1;j>=0;j--){
                if(k[j]==false&&str[j]=='('){
                    y++;
                    k[j]=true;
                    break;
                }
            }
        }
    }
    return 2*min(x,y);
}
vector<string> DP[500][500];
void findBitCombinations(int k,int count) {
    for (int len = 1; len <= k; len++) {
        for (int n = 1; n <= count; n++) {
            for (string str : DP[len - 1][n])
                DP[len][n].clear();
            for (string str : DP[len - 1][n - 1])
                DP[len][n].clear();
        }
    }
    string str = "";
    for (int len = 0; len <= k; len++) {
        DP[len][0].push_back(str);
        str = str + "0";
    }
    for (int len = 1; len <= k; len++) {
        for (int n = 1; n <= count; n++) {
            for (string str : DP[len - 1][n])
                DP[len][n].push_back("0" + str);
            for (string str : DP[len - 1][n - 1])
                DP[len][n].push_back("1" + str);
        }
    }
}

string tester(string str,string str1,int count,int dem){
    if(dem==0) {
        string s="";
        FOR(i,0,str1.size()-1){
            if(str[i]=='1');
            else {
                string s1=string(1,str1[i]);
                s+=s1;
            }
        }
        if(test(s)==str1.size()-count){
            return s;
        }
        return "0";
    }
    else {
        string s2="";
        FOR(i,0,str1.size()-1){
            if(str1[i]=='('||str1[i]==')'){
                string s1=string(1,str1[i]);
                s2+=s1;
            }
        }
        string s="";
        FOR(i,0,s2.size()-1){
            if(str[i]=='1');
            else {
                string s1=string(1,s2[i]);
                s+=s1;
            }
        }
        if(test(s)==str1.size()-count-dem){
            string str2="";
            FOR(i,0,str1.size()-1){
                if(str1[i]!=')'&&str1[i]!='('){
                    string sa=string(1,str1[i]);
                    str2+=sa;
                }
                if(i<s.size()){
                    string sa=string(1,s[i]);
                    str2+=s[i];
                }
            }
            return str2;
        }
        return "0";
    }
}

set <string> res;
void removeInvalidParenthesis(string str){
    int dem=0;
    FOR(i,0,str.size()-1){
        if(str[i]!=')'&&str[i]!='(')
            dem++;
    }
    int count=str.size()-test(str)-dem;
    // cout<<str.size()<<dem<<" "<<test(str)<<" ";
    int count1=str.size()-dem;
    // cout<<count<<" "<<count1<<endl;
    findBitCombinations(count1,count);
    for(string str1: DP[count1][count]){
        if(tester(str1,str,count,dem) !="0"){
            res.insert(tester(str1,str,count,dem));
        }
    }
}

bool test11(string str){
    int d=0;
    FOR(i,0,str.length()-1)
        if(str[i]==')'||str[i]=='('){
            d++;
            if(d>=2) return true;
        }     
    return false;
}

main() {
	int soTest;
	cin >> soTest;string s;
    cin.ignore();
	while(soTest--) {
		res.clear();
        int dem=0;getline(cin,s);
        if(s=="") {
            cout<<-1<<endl;
            continue;
        }
        FOR(i,0,s.size()-1){
            if(s[i]!=')'&&s[i]!='(')
                dem++;
        }
		if(test11(s)==0||test(s)==0||test(s)+dem==s.size()) cout<<-1;
		else {
            removeInvalidParenthesis(s);
            // sort(res.begin(),res.end());
            if(res.size()==0) {
                cout<<-1<<endl;
                continue;
            }
            for(auto i: res){
                cout<< i <<" ";
            }
		}
		cout<<endl;
	}
	return 0;
}