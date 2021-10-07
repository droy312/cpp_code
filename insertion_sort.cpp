#include<bits/stdc++.h>
#include<string>
using namespace std;
#define int long long

// bool compareQ(pair<int, int> a, pair<int, int> b)
// {
// 	if (a.first < b.first)
// 		return (a.second > b.second);


// 	return false;
// // }
// int N = 1e9 + 2;
void insertion_sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;

	}
}

void solve()
{

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	insertion_sort(a, n);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}




int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	long long t = 1;

	// cin >> t;
	while (t--)
	{

		solve();
	}



}






