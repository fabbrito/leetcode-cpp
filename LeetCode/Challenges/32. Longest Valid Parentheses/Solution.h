#ifndef LONGEST_VALID_PARENTHESES_H_INLCUDED
#define LONGEST_VALID_PARENTHESES_H_INLCUDED

//32. Longest Valid Parentheses
namespace leetcode_32 {
    class Solution {
    public:
        bool isValid(std::string& s, int pStart, int pStop);
        int longestValidParenthesesSlow(std::string s);

        //int longestValidParentheses(std::string s);
        //int partition(std::string& s, int pStart, int pEnd);
        //int longestValidParenthesesRecursive(std::string& s, int p);
    };
}

int test_32();

#endif