// trovare la sottostringa palindroma di lunghezza maggiore

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int SIZE = 64;

int longestPalindrom(string s, int dp[SIZE][SIZE], int i, int j);


int main(int argc, char const* argv[])
{
    int dp[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            dp[i][j] = -1;



    string input;
    cin >> input;

    cout << longestPalindrom(input, dp, 0, input.length() - 1);
    return 0;
}

int longestPalindrom(string s, int dp[SIZE][SIZE], int i, int j) {

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i == j) return 1;
    if(i >= j) return 0;

    if(s[i] == s[j]) {
        dp[i][j] = 2 + longestPalindrom(s, dp, i + 1, j - 1);
        return dp[i][j];
    }
    else {
        dp[i][j] = max(longestPalindrom(s, dp, i + 1, j),
            longestPalindrom(s, dp, i, j - 1));
        return dp[i][j];
    }
    return 0;
}

/*
    se i >  j -> 0
    se i == j -> 1
    se i < j:
        se s[i] == s[j] -> 2 + longestPalindrome(i+1, j-1)
        se s[i] != s[j] -> max(longestPalindrome(i+1, j),
                               longestPalindrome(i, j-1))
    */
