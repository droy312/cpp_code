#include <bits/stdc++.h>

#define ll long long int
#define ld long double

using namespace std;

void file_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class ThreeVal
{
public:
    bool True, False, None;

    ThreeVal()
    {
        True = false;
        False = false;
        None = false;
    }

    void setTrue()
    {
        True = true;
        False = false;
        None = false;
    }

    void setFalse()
    {
        False = true;
        True = false;
        None = false;
    }

    void setNone()
    {
        None = true;
        True = false;
        False = false;
    }
};

void addPerson(vector<ll> *arr, ll n, vector<ThreeVal> *currentElements, ll noOfSelectedElements, vector<ThreeVal> *solution, ll *minimumDifference, ll sum, ll currentSum, ll currentPosition)
{
    if (currentPosition == n)
    {
        return;
    }

    if (((n / 2) - noOfSelectedElements) > (n - currentPosition))
    {
        return;
    }
    addPerson(arr, n, currentElements, noOfSelectedElements, solution, minimumDifference, sum, currentSum, currentPosition + 1);
    noOfSelectedElements++;
    currentSum += (*arr)[currentPosition];
    (*currentElements)[currentPosition].setTrue();

    if (noOfSelectedElements == n / 2)
    {
        if ((abs(sum / 2) - currentSum) < *minimumDifference)
        {
            *minimumDifference = abs(sum / 2 - currentSum);
            for (ll i = 0; i < n; i++)
            {
                (*solution)[i] = (*currentElements)[i];
            }
        }
    }
    else
    {
        addPerson(arr, n, currentElements, noOfSelectedElements, solution, minimumDifference, sum, currentSum, currentPosition + 1);
    }

    (*currentElements)[currentPosition].setFalse();
}

void tugOfWar(vector<ll> *arr, ll n)
{
    vector<ThreeVal> *currentElements = new vector<ThreeVal>();
    for (ll i = 0; i < n; i++)
    {
        ThreeVal tv;
        tv.setNone();
        currentElements->push_back(tv);
    }

    vector<ThreeVal> *solution = new vector<ThreeVal>();
    for (ll i = 0; i < n; i++)
    {
        ThreeVal tv;
        tv.setNone();
        solution->push_back(tv);
    }

    ll minimumDifference = INT_MAX;

    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += (*arr)[i];
        (*currentElements)[i].setFalse();
        (*solution)[i].setFalse();
    }

    addPerson(arr, n, currentElements, 0, solution, &minimumDifference, sum, 0, 0);

    ll sum1 = 0, sum2 = 0;

    for (ll i = 0; i < n; i++)
    {
        // cout << (*solution)[i].True << " " << (*solution)[i].False << " " << (*solution)[i].None << endl;
        if ((*solution)[i].True)
        {
            sum1 += (*arr)[i];
        }

        if ((*solution)[i].False)
        {
            sum2 += (*arr)[i];
        }
    }

    if (sum1 < sum2)
    {
        cout << sum1 << " " << sum2 << endl;
    }
    else
    {
        cout << sum2 << " " << sum1 << endl;
    }
}

int main()
{
    file_io();
    ll testCases;
    cin >> testCases;
    ll n, no;
    vector<ll> arr;
    while (testCases--)
    {
        arr.clear();
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> no;
            arr.push_back(no);
        }
        tugOfWar(&arr, n);
    }

    return 0;
}