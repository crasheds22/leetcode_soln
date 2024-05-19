// https://leetcode.com/problems/longest-common-prefix/

#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <cassert>

#include "test.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int k=0;
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j=1; j<strs.size(); j++) {
                if (i>strs[j].size()) return strs[0].substr(0, k);
                if (strs[0][i]!=strs[j][i]) return strs[0].substr(0, i);
            }
            k++;
        }
        return strs[0].substr(0,k);
    }
};

Solution soln;

int judge(tuple<vector<string>, string> test_case) {
    vector<string> strs = get<0>(test_case);
    string exp = get<1>(test_case);

    string res = soln.longestCommonPrefix(strs);

    assert (res.compare(exp));

    return 1;
}

int main() {
    test<vector<string>, string> longestPrefix;

    longestPrefix.add_case({"flower", "flow", "flight"}, "fl");
    longestPrefix.add_case({"dog", "racecar", "car"}, "");
    longestPrefix.add_case({"a"}, "a");
    longestPrefix.add_case({"flower", "flower", "flower", "flower"}, "flower");

    longestPrefix.run_tests(judge);

    cout << "All test cases pass\n" << endl;

    return 1;
}
