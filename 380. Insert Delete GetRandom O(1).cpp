#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    vector<int> array;
    unordered_map<int, int> index;

    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (index.find(val) != index.end()) return false;
        array.push_back(val);
        index.insert({val, array.size()-1});
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto val_index = index.find(val); //val_index is a dictionary item
        if (val_index == index.end()) return false;
        auto last_index = index.find(array.back()); //last_index is a dictionary item
        swap(array[val_index->second], array[last_index->second]); //swap
        index[last_index->first] = val_index->second; //update the map
        array.pop_back(); //delete val from the array
        index.erase(val_index); // delete val from the map
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return array[rand()%array.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */