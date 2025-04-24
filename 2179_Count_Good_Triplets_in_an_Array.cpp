//#2179 Count Good Triplets in an Array - https://leetcode.com/problems/count-good-triplets-in-an-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct BinarySearchTree{
    vector<int> bit;
    int n;
    BinarySearchTree(int size){
        n = size + 1;
        bit.assign(n, 0);
    }
    void update(int idx, int delta){
        idx++;
        while(idx < n)
        {
            bit[idx] += delta;
            idx += idx & (-idx);
        }
    }
    int getLowerCount(int idx){
        idx++;
        int res = 0;
        while(idx > 0){
            res += bit[idx];
            idx -= idx & (-idx);
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for(int i = 0; i < n; i++)
            pos2[nums2[i]] = i;
        vector<int> num1PosInNum2(n);
        for(int i = 0; i < n; i++)
            num1PosInNum2[i] = pos2[nums1[i]];
        BinarySearchTree bit(n);
        long long result = 0;
        bit.update(num1PosInNum2[0], 1);
        for(int pos1 = 1; pos1 < n - 1; pos1++)
        {
            int pos2 = num1PosInNum2[pos1];
            int left = bit.getLowerCount(pos2);
            bit.update(pos2, 1);
            int right = (n - 1 - pos2) - (pos1 - left);
            result += (long long)left * right;
        }
        return result;
    }
};





int main()
{
    Solution solution;
    vector<int> given_nums1 = {2, 0, 1, 3};
    vector<int> given_nums2 = {0, 1, 2, 3};
    long long expected_answer = 1;
    assert(solution.goodTriplets(given_nums1, given_nums2) == expected_answer);

    given_nums1 = {7, 8, 1 ,0, 4, 2, 5, 6, 3, 9, 11, 10};
    given_nums2 = {7, 9, 10, 6, 0, 8, 1, 2, 3, 11, 4, 5};
    expected_answer = 47;
    assert(solution.goodTriplets(given_nums1, given_nums2) == expected_answer);

    return 0;
}
