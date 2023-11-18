#include "pch.h"
#include "./Solution30.h"

namespace leetcode_30 {
	class Solution {
	public:
		std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);
		std::vector<int> findSubstringOptimal(std::string s, std::vector<std::string>& words);
	};
}

std::vector<int> leetcode_30::Solution::findSubstringOptimal(std::string s, std::vector<std::string>& words) {
	std::vector<int> ans;
	int word_sz = words[0].length();
	int concat_len = word_sz * words.size();

	// window: holds the last 3 substrings and slides throughout the input string s
	std::queue<std::string> window;
	// words_map: holds all the unique words and their frequency in the vector 'words'
	// freq: counts the matched words each step of the algorithm
	std::map<std::string, int> words_map, freq;
	for (std::string& word : words) {
		words_map[word] += 1;
	}

	// offset algorithm to check substrings with different alignment
	for (int offset = 0; offset < word_sz; ++offset) {
		freq.clear();
		window = std::queue<std::string>();
		int idx = offset;
		// separates the input string in chunks of 'word_sz' length
		while (idx + word_sz <= s.length()) {
			// checks if a substrings is within the input vector of words
			std::string sub_s = s.substr(idx, word_sz);
			if (words_map.find(sub_s) == words_map.end()) { // substring not in the map
				// reset
				if (!freq.empty()) {
					freq.clear();
					window = std::queue<std::string>();
				}
			}
			else { // matched substring to a word in words
				freq[sub_s] += 1;
				window.push(sub_s);
				if (freq[sub_s] > words_map[sub_s]) {
					// partial reset: clears freq and leaves only the current substring
					while (true) {
						std::string head = window.front();
						freq[head] -= 1;
						window.pop();
						if (head == sub_s) break;
					}
				}

			}
			idx += word_sz;

			// this check only passes if all the substrings in the window match the words in 'words',
			// with the same frequency
			if (window.size() == words.size()) {
				ans.push_back(idx - concat_len);
			}
		}
	}
	return ans;
}

std::vector<int> leetcode_30::Solution::findSubstring(std::string s, std::vector<std::string>& words) {
	int s_sz = s.length();
	int words_sz = words.size();
	int w_sz = words[0].length();

	std::vector<int> ans = {};

	// holds all the unique words and their frequencies
	std::unordered_map<std::string, int> words_map, original_map;
	for (auto& word : words) {
		words_map[word]++;
	}
	original_map = words_map;
	int quant = words_sz;

	// pC traverses the input string
	// pStart = -1 if no word has been matched so far
	//        = N, where N is the first start position of the matches
	int pC = 0, pStart = -1;
	while (pC <= s_sz - w_sz) {
		std::string sub_s = s.substr(pC, w_sz);
		if (words_map.find(sub_s) != words_map.end()) {
			if (words_map[sub_s] > 1) words_map[sub_s]--;
			else words_map.erase(sub_s);
			quant--;
			if (pStart == -1) pStart = pC;
			if (quant == 0) {
				ans.push_back(pStart);
				// reset
				words_map = original_map;
				quant = words_sz;
				pC = pStart + 1;
				pStart = -1;
			}
			else
				pC += w_sz;
		}
		else if (quant != words_sz) {
			// reset
			words_map = original_map;
			quant = words_sz;
			pC = pStart + 1;
			pStart = -1;
		}
		else
			pC++;
	}
	return ans;
}

int test_30() {
	using namespace leetcode_30;
	Solution solution;
	std::vector<int> result;
	struct Test {
		std::string s;
		std::vector<std::string> words;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{"barfoofoobarthefoobarman", {"bar","foo","the"}, {6,9,12}},
		{"ababaab", {"ab","ba","ba"}, {1}},
		{"aaaaaaaaaaaaaa", {"aa","aa"}, {0,1,2,3,4,5,6,7,8,9,10}},
		{"barfoothefoofoobarman",  {"foo","foo"}, {9}},
		{"barfoothefoobarman",  {"foo","bar"}, {0,9}},
		{"wordgoodgoodgoodbestword",  {"word","good","best","word"}, {}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << test.s << ", ";
		utils::printVector(test.words);
		// std::cout << " -> ";
		result = solution.findSubstringOptimal(test.s, test.words);
		utils::printVector(result);
		if (result.size() != test.expected.size()) return 1;
		//if (result != test.expected) return 1;
	}
	return 0;
}