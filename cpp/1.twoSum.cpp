// https://leetcode.com/problems/two-sum/description/

#include <cassert>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=1; j<nums.size(); j++) {
                if (i==j) continue;
                if (nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {0,1};
    }
};

int main() {
    Solution soln;

    vector<
        tuple<
            vector<int>, // nums
            int,         // target
            vector<int>  // expected
        >
    > cases = {
        {
            { 2, 7, 11, 15 },
            9,
            { 0, 1 }
        }, {
            { 3, 2, 4 },
            6,
            { 1, 2 },
        }, {
            { 3, 3 },
            6,
            { 0, 1 },
        }, {
            { -3, 4, 3, 90 },
            0,
            { 0, 2 }
        }
    };

    for (unsigned int i = 0; i < cases.size(); i++) {
        cout << "Test case " << i + 1 << endl;
        auto res = soln.twoSum(get<0>(cases[i]), get<1>(cases[i]));

        assert(equal(res.begin(), res.end(), get<2>(cases[i]).begin()));
    }

    cout << "All test cases pass\n" <<  endl;

    return 1;
}
