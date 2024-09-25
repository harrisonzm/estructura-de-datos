#pragma once
#include <list> // Include for STL list
#include <classes for labs/headers/Usuario.hpp>
#include <utility>
#include <typeinfo>
#include <iostream>
#include <cmath>

template<typename K, typename V>
class hashTable
{
public:
    hashTable(int m, char type);

    void insert(K key, V* value);
    V* deleteFrom(K key);
    V& operator[](K key); // search operation
    void toPrint();

private:
    int hashingM(K key);
    int hashingD(K key);
    const double A = double(std::sqrt(5)) / double(2);
    int m = 0;
    char type = 'N';
    std::list<std::pair<K, V>>* table = nullptr;  // Replaced custom linked list with STL list
};

// IMPLEMENTATION

template<typename K, typename V>
hashTable<K, V>::hashTable(int m, char type)
{
    this->table = new std::list<std::pair<K, V>>[m];  // Initialize the hash table using std::list
    this->type = type;
    this->m = m;
}

template<typename K, typename V>
void hashTable<K, V>::insert(K key, V* value)
{
    int index = (type == 'D') ? hashingD(key) : hashingM(key);
    std::pair<K, V> tempPair = std::make_pair(key, *value);
    table[index].push_back(tempPair);  // Use push_back to add the element to the list
}

template<typename K, typename V>
V* hashTable<K, V>::deleteFrom(K key)
{
    int index = (type == 'D') ? hashingD(key) : hashingM(key);
    auto it = table[index].begin();

    while (it != table[index].end() && it->first != key) {
        ++it;
    }

    if (it != table[index].end()) {
        V* result = &it->second;
        table[index].erase(it);  // Remove the element from the list
        return result;
    }

    return nullptr;
}

template<typename K, typename V>
V& hashTable<K, V>::operator[](K key)
{
    int index = (type == 'D') ? hashingD(key) : hashingM(key);
    auto it = table[index].begin();

    while (it != table[index].end() && it->first != key) {
        ++it;
    }

    if (it == table[index].end()) {
        throw std::out_of_range("Key not found in hash table");
    }

    return it->second;
}

template<typename K, typename V>
int hashTable<K, V>::hashingM(K key)
{
    return key % m;
}

template<typename K, typename V>
int hashTable<K, V>::hashingD(K key)
{
    long double tmp = fmod((key * A), double(1));
    return static_cast<int>(m * tmp);
}

template<typename K, typename V>
void hashTable<K, V>::toPrint()
{
    for (int i = 0; i < m; i++) {
        std::cout << "Bucket : " << i << "\n";
        for (const auto& pair : table[i]) {
            if constexpr (std::is_same_v<V, Usuario>) {
                // If the value type is Usuario, print the ID
                std::cout << pair.second.getId() << " ";
            }
            else {
                // For other types, print the value directly
                std::cout << pair.second << " ";
            }
        }
        std::cout << "\n";
    }
}
