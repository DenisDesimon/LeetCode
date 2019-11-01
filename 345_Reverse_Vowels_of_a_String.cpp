//#345 Reverse Vowels of a String - https://leetcode.com/problems/reverse-vowels-of-a-string/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        while(left < right)
        {
            if(!vowels.count(tolower(s[left])))
                left++;
            else if(!vowels.count(tolower(s[right])))
                right--;
            else
                swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string given_s = "hello";
    string expected_answer = "holle";
    assert(solution.reverseVowels(given_s) == expected_answer);

    given_s = "leetcode";
    expected_answer = "leotcede";
    assert(solution.reverseVowels(given_s) == expected_answer);

    return 0;
}
