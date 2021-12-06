#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{

    // 10 10 6 5 1

    // 5 3 12 9
    // 12 9 5 3

    vector<int> coins;

    int input;
    while(true) {
        cin >> input;
        if(input == -1) break;
        coins.push_back(input);
    }


    // 10 4 4 2

    // sort(coins.begin(), coins.end(), greater<int>());

    // int difference = 0;

    // for(int i = 0; i < coins.size(); i++) {
    //     if(difference <= 0)
    //         difference += coins[i];
    //     else difference -= coins[i];
    //     cout << difference << endl;
    // }
    const int n = coins.size();

    vector<int> combinazioni;

    // for(int i = 0; i < n; i++)
    //     combinazioni[i][i] = coins[i];



    // for(int i = 1; i < n; i++)
    //     for(int j = 0; j < n - i; j++)
    //         combinazioni[j][i + j] = combinazioni[j - 1][i + j] + combinazioni[j][i + j - 1];


    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++)
    //         cout << combinazioni[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
}
