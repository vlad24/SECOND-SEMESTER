#include "TreeSet.h"
#include "TreeTester.h"
#include <iostream>

using namespace std;

enum command
{
    stop = 0, add, deleteValue, printup, exsists, intersect, sum, symbols, numbers
};

void introduction()
{
    cout << "---\n# 0 - exit" << endl;
    cout << "# 1 - add value to the set" << endl;
    cout << "# 2 - remove value from the set" << endl;
    cout << "# 3 - print set common" << endl;
    cout << "# 4 - exsists in set" << endl;
    cout << "# 5 - intersect two sets" << endl;
    cout << "# 6 - sum two sets" << endl;
}

int askType()
{
    int ans = 0;
    cout << "What type of set wil you work with? (7 - char ; 8 - int) " << endl;
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
    int setAnswer = 1;
    int intValue = 0;
    char charValue = '+';
    if (type == symbols)
    {
        Tree<char>* treeSet = new Tree<char>;
        Tree<char>* treeSet2 = new Tree<char>;
        while (answer != stop)
        {
            answer = askAction();
            switch(answer)
            {
            case(add):
            {
                cout << "What value? " << endl;
                cin >> charValue;
                cout << "To what set?(1 or 2) ";
                cin >> setAnswer;
                if (setAnswer == 1)
                    treeSet->addToTree(charValue);
                else
                    treeSet2->addToTree(charValue);
                cout << "Done." << endl;
                break;
            }
            case(deleteValue):
            {
                cout << "What value? " << endl;
                cin >> charValue;
                cout << "From what set?(1 or 2) ";
                cin >> setAnswer;
                if (setAnswer == 1)
                    treeSet->removeFromTree(charValue);
                else
                    treeSet2->removeFromTree(charValue);
                cout << "Done." << endl;
                break;
            }
            case(printup):
            {
                cout << "What set?(1 or 2) ";
                cin >> setAnswer;
                if (setAnswer == 1)
                    treeSet->treeInorder();
                else
                    treeSet2->treeInorder();
                break;
            }
            case(exsists):
            {
                cout << "What value? " << endl;
                cin >> charValue;
                cout << "What set?(1 or 2)" << endl;
                cin >> setAnswer;
                if (setAnswer == 1)
                {
                    if (treeSet->exsistsInTree(charValue))
                        cout << "Exsists" << endl;
                    else
                        cout << "Doesn't exsist" << endl;
                }
                else
                {
                    if (treeSet2->exsistsInTree(charValue))
                        cout << "Exsists" << endl;
                    else
                        cout << "Doesn't exsist" << endl;
                }

                break;
            }
            case (intersect):
            {
                treeSet->intersectTrees(treeSet2);
                break;
            }
            case (sum):
            {
                treeSet->sumTrees(treeSet2);
                break;
            }
            }
        }
        delete treeSet;
        delete treeSet2;
    }
    else
    {
        Tree<int>* treeSet = new Tree<int>;
        Tree<int>* treeSet2 = new Tree<int>;
        while (answer != stop)
        {
            answer = askAction();
            switch(answer)
            {
            case(add):
            {
                cout << "What value? " << endl;
                cin >> intValue;
                cout << "To what set?(1 or 2) ";
                cin >> setAnswer;
                if (setAnswer == 1)
                    treeSet->addToTree(intValue);
                else
                    treeSet2->addToTree(intValue);
                cout << "Done." << endl;
                break;
            }
            case(deleteValue):
            {
                cout << "What value? " << endl;
                cin >> intValue;
                cout << "From what set?(1 or 2) ";
                cin >> setAnswer;
                if (setAnswer == 1)
                    treeSet->removeFromTree(intValue);
                else
                    treeSet2->removeFromTree(intValue);
                cout << "Done." << endl;
                break;
            }
            case(printup):
            {
                cout << "What set?(1 or 2) ";
                cin >> setAnswer;
                if (setAnswer == 1)
                    treeSet->treeInorder();
                else
                    treeSet2->treeInorder();
                break;
            }
            case(exsists):
            {
                cout << "What value? " << endl;
                cin >> intValue;
                cout << "What set?(1 or 2)" << endl;
                cin >> setAnswer;
                if (setAnswer == 1)
                {
                    if (treeSet->exsistsInTree(intValue))
                        cout << "Exsists" << endl;
                    else
                        cout << "Doesn't exsist" << endl;
                }
                else
                {
                    if (treeSet2->exsistsInTree(intValue))
                        cout << "Exsists" << endl;
                    else
                        cout << "Doesn't exsist" << endl;
                }

                break;
            }
            case (intersect):
            {
                treeSet->intersectTrees(treeSet2);
                break;
            }
            case (sum):
            {
                treeSet->sumTrees(treeSet2);
                break;
            }
            }
        }
        delete treeSet;
        delete treeSet2;
    }
}
