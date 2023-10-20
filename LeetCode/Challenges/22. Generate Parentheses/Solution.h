#ifndef GENERATE_PARENTHESES_H_INLCUDED
#define GENERATE_PARENTHESES_H_INLCUDED

//22. Generate Parentheses
namespace leetcode_22 {
    class Solution {
    public:
        std::vector<std::string> modifyParenthesis(std::string s);
        std::vector<std::string> generateParenthesis(int n);

        std::vector<std::string> solveRecursively(int n, int pOpen, int pClose, std::string s, std::vector<std::string> prev_ans = {});
        std::vector<std::string> generateParenthesis2(int n);
    };
}

int test_22();

#endif