//#93 Restore IP Addresses - https://leetcode.com/problems/restore-ip-addresses/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    void restoreIpAddressess(string& s, vector<string>& result, vector<string>& cur_ip, int count, int pos){
        if(count == 4 && pos == (int)s.size())
        {
            string res;
            for(auto &item : cur_ip)
                res += item + '.';
            res.pop_back();
            result.push_back(res);
            return;
        }
        if(count >= 4)
            return;
        for(int i = 1; i <= 3 && pos + i - 1 < (int)s.size(); i++)
        {
            string cur_num = s.substr(pos, i);
            if(stoi(cur_num) > 255 || (cur_num.size() > 1 && cur_num[0] == '0'))
                break;
            if((3 - count) * 3 < (int)s.size() - pos - i)
                continue;
            cur_ip.push_back(cur_num);
            restoreIpAddressess(s, result, cur_ip, count + 1, pos + i);
            cur_ip.pop_back();
        }


    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> cur_ip;
        restoreIpAddressess(s, result, cur_ip, 0, 0);
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "25525511135";
    vector<string> expected_answer = {"255.255.11.135", "255.255.111.35"};
    assert(solution.restoreIpAddresses(given_s) == expected_answer);

    return 0;
}
