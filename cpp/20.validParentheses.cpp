// https://leetcode.com/problems/valid-parentheses/description/

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

class Solution {
public:
    char oppositeParen(char paren) {
        switch(paren) {
            case '(': return ')';
            case '[': return ']';
            case '{': return '}';
            default: return '\0';
        }
    }

    bool isValid(string s) {
        if (s.size()%2) return false;
        vector<char> isOpen;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
                isOpen.push_back(s[i]);
            } else {
                if (isOpen.size()==0) return false;
                if (oppositeParen(isOpen.back())!=s[i]) {
                    return false;
                }
                isOpen.pop_back();
            }
        }
        if (isOpen.size()!=0) {
            return false;
        }
        return true;
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

    vector<tuple<string, bool>> cases;
    cases.push_back({"()", true});
    cases.push_back({"()[]{}", true});
    cases.push_back({"(]", false});
    cases.push_back({"((", false});
    cases.push_back({"(){}}{", false});

    for (int i = 0; i < cases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        bool res = soln.isValid(get<0>(cases[i]));
        bool exp = get<1>(cases[i]);

        if (res == exp) {
            cout << "passed" << endl;
        } else {
            cout << bool_to_str(res) << " != " << bool_to_str(exp) << endl;
            return 0;
        }
    }

    return 0;
}
