#include <iostream>
#include <cstring> 
#include "crc.h"
using namespace std;
#define MAX_SIZE  10000
template <class Key, class Value>
class Dictionary {
private:
    Key keys[MAX_SIZE];
    Value values[MAX_SIZE];

public:
    Dictionary() {
        memset(keys, 0, sizeof(keys));
        memset(values, 0, sizeof(values));
    }
    void set(const Key& key, const Value& value) {
        unsigned long hash = calculate_crc32(reinterpret_cast<const unsigned char*>(&key), sizeof(key));
        int index = hash % MAX_SIZE;
        while (keys[index] != Key() && index < MAX_SIZE)
        {
            index = (index + 1);
        }
        if (index < MAX_SIZE) 
        {
            keys[index] = key;
            values[index] = value;
        }
        else 
        {
            cout << "Dictionary is full. Cannot insert more elements." << endl;
        }
    }

    Value get(const Key& key) {
        unsigned long hash = calculate_crc32(reinterpret_cast<const unsigned char*>(&key), sizeof(key));
        int index = hash % MAX_SIZE;
        while (keys[index] != key && index < MAX_SIZE)
        {
            index = (index + 1);
        }
        if (keys[index] == key) 
        {
            return values[index];
        }
        else 
        {
            cout << "Key not found in the dictionary." << endl;
            return Value();
        }
    }
};