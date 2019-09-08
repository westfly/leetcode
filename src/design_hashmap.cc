#include "code_utils.h"
#include <string.h>
auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
#pragma GCC optimise ("Ofast")
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
       memset(hash_map, kUnValidValue, sizeof(hash_map));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
       hash_map[key] = value; 
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
       return hash_map[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
       hash_map[key] = kUnValidValue; 
    }
 private:
    static const int kUnValidValue = -1;
    int hash_map[1000000];
};
int main() {
/**
 * Your MyHashMap object will be instantiated and called as such:
 */
 MyHashMap* obj = new MyHashMap();
 int key = 3, value = 10;
 obj->put(key,value);
 int param_2 = obj->get(key);
 obj->remove(key);

 delete obj;
}
