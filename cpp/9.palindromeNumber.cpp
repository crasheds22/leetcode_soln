//https://leetcode.com/problems/palindrome-number/description/

#include "./common.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x<10) return true;
        double p=0;
        int n=x;
        while (n>0) {
            p=p*10+n%10;
            n/=10;
        }
        return p==x;
    }
};

const char* bool_to_str(bool in) {
    if (in) {
        return "true";
    }
    return "false";
}

int main() {
    Solution soln;

    vector<tuple<int, bool>> cases;
    cases.push_back({121, true});
    cases.push_back({-121, false});
    cases.push_back({10, false});
    cases.push_back({1234567899, false});

    for (auto i = 0; i < cases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        bool res = soln.isPalindrome(get<0>(cases[i]));

        bool exp = get<1>(cases[i]);
        if (res == exp) {
            cout << "passed" << endl;
        } else {
            cout << bool_to_str(exp) << " != " << bool_to_str(res) << endl;
            return 0;
        }
    }

    return 1;
}
