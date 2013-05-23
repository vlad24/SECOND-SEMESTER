#pragma once
#include "MultiTreeSet.h"
#include "Queue.h"

//! A class which can work with MultiTreeSet enabling auser to have an "iterative" acces to elements of the set

template <typename O>

class Iterator
{
    friend class IteratorTester;
public:
    //! @param set to which we connect our iterator
    Iterator(MultiTreeSet<O> *set);
    //! Returns The current element of the iterator and gpes to the next
    O next();
    //! Tells whether the element is the last
    bool hasNext()
    {
        return !(queue.isEmpty());
    }
    //! Adds an element to the set
    void add(O value);
    //! Removes current iterator's element from the element
    void remove();
    ~Iterator();
private:
    //! A set with which an iterator will work
    MultiTreeSet<O>* workingSet;
    //! A queue that contains elements of the set in special order
    Queue<O> queue;
    void formIteratorQueue(TreeNode<O> *node);
};

template <typename O>
Iterator<O>::Iterator(MultiTreeSet<O> *set)
{
    workingSet = set;
    formIteratorQueue(workingSet->getRoot());
}

template <typename O>
O Iterator<O>::next()
{
    try
    {
        O result = queue.take();
        return result;
    }
    catch (TakingError error)
    {
        throw error;
    }
}

template <typename O>
void Iterator<O>::add(O value)
{
    workingSet->addToTree(value);
}

template <typename O>
void Iterator<O>::remove()
{
    try
    {
        O result = queue.take();
        workingSet->removeFromTree(result);
    }
    catch(TakingError error)
    {
        printf("#Nothing to remove");
    }
}

template <typename O>
Iterator<O>::~Iterator()
{
    queue.~Queue();
    delete workingSet;
}

template <typename O>
void Iterator<O>::formIteratorQueue(TreeNode<O> *node)
{
    if (node == NULL)
        return;
    else
    {
        formIteratorQueue(node->left);
        for (int i = 0; i < node->reps; i++)
            queue.add(node->value);
        formIteratorQueue(node->right);
    }
    return;
}
