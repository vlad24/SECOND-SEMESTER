#pragma once

class List
{
public:
    struct ListElement
    {
        char* value;
        ListElement* next ;
    };
    List();
    void print() const;
    bool isEmpty() const;
    void add(char* str);
    void remove(char* str);
    /*!
      \brief Gives some element of the List
      \return An element if pos <= length of a list , NULL if pos > length of a list
      */
    ListElement* takeElement(int pos) const;
    bool stringExsists(char* str) const;
    int getLength() const;
    ~List();
private:
    ListElement* first;
    /*!
      A function which returns a pointer to a ListElement with the needed string and
      also changes the "prev" pointer which points to an element
      which stands before the needed element.
      If the string is not in the List NULL is returned and prev points to the last element.
      */
    ListElement* searchString(char* str, ListElement* &prev) const;
    bool stringsEqual(char* s1, char* s2) const;
    int listLength;
};
