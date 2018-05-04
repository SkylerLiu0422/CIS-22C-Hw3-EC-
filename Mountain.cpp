/*
 CIS 22C: Homework 2
 Mountain.cpp

 Written by:Sihan Liu
 IDE:Code Blocks

 */

#include <stdio.h>
#include "Mountain.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************

//string name;
//int elevation;
//string range;
//string state;
Mountain & Mountain::operator = (const Mountain &obj)
{
    name = obj.name;
    elevation = obj.elevation;
    range = obj.range;
    state = obj.state;
    return *this;
}


/**************************************************
 Oprator overload
 **************************************************/
bool Mountain::operator == (const Mountain &obj)
{
    return name == obj.name;
}

bool Mountain::operator < (const Mountain &obj)
{
    return name < obj.name;
}


bool Mountain::operator > (const Mountain &obj)
{
    return name > obj.name;
}

bool Mountain::operator != (const Mountain &obj)
{
    return name != obj.name;
}


/**************************************************
 Overload the file cout insertion operator
 **************************************************/
ostream& operator << (ostream &str, const Mountain &obj){

    cout << setw(20) << left << obj.name
    << setw(7)  << right << obj.elevation<< "   "
    << setw(23) << left << obj.range << "  "
    << setw(23) << obj.state;
    return str;
}

/**************************************************
 Overload the file out insertion operator
 **************************************************/
ofstream& operator <<(ofstream &outFile, const Mountain &obj)
{
    outFile << obj.name
    << ' ' << obj.elevation
    << ' ' << obj.range
    << ' ' << obj.state<< '\n';
    return outFile;
}
