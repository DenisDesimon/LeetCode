//#2043 Simple Bank System - https://leetcode.com/problems/simple-bank-system/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Bank {
    vector<long long> accounts;
    int n;
public:
    Bank(vector<long long>& balance) {
        n = balance.size();
        accounts = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        account1--, account2--;
        if(account1 >= n || account2 >= n || accounts[account1] < money)
            return false;
        accounts[account1] -= money;
        accounts[account2] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        account--;
        if(account >= n)
            return false;
        accounts[account] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        account--;
        if(account >= n || accounts[account] < money)
            return false;
        accounts[account] -= money;
        return true;
    }
};

int main()
{
    vector<long long> givenBalance = {10, 100, 20, 50, 30};
    Bank solution(givenBalance);
    int givenAccount = 3;
    int givenMoney = 10;
    bool expectedAnswer = true;
    assert(solution.withdraw(givenAccount, givenMoney) == expectedAnswer);

    givenAccount = 3;
    int givenAccountSecond = 4;
    givenMoney = 15;
    expectedAnswer = false;
    assert(solution.transfer(givenAccount, givenAccountSecond, givenMoney) == expectedAnswer);

    return 0;
}
