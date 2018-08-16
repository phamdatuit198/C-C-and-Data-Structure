//
//  main.cpp
//  graph
//
//  My name: Dat Pham
//  class number: CS163
//  project number: 5
//  Purpose:
/*
    this is a man function of software. the software will call main() function first
    we will insert information for vertex. Then, we will insert into graph
 */


#include <iostream>
#include <cstring>
#include "graph.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int size;                     //the number of vertex or size of adjacency list
    int i=0;                      // variable is defined to count step of loop
    int result;                   //result return form ADT to client
    bool addMore = false;         //variable is defined your choose that do you want add more conection between two vertex
    char yourChoose = 'N';//your choose to accept or unaccept
    char title[100];             // variable is defined that enterning title
    char connected[100];         // variable is defined vertex need to connected .
    char notes[300];             //variable is defined notes


    //Let's add some items ot the journal first
    cout<<"\n Enter number of vertex: ";
    cin>>size;

    journal_entry to_add;    // object of myfriend
    table myTable(size);// object of table


    do
    {
        cout <<"Please enter a title: ";
        cin.ignore(100,'\n');
        cin.get(title, 100);


        cout <<"Please enter a notes: ";
        cin.ignore(100,'\n');
        cin.get(notes, 300);

        to_add.create_entry(title, notes);

        //now insert it into the graph
        myTable.insert_vertex(to_add);

        i++;
    } while (i!=size);

    //display vertex
       cout<<"\nDisplay vertex: \n";
       myTable.display_vertex();

    //Let's add some connections
    do
    {
        cout <<"\nEnter first title that are related (connected): ";
        cin.ignore(100,'\n');
        cin.get(title, 100);

        cout <<"\nEnter second title that are related (connected): ";
        cin.ignore(100,'\n');
        cin.get(connected, 100);

        myTable.insert_edge(title, connected);
        myTable.insert_edge(connected, title); //not a directed graph

        cout <<"\nDo you want to add more(Y/N): ";
        cin>>yourChoose;

    } while (yourChoose == 'Y');

    //display graph

    cout <<"\n\nThis is the contents of the table:\n";
    myTable.display_all();

    cout<<"\nCheck graph!";
    result = myTable.checkGraph();

    if(result == 0)
        cout<<"\nGraph empty \n";
    else if(result == 1)
        cout<<"\nGraph is complete \n";
            else if(result == 2)
                cout<<"\nGraph is connected \n";
}

