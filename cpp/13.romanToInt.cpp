// https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int s_to_i(char s) {
        switch (s) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int num=0;
        for (int i=0;i<s.length();i++) {
            if (s_to_i(s[i])<s_to_i(s[i+1])) {
                num-=s_to_i(s[i]);
            } else {
                num+=s_to_i(s[i]);
            }
        }
        return num;
    }
};

int main() {
    Solution soln;

    vector<tuple<string, int>> cases;
    cases.push_back({ "III", 3 });
    cases.push_back({ "LVIII", 58 });
    cases.push_back({ "MCMXCIV", 1994 });

    for (auto i = 0; i < cases.size(); i++) {
        cout << "Test case " << i + 1;
        auto res = soln.romanToInt(get<0>(cases[i]));

        auto exp = get<1>(cases[i]);
        if (exp == res) {
            cout << " passed" << endl;
        } else {
            cout << exp << " != " << res << endl;
            return 0;
        }
    }

    cout << "All test cases pass" << endl;

    return 1;
}
