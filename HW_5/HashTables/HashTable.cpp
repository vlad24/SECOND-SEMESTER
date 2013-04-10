#include <stdio.h>
#include "HashTable.h"
#include "CommonHasher.h"
#include "BaseHasher.h"
#include "PolynomialHasher.h"
#include "List.h"
#include <string.h>

HashTable::HashTable()
{
    tableSize = 31;
    hArray = new List*[tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        hArray[i] = new List;
    }
    hasher = new CommonHasher;
}


void HashTable::addToHashTable(char *string)
{
    int hashIndex = hasher->hashFunction(string);
    hArray[hashIndex]->add(string);
}

void HashTable::removeFromHashTable(char *string)
{
    int hashIndex = hasher->hashFunction(string);
    hArray[hashIndex]->remove(string);
}

bool HashTable::isInHashTable(char *string) const
{
    int hashIndex = hasher->hashFunction(string);
    return (hArray[hashIndex]->stringExsists(string));
}

void HashTable::showStatistics() const
{
    int free = freeCellsAmount();
    int taken = tableSize - free;
    int conflicts = conflictsAmount();
    int worstLength = worstConflict();
    printf("#####################\n");
    //Number of cells
    printf("The current number of cells: %d.\n", tableSize);
    //Number of free
    printf("The current number of free: %d.\n", free);
    //Conflicts
    printf("The current number of conflicts: %d.\n", conflicts);
    //Worst conflict
    if (conflicts != 0)
        printf("The worst length of conflict: %d.\n", worstLength);
    else
        printf("The worst length of conflict: no conflicts.\n");
    //Load factor
    if (free != 0)
    {
        double loadFactor = double(taken) / double(free);
        printf("Load factor: %lf.\n", loadFactor);
    }
    else
        printf("All cells are taken\n");
    printf("#####################\n");
}

void HashTable::setHashFunction(Hasher *newHasher)
{
   Hasher* oldHasher = hasher;
   hasher = newHasher;
   rehashTable(oldHasher);
   delete oldHasher;
}

HashTable::~HashTable()
{
    for (int i = 0; i < tableSize; i++)
        delete hArray[i];
    delete[] hArray;
    delete hasher;
}

int HashTable::freeCellsAmount() const
{
    int result = 0;
    for (int i = 0; i < tableSize; i++)
    {
        if (hArray[i]->isEmpty())
            result++;
    }
    return result;
}


int HashTable::conflictsAmount() const
{
    int conflicts = 0;
    for (int i = 0 ; i < tableSize; i++)
    {
        if (hArray[i]->getLength() > 1)
            conflicts++;
    }
    return conflicts;
}

int HashTable::worstConflict() const
{
    int worst = 0;
    for (int i = 0; i < tableSize; i++)
    {
        if (hArray[i]->getLength() > worst)
            worst = hArray[i]->getLength();
    }
    return worst;
}

void HashTable::rehashTable(Hasher* oldHasher)
{
    for (int i = 0; i < tableSize; i++)
    {
        int k = 1;
        int lengthOfCurrentList = hArray[i]->getLength();
        for (int j = 1; j <= lengthOfCurrentList; j++)
        {
            List::ListElement* tableElement = hArray[i]->takeElement(k);
            if (hasher->hashFunction(tableElement ->value) != oldHasher->hashFunction(tableElement ->value))
            {
                addToHashTable(tableElement->value);
                hArray[oldHasher->hashFunction(tableElement->value)]->remove(tableElement->value);
            }
            else
                k++;
        }
    }
}
