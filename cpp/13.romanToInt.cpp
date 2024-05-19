// https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <cassert>

#include "test.h"

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

Solution soln;

int judge(tuple<string, int> test_case) {
    string s = get<0>(test_case);
    int n = get<1>(test_case);

    int r = soln.romanToInt(s);

    assert (n == r);

    return 1;
}

int main() {
    test<string, int> romanToInt;

    romanToInt.add_case("III", 3);
    romanToInt.add_case("LVIII", 58);
    romanToInt.add_case("MCMXCIV", 1994);

    romanToInt.run_tests(judge);

    cout << "All test cases pass\n" << endl;

    return 1;
}
