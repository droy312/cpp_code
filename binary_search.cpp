#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define MOD 1000000007
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int binarySearch(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}
int main()
{
    int noOfElements;
    cout << "Please enter number of elements : ";
    cin >> noOfElements;
    vector<int> elements;

    cout << "Please enter the elements one by one" << endl;
    for (int i = 0; i < noOfElements; i++)
    {
        int a;
        cin >> a;
        elements.push_back(a);
    }
    sort(elements.begin(), elements.end());

    int noToFind;
    cout << "Please enter the number to search : ";
    cin >> noToFind;

    int index = binarySearch(elements, noToFind);
    if (index != -1)
    {
        cout << noToFind << " found in the array" << endl;
    }
    else
    {
        cout << noToFind << " is not present" << endl;
    }

    return 0;
}