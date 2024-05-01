#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomizedSet
{
private:
    std::unordered_map<int, int> valToIndex;
    std::vector<int> values;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (valToIndex.find(val) != valToIndex.end())
            return false; // Element already exists
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (valToIndex.find(val) == valToIndex.end())
            return false; // Element not found
        int index = valToIndex[val];
        int last = values.back();
        values[index] = last;
        valToIndex[last] = index;
        values.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom()
    {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
};

int main()
{
    srand(time(NULL)); // Seed the random number generator

    RandomizedSet *obj = new RandomizedSet();

    // Insert some elements
    obj->insert(1);
    obj->insert(2);
    obj->insert(3);
    obj->insert(4);

    // Remove an element
    obj->remove(2);

    // Get a random element
    int randomElement = obj->getRandom();
    cout << "Random element: " << randomElement << endl;

    delete obj;
    return 0;
}
