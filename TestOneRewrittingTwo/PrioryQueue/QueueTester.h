#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "PrioryQueue.h"

class QueueTester : public QObject
{
    Q_OBJECT
public:
    explicit QueueTester(QObject *parent = 0) : QObject(parent){}

private slots:

    void testIsEmpty()
    {
        PrioryQueue<char> queue;
        QVERIFY(queue.isEmpty());
    }

    void testAdding()
    {
        PrioryQueue<char> queue;
        queue.enqueue('b', 9);
        queue.enqueue('c', 5);
        QVERIFY(queue.head->value == 'b');
        QVERIFY(queue.head->next->value == 'c');
    }    

    void testTaking()
    {
        PrioryQueue<int> queue;
        queue.enqueue(2, 2);
        queue.enqueue(3, 3);
        int result = queue.dequeue();
        QVERIFY(result == 3);
    }

    void testTakingFromEmpty()
    {
        PrioryQueue<int> queue;
        queue.enqueue(2,2);
        queue.dequeue();
        bool success = false;
        try
        {
            queue.dequeue();
        }
        catch(EmptyQueueError error)
        {
            success = true;
        }
        QVERIFY(success);
    }
};
