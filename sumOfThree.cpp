#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
bool findThreeSumIndices(const vector<int>& nums, int target, vector<int>& resultIndices) {
    int n = nums.size();
    if (n < 3) return false;
    vector<pair<int, int>> indexedNums(n);
    for (int i = 0; i < n; ++i) {
        indexedNums[i] = {nums[i], i};
    }
    sort(indexedNums.begin(), indexedNums.end());
    for (int i = 0; i < n - 2; ++i) {
        if (indexedNums[i].first + indexedNums[i + 1].first + indexedNums[i + 2].first > target) break;
        auto left = indexedNums.begin() + i + 1;
        auto right = indexedNums.end() - 1;
 
        while (left < right) {
            int current_sum = indexedNums[i].first + left->first + right->first;
            if (current_sum == target) {
                resultIndices = {indexedNums[i].second, left->second, right->second};
                return true;
            } 
            else if (current_sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
    return false;
}
 
int main() {
    int n, target;
    cin >> n;
    cin >> target;
    if (n < 3) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<int> indices;
    if (findThreeSumIndices(nums, target, indices)) {
        cout 
             << indices[0]+1 << " " 
             << indices[1]+1 << " " 
             << indices[2]+1 << endl;
    } else {
        cout << "IMPOSSIBLE"<< endl;
    }
    return 0;
}
