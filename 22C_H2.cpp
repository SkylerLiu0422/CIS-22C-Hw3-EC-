/*
 CIS 22C: Homework 2

 Written by: A. Student
 Changed by:Sihan Liu
 IDE:Code Blocks

 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Mountain.h"
#include "MountainList.h"
using namespace std;

void printIntro();
void printEndMsg();
//write / read to file
void readMountains(string filename, MountainList& list);
void writeFile(MountainList &list, string fileName);
//
void deleteMountains(MountainList &list);
void searchMountains(MountainList &list);
void insertMountains(MountainList &list); // the new function
void tallestMountain(MountainList &list);
//
void printList(MountainList &list);
void printHeader();
bool checkEleva(int elevation);

int main()
{
    string inputFileName = "mountains.txt";
    string outputFileName = "report.txt";
    MountainList list;

	printIntro();
	readMountains(inputFileName, list);
    printList(list);

	cout << "The total number of mountains is: " << list.getCount() << endl;
    //search the list
	searchMountains(list);

	//delete the informations form the list
	deleteMountains(list);
    printList(list);

	cout << "The remain number of mountains is: " << list.getCount() << endl;
	//insert new mountain informations into list
	insertMountains(list);
	printList(list);
	//Display the tallest mountain
	cout << "The tallest mountain is: " << endl;
	tallestMountain(list);

    // display the number of nodes in the list here
    cout<<"The total number of mountains(after insert) is: "<<list.getCount()<<endl;

    writeFile(list,outputFileName);
    printEndMsg();
    return 0;
}

/*****************************************************************************
 Display a short statement about the purpose of the program
 *****************************************************************************/
void printIntro()
{
    cout << "Build and process a sorted Linked List of Mountains\n";
    cout << "___________________________________________________\n\n";

}

/*****************************************************************************
 Display an "End of the program" message
 *****************************************************************************/
void printEndMsg()
{
    cout << "\n\n____________________________________________\n\n";
    cout << "   End of the Sorted Linked List program!\n";
    cout << "____________________________________________\n";
}


/*****************************************************************************
 This function reads data about mountains from a given file and inserts it
 into the  MountainList.
 *****************************************************************************/
