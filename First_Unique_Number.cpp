//#First Unique Number - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/531/week-4/3313/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <cassert>
using namespace std;

class FirstUnique {
    unordered_map<int, list<int>::iterator> hash;
    list<int> unique;
    void delete_num(int num){
        if(hash[num] != unique.end())
        {
            unique.erase(hash[num]);
            hash[num] = unique.end();
        }
    }
public:
    FirstUnique(vector<int>& nums) {
        for(auto& num : nums)
        {
            if(!hash.count(num))
            {
                unique.push_back(num);
                hash[num] = unique.end();
                hash[num]--;
            }
            else
                delete_num(num);
        }
    }

    int showFirstUnique() {
        if(!unique.empty())
            return unique.front();
        else
            return -1;
    }

    void add(int value) {
        if(!hash.count(value))
        {
            unique.push_back(value);
            hash[value] = unique.end();
            hash[value]--;
        }
        else
            delete_num(value);
    }
};

int main()
{
    vector<int> given_nums = {7, 7, 7, 7, 7, 7};
    FirstUnique solution(given_nums);
    int expected_answer = 17;
    solution.add(3);
    solution.add(3);
    solution.add(7);
    solution.add(17);
    assert(solution.showFirstUnique() == expected_answer);

    given_nums = {2, 3, 5};
    solution = FirstUnique(given_nums);
    expected_answer = 3;
    solution.add(2);
    solution.add(5);
    assert(solution.showFirstUnique() == expected_answer);

    return 0;
}
