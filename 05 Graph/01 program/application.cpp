//My name: Dat Pham
//class number: CS163
//project number: 5
//Purpose:
/*
 this is a man function of software. the software will call main() function first
 we will insert information about friend first. Then, we will insert into graph
 */



#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    
        int size; //the number of vertex or size of adjacency list
        int i=0;  // variable is defined to count step of loop
    
        bool addMore = false; //variable is defined your choose that do you want add more conection between two vertex
        char yourChoose = 'N';//your choose to accept or unaccept
        char event[100]; // variable is defined that enterning event that happen of your friend.
        char connected[100]; // variable is defined vertex need to connected .
        char name[300];//variable is defined name of your friend
    
   
        //Let's add some items ot the journal first
        cout<<"\n Enter number of vertex: ";
        cin>>size;
    
        myfriend to_add;    // object of myfriend
        table myTable(size);// object of table
    
    
        do
        {
            cout <<"Please enter a event: ";
            cin.ignore(100,'\n');
            cin.get(event, 100);
            
          
            cout <<"Please enter the name your friend: ";
            cin.ignore(100,'\n');
            cin.get(name, 300);
            
            to_add.addInfor(name, event);
            
            //now insert it into the graph
            myTable.addvertex(to_add);
            
            i++;
        } while (i!=size);
    
        //Let's add some connections
        do
        {
            cout <<"\nEnter first event that are related (connected): ";
            cin.ignore(100,'\n');
            cin.get(event, 100);
            
            cout <<"\nEnter second event that are related (connected): ";
            cin.ignore(100,'\n');
            cin.get(connected, 100);
            
            myTable.addedge(event, connected);
            myTable.addedge(connected, event); //not a directed graph
            
            cout <<"\nDo you want to add more(Y/N): ";
            cin>>yourChoose;
//            cin.ignore(100,'\n');
//            cin.get(yourChoose, 1);
            if(yourChoose == 'Y')
                addMore = true;
            else
                addMore = false;
        } while (addMore);
    
        //Let's display what we have  (this function was provided for you)
        cout <<"\n\nThis is the contents of the table:\n";
        myTable.display();
    
    
return 0;
}