void readMountains(string filename, MountainList& list)
{
    ifstream infile;

    // Open the input file
    infile.open(filename.c_str());
    if (infile.fail())
    {
        cout << "\n\Error opening the input file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    Mountain mountain;
    string name, range, state;
    int elevation;


    while (getline(infile, name, ';'))
    {
        infile.ignore(); // to discard ';'
        infile >> elevation; infile.ignore();
        getline(infile, range, ';'); infile.ignore();
        getline(infile, state, ';'); infile.ignore();
        // Store one line into mountain.
        mountain.setName(name);

        mountain.setRange(range);
        mountain.setElevation(elevation);
        mountain.setState(state);

        list.insertNode(mountain);

    }
    // Close the input file
    infile.close();
}

/*****************************************************************************
 Delete manager: delete items from the list until the user enters QUIT
 Input Parameter: list
 *****************************************************************************/
void deleteMountains(MountainList &list)
{
    string targetMountain;

    Mountain mountain;
    cout << "\n Delete\n";
    cout << "______\n";

    cout << endl << "Enter the mountain for delete (QUIT for stop searching) : ";
    getline(cin, targetMountain);

    while(targetMountain != "QUIT")
    {
        mountain.setName(targetMountain);
        if( list.deleteNode(mountain))
        {
            cout << targetMountain << " has been successfully deleted.\n";
        }
        else
        {
            cout << targetMountain << " is not found.\n";
        }

        cout << endl << "Enter the mountain for delete (QUIT for stop searching) : ";
        getline(cin, targetMountain);

    }
    cout << "___________________\n";
}


/************************************************************************************
Check manages: this function is to check if the input is legal
*************************************************************************************/
bool checkEleva(int elevation)
{
    bool eleva = false;
    if((elevation > 0)&&(elevation < 29028))
    {
        eleva = true;
    }
    return eleva;
}

/************************************************************************
 Insert manages: inserting new records. It prompts the user to enter a new record and inserts it into the list.until the user enters QUIT
 Input Parameter: list
************************************************************************/

void insertMountains(MountainList &list)
{

    Mountain mountain;
    string name, range, state;

    int elevation;

    cout << "\n Insert \n";
    cout << "______\n";

    cout<<"\nEnter the name of the mountain for insert (QUIT for stop searching): ";

    getline(cin, name);
    while(name != "QUIT")
    {
        cout<<"Elevation: ";
        cin>>elevation;
        cin.ignore(); // to discard ';'
        //to check if the elevation is legal
        if(checkEleva(elevation))
        {
            cout << "\nPlease enter the rang of the mountain: ";
            getline(cin, range);

            cout << "\nPlease enter the state of the mountain: ";
            getline(cin, state);


            // Store one line into mountain.
            mountain.setName(name);
            mountain.setRange(range);
            mountain.setElevation(elevation);
            mountain.setState(state);

            if (!list.insertNode(mountain))
            {
                cout << "Mountain duplicates\n";
            }
            else
            {
                cout << "Inserted mountain: \n";
                cout << "=================== ========= ======================== ===============\n";
                cout<< mountain<<endl;
                cout << "=================== ========= ======================== ===============\n\n";
            }
        }
        else
        {
            cout << "The mountain is not exist!" << endl;
        }



        cout << endl << "Enter the imformations of new mountain for insert (QUIT for stop insert) : " << endl;
        cout << "Please enter the name of the mountain:";
        getline(cin, name);
    }
    cout<<"___________________\n";

}


/*****************************************************************************
 Search manager: search the mountain list until the user enters QUIT
 Input Parameter: list
 *****************************************************************************/
void searchMountains(MountainList &list)
{
    string targetMountain;
    Mountain mountain,data;


    cout << "\nSearch\n";
    cout <<   "______\n";

    cout << "\nEnter the mountain for search (QUIT for stop searching) : ";
    getline(cin, targetMountain);
    while(targetMountain != "QUIT")
    {
        mountain.setName(targetMountain);

        if(list.searchNode(mountain,data))
        {
            cout << "Display searched mountain: \n";
            cout << "=================== ========= ======================== ===============\n";
            cout<< data <<endl;
            cout << "=================== ========= ======================== ===============\n";
        }
        else
        {
            cout << targetMountain << " is not found.\n";
        }

        cout << "\nEnter the mountain for search (QUIT for stop searching) : ";
        getline(cin, targetMountain);

    }
    cout << "___________________\n";
}

/************************************************************************
 Find manages: this function is to find the highest mountain in the list
 Input Parameter: list
************************************************************************/
void tallestMountain(MountainList &list)
{
    Mountain mountain;
    cout<<"Display the tallest mountain: \n";
    cout << "=================== ========= ======================== ===============\n";
    list.findTallest(mountain);
    cout << "=================== ========= ======================== ===============\n\n";
}

void writeFile(MountainList &list, string fileName)
{

    ofstream outfile;
    outfile.open(fileName);

    list.writeFile(outfile);

    outfile.close();
    cout<< "Write to file: \n";
    cout << "Data has been write to " << fileName << endl;


}

/************************************************************************
Print manages: this function is to print the header of the table
************************************************************************/

void printHeader()
{
    // Display header
    cout << "\t Mountain List\n";
    cout << "=================== ========= ======================== ===============\n";
    cout << "Name                Elevation     Range                 State\n";
    cout << "=================== ========= ======================== ===============\n";

}

/************************************************************************************
Print manages: this function is to print the datas in two types with a header
*************************************************************************************/
void printList(MountainList &list)
{
   	//display the list in ascending and descending order
	cout << "Here is the ascending order of the list: " << endl;
	printHeader();
    list.printAscend();
    cout << "=================== ========= ======================== ===============\n\n\n";
    cout << "Here is the descending order of the list: " << endl;
    printHeader();
    list.printDescend();
    cout << "=================== ========= ======================== ===============\n\n";
}


/************* OUTPUT ******************************

Build and process a sorted Linked List of Mountains
___________________________________________________

Here is the ascending order of the list:
         Mountain List
=================== ========= ======================== ===============
Name                Elevation     Range                 State
=================== ========= ======================== ===============
Adams                 12281    Cascade Range           Washington
Antero                14276    Sawatch Range           Colorado
Bachelor               9068    Cascade Range           Oregon
Castle Peak            9109    Sierra Nevada           California
Churchill             15638    Saint Elias Mountains   Alaska
Doublet Peak          13600    Wind River Range        Wyoming
Granite Peak          12807    Beartooth Mountains     Montana
Half Dome              8836    Yosemite National Park  California
Jeff Davis Peak       12771    Snake Range             Nevada
Mauna Kea             13803    Mauna Kea               Hawaii
Pyramid Peak           9985    Crystal Range           California
Rainier               14411    Cascade Range           Washington
Shasta                14179    Cascade Range           California
Torbert               11413    Tordillo Mountains      Alaska
=================== ========= ======================== ===============


Here is the descending order of the list:
         Mountain List
=================== ========= ======================== ===============
Name                Elevation     Range                 State
=================== ========= ======================== ===============
Torbert               11413    Tordillo Mountains      Alaska
Shasta                14179    Cascade Range           California
Rainier               14411    Cascade Range           Washington
Pyramid Peak           9985    Crystal Range           California
Mauna Kea             13803    Mauna Kea               Hawaii
Jeff Davis Peak       12771    Snake Range             Nevada
Half Dome              8836    Yosemite National Park  California
Granite Peak          12807    Beartooth Mountains     Montana
Doublet Peak          13600    Wind River Range        Wyoming
Churchill             15638    Saint Elias Mountains   Alaska
Castle Peak            9109    Sierra Nevada           California
Bachelor               9068    Cascade Range           Oregon
Antero                14276    Sawatch Range           Colorado
Adams                 12281    Cascade Range           Washington
=================== ========= ======================== ===============

The total number of mountains is: 14

Search
______

Enter the mountain for search (QUIT for stop searching) : Adams
Display searched mountain:
=================== ========= ======================== ===============
Adams                 12281    Cascade Range           Washington
=================== ========= ======================== ===============

Enter the mountain for search (QUIT for stop searching) : Abcc
Abcc is not found.

Enter the mountain for search (QUIT for stop searching) : QUIT
___________________

 Delete
______

Enter the mountain for delete (QUIT for stop searching) : Adams
Adams has been successfully deleted.

Enter the mountain for delete (QUIT for stop searching) : abcc
abcc is not found.

Enter the mountain for delete (QUIT for stop searching) : QUIT
___________________
Here is the ascending order of the list:
         Mountain List
=================== ========= ======================== ===============
Name                Elevation     Range                 State
=================== ========= ======================== ===============
Antero                14276    Sawatch Range           Colorado
Bachelor               9068    Cascade Range           Oregon
Castle Peak            9109    Sierra Nevada           California
Churchill             15638    Saint Elias Mountains   Alaska
Doublet Peak          13600    Wind River Range        Wyoming
Granite Peak          12807    Beartooth Mountains     Montana
Half Dome              8836    Yosemite National Park  California
Jeff Davis Peak       12771    Snake Range             Nevada
Mauna Kea             13803    Mauna Kea               Hawaii
Pyramid Peak           9985    Crystal Range           California
Rainier               14411    Cascade Range           Washington
Shasta                14179    Cascade Range           California
Torbert               11413    Tordillo Mountains      Alaska
=================== ========= ======================== ===============


Here is the descending order of the list:
         Mountain List
=================== ========= ======================== ===============
Name                Elevation     Range                 State
=================== ========= ======================== ===============
Torbert               11413    Tordillo Mountains      Alaska
Shasta                14179    Cascade Range           California
Rainier               14411    Cascade Range           Washington
Pyramid Peak           9985    Crystal Range           California
Mauna Kea             13803    Mauna Kea               Hawaii
Jeff Davis Peak       12771    Snake Range             Nevada
Half Dome              8836    Yosemite National Park  California
Granite Peak          12807    Beartooth Mountains     Montana
Doublet Peak          13600    Wind River Range        Wyoming
Churchill             15638    Saint Elias Mountains   Alaska
Castle Peak            9109    Sierra Nevada           California
Bachelor               9068    Cascade Range           Oregon
Antero                14276    Sawatch Range           Colorado
=================== ========= ======================== ===============

The remain number of mountains is: 13

 Insert
______

Enter the name of the mountain for insert (QUIT for stop searching): Abcc
Elevation: 9501444
The mountain is not exist!

Enter the imformations of new mountain for insert (QUIT for stop insert) :
Please enter the name of the mountain:Abcc
Elevation: -123
The mountain is not exist!

Enter the imformations of new mountain for insert (QUIT for stop insert) :
Please enter the name of the mountain:De anza
Elevation: 12345

Please enter the rang of the mountain: Cupertino

Please enter the state of the mountain: California
Inserted mountain:
=================== ========= ======================== ===============
De anza               12345   Cupertino                California
=================== ========= ======================== ===============


Enter the imformations of new mountain for insert (QUIT for stop insert) :
Please enter the name of the mountain:QUIT
___________________
Here is the ascending order of the list:
         Mountain List
=================== ========= ======================== ===============
Name                Elevation     Range                 State
=================== ========= ======================== ===============
Antero                14276    Sawatch Range           Colorado
Bachelor               9068    Cascade Range           Oregon
Castle Peak            9109    Sierra Nevada           California
Churchill             15638    Saint Elias Mountains   Alaska
De anza               12345   Cupertino                California
Doublet Peak          13600    Wind River Range        Wyoming
Granite Peak          12807    Beartooth Mountains     Montana
Half Dome              8836    Yosemite National Park  California
Jeff Davis Peak       12771    Snake Range             Nevada
Mauna Kea             13803    Mauna Kea               Hawaii
Pyramid Peak           9985    Crystal Range           California
Rainier               14411    Cascade Range           Washington
Shasta                14179    Cascade Range           California
Torbert               11413    Tordillo Mountains      Alaska
=================== ========= ======================== ===============


Here is the descending order of the list:
         Mountain List
=================== ========= ======================== ===============
Name                Elevation     Range                 State
=================== ========= ======================== ===============
Torbert               11413    Tordillo Mountains      Alaska
Shasta                14179    Cascade Range           California
Rainier               14411    Cascade Range           Washington
Pyramid Peak           9985    Crystal Range           California
Mauna Kea             13803    Mauna Kea               Hawaii
Jeff Davis Peak       12771    Snake Range             Nevada
Half Dome              8836    Yosemite National Park  California
Granite Peak          12807    Beartooth Mountains     Montana
Doublet Peak          13600    Wind River Range        Wyoming
De anza               12345   Cupertino                California
Churchill             15638    Saint Elias Mountains   Alaska
Castle Peak            9109    Sierra Nevada           California
Bachelor               9068    Cascade Range           Oregon
Antero                14276    Sawatch Range           Colorado
=================== ========= ======================== ===============

The tallest mountain is:
Display the tallest mountain:
=================== ========= ======================== ===============
Churchill             15638    Saint Elias Mountains   Alaska
=================== ========= ======================== ===============

The total number of mountains(after insert) is: 14
Write to file:
Data has been write to report.txt


____________________________________________

   End of the Sorted Linked List program!
____________________________________________

Process returned 0 (0x0)   execution time : 64.287 s
Press any key to continue.


 ************************************************************************/
