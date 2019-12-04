#include <iostream>
#include <time.h>
// TODO: include the appropriate library for that class
#include <set>
#include <unordered_set>
#include "HashTable.h"    // this was the name of my header file for my hash set 
//class
#include "AVL.h"
using namespace std;
// takes as input the number of items to insert into the set
int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Not enough arguments" << endl;
        return 0;
    }
    int N = atoi(argv[1]);  // store the number of items to be put into the set 
//into the integer N
    // store N random integers into an array
    int *insertNums = new int[N];
    for (int i = 0; i < N; i++) {
        insertNums[i] = rand() % 99999;
    }
    long empieza, fin;
    
    
    //-------SET--------------
    set<int> *s = new set<int>;
    cout << "Insert " << N << " integers into from the SET ... ";
    empieza = clock();
    for (int i = 0; i < N; i++) {
        s->insert(insertNums[i]);
    }
    fin = clock();
    cout << "done" << endl;
    cout << "Processor time elapsed to insert " << N << " items: " << (fin - 
empieza) << endl << endl << endl;
    cout << "Remove " << N << " integers into from the SET ... ";
    empieza = clock();
    for (int i = 0; i < N; i++) {
        s->erase(insertNums[i]);
    }
    fin = clock();
    cout << "done" << endl;
    cout << "Processor time elapsed to remove " << N << " items: " << (fin - 
empieza) << endl << endl << endl;
    delete s;
    
    
    //UNORDER SET
    unordered_set<int> *us = new unordered_set<int>;
    cout << "Insert " << N << " integers into from the UNORDERED_SET ... ";
    empieza = clock();
    for (int i = 0; i < N; i++) {
        us->insert(insertNums[i]);
    }
    fin = clock();
    cout << "done" << endl;
    cout << "Processor time elapsed to insert " << N << " items: " << (fin - 
empieza) << endl << endl << endl;
    cout << "Remove " << N << " integers into from the UNORDERED_SET ... ";
    empieza = clock();
    for (int i = 0; i < N; i++) {
        us->erase(insertNums[i]);
    }
    fin = clock();
    cout << "done" << endl;
    cout << "Processor time elapsed to remove " << N << " items: " << (fin - 
empieza) << endl << endl << endl;
    delete us;
    
    
    //AVL TREE
    AVL *a = new AVL();
    cout << "Insert " << N << " integers into from the AVL TREE ... ";
    empieza = clock();
    for (int i = 0; i < N; i++) {
        a->add(insertNums[i]);
    }
    fin = clock();
    cout << "done" << endl;
    cout << "Processor time elapsed to insert " << N << " items: " << (fin - 
empieza) << endl << endl << endl;
    cout << "Remove " << N << " integers into from the AVL TREE ... ";
    empieza = clock();
    for (int i = 0; i < N; i++) {
        a->remove(insertNums[i]);
    }
    fin = clock();
    cout << "done" << endl;
    cout << "Processor time elapsed to remove " << N << " items: " << (fin - 
empieza) << endl << endl << endl;
    delete a;
    
    
    //HASHTABLE
    HashTable *h = new HashTable(N);
    cout << "Insert " << N << " integers into from the HASHTABLE ... ";
    empieza = clock();
    for (int i = 0; i < N; i++) {
        h->insert(insertNums[i]);
    }
    fin = clock();
    cout << "done" << endl;
    cout << "Processor time elapsed to insert " << N << " items: " << (fin - 
empieza) << endl << endl << endl;
    cout << "Remove " << N << " integers into from the HASHTABLE ... ";
    empieza = clock();
    for (int i = 0; i < N; i++) {
        h->erase(insertNums[i]);
    }
    fin = clock();
    cout << "done" << endl;
    cout << "Processor time elapsed to remove " << N << " items: " << (fin - 
empieza) << endl << endl << endl;
    delete[] insertNums;
    delete h;
    
    return 0;
}

