#include "TreeSet.h"
#include "TreeTester.h"
#include <iostream>

using namespace std;

enum command
{
    stop = 0, add, deleteValue, printup, exsists, symbols, numbers
};

void introduction()
{
    cout << "---\n# 0 - exit" << endl;
    cout << "# 1 - add value to the set" << endl;
    cout << "# 2 - remove value from the set" << endl;
    cout << "# 3 - print set common" << endl;
    cout << "# 4 - exsists in set" << endl;
}

int askType()
{
    int ans = 0;
    cout << "What type of set wil you work with? (5 - char ; 6 - int) " << endl;
    cin >> ans;
    return ans;
}

int askAction()
{
    cout << "What now? : ";
    int answer = 0;
    cin >> answer;
    return answer;
}

int main()
{
    TreeTester tester;
    QTest::qExec(&tester);
    int type = askType();
    introduction();
    int answer = -1;
    int intValue = 0;
    char charValue = '+';
    if (type == symbols)
    {
        Tree<char>* treeSet = new Tree<char>;
        while (answer != stop)
        {
            answer = askAction();
            switch(answer)
            {
            case(add):
            {
                cout << "What value? " << endl;
                cin >> charValue;
                treeSet->addToTree(charValue);
                cout << "Done." << endl;
                break;
            }
            case(deleteValue):
            {
                cout << "What value? " << endl;
                cin >> charValue;
                treeSet->removeFromTree(charValue);
                cout << "Done." << endl;
                break;
            }
            case(printup):
            {
                treeSet->treeInorder();
                cout << endl;
                break;
            }
            case(exsists):
            {
                cout << "What value? " << endl;
                cin >> charValue;
                if (treeSet->exsistsInTree(charValue))
                    cout << "Exsists" << endl;
                else
                    cout << "Doesn't exsist" << endl;
                break;
            }
            }
        }
        delete treeSet;
    }
    else
    {
        Tree<int>* treeSet = new Tree<int>;
        while (answer != stop)
        {
            answer = askAction();
            switch(answer)
            {
            case(add):
            {
                cout << "What value? " << endl;
                cin >> intValue;
                treeSet->addToTree(intValue);
                cout << "Done." << endl;
                break;
            }
            case(deleteValue):
            {
                cout << "What value? " << endl;
                cin >> intValue;
                treeSet->removeFromTree(intValue);
                cout << "Done." << endl;
                break;
            }
            case(printup):
            {
                treeSet->treeInorder();
                cout << endl;
                break;
            }
            case(exsists):
            {
                cout << "What value? " << endl;
                cin >> intValue;
                if (treeSet->exsistsInTree(intValue))
                    cout << "Exsists" << endl;
                else
                    cout << "Doesn't exsist" << endl;
                break;
            }
            }
        }
        delete treeSet;
    }
}
