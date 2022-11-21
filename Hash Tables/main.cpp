#include <iostream>
#include <algorithm>
#include <map>
#include<vector>
#include <unordered_map>
using namespace std;
// Function
int maximumUniqueSubarray(vector<int>& nums);

int main() {
    vector<int> test = {4,2,4,5,6};
    vector<int> test2 = {5,2,1,2,5,2,1,2,5};
    vector<int> test3 = {187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,
    743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434};
    cout << maximumUniqueSubarray(test) << endl;
    cout << maximumUniqueSubarray(test2) << endl;
    cout << maximumUniqueSubarray(test3) << endl;
    return 0;
}

/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
*/
int maximumUniqueSubarray(vector<int>& nums) {
    unordered_map<int,int>uniqueVal;
    for (int i = 0; i < nums.size();i++) {
        if (uniqueVal.count(nums[i]) == 0) {
            uniqueVal.insert(std::pair<int,int>(nums[i],nums[i]));
        }
    }
    int sum = 0;
    for (auto i = uniqueVal.begin(); i != uniqueVal.end();i++) {
        sum+=i->first;
    }
    return sum;
}