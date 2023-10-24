#ifndef SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H_INLCUDED
#define SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H_INLCUDED

//30. Substring with Concatenation of All Words
namespace leetcode_30 {
    class Solution {
    public:
        std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);
        std::vector<int> findSubstringOptimal(std::string s, std::vector<std::string>& words);
    };
}

int test_30();

#endif