#pragma once

/*!
    Class that enables a user to test different sort algorithms
  */
class SortBattler
{
public:
    void sortsTimeBattle(int testLength);
private:
    void fillArrayRandomly(int testArray[], int testLength);
    //! @brief The function for capturing the time at when calling this function
    void printTime();

};

