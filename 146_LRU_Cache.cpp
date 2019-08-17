//#146 LRU Cache - https://leetcode.com/problems/lru-cache/
#include <iostream>
#include <map>
#include <list>
#include <cassert>
using namespace std;

class LRUCache {
    map<int, pair<int, list<int>::iterator>> cache;
    list<int> used;
    int size;
    void update_used(int key)
    {
        used.erase(cache[key].second);
        used.push_front(key);
        cache[key].second = used.begin();
    }
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if(!cache.count(key))
            return -1;
        update_used(key);
        return cache[key].first;
    }

    void put(int key, int value) {
        if(cache.count(key))
        {
            cache[key].first = value;
            update_used(key);
            return;
        }
        if((int)cache.size() == size)
        {
            cache.erase(used.back());
            used.pop_back();
        }
        used.push_front(key);
        cache[key] = {value, used.begin()};
    }
};


int main()
{
    LRUCache solution(2);
    solution.put(1, 1);
    solution.put(2, 2);
    solution.get(1);
    solution.put(3, 3);
    int expected_answer = 1;
    assert(solution.get(1) == expected_answer);
    expected_answer = -1;
    assert(solution.get(2) == expected_answer);

    return 0;
}
