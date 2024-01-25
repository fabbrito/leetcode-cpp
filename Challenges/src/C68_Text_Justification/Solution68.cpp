#include "pch.h"
#include "Solution68.h"

namespace leetcode_68 {
	using namespace std;
	class Solution;
	class MySolution;
	void printJoin(const vector<string>& words) {
		for (auto& word : words) {
			std::cout << word << ' ';
		}
	}
	void printJustified(const vector<string>& lines, bool highlights = true) {
		std::ostringstream oss;
		for (auto& line : lines) {
			if (highlights) {
				oss << "|";
				for (auto& elem : line) {
					if (elem == ' ') oss << '_';
					else oss << elem;
				}
				oss << "|" << std::endl;
			}
			else oss << "|" << line << "|" << std::endl;
		}
		std::cout << oss.str();
	}
}

class leetcode_68::Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		string output = words[0];
		int start = 0;
		for (int i = 1; i < words.size(); i++) {
			if (output.length() + words[i].length() + 1 <= maxWidth) // +1 for space 
				output += " " + words[i]; //add space before adding word
			else { // can't add more words
				int spacesInString = i - start - 1;
				output = spaceJustifier(output, maxWidth, spacesInString, false); // justify line
				result.push_back(output);
				start = i;
				output = words[i]; // start of new line
			}
		}
		// justifying spaces in last line
		output = spaceJustifier(output, maxWidth, words.size() - start - 1, true);
		result.push_back(output);
		return result;
	}
private:
	string spaceJustifier(string str, int maxWidth, int spacesInString, bool isLast) {
		if (str.length() == maxWidth)
			return str;

		int spacesToBeInserted = maxWidth - str.length();

		// Left-Justify 
		if (spacesInString == 0 || isLast) {
			str.insert(str.length(), spacesToBeInserted, ' ');
			return str;
		}
		// Justify
		int eachSlot = spacesToBeInserted / spacesInString;
		int leftOverSpace = spacesToBeInserted % spacesInString;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ' && (eachSlot > 0 || leftOverSpace > 0)) { //we add spaces till (eachSlot > 0 || leftOverSpace >0)
				int noOfSpaces = eachSlot + ((leftOverSpace--) > 0 ? 1 : 0);
				str.insert(i, noOfSpaces, ' ');
				i += noOfSpaces;
			}
		}
		return str;
	}
};

class leetcode_68::MySolution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> lines;
		int n = words.size();
		int begin = 0, end = 0;
		int wordsLength = 0;
		while (end < n) {
			wordsLength += words[end].length();
			int currWidth = wordsLength + end - begin; // using simple spaces
			if (end + 1 < n && (currWidth + 1 + words[end + 1].length()) > maxWidth) {
				int totalSpaces = maxWidth - wordsLength;
				lines.emplace_back(fullJustifyLine(words, begin, end, totalSpaces, maxWidth));
				begin = end + 1;
				wordsLength = 0;
			}
			else if (end == n - 1) {
				int totalSpaces = maxWidth - wordsLength;
				lines.emplace_back(leftJustifyLine(words, begin, end, totalSpaces, maxWidth));

			}
			end++;
		}
		return lines;
	}
private:
	string leftJustifyLine(const vector<string>& words, int begin, int end, int totalSpaces, int maxWidth) {
		if (begin == end) {
			return words[begin] + string(totalSpaces, ' ');
		}
		string output = "";
		output.reserve(maxWidth);
		int spaces = 0;
		for (int i = begin; i < end; i++) {
			output += words[i] + ' ';
			spaces++;
		}
		output += words[end];
		if (spaces < totalSpaces)
			output += string(totalSpaces - spaces, ' ');
		return output;
	}

	string fullJustifyLine(const vector<string>& words, int start, int end, int totalSpaces, int maxWidth) {
		if (end == start)
			return leftJustifyLine(words, start, end, totalSpaces, maxWidth);

		vector<string> join;
		int i = end;
		while (totalSpaces > 0 && i > start) {
			int spaces = totalSpaces / (i - start);
			join.emplace_back(words[i]);
			join.emplace_back(string(spaces, ' '));
			totalSpaces -= spaces;
			i--;
		}
		join.emplace_back(words[i]);
		std::reverse(join.begin(), join.end());

		string output = "";
		output.reserve(maxWidth);
		for (auto& elem : join) {
			output += elem;
		}
		return output;
	}
};

int test_68()
{
	using namespace leetcode_68;
	struct test_t {
		vector<string> words;
		int maxWidth;
		vector<string> expected;
	};
	vector<test_t> tests = {
		{
			.words = {"This", "is", "an", "example", "of", "text", "justification."},
			.maxWidth = 16,
			.expected = {
				"This    is    an",
				"example  of text",
				"justification.  ",
			},
		},
		{
			.words = {"What","must","be","acknowledgment","shall","be"},
			.maxWidth = 16,
			.expected = {
				"What   must   be",
				"acknowledgment  ",
				"shall be        ",
			},
		},
		{
			.words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"},
			.maxWidth = 20,
			.expected = {
				"Science  is  what we",
				"understand      well",
				"enough to explain to",
				"a  computer.  Art is",
				"everything  else  we",
				"do                  ",
			},
		},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;

		auto result = solution.fullJustify(test.words, test.maxWidth);
		printJoin(test.words);
		std::cout << test.maxWidth << "\r\n";
		printJustified(result);
		std::cout << "\r\n";
		if (result != test.expected) return 1;
	}

	return 0;
}