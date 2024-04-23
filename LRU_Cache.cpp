#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

struct LRUCache
{
    int capacity;
    list<int> elements;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        updateLRU(key);
        cout << cache[key].first << endl;
        return cache[key].first;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            updateLRU(key);
            cache[key].first = value;
            return;
        }

        if (cache.size() == capacity)
        {
            cache.erase(elements.back());
            elements.pop_back();
        }

        elements.push_front(key);
        cache[key] = {value, elements.begin()};
    }

    void updateLRU(int key)
    {
        elements.erase(cache[key].second);
        elements.push_front(key);
        cache[key].second = elements.begin();
    }
};

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    lRUCache.get(1);
    lRUCache.put(3, 3);
    lRUCache.get(2);
    lRUCache.put(4, 4);
    lRUCache.get(1);
    lRUCache.get(3);
    lRUCache.get(4);

    return 0;
}
