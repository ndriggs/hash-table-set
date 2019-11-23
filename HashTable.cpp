#include "HashTable.h"

using namespace std;

HashTable::HashTable(){
    htable = new list<int>[defaultSize];
    sizes = new int[defaultSize];
}

HashTable::HashTable(int size){
    htable = new list<int>[size];
    sizes = new int[size];
}

HashTable::~HashTable(){
    clear();
}

int HashTable::getHashCode(int data){ //converts the data into the hashcode
    return data;
}


// returns the number of items in the set
int HashTable::size(){
    int size = 0;
    for(int i : sizes)
        size += sizes[i];
    return size;
} 

// returns true if the integer "data" is in the set and false otherwise
bool HashTable::find(int data){
    int index = getHashCode(data);
    for(int i : htable){
        if(htable[i] == data)
            return true;
    }
    return false;
} 

// inserts the integer "data" into the set if that integer is not already in the set
// if the integer "data" is already in the set, the integer should not be inserted
// return true if the function adds the integer to the set, and false otherwise
bool HashTable::insert(int data){
    return true;
} 

// erases the integer "data" from the set if it is in the set
// return true if the function removes the integer from the set, and false otherwise
bool HashTable::erase(int data){
    return true;
}

void HashTable::clear(){
    delete htable;
    delete sizes;
    
    for(int i : htable)
        delete htable[i];
}