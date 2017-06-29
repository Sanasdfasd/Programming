
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int MAXN = (1 << 20);
const int inf = (int)1e7 + 42;

int n;
string s;

int last[MAXN];
set<char> st;

void solve()
{
	for(int i = 0; i < n; i++)
		st.insert(s[i]);

	for(char c: st)
		last[c] = -inf;

	int ans = inf;
	for(int i = 0; i < n; i++)
	{
		last[s[i]] = i;
		
		int lst = i;
		for(char c: st)
			lst = min(lst, last[c]);

		ans = min(ans, i - lst + 1);
	}

	cout << ans << endl;
}

int main()
{
	cin>>n>>s;

	solve();
	return 0;
}

