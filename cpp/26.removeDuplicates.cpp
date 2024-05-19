// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
/**
    Given an integer array nums sorted in non-decreasing order, remove the 
        duplicates in-place such that each unique element appears only once. 
    The relative order of the elements should be kept the same. 
    Then return the number of unique elements in nums.

    Consider the number of unique elements of nums to be k, to get accepted, 
        you need to do the following things:
        - Change the array nums such that the first k elements of nums contain the 
            unique elements in the order they were present in nums initially. 
            The remaining elements of nums are not important as well as the size of nums.
        - Return k.
 */

#include <vector>
#include <cassert>
#include <tuple>
#include <iostream>

#include <set>
#include <algorithm>

#include "test.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> seen(nums.begin(), nums.end());
        nums = vector<int>(seen.begin(), seen.end());
        sort(nums.begin(), nums.begin() + seen.size());
        return seen.size();
    }
};

Solution soln;

int judge(tuple<vector<int>, vector<int>> test_case) {
    vector<int> nums = get<0>(test_case);
    vector<int> expected = get<1>(test_case);

    int k = soln.removeDuplicates(nums);

    assert (k == expected.size());
    for (int i = 0; i < k; i++) {
        assert (nums[i] == expected[i]);
    }

    return 1;
}

int main() {
    test<vector<int>, vector<int>> removeDuplicates;

    removeDuplicates.add_case(
        {1, 1, 2},
        {1, 2}
    );
    removeDuplicates.add_case(
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
        {0, 1, 2, 3, 4}
    );

    removeDuplicates.run_tests(judge);

    cout << "All test cases pass\n" << endl;

    return 0;
}
