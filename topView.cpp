#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int>topView(Node* root) {

	vector<int> ans;
	if (root == NULL)return ans;
	map<int, int>mpp;
	queue<pair<Node*, int>> q;
	q.push({root, 0});
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		Node* node = it.ff;
		int line = it.ss;

		if (mpp.find(line) == mpp.end())
			mpp[line] = node->data;

		if (node->left != NULL) {
			q.push({node->left, line - 1});
		}
		if (node->right != NULL) {
			q.push({node->right, line + 1});
		}
	}
	for (auto it : mpp) {
		ans.pb(it.ss);
	}
	return ans;
}

int32_t main()
{
	FIO;



	return 0;
}