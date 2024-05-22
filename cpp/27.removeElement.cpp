// https://leetcode.com/problems/remove-element/description/
/**
    Given an integer array nums and an integer val, remove all occurrences 
        of val in nums in-place. 
        The order of the elements may be changed. 
        Then return the number of elements in nums which are not equal to val.

    Consider the number of elements in nums which are not equal to val be k, 
        to get accepted, you need to do the following things:
        - Change the array nums such that the first k elements of nums contain 
            the elements which are not equal to val. 
            The remaining elements of nums are not important as well as the size of nums.
        - Return k.
 */

#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>
#include <algorithm> // sort 

#include "test.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for (auto it = nums.begin(); it < nums.end(); it++) {
            if (*it == val) {
                k--;
                nums.erase(it);
                it--;
            }
        }
        return k;
    }
};

Solution soln;

int judge(tuple<vector<int>, int, vector<int>> test_case) {
    vector<int> nums = get<0>(test_case);

    int val = get<1>(test_case);

    vector<int> expected = get<2>(test_case);
    sort(expected.begin(), expected.end());

    int k = soln.removeElement(nums, val);
    sort(nums.begin(), nums.begin() + k);
    assert (expected.size() == k);
    for (int i = 0; i < k; i++) {
        assert (nums[i] == expected[i]);
    }

    return 1;
}

int main() {
    test<vector<int>, int, vector<int>> removeElement;

    removeElement.add_case({3, 2, 2, 3}, 3, {2, 2});
    removeElement.add_case({0, 1, 2, 2, 3, 0, 4, 2}, 2, {0, 1, 3, 0, 4});

    removeElement.run_tests(judge);

    cout << "All test cases pass\n" << endl;

    return 0;
}
