//#71 Simplify Path - https://leetcode.com/problems/simplify-path/
#include <iostream>
#include <deque>
#include <sstream>
#include <cassert>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        deque<string> result_path;
        stringstream ss(path);
        string result;
        while (std::getline(ss, result, '/')) {
                if(result == "..")
                {
                    if(!result_path.empty())
                        result_path.pop_back();
                }
                else if(result == "." || result == "")
                    continue;
                else
                    result_path.push_back(result);
            }
        result = "/";
        while(!result_path.empty())
        {
            result += result_path.front() + '/';
            result_path.pop_front();
        }
        if(result.size() > 1)
            result.pop_back();
        return result;

    }
};
int main()
{
    Solution solution;
    string given_path = "/a//b////c/d//././/..";
    string expected_answer = "/a/b/c";
    assert(solution.simplifyPath(given_path) == expected_answer);

    given_path = "/a/../../b/../c//.//";
    expected_answer =  "/c";
    assert(solution.simplifyPath(given_path) == expected_answer);

    return 0;
}
