#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target);


int main() {
    vector<int> nums{ 2, 3, 4, 5 };
    int target = 7;

    vector<int> soluzione = twoSum(nums, target);
    for(int i = 0; i < soluzione)
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<int> soluzione;
    for(int i = 0; i < nums.size(); i++) {
        auto it = map.find(target - nums[i]);

        if(it != map.end()) {
            cout << "Soluzione trovata\n";
            soluzione.push_back(i);
            soluzione.push_back(it->second);
            return soluzione;
        }
        else {
            map.insert({ nums[i], i });
        }
    }
    return;

}

