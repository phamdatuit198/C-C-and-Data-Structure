//My name: Dat Pham
//class number: CS163
//project number: 4
//Purpose:
/*
 this is a man function of software. the software will call main() function first
we will have 6 option such as display all, insert new concept, search concept, remove by concept, remove by data structure and remove all
 */

#include <iostream>
#include "binarytree.h"

using namespace std;
int main(){

   // int value;
    int number = 1;             // the number of the list your choice when the program start
    
    bool chooseAd = true;       //variables is defined that do you want insert more advantage
    bool chooseDis = true;      //variables is defined that do you want insert more disadvantage
    bool chooseInsert = true;   //variables is defined that do you want insert more concept
    
    char mychoose = 'N';        //variables is defined that if you need add more say yes, if you don't need say no
    char name[200];             // variable is defined name of concept
    char dataStructure[200];    // variable is defined name of datastructure
    char advan[1000];           // variable is defined content of advantage
    char disadvan[1000];        // variable is defined content of disadvantage
    char nameSearch[200];       // variable is defined name of concept that you need search
    char nameRemove[200];       // variable is defined name of concept that you need remove
    char nameRemoveByData[200]; // variable is defined name of datastrucute that you need remove
    
    binarytree myTree;          // variable is defined object of binarytree
    concept myConcept;          // variable is defined object of concept
    advantage myAdvantage;      // variable is defined object of advantage
    listAdvantage myListAdvan;  // variable is defined object of list advantage
    disadvantage myDisadvantage;// variable is defined object of disadvantage
    listDisadvantage myListDisadvan;// variable is defined object of list disadvantage
    
    while(number != 7){
        cout<<"\n1. Display All: \n";
        cout<<"2. Insert new concept: \n";
        cout<<"3. Search concept\n";
        cout<<"4. Remove by concept\n";
        cout<<"5. Remove by data structure\n";
        cout<<"6. Remove All\n";
        cout<<"7. End\n";
        cout<<"choose number you need: ";
        cin>>number;
        switch (number){
            case 1:
                myTree.print_inorder();
                break;
            case 2:
                do{
                    cout<<"\n Enter name of concept: ";
                    cin>>name;
                    cout<<"\n Enter name of data structure: ";
                    cin>>dataStructure;
                    
                    while(chooseAd){
                        
                        cout<<"\n Enter advantage: ";
                        cin>>advan;
                        cout<<"\n Do you want to add more advantage(Y/N): ";
                        cin>>mychoose;
                        
                        myAdvantage.addInfor(advan);
                        myListAdvan.addList(myAdvantage);
                        
                        if(mychoose=='N')
                            chooseAd = false;
                    }
                    
                    while(chooseDis){
                        
                        cout<<"\n Enter disadvantage: ";
                        cin>>disadvan;
                        cout<<"\n Do you want to add more disadvantage(Y/N): ";
                        cin>>mychoose;
                        
                        myDisadvantage.addInfor(disadvan);
                        myListDisadvan.addList(myDisadvantage);
                        
                        if(mychoose=='N')
                            chooseDis = false;
                    }
                    

                    myConcept.addInfor(name, dataStructure);
                    myTree.insert(myConcept,myListAdvan, myListDisadvan);
                    cout<<"\n Do you want to add more cocept (Y/N): ";
                    cin>>mychoose;
                    if(mychoose == 'N')
                        chooseInsert = false;
                    else{
                        
                        chooseAd = true;
                        chooseDis = true;
                        
                    }
                }while(chooseInsert);
                
                break;
                
            case 3:
                cout<<"\n Enter name of concept that you need to search: ";
                cin>>nameSearch;
                myTree.retrive(nameSearch);
                break;
            case 4:
                cout<<"\n Enter name of concept that you need to remove: ";
                cin>>nameRemove;
                myTree.removeByConcept(nameRemove);
                break;
            case 5:
                cout<<"\n Enter name of data Structure that you need to remove: ";
                cin>>nameRemoveByData;
                myTree.removeByDataStruc(nameRemoveByData);
                break;
            case 6:
                myTree.removeAll();
                break;
            case 7:
                number = 7;
            default:
                cout<<"\nNothing! Can you choose again !";
                break;
        }
    }
    return 1;
}