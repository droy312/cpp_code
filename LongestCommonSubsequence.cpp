#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

//finding max value
int max(int a, int b)
{
    return (a > b) ? a : b;
}

//finding LCS
int LongestCommonSubsequence(char *str1, char *str2, int x, int y)
{
    if (x == 0 || y == 0)
    {
        return 0;
    }
    if (str1[x - 1] == str2[y - 1])
    {
        return (1 + LongestCommonSubsequence(str1, str2, x - 1, y - 1));
    }
    else
    {
        return max(LongestCommonSubsequence(str1, str2, x, y - 1), LongestCommonSubsequence(str1, str2, x - 1, y));
    }
}

//main function
int main()
{
    char str1[] = "cantonment";
    char str2[] = "longatone";
    int x = strlen(str1);
    int y = strlen(str2);
    cout << "\nLength of Longest Common Subsequence From Both The Strings Is " << LongestCommonSubsequence(str1, str2, x, y) << endl;
    return 0;
}