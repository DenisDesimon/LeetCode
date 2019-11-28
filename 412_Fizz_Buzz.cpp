//#412 Fizz Buzz - https://leetcode.com/problems/fizz-buzz/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        for(int i = 1; i <= n; i++)
        {
            if(i % 3 == 0)
            {
                if(i % 5 == 0)
                    result[i - 1] = "FizzBuzz";
                else
                    result[i - 1] = "Fizz";
            }
            else if (i % 5 == 0)
                result[i - 1] = "Buzz";
            else
                result[i - 1] = to_string(i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 15;
    vector<string> expected_answer = {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11",
                                      "Fizz", "13", "14", "FizzBuzz"};
    assert(solution.fizzBuzz(given_n) == expected_answer);

    given_n = 5;
    expected_answer = {"1", "2", "Fizz", "4", "Buzz"};
    assert(solution.fizzBuzz(given_n) == expected_answer);

    return 0;
}
