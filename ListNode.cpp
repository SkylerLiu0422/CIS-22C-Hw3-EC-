/*
 CIS 22C: Homework 2
 Implementation file for the ListNode class
 ListNode.cpp

 Written by:Sihan Liu
 IDE:Code Blocks

 */

#include "MountainList.h"
#include "Mountain.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

//*********************************************
// accept ListNode pointer as argument.
//set it to forw pointer of the Node
//*********************************************
void ListNode::setForw(ListNode * nodePtr)
{
    forward = nodePtr;

}

//*********************************************
// accept ListNode pointer as argument.
// set it to Back pointer of the Node
//*********************************************
void ListNode::setBack(ListNode * nodePtr)
{
    back = nodePtr;
}

//*********************************************
//setters to set data
//*********************************************
void ListNode::setData(const Mountain &obj)
{
    mountain = obj;
}

//*********************************************
//return back pointer to the previous node in the list
//*********************************************
ListNode* ListNode::getBack()
{
    return back;
}

//*********************************************
// return forw pointer a pointer to the next node in the list
//*********************************************
ListNode* ListNode::getForw()
{
    return forward;
}

//*********************************************
// return reference of data
//*********************************************
Mountain ListNode::getData()
{
    return mountain;
}





