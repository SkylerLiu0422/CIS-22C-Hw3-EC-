/*
 CIS 22C: Homework 2
 Mountain.h

 Written by:Sihan Liu
 IDE:Code Blocks

 */

#ifndef MOUNTAIN_H
#define MOUNTAIN_H
#include <iostream>
#include <string>
//using namespace std;

//using namespace std;  //<==== This statement
// in a header file of a complex project could create
// namespace management problems for the entire project
// (such as name collisions).
// Do not write namespace using statements at the top level in a header file!

using std::string;
using std::ofstream;
using std::ostream;

class Mountain
{
private:
    string name;
    int elevation;
    string range;
    string state;

public:
    // Constructors
    Mountain(){name = range = state = ""; elevation = -1; }
    Mountain(string n, int e, string r, string s){name = n; elevation = e; range = r; state = s;}

    // Setters and getters
    void setName(string n){name = n;}
    void setElevation(int e){elevation = e;}
    void setRange(string r){range = r;}
    void setState(string s){state = s;}
    string getName() const {return name;}
    int getElevation() const {return elevation;}
    string getRange() const {return range;}
    string getState() const {return state;}


    // opeator overloading

    Mountain & operator = (const Mountain &obj);
    bool operator == (const Mountain &obj);
    bool operator < (const Mountain &obj);
    bool operator > (const Mountain &obj);
    bool operator != (const Mountain &obj);
    friend ostream& operator << (ostream &str, const Mountain &obj);
    friend ofstream& operator << (ofstream &outFile, const Mountain &obj);
};

#endif

