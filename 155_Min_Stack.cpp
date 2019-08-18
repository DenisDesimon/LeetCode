//#155 Min Stack - https://leetcode.com/problems/min-stack/
#include <iostream>
#include <cassert>
using namespace std;

struct item{
    int val;
    item* prev;
    item(int _val, item* _prev = NULL){
        val = _val;
        prev = _prev;
    }
};

class MinStack {
    item* cur = NULL;
    item* min = NULL;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        cur = new item(x, cur);
        if(min == NULL)
            min = new item(x, min);
        else if(x < min->val)
            min = new item(x, min);
        else
            min = new item(min->val, min);
    }

    void pop() {
        item* to_del = cur;
        cur = cur->prev;
        delete to_del;
        to_del = min;
        min = min->prev;
        delete to_del;
    }

    int top() {
        return cur->val;
    }

    int getMin() {
        return min->val;
    }
};



int main()
{
    MinStack solution;
    solution.push(3);
    solution.push(5);
    solution.push(1);
    solution.push(7);
    solution.push(9);
    solution.pop();
    assert(solution.getMin() == 1 && solution.top() == 7);

    return 0;
}
