//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <string>
#include <tuple>
#include <cassert>
#include <iostream>

#include "test.h"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        if (pos == string::npos) {
            return -1;
        }
        return pos;
    }
};

Solution soln;

int judge(tuple<string, string, int> test_case) {
    string haystack = get<0>(test_case);
    string needle = get<1>(test_case);
    int index = get<2>(test_case);

    int res = soln.strStr(haystack, needle);

    assert(index == res);

    return 1;
}

int main() {
    test<string, string, int> strStr;

    strStr.add_case("sadbutsad", "sad", 0);
    strStr.add_case("leetcode", "leeto", -1);
    strStr.add_case("hello", "ll", 2);
    strStr.add_case("a", "a", 0);

    strStr.run_tests(judge);

    cout << "All test cases pass\n" << endl;

    return 0;
}
