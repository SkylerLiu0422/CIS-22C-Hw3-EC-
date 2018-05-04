/*
 CIS 22C: Homework 2
 Implementation file for the MountainList class
 MountainList.cpp

 Written by:Sihan Liu
 IDE:Code Blocks

 */

#include "MountainList.h"
#include "Mountain.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::cerr;
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
MountainList::MountainList()
{
    head = new ListNode();
    head->setBack(head);
    head->setForw(head);
    count = 0;
}

//*****************************************************************
 //create a node has data of dataIn and insert it before another node
 //***************************************************************
void MountainList::insertBefore(const Mountain &data, ListNode *nodePtr)
{
    ListNode* insert = new ListNode(data, nodePtr->getBack(), nodePtr);
    if(!insert)
    {
        cerr << "Allocate Error\n";
        exit(0);
    }
    ListNode* temp = insert->getBack();
    temp->setForw(insert);
    insert->getForw()->setBack(insert);

}

//******************************************************
//remove a node in the list
//cannot remove sentinel node
//********************************************
void MountainList::removeNode(ListNode *nodePtr)
{
    nodePtr->getBack()->setForw(nodePtr->getForw());
    nodePtr->getForw()->setBack(nodePtr->getBack());
    delete nodePtr;
}

//****************************************************
 //Travel the List to find target node
 //return ListNode ptr that was found
 //***************************************************
ListNode *MountainList::travelList(const Mountain & obj)const
{
    ListNode * travel = head->getForw();
    while(travel != head && travel->getData() < obj)
        travel = travel->getForw();
    return travel;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************
void MountainList::printAscend() const
{

    ListNode *pCur = head->getForw();
    while (pCur != head)
    {
        cout << pCur->getData() << endl;
        pCur = pCur -> getForw();
    }
}

//**************************************************
// descendDisplay shows the value
// stored in each node of the linked list
// pointed to by head in descending order
//**************************************************
void MountainList::printDescend() const
{
    ListNode *pCur = head->getBack();
    while (pCur != head)
    {
        cout << pCur->getData()<<endl;
        pCur = pCur->getBack();
    }

}

//**************************************************
// The insertNode function inserts a node with
// mountain copied to its value member.
//**************************************************

bool MountainList::insertNode(Mountain data)
{
    bool inserted = false;
    ListNode *nodePtr = head->getForw();

    // Skip all nodes whose value is less than num.
    while (nodePtr != head && nodePtr->getData() < data)
    {
        nodePtr = nodePtr->getForw();
    }

    // Update links to insert the new node
    if(nodePtr->getData() != data)
    {
        // Allocate a new node, store dataIn there and insert it before a found position.
        insertBefore(data, nodePtr);
        count++;
        inserted = true;
    }
    return inserted;
}

//**************************************************
// The deleteNode function searches if the target
// is inside the list.
// The node, if found, will be
// deleted from the list and from memory.
//**************************************************
bool MountainList::deleteNode(Mountain target)
{
    bool deleted = false;
    ListNode *pCur;
    pCur = travelList(target);

    if (pCur->getData() == target ) {
        removeNode(pCur);
        count--;
        deleted =  true;
    }
    return deleted;
}

//**************************************************
// This function is to search if the target is
// inside the list. The node's date will be printed
// out, if the target is found.
//**************************************************
bool MountainList::searchNode(const Mountain & target, Mountain &data) const
{
    bool found = false;
    ListNode *pCur;
    pCur = travelList(target);
    if (pCur->getData() == target ) {
        data = pCur->getData();
        found =  true;
    }
    return found;
}

//**************************************************
// This function is to locate the highest mountain
// of the list. The node's data will be printed
// out, if the target is found.
//**************************************************
void MountainList:: findTallest(Mountain &data)
{
    ListNode *pCur = head;
    // ListNode *pPre = head;
    int tallest;
    tallest = head->getData().getElevation();
    while(pCur->getForw() != head)
    {
        if(pCur->getData().getElevation()>=tallest)
        {
            tallest = pCur->getData().getElevation();
            data = pCur->getData();
        }
        pCur = pCur -> getForw();
    }
    cout << data << endl;
}

//**************************************************
// This function is to write the datas to the file
//**************************************************
void MountainList::writeFile(ofstream & outFile)const
{
    ListNode *nodePtr = head->getForw();
    while (nodePtr != head)
    {
        outFile << nodePtr->getData();
        nodePtr = nodePtr->getForw();
    }
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list,   *
// and it prevents memory leaks.                   *
//**************************************************
MountainList::~MountainList(){
    ListNode *del;
    head->getBack()->setForw(NULL);
    del = head;
    while(del)
    {
        head = head->getForw();
        delete del;
        del = head;
    }
}

