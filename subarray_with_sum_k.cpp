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


int findSubarraySum(int arr[], int n, int sum) {
	unordered_map<int, int> prevSum;

	int res = 0;
	int currSum = 0;

	for (int i = 0; i < n; i++) {
		currSum += arr[i];
		if (currSum == sum)
			res++;
		if (prevSum.find(currSum - sum) != prevSum.end())
			res += (prevSum[currSum - sum]);

		prevSum[currSum]++;
	}
	return res;
}
int32_t main()
{
	/*int arr[] = {10, 2, -2, -20, 10};
	int k = -10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += arr[j];
			if (sum == k)
				res++;
		}
	}
	cout << (res) << endl;*/

	// Better approach
	int arr[] = { 10, 2, -2, -20, 10 };
	int sum = -10;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findSubarraySum(arr, n, sum);



	return 0;
}