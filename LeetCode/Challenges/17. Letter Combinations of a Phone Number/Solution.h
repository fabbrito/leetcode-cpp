#ifndef LETTER_COMBINATIONS_OF_PHONE_NUMBER_H_INCLUDED
#define LETTER_COMBINATIONS_OF_PHONE_NUMBER_H_INCLUDED

namespace leetcode_17 {
    class Solution {
    public:
        std::string digitToLetters(char digit);
        std::vector<std::string> letterCombinations(std::string digits);
    };
}

int test_17();

#endif