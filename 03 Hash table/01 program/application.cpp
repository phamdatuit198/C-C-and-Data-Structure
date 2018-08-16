//My name: Dat Pham
//class number: CS163
//project number: 3
//Purpose:
/*
 this is a man function of software. the software will call main() function first
 we will load list of news item from File Data to hashtable
 Then insert news item if you need, or search news item with keyword. Then save new data into file data
 */

#include <iostream>
#include "hashtable.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    
    bool myChoose = true ; //variables is defined that do you want insert more new item
    char choose = 'Y'; // variable is defined that you want insert more or no
    char title[100]; // variable is defined title of new item
    char comment[500];// variable is defined comment of new item
    char keyWord[100];// variable is defined keyword of new item
    char searchKeyWord[100];// variable is defined keyword which need to search of new item
    int countLike=0; // variable is defined quantity like of new item
    int countComment = 0; // variable is defined quantity comment of new item
    int countView = 0;   // variable is defined quantity view of new item
    int number = 1; //number you choose function running
    newItem myNewitem; // variable is defined object of new item
    hashtable myHashTable; // variable is defined object of hashtable
    
    char buffer[1000]; //variable save each line in the file data
    char *temptitle; // variable save title when we read from file data
    char *tempcomment;// variable save comment when we read from file data
    char *tempkeyWord;// variable save kewword when we read from file data
    char *tempLike;// variable save quantity like when we read from file data
    char *tempComment;// variable save quantity comment when we read from file data
    char *tempView;// variable save quantity view when we read from file data
    ofstream myFile; //write into file data
    ifstream lineFile;//read from file data
    lineFile.open("listnewitem.txt"); // file data name is listnewitem
    
    while (!lineFile.eof())
    {
        lineFile.getline(buffer, 1000, '\n');
        if (strlen(buffer) > 0)
        {
            
            temptitle = strtok (buffer, "#");
            tempcomment = strtok (NULL, "#");
            tempLike = strtok (NULL, "#");
            tempView = strtok (NULL, "#");
            tempComment = strtok (NULL, "#");
            tempkeyWord = strtok (NULL, "#");
            cout<<"\n#######################";
            cout<<"\ntitle: "<<temptitle;
            cout<<"\ncomment: "<<tempcomment;
            cout<<"\ntemplike: "<<tempLike;
            cout<<"\ntempView: "<<tempView;
            cout<<"\ntempComment: "<<tempComment;
            cout<<"\nkeyword: "<<tempkeyWord;
            cout<<"\n#######################";
           // conver quality from char to int
            countLike= atoi(tempLike);
            countView= atoi(tempView);
            countComment= atoi(tempComment);
            //add information for object newitem
            myNewitem.addNew(temptitle, tempcomment, countLike, countView, countComment, tempkeyWord);
            //add to hashtable
            myHashTable.insert(tempkeyWord, myNewitem);
        }
    }
    
    
        while(number != 4){
        cout<<"\n1. Display All: \n";
        cout<<"2. Insert new Item: \n";
        cout<<"3. Search Item\n";
        cout<<"4. End\n";
        cout<<"choose number you need: ";
        cin>>number;
        switch (number){
            case 1:
                 myHashTable.displayAll();
                 break;
            case 2:
                do{
                    cout<<"\n Enter title: ";
                    cin>>title;
                    cout<<"\n Enter comment: ";
                    cin>>comment;
                    cout<<"\n Enter Keyword: ";
                    cin>>keyWord;
                    cout<<"\n Enter quantity like: ";
                    cin>>countLike;
                    cout<<"\n Enter quantity Comment: ";
                    cin>>countComment;
                    cout<<"\n Enter quantity View: ";
                    cin>>countView;
                    
                    //add information for object newitem

                    myNewitem.addNew(title, comment, countLike, countView, countComment, keyWord);
                  
                    //add to hashtable
                    myHashTable.insert(keyWord, myNewitem);
            
                    //write data into file txt when we done insert into hashtable.
                    myFile.open( "listnewitem.txt", ios::out | ios::app );
            
                    if(myFile.is_open()){
                    myFile<<"\n"<<title<<"#"<<comment<<"#"<<countLike<<"#"<<countView<<"#"<<countComment<<"#"<<keyWord;
                        myFile.close();
                    }
                    cout<<"\n Do you need to add more: (Y/N)";
                    cin>>choose;
                    
                    if(choose == 'N')
                        myChoose = false;
                }while(myChoose);

                break;
                
            case 3:
                cout<<"\n Enter keyword that you need to search: ";
                cin>>searchKeyWord;
                myHashTable.retrieve(searchKeyWord);
                break;
            case 4:
                cout<<"END!\n";
                break;
            default:
                cout<<"\nNothing! Can you choose again !";
                break;
        }
    }

    return 1;
}