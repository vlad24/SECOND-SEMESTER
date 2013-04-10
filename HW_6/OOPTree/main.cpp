#include <stdio.h>
#include "Tree.h"
#include "TreeTester.h"
int main()
{
    TreeTester tester;
    QTest::qExec(&tester);
    //getc(stdin);
    Tree* tree = new Tree;
    int result = tree->calculateStringByTree("* (*( +( *(45) 4) 2)5)");
    tree->printTree();
    printf("\n%d ", result);
    delete tree;
    return 0;
}

