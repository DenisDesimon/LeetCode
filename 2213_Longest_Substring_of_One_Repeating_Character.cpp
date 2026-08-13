//#2213 Longest Substring of One Repeating Character - https://leetcode.com/problems/longest-substring-of-one-repeating-character/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class SegmentTree{
    int n;
    vector<int> pre, suff;
    vector<char> leftLetter, rightLetter;
    string s;
    void merge(int u, int l, int r)
    {
        int mid = (l + r) >> 1;
        int leftLen = mid - l + 1, rightLen = r - mid;
        int left = u << 1, right = u << 1 | 1;
        leftLetter[u] = leftLetter[left];
        rightLetter[u] = rightLetter[right];
        pre[u] = pre[left];
        if(pre[left] == leftLen && rightLetter[left] == leftLetter[right])
            pre[u] = pre[left] + pre[right];
        suff[u] = suff[right];
        if(suff[right] == rightLen && rightLetter[left] == leftLetter[right])
            suff[u] = suff[right] + suff[left];
        maxLen[u] = max(maxLen[left], maxLen[right]);
        if(rightLetter[left] == leftLetter[right])
            maxLen[u] = max(maxLen[u], suff[left] + pre[right]);
    }
public:
    vector<int> maxLen;
    SegmentTree(string s){
        n = s.size();
        this->s = s;
        pre.resize(4 * n);
        suff.resize(4 * n);
        maxLen.resize(4 * n);
        leftLetter.resize(4 * n);
        rightLetter.resize(4 * n);
    }
    void build(int u, int l, int r)
    {
        if(l == r)
        {
            pre[u] = 1;
            suff[u] = 1;
            maxLen[u] = 1;
            leftLetter[u] = s[l];
            rightLetter[u] = s[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        merge(u, l, r);
    }
    void update(int u, int l, int r, int pos, char letter)
    {
        if(l == r)
        {
            leftLetter[u] = letter;
            rightLetter[u] = letter;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid)
            update(u << 1, l, mid, pos, letter);
        else
            update(u << 1 | 1, mid + 1, r, pos, letter);
        merge(u, l, r);
    }

};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree tree(s);
        int n = s.size();
        int k = queryCharacters.size();
        tree.build(1, 0, n - 1);
        vector<int> result(k);
        for(int i = 0; i < k; i++)
        {
            tree.update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result[i] = tree.maxLen[1];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "babacc";
    string givenCharacters = "bcb";
    vector<int> givenIndices = {1, 3, 3};
    vector<int> expectedAnswer = {3, 3, 4};
    assert(solution.longestRepeating(givenS, givenCharacters, givenIndices) == expectedAnswer);

    givenS = "abyzz";
    givenCharacters = "aa";
    givenIndices = {2, 1};
    expectedAnswer = {2, 3};
    assert(solution.longestRepeating(givenS, givenCharacters, givenIndices) == expectedAnswer);


    return 0;
}
