#include "MultiTreeSetTester.h"
#include "MultiTreeSet.h"
#include <iostream>

using namespace std;

enum command
{
    stop = 0, add, deleteValue, printup, exsists, intersect, summing, symbols, numbers
};

void introduction()
{
    cout << "---\n# 0 - exit" << endl;
    cout << "# 1 - add value to the set" << endl;
    cout << "# 2 - remove value from the set" << endl;
    cout << "# 3 - print set" << endl;
    cout << "# 4 - exsists in set" << endl;
    cout << "# 5 - intersect the current set with another" << endl;
    cout << "# 6 - sum the current se with another set" << endl;
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
    MultiTreeSetTester testerSet;
    QTest::qExec(&testerSet);
    int type = askType();
    introduction();
    int answer = -1;
    int intValue = 0;
    char charValue = '+';
    if (type == symbols)
    {
        MultiTreeSet<char>* treeSet = new MultiTreeSet<char>;
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
                treeSet->printTree();
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
            case(intersect):
            {
                cout << "#Fill another set:\n #0 - exit\n #1 - add\n #2 - remove\n";
                MultiTreeSet<char>* anotherTreeSet = new MultiTreeSet<char>;
                int anotherAnswer = 1;
                while (anotherAnswer != stop)
                {
                    anotherAnswer = askAction();
                    switch(anotherAnswer)
                    {
                    case(stop):
                    {
                        cout << "You have finished with the second set\n Result of intersection:\n";
                        break;
                    }
                    case(add):
                    {
                        cout << "What value? " << endl;
                        cin >> charValue;
                        anotherTreeSet->addToTree(charValue);
                        break;
                    }
                    case(deleteValue):
                    {
                        cout << "What value? " << endl;
                        cin >> charValue;
                        anotherTreeSet->removeFromTree(charValue);
                        break;
                    }
                    }
                }
                treeSet->intersectTrees(anotherTreeSet);
                delete anotherTreeSet;
                break;
            }
            case(summing):
            {
                cout << "Fill another set\n #0 - exit\n #1 - add\n #2 - remove\n";
                MultiTreeSet<char>* anotherTreeSet = new MultiTreeSet<char>;
                int anotherAnswer = 1;
                while (anotherAnswer != stop)
                {
                    anotherAnswer = askAction();
                    switch(anotherAnswer)
                    {
                    case(stop):
                    {
                        cout << "You have finished with the second set\n Result of intersection:\n";
                        break;
                    }
                    case(add):
                    {
                        cout << "What value? " << endl;
                        cin >> charValue;
                        anotherTreeSet->addToTree(charValue);
                        break;
                    }
                    case(deleteValue):
                    {
                        cout << "What value? " << endl;
                        cin >> charValue;
                        anotherTreeSet->removeFromTree(charValue);
                        break;
                    }
                    }
                }
                treeSet->sumTrees(anotherTreeSet);
                delete anotherTreeSet;
                break;
            }
            }
        }
        delete treeSet;
    }
    else
    {
        MultiTreeSet<int>* treeSet = new MultiTreeSet<int>;
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
                treeSet->printTree();
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
            case(intersect):
            {
                cout << "#Fill another set:\n #0 - exit\n #1 - add\n #2 - remove\n";
                MultiTreeSet<int>* anotherTreeSet = new MultiTreeSet<int>;
                int anotherAnswer = 1;
                while (anotherAnswer != stop)
                {
                    anotherAnswer = askAction();
                    switch(anotherAnswer)
                    {
                    case(stop):
                    {
                        cout << "You have finished with the second set\n Result of intersection:\n";
                        break;
                    }
                    case(add):
                    {
                        cout << "What value? " << endl;
                        cin >> charValue;
                        anotherTreeSet->addToTree(charValue);
                        break;
                    }
                    case(deleteValue):
                    {
                        cout << "What value? " << endl;
                        cin >> charValue;
                        anotherTreeSet->removeFromTree(charValue);
                        break;
                    }
                    }
                }
                treeSet->intersectTrees(anotherTreeSet);
                delete anotherTreeSet;
                break;
            }
            case(summing):
            {
                cout << "Fill another set\n #0 - exit\n #1 - add\n #2 - remove\n";
                MultiTreeSet<int>* anotherTreeSet = new MultiTreeSet<int>;
                int anotherAnswer = 1;
                while (anotherAnswer != stop)
                {
                    anotherAnswer = askAction();
                    switch(anotherAnswer)
                    {
                    case(stop):
                    {
                        cout << "You have finished with the second set\n Result of summing:\n";
                        break;
                    }
                    case(add):
                    {
                        cout << "What value? " << endl;
                        cin >> intValue;
                        anotherTreeSet->addToTree(intValue);
                        break;
                    }
                    case(deleteValue):
                    {
                        cout << "What value? " << endl;
                        cin >> intValue;
                        anotherTreeSet->removeFromTree(intValue);
                        break;
                    }
                    }
                }
                treeSet->sumTrees(anotherTreeSet);
                delete anotherTreeSet;
                break;
            }
            }
        }
        delete treeSet;
    }
}
