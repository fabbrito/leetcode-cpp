#include "pch.h"
#include "Solution71.h"

namespace leetcode_71 {
	using namespace std;
	class Solution;
	class MySolution;
}


class leetcode_71::Solution {
public:
	string simplifyPath(string path) {
		stack<string> st;
		string res;

		for (int i = 0; i < path.size(); ++i) {

			if (path[i] == '/') {
				continue;
			}
			string temp;

			while (i < path.size() && path[i] != '/') {
				// add path to temp string
				temp += path[i];
				++i;
			}

			if (temp == ".") {
				continue;
			}
			else if (temp == "..") {
				// pop the top element from stack if exists
				if (!st.empty())
					st.pop();
			}
			else {
				// push the directory file name to stack
				st.push(temp);
			}
		}

		// adding all the stack elements to res
		while (!st.empty()) {
			res = "/" + st.top() + res;
			st.pop();
		}

		// if no directory or file is present
		if (res.size() == 0)
			return "/";

		return res;
	}
};

class leetcode_71::MySolution {
public:
	string simplifyPath(string path) {
		std::deque<std::string_view> dq;
		int i = 0, j = 0;
		while (i < path.length()) {
			j = 0;
			while (i + j < path.length() && path[i + j] != '/') j++;
			if (j > 0) {
				auto p = subString(path, i, j);
				if (p == ".."sv && !dq.empty()) {
					dq.pop_back();
				}
				else if (p != "."sv && p != ".."sv) {
					dq.push_back(p);
				}
			}
			i += j + 1;
		}
		string res = "/";
		while (!dq.empty()) {
			res += dq.front();
			dq.pop_front();
			if (!dq.empty())
				res += '/';
		}
		return res;
	}
private:
	std::string_view subString(std::string_view s, std::size_t p, std::size_t n = std::string_view::npos) {
		return s.substr(p, n);
	}
};

int test_71()
{
	using namespace leetcode_71;
	struct test_t {
		string path;
		string expected;
	};
	vector<test_t> tests = {
		{"/home/foo/../bar","/home/bar"},
		{"/home/../../../foo","/foo"},
		{"/home/../foo","/foo"},
		{"/../","/"},
		{"/home/./foo","/home/foo"},
		{"/home//foo/","/home/foo"},
		{"/home/","/home"},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;

		auto result = solution.simplifyPath(test.path);
		std::cout << test.path << " -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}

	return 0;
}