//#1622 Fancy Sequence - https://leetcode.com/problems/fancy-sequence/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Fancy {
private:
    vector<int> vals, a, b;
    int mod = 1e9 + 7;
    int power(int x, int n)
    {
        int result = 1;
        while(n)
        {
            if(n & 1)
                result = (long long)result * x % mod;
            n >>= 1;
            x = (long long)x * x % mod;
        }
        return result;
    }
    int inversion(int num){
        return power(num, mod - 2);
    }
public:
    Fancy() {
        a.push_back(1);
        b.push_back(0);
    }

    void append(int val) {
        vals.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }

    void addAll(int inc) {
        b.back() = (b.back() + inc) % mod;
    }

    void multAll(int m) {
        a.back() = ((long long)a.back() * m) % mod;
        b.back() = ((long long)b.back() * m) % mod;
    }

    int getIndex(int idx) {
        if(idx >= (int)vals.size())
            return -1;
        int aResult = (long long)a.back() * inversion(a[idx]) % mod;
        int bResult = (b.back() - (long long)b[idx] * aResult % mod + mod) % mod;
        return ((long long)aResult * vals[idx] % mod + bResult) % mod;
    }
};

int main()
{
    Fancy *fancy = new Fancy();
    int givenVal = 2;
    fancy->append(givenVal);   // fancy sequence: [2]
    int givenInc = 3;
    fancy->addAll(givenInc);   // fancy sequence: [2+3] -> [5]
    givenVal = 7;
    fancy->append(7);   // fancy sequence: [5, 7]
    int givenM = 2;
    fancy->multAll(givenM);  // fancy sequence: [5*2, 7*2] -> [10, 14]
    givenInc = 3;
    fancy->addAll(givenInc);   // fancy sequence: [10+3, 14+3] -> [13, 17]
    givenVal = 10;
    fancy->append(givenVal);  // fancy sequence: [13, 17, 10]
    givenM = 2;
    fancy->multAll(givenM);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
    int expectedAnswer = 26;
    int givenIdx = 0;
    assert(fancy->getIndex(givenIdx) == expectedAnswer);

    expectedAnswer = 34;
    givenIdx = 1;
    assert(fancy->getIndex(givenIdx) == expectedAnswer);

    expectedAnswer = 20;
    givenIdx = 2;
    assert(fancy->getIndex(givenIdx) == expectedAnswer);


    return 0;
}
