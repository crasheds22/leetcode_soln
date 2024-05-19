// https://leetcode.com/problems/valid-parentheses/description/

#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <cassert>

#include "test.h"

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
        return isOpen.size()==0;
    }
};

Solution soln;

int judge(tuple<string, bool> test_case) {
    string paren = get<0>(test_case);
    bool valid = get<1>(test_case);

    bool res = soln.isValid(paren);

    assert (valid == res);

    return 1;
}

int main() {
    test<string, bool> validParen;

    validParen.add_case("()", true);
    validParen.add_case("()[]{}", true);
    validParen.add_case("(]", false);
    validParen.add_case("((", false);
    validParen.add_case("(){}}{", false);

    validParen.run_tests(judge);

    cout << "All test cases pass\n" << endl;

    return 0;
}
