//#1865 Finding Pairs With a Certain Sum - https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> hash;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1.assign(nums1.begin(), nums1.end());
        this->nums2.assign(nums2.begin(), nums2.end());
        for(auto &num : nums2)
            hash[num]++;
    }

    void add(int index, int val) {
        hash[nums2[index]]--;
        nums2[index] += val;
        hash[nums2[index]]++;
    }

    int count(int tot) {
        int result = 0;
        for(auto &num : nums1)
        {
            if(hash.count(tot - num))
                result += hash[tot - num];
        }
        return result;
    }
};

int main()
{
    vector<int> given_nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> given_nums2 = {1, 4, 5, 2, 5, 4};
    FindSumPairs findSumPairs(given_nums1, given_nums2);
    int given_tot = 7;
    int given_idx = 3;
    int given_val = 2;
    int expected_answer = 8;

    assert(findSumPairs.count(given_tot) == expected_answer);

    findSumPairs.add(given_idx, given_val);

    given_tot = 8;
    expected_answer = 2;
    assert(findSumPairs.count(given_tot) == expected_answer);


    given_idx = 0;
    given_val = 1;
    findSumPairs.add(given_idx, given_val);

    given_tot = 7;
    expected_answer = 9;
    assert(findSumPairs.count(given_tot) == expected_answer);


    return 0;
}

