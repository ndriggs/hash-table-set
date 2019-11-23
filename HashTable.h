#pragma once

#include <iostream>
#include <list>

using namespace std;

class HashTable {
private :
    list<int> *htable;
    int *sizes; //stores the size of each bin in the hashtable
    
    int getHashCode(int data); //converts the data into the hashcode
    //int getIndex(long hashCode); //mods the hash code to get the correct index
    const int defaultSize = 10;
    int numBins;
    void clear();
    
public :
    HashTable();
    HashTable(int size);
    ~HashTable();
    
    // returns the number of items in the set
    int size(); 
    
    // returns true if the integer "data" is in the set and false otherwise
    bool find(int data); 
    
    // inserts the integer "data" into the set if that integer is not already in the set
    // if the integer "data" is already in the set, the integer should not be inserted
    // return true if the function adds the integer to the set, and false otherwise
    bool insert(int data); 
    
    // erases the integer "data" from the set if it is in the set
    // return true if the function removes the integer from the set, and false otherwise
    bool erase(int data);
};
