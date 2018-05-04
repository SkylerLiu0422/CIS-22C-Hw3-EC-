/*
 CIS 22C: Homework 2
 MountainList.h
 Specification file for the MountainList class
 Written by:Sihan Liu
 IDE:Code Blocks

 */
#ifndef MOUNTAINLIST_H
#define MOUNTAINLIST_H

#include "Mountain.h"
#include "ListNode.h"

class MountainList
{
private:

    ListNode *head;
    int count;          // to keep track of the number of items in the list

    void insertBefore(const Mountain &data, ListNode *nodePtr);
    void removeNode(ListNode *nodePtr);
    ListNode *travelList(const Mountain & )const;

public:
    MountainList();     // Constructor
    ~MountainList();    // Destructor

    int getCount() { return count; }
    void printAscend() const;
    void printDescend() const;
    bool insertNode(Mountain);

    bool deleteNode(Mountain);
    bool searchNode(const Mountain &, Mountain &) const;
    void findTallest(Mountain &);
    void writeFile(ofstream & outFile)const;


};
#endif
