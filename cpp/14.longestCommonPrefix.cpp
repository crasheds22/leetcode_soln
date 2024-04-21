// https://leetcode.com/problems/longest-common-prefix/

#include <string>
#include <vector>
#include <iostream>
#include <tuple>

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

int main() {
    Solution soln;

    vector<tuple<vector<string>, string>> cases;
    cases.push_back({{"flower", "flow", "flight"}, "fl"});
    cases.push_back({{"dog", "racecar", "car"}, ""});
    cases.push_back({{"a"}, "a"});
    cases.push_back({{"flower", "flower", "flower", "flower"}, "flower"});

    for (int i = 0; i < cases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";

        string res = soln.longestCommonPrefix(get<0>(cases[i]));

        string exp = get<1>(cases[i]);
        if (res.compare(exp)) {
            cout << res << " != " << exp << endl;
            return 0;
        } else {
            cout << "passed" << endl;
        }
    }

    return 1;
}
