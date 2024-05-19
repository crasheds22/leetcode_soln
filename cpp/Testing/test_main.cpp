
#include <vector>
#include <cassert>

#include "../test.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=1; j<nums.size(); j++) {
                if (i==j) continue;
                if (nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {0,1};
    }
};

Solution soln;

int judge(std::tuple<std::vector<int>, int, std::vector<int>> test_case) {
    std::vector<int> nums = std::get<0>(test_case);
    int target = std::get<1>(test_case);
    std::vector<int> expected = std::get<2>(test_case);

    std::vector<int> res = soln.twoSum(nums, target);

    assert (equal(res.begin(), res.end(), expected.begin()));

    return 1;
}

int main() {
    // nums, target, || expected
    test<std::vector<int>, int, std::vector<int>> twoSum;

    twoSum.add_case({2, 7, 11, 15}, 9, {0, 1});
    twoSum.add_case({3, 2, 4}, 6, {1, 2});
    twoSum.add_case({3, 3}, 6, {0, 1});
    twoSum.add_case({-3, 4, 3, 90}, 0, {0, 2});

    twoSum.run_tests(judge);

    std::cout << "All test cases pass\n" << std::endl;
}
