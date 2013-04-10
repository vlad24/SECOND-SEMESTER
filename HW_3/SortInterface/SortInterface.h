#pragma once
/*!
  An abstract class, that enables a user to sort up an array up with different sorting algorithms
  */
class SortInterface
{
public:
    /*!
      A function that sorts an array of "length" elements in the  way depending on the user's choice
      */
    virtual void sortArray(int array[], int length) = 0;
    virtual ~SortInterface()
    {
    }
};
