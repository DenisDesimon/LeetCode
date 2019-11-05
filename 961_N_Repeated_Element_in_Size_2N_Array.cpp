//#961 N-Repeated Element in Size 2N Array - https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> hash;
        for(auto num : A)
        {
            if(hash.count(num))
                return num;
            hash.insert(num);
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {1, 2, 3, 3};
    int expected_answer = 3;
    assert(solution.repeatedNTimes(given_A) == expected_answer);

    given_A = {2, 1, 2, 5, 3, 2};
    expected_answer = 2;
    assert(solution.repeatedNTimes(given_A) == expected_answer);

    return 0;
}
