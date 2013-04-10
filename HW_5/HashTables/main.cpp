#include <stdio.h>
#include <string.h>
#include "ListTester.h"
#include "HasherTester.h"
#include "HashTableTester.h"
enum answers
{
    end = 0, put, del, exsists, info, changeFunction, common, polynomial, base
};

int main()
{
    ListTester tester;
    QTest::qExec(&tester);
    HasherTester tester2;
    QTest::qExec(&tester2);
    HashTableTester tester3;
    QTest::qExec(&tester3);

    printf("/////////////////////////////////////////////////////\n");
    HashTable* hTable = new HashTable;
    printf("# A NEW HASH TABLE HAS BEEN CREATED.\n");
    printf("# 0 - EXIT\n");
    printf("# 1 - ADD A STRING TO THE HASH TABLE\n");
    printf("# 2 - REMOVE A STRING FROM THE HASH TABLE\n");
    printf("# 3 - CHECK WHETHER A STRING IS IN THE HASH TABLE\n");
    printf("# 4 - SHOW HASH INFO(load factor, number of conflicts, etc)\n");
    printf("# 5 - CHANGE HASH FUNCTION\n");
    printf("/////////////////////////////////////////////////////\n");
    int answer = 0;
    char string[500] = {};
    bool stopIt = false;
    while (!stopIt)
    {
        printf("- What now?\n");
        scanf("%d", &answer);
        switch (answer)
        {
        case end:
        {
            delete hTable;
            stopIt = true;
            break;
        }
        case put :
        {
            printf("# ENTER YOUR STRING TO ADD : \n");
            scanf("%s", &string);
            hTable->addToHashTable(string);
            printf("# Added.\n");
            break;
        }
        case del:
        {
            printf("# ENTER YOUR STRING TO DELETE : \n");
            scanf("%s", &string);
            hTable->removeFromHashTable(string);
            printf("# Removed\n");
            break;
        }
        case exsists:
        {
            printf("# ENTER YOUR STRING TO CHECK IF IT EXSISTS : \n");
            scanf("%s", &string);
            if (hTable->isInHashTable(string))
                printf("# It is in the table\n");
            else
                printf("# It is NOT in the table\n");
            break;
        }
        case info:
        {
            hTable->showStatistics();
            break;
        }
        case changeFunction:
        {
            printf("#########\n");
            printf("Choose the function : \n");
            printf("    6 - Common hash. // SUM OF ((-1)^posSYMBOLInString)*ord(SYMBOL)\n");
            printf("    7 - Polynomial hash. // SUM OF (ord(SYMBOL)* (p)^posSYMBOLInString \n");
            printf("    8 - Base hash. // SUM OF (ord(SYMBOL) in base 2) interpreted as a number in base3\n");
            printf("#########\n");
            int answer2 = common;
            scanf("%d", &answer2);
            switch (answer2)
            {
            case polynomial:
            {
                Hasher* newHasher = new PolynomialHasher;
                hTable->setHashFunction(newHasher);
                printf("# Success.\n");
                break;
            }
            case base:
            {
                Hasher* newHasher = new BaseHasher;
                hTable->setHashFunction(newHasher);
                printf("# Success.\n");
                break;
            }
            case common:
            {
                Hasher* newHasher = new CommonHasher;
                hTable->setHashFunction(newHasher);
                printf("# Success.\n");
                break;
            }
            default:
            {
                printf("# Error\n");
            }
            }
            break;
        }
        }
    }
}
