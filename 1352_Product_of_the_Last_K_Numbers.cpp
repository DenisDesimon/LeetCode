//#1352 Product of the Last K Numbers - https://leetcode.com/problems/product-of-the-last-k-numbers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class ProductOfNumbers {
    vector<int> Prefix;
public:
    ProductOfNumbers() {
        Prefix.push_back(1);
    }

    void add(int num) {
        if(num == 0)
            Prefix = {1};
        else
            Prefix.push_back(Prefix.back() * num);
    }

    int getProduct(int k) {
        if(k >= (int)Prefix.size())
            return 0;
        return Prefix.back() / Prefix[Prefix.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main()
{
    ProductOfNumbers solution;
    solution.add(3);
    solution.add(5);
    solution.add(7);
    int expected_answer = 35;
    int given_k = 2;
    assert(solution.getProduct(given_k) == expected_answer);

    solution.add(0);
    given_k = 2;
    expected_answer = 0;
    assert(solution.getProduct(given_k) == expected_answer);

    return 0;
}
