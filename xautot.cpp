#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	long long n, i, j = 1, k = 0, sb = 0;
	cin>>n>>s;
	for (i = 0; i<n-1; i++)
		if (s[i] != s[i + 1])
			sb += j,j=k=1;
		else
			j++,sb += k;
	printf("%lld", n * (n - 1) / 2 - sb);
	return 0;
}