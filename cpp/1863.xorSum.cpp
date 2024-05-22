// https://leetcode.com/problems/sum-of-all-subset-xor-totals/?envType=daily-question&envId=2024-05-20

#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>

#include "test.h"

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < (1 << nums.size()); i++) {
            int ss = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((i & (1 << j)) != 0) {
                    ss ^= nums[j];
                }
            }
            sum += ss;
        }
        return sum;
    }
};

Solution soln;

int judge(tuple<vector<int>, int> test_case) {
    vector<int> nums = get<0>(test_case);
    int k = get<1>(test_case);

    int res = soln.subsetXORSum(nums);
    assert(k == res);

    return 1;
}

int main() {
    test<vector<int>, int> xorSum;

    xorSum.add_case({1, 3}, 6);
    xorSum.add_case({5, 1, 6}, 28);
    xorSum.add_case({3, 4, 5, 6, 7, 8}, 480);

    xorSum.run_tests(judge);

    cout << "All test cases pass\n" << endl;

    return 0;
}
