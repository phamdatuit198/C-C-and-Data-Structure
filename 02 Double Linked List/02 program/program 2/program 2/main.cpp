//My name: Dat Pham
//class number: CS163
//project number: 2
//Purpose:
/*
 this is a man function of software. the software will call main() function first
 Assume we will receive message and save difference way such as queue or stack
 We also display message missed using peek function
 save message and block sender.
 */


#include <iostream>
#include "stack.hpp"

using namespace std;
int main() {
    
    
    char myChooseType = 'Y';        //Choose add more in the list
    char myChooseSave = 'Y';        //Choose save message or it is not
    char myChooseBock = 'Y';        //Choose block message or it is not
    
    char text[200];                 //text of messenge
    char sender[100];               //name of sender
   
    message myMessage;              //object of message
    message myMissText;             //object of message which is miss
    queue myQueue;                  //object of queue
    stack myStack;                  //object of stack
    listBlock myListBlock;          //object of listBlock which is a list sender who is blocked
    listSave  myListSave;           //object of listSave which is a list message that you need to save
    
    int result = 0;                 //catch result from ADT;
    
    
    //push messenger into list
    do{
        //Enter information of messenge
        
        cout<<"\nEnter sender of messenger: ";
        cin.get(sender,100);
        cin.ignore(100,'\n');
        
        cout<<"\nEnter text of messenger: ";
        cin.get(text,200);
        cin.ignore(200,'\n');
        
        //insert into myMessage object
        
        result = myMessage.insert(sender, text);
        if(result == 0)
            cout<<"\n insert message is wrong!";
        myMessage.display();
        
        //insert into queue list
        
        result = myQueue.enqueue(myMessage);
        if(result == 0)
            cout<<"\n insert into queue is wrong!";
        
        //insert into stack list
        
        result = myStack.push(myMessage);
        if(result == 0)
            cout<<"\n insert into stack is wrong!";

        
        //insert into listBlock
        
        cout<<"\n Do you want to block sender (Y/N): ";
        cin>>myChooseBock;
        
        if(myChooseBock == 'Y')
            result = myListBlock.insert(sender);
        
        if(result == 0)
            cout<<"\n insert into list block is wrong!";
        
        //insert into listSave
        
        cout<<"\n Do you want to save message: (Y/N) ";
        cin>>myChooseSave;
        
        if(result == 0)
            cout<<"\n insert into list save is wrong!";

        if(myChooseSave == 'Y')
            result = myListSave.insert(myMessage);
        
        //choose add more message or its not
        
        cout<<"\n Do you want to add more: (Y/N) ";
        cin>>myChooseType;
        cin.ignore(100,'\n');
        
    }while(myChooseType =='Y');
    
    //display list message of queue
    
    cout<<"List of message in Queue";
    myQueue.display();
    cout<<"\n--------\n";
    
    //display missed old text, Assume this is a first message
    
    result= myQueue.peek(myMissText);
    if(result == 0)
        cout<<"\n get miss text is wrong!";
    
    cout<<"\nDisplay missed old text on Queue: \n";
    myMissText.display();
    cout<<"\n---------\n";
    
    //display missed old text, Assume this is a last message from stack
    
    result = myStack.peek(myMissText);
    if(result == 0)
        cout<<"\n get miss text is wrong!";
    
    cout<<"\nDisplay missed old text on Stack: \n";
    myMissText.display();
    cout<<"\n---------\n";
    
    //display list message of stack
    
    cout<<"\nDisplay list of stack\n";
    myStack.display();
    cout<<"\n---------\n";
    
    cout<<"\n Do you want to remove message: (Y/N) ";
    cin>>myChooseType;
    
    while(myChooseType == 'Y'){
        //remove message in queue
        result = myQueue.dequeue();
        
        //remove message in stack
        result = myStack.pop();
        if(result==0){
            cout<<"\nlist is empty!\n";
            myChooseType = 'N';
        }
        if(result!=0){
            cout<<"\n Do you want to remove more message: (Y/N) ";
            cin>>myChooseType;
        }
    }
    
    //display list message of queue after remove
    
    cout<<"\nAfter remove in Queue";
    myQueue.display();
    cout<<"\n---------\n";
    
    
    //display list message of stack after remove
    cout<<"\nAfter remove in stack\n";
    myStack.display();
    cout<<"\n---------\n";
    //display list save
    
    cout<<"\nDisplay list save";
    myListSave.display();
    cout<<"\n---------\n";
    
    //display list block
    cout<<"\nDisplay list block\n";
    myListBlock.display();
    cout<<"\n";
    return 1;
}
