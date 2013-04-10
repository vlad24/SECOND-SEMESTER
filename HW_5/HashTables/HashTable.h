#pragma once
#include "List.h"
#include "Hasher.h"
/*!
  A class that provides all necessary functions to work with hash tables
  */
class HashTable
{
public:
    HashTable();
    void addToHashTable(char* string);
    void removeFromHashTable(char* string);
    bool isInHashTable(char* string) const;
    void showStatistics() const;
    //! Changes the current hash function after what the table is rehashed
    void setHashFunction(Hasher* newHasher);
    ~HashTable();
private:
    Hasher* hasher;
    int tableSize;
    List** hArray;

    int freeCellsAmount() const;
    int conflictsAmount() const;
    //! Works out the longes length of conflict
    int worstConflict() const;
    void rehashTable(Hasher *oldHasher);

};
