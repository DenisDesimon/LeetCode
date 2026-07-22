//#3501 Maximize Active Section with Trade II - https://leetcode.com/problems/maximize-active-section-with-trade-ii/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class SegmentTree{
    int n;
    vector<int> arr;
    vector<int> seg;

    void build(int p, int l, int r){
        if(l == r)
        {
            seg[p] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int _query(int p, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr)
            return seg[p];
        int mid = (l + r) >> 1;
        int result = 0;
        if(ql <= mid)
            result = _query(p << 1, l, mid, ql, qr);
        if(qr > mid)
            result = max(result, _query(p << 1 | 1, mid + 1, r, ql, qr));
        return result;
    }
public:
    SegmentTree(vector<int> arr) : arr(arr){
        n = arr.size();
        seg.resize(n << 2, 0);
        build(1, 0, n - 1);
    }
    int query(int ql, int qr){
        if(ql > qr)
            return 0;
        return _query(1, 0, n - 1, ql, qr);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int countOnes = 0;


        vector<int> countZeroes;
        vector<int> sectionStart;
        vector<int> sectionEnd;

        for(int right = 0; right < n;)
        {
            int left = right;
            while(right < n && s[left] == s[right])
                right++;
            if(s[left] == '0')
            {
                countZeroes.push_back(right - left);
                sectionStart.push_back(left);
                sectionEnd.push_back(right - 1);
            }
            else
                countOnes += right - left;
        }

        int sectionCount = countZeroes.size();
        if(sectionCount < 2)
            return vector<int>(queries.size(), countOnes);
        vector<int> countSectionPairs(sectionCount - 1);
        for (int i = 0; i < sectionCount - 1; i++) {
            countSectionPairs[i] = countZeroes[i] + countZeroes[i + 1];
        }
        SegmentTree seg(countSectionPairs);
        vector<int> result;

        for(auto &query : queries)
        {
            int ql = query[0];
            int qr = query[1];
            int firstSectionStart = lower_bound(sectionEnd.begin(), sectionEnd.end(), ql) - sectionEnd.begin();
            int lastSectionStart = upper_bound(sectionStart.begin(), sectionStart.end(), qr) - sectionStart.begin() - 1;

            if(firstSectionStart > sectionCount - 1 || lastSectionStart < 0 || firstSectionStart >= lastSectionStart)
            {
                result.push_back(countOnes);
                continue;
            }

            int firstLen = sectionEnd[firstSectionStart] - max(sectionStart[firstSectionStart], ql) + 1;
            int lastLen = min(sectionEnd[lastSectionStart], qr) - sectionStart[lastSectionStart] + 1;

            if(firstSectionStart + 1 == lastSectionStart)
            {
                int longestSection = firstLen + lastLen;
                result.push_back(longestSection + countOnes);
                continue;
            }

            int resFirstSection = firstLen + countZeroes[firstSectionStart + 1];
            int resMid = countZeroes[lastSectionStart - 1] + lastLen;
            int resLastSection = seg.query(firstSectionStart + 1, lastSectionStart - 2);
            int longestSection = max({resFirstSection, resMid, resLastSection});
            result.push_back(countOnes + longestSection);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "0100";
    vector<vector<int>> givenQueries = {{0, 3}, {0, 2}, {1, 3}, {2, 3}};
    vector<int> expectedAnswer = {4, 3, 1, 1};
    assert(solution.maxActiveSectionsAfterTrade(givenS, givenQueries) == expectedAnswer);

    givenS = "1000100";
    givenQueries = {{1, 5}, {0, 6}, {0, 4}};
    expectedAnswer = {6, 7, 2};
    assert(solution.maxActiveSectionsAfterTrade(givenS, givenQueries) == expectedAnswer);

    return 0;
}
