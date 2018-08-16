//My name: Dat Pham
//class number: CS163
//project number: 1
//Purpose:
/*
    this is a man function of software. the software will call main() function first
    we will enter the name, major, thinking, rank of candidate.
 */

#include "candidate.h"
using namespace std;

int main(){
    char nameCandidate[100];     // name of Candidate
    char major[500];             // 5 major view of each candidate
    char thinking[100];          // your thinking about candidate
    char party[100];             // name of party
    int rank;                    // ranking of candidate
    int number=0;                // the number of the list your choice when the program start
    int n;                       // number candidate for each party
    int m;                       // number for party
    char nameUpdate[100];        // name of candidate which you enter for update information
    char partyUpdate[100];       // name of party which you enter for update information
    
    listParty listPar;           // list of party class
    
    cout<<"Please push number for party: ";
    cin>>m;
    
    for(int j= 1;j<=m;j++){
        
        // start create party
        candidate singleData;    // candidate class
        listCandidate listCan;   // listCandidate class
        
        cout<<"\nYou are pushing information for party "<<j<<"\n";
        
        cout<<"\nEnter name party: ";
        cin>>party;
        
        cout<<"\nPlease push number Candidate for party "<<j<<": ";
        cin>>n;
        
        for(int i = 1; i<= n ; i++){
            
            //start create list for each party
            
            cout<<"\nEnter Name:";
            cin>>nameCandidate;
            cout<<"\nEnter major view: ";
            cin>>major;
            cout<<"\nEnter your thinking: ";
            cin>>thinking;
            cout<<"\nEnter rank: ";
            cin>>rank;
            
            //add information of candiate
            singleData.addNew(nameCandidate, major, thinking, rank);
            
            //add candiate into list
            listCan.addListCandidate(singleData);
        }
        // add list of candidate into party
        listPar.addListParty(listCan, party);

    }
    
        // you begin choose activity you need
    
        while(number!= 4){
        cout<<"\n1. Display All\n";
        cout<<"2. Update Roll\n";
        cout<<"3. Update Thinking\n";
        cout<<"4. End\n";
        cout<<"choose number you need: ";
        cin>>number;
        switch (number){
            case 1:
                listPar.display();
                break;
            case 2:
                cout<<"Enter name of Candidate who need to update: ";
                cin>>nameUpdate;
                cout<<"Enter Party name of Candidate who need to update: ";
                cin>>partyUpdate;
                listPar.updatePoll(nameUpdate,partyUpdate);
                listPar.display();
                break;
        
            case 3:
                cout<<"Enter name of Candidate who need to update: ";
                cin>>nameUpdate;
                cout<<"Enter Party name of Candidate who need to update: ";
                cin>>partyUpdate;
                listPar.updateThinking(nameUpdate,partyUpdate);
                listPar.display();
                break;
            case 4:
                cout<<"END!\n";
		break;
            default:
                cout<<"\nNothing! Can you choose again !";
                break;
        }
    }
}
