#include "HashTable.h"


using namespace std;

HashTable::HashTable(){
    htable = new list<int>[defaultSize];
}

HashTable::HashTable(int size){
    htable = new list<int>[size];
    sizes = new int[size];
}

HashTable::~HashTable(){
    clear();
}

// returns the number of items in the set
int HashTable::size(){
    int size = 0;
    for(int i : htable)
        size += htable[i].size();
    return size;
} 

// returns true if the integer "data" is in the set and false otherwise
bool HashTable::find(int data){
    int index = data % numBins;
    for(list<int>::iterator it = htable[index].begin(); it != htable[index].end(); ++it){
        if(*it == data)
            return true;
    }
    return false;
} 

double HashTable::loadFactor(){
    return double(size())/numBins;
}

// inserts the integer "data" into the set if that integer is not already in the set
// if the integer "data" is already in the set, the integer should not be inserted
// return true if the function adds the integer to the set, and false otherwise
bool HashTable::insert(int data){
    int index = data % numBins;
    
    //first duplicate check
    for(list<int>::iterator it = htable[index].begin(); it != htable[index].end(); ++it){
        if(*it == data){
            return false;
        }
    }
    //no duplicate found? feel free to add it
    htable[index].push_back(data);
    
    //now let's check and see if we need to rehash
    checkRehash(true);
    
    return true;
} 

// erases the integer "data" from the set if it is in the set
// return true if the function removes the integer from the set, and false otherwise
bool HashTable::erase(int data){
    int index = data % numBins;
    
    //first find our item
    for(list<int>::iterator it = htable[index].begin(); it != htable[index].end(); ++it){
        if(*it == data){
            htable[index].erase(it);
            checkRehash(false);
            return true;
        }
    }
    //now let's check and see if we need to rehash
    checkRehash();
    
    return false;
}

void HashTable::checkRehash(bool addOrSubtract){
    if(addOrSubtract)
        newItemsInserted++;
    else
        newItemsInserted--;
    if(newItemsInserted > 10){
        if(loadFactor() > 1){
            //rehash
            newItemsInserted = 0;
        }
    }
}

void HashTable::clear(){
    delete [] htable;
}