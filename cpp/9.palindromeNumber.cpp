//https://leetcode.com/problems/palindrome-number/description/

#include <cassert>
#include <vector>
#include <tuple>
#include <iostream>

#include "test.h"

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

Solution soln;

int judge(tuple<int, bool> test_case) {
    int num = get<0>(test_case);
    bool expected = get<1>(test_case);

    bool res = soln.isPalindrome(num);

    assert (expected == res);

    return 1;
}

int main() {
    test<int, bool> palindromeNumber;

    palindromeNumber.add_case(121, true);
    palindromeNumber.add_case(-121, false);
    palindromeNumber.add_case(10, false);
    palindromeNumber.add_case(123456789, false);

    palindromeNumber.run_tests(judge);

    cout << "All test cases pass\n" << endl;

    return 1;
}
