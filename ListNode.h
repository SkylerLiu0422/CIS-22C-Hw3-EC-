/*
 CIS 22C: Homework 2
 ListNode.h

 Written by:Sihan Liu
 IDE:Code Blocks

 */

#ifndef ListNode_h
#define ListNode_h
#include <iostream>
#include "Mountain.h"

class ListNode
{
private:
        ListNode *back;
        Mountain mountain;
        ListNode *forward;
public:
    //constructors:
    ListNode():forward(NULL),back(NULL){}
    ListNode(const Mountain& dataIn, ListNode* bPtr = NULL,ListNode* fPtr = NULL):mountain(dataIn), back(bPtr), forward(fPtr){}


    //getters:
    ListNode *getForw();
    ListNode *getBack();
    Mountain getData();

    //setters:
    void setForw(ListNode * nodePtr);
    void setBack(ListNode * nodePtr);
    void setData(const Mountain &obj);


};





#endif /* ListNode_h */
