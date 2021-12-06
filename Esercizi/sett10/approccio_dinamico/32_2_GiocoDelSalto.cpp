#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int numeroMinimoSalti(const vector<int>& nums);
int getMinimoRaggiungibile(int i, vector<int> nums, int* salti_da);


int main(int argc, char const* argv[])
{
    // vector<int> nums = { 2,3,1,1,4 };

    vector<int> nums = { 1,4,3,5,10,0,1,1,9,7,6,1,2,3,4,1,2,4,0,3,5,1,2,3,1,5,6,7,0,9,7,8,9,0,3,2,4,1,5,2,1,2,3,4,7,8,9,6,5,3,2,0,2,1,3,4,0,3,5,6,2,3,0,1,2 };

    cout << numeroMinimoSalti(nums) << endl;
};









    // [5, 2, 1, 6, 2]
    // salti riichiesti :
    // it - 1 : [-1, -1, -1, -1, 0]
    //     it - 2 : [-1, -1, -1, 1, 0]
    //     it - 3 : [-1, -1, 2, 1, 0]
    //     it - 4 : [-1, 2, 2, 1, 0]
    //     it - 5 : [1, 2, 2, 1, 0]
    //     ^
    //     output


return 0;
}


int numeroMinimoSalti(const vector<int>& nums) {

    int n = nums.size();
    int salti_da[n];

    salti_da[n - 1] = 0;
    for(int i = n - 2; i >= 0; --i) {
        salti_da[i] = 1 + getMinimoRaggiungibile(i, nums, salti_da);
    }

    for(auto salti : salti_da)
        cout << salti << ", ";
    cout << endl;


    return salti_da[0];
}

int getMinimoRaggiungibile(int i, vector<int> nums, int* salti_da) {
    int salti_min = INT_MAX - 1;
    for(int salto = 1; salto <= nums[i] && (i + salto) < nums.size(); salto++) {
        salti_min = min(salti_min, salti_da[i + salto]);
    }
    return salti_min;
}
