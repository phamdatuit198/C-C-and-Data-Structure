//My name: Dat Pham
//class number: CS163
//project number: 1
//Purpose:
/*
    we are using ADT for managing a list of candidate. 
    we will develop a function for update infor and display
*/

#include "candidate.h"
using namespace std;


//constructor of candidate class

candidate::candidate(){
    nameCan = NULL;
    major = NULL;
    thinking = NULL;
    rankThePoll = 0;

}


//destructor of candidate class

candidate::~candidate(){
    
    if(nameCan)
        nameCan=NULL;
    if(major)
        major=NULL;
    if(thinking)
        thinking=NULL;
    if(rankThePoll!=0)
        rankThePoll=0;

}



/*
    @purpose: add information of candidate into object candidate
   
    @param name_in[]
            array character for name of candidate
    @param major_in[]
            array character for 5 major view of candidate
    @param thinking_in[]
            array character for your thinking about candidate
    @param rank_in
            variable ranking of candidate
 
    @return 1
            when we add done
 */


int candidate::addNew(char name_in[], char major_in[], char thinking_in[],int rank_in){
    
    nameCan = new char[strlen(name_in)+1];
    major = new char[strlen(major_in)+1];
    thinking = new char[strlen(thinking_in)+1];
    
    strcpy(nameCan,name_in);
    strcpy(major,major_in);
    strcpy(thinking,thinking_in);
    
    rankThePoll= rank_in;
    
    return 1;
}



/*
    @purpose: display information for single candidate
 
    @return 1
        when we add done
 */

int candidate::display(){
    if(!nameCan)
        return 0;
    cout<<"\nName: "<<nameCan;
    cout<<"\nMajor: "<<major;
    cout<<"\nthinking: "<<thinking;
    cout<<"\nRanking:"<<rankThePoll;
    cout<<"\n";
    return 1;
}


/*
    @purpose: update ranking of single candidate
    @param _name[]
            the name of candidate who need to update
    @return 1
        when we add done
    @return
        when we don't find any person who has same name for update
 */

int candidate::updatePoll(char _name[]){

    if(strcmp(nameCan,_name)==0){
        cout<<"what roll you need update: ";
        cin>>rankThePoll;
        
        cout<<"\nwe done for update!";
        
        display();
    }else{
        return 0;
    }
    return 1;
}



/*
    @purpose: update thinking about single candidate
    @param _name[]
        the name of candidate who need to update
    @return 1
        when we add done
    @return 0
        when we don't find a person who has same name for update
 */

int candidate::updateThinking(char _name[]){
    
    if(strcmp(nameCan,_name)==0){
        cout<<"what thinking you need update: ";
        cin>>thinking;
        
        cout<<"\nwe done for update!";
        
        display();
    }else{
	return 0;	
    }
    return 1;
}



//constructor of listCandidate class

listCandidate::listCandidate(){
    head = NULL;
    tail = NULL;
}



//destructor of candidate class

listCandidate::~listCandidate(){
//    node *p = new node;
//    while(head!=NULL){
//        p = head;
//        head = head->next;
//        delete p;
//    }
}


/*
    @purpose: add new candidate into list of candidate
    
    @param singleData
        information about new candidate
    
    @return 1
        when we add done
 */

int listCandidate::addListCandidate(candidate singleData){
    node *p = new node;
    p->Inforcandidate = singleData;
    p->next = NULL;
    if(head==NULL){
        head=p;
        tail = head;
    }else{
        tail->next = p;
        tail = p;
    }
    return 1;
}



/*
    @purpose: display information list of candidate, we will call display function of candidate
 
    @return 1
        when we add done
 */

int listCandidate::display(){
    node *p;
    p =head;
    int i=1;
    cout<<"LIST CANDIDATE\n\n";
    while(p!=NULL){
        cout<<"\nCandidate: "<<i<<"\n";
        
        p->Inforcandidate.display();
        p=p->next;
        i++;
    }
    return 1;
}




/*
    @purpose: update ranking about single candidate, we will call updatePoll of candidate

    @param _name[]
        the name of candidate who need to update
    
    @return 1
        when we add done
 */

int listCandidate::updatePoll(char name_in[]){
    
    node *p = new node;
    p = head;
    
    while(p!=NULL){
        p->Inforcandidate.updatePoll(name_in);
        p=p->next;
    }

    return 1;
}



/*
    @purpose: update thinking about single candidate, we will call updateThinking of candidate
 
    @param _name[]
        the name of candidate who need to update
 
    @return 1
        when we add done
 */

int listCandidate::updateThinking(char name_in[]){
    
    node *p = new node;
    p = head;
    while(p!=NULL){
        p->Inforcandidate.updateThinking(name_in);
        p=p->next;
    }
    
    return 1;
}



//constructor of listCandidate class


listParty::listParty(){
    head = NULL;
    tail = NULL;
}



//destructor of listCandidate class

listParty::~listParty(){
    list *p;
    while(head!=NULL){
        p = head->next;
        delete head;
        head = p;
    }
}



/*
    @purpose: add new list of candidate into party
 
    @param _listCan
        information about new list of candidate
 
    @param _nameParty[]
         array of character name party
 
    @return 1
        when we add done
 */

int listParty::addListParty(listCandidate _listCan,char nameParty[]){
    list *p = new list;
    p->listCan= _listCan;
    p->next = NULL;
    
    strcpy(p->party, nameParty);
    if(head==NULL){
        head=p;
        tail = head;
    }else{
        tail->next = p;
        tail = p;
    }
    return 1;
}



/*
    @purpose: display information list of party, we will call display function of listCandidate
 
    @return 1
        when we add done
 */

int listParty::display(){
    
    list *p;
    p =head;
    cout<<"LIST Party\n\n";
    while(p!=NULL){
        cout<<"\n-----Party: "<<p->party<<"------\n";
        
        p->listCan.display();
        p=p->next;
    }

    return 1;
}



/*
    @purpose: update ranking about single candidate, we will call updatePoll of listCandidate
 
    @param name_in[]
        the name of candidate who need to update
 
    @param party[]
        the name of party which candidate join.
 
    @return 1
        when we add done
 */

int listParty::updatePoll(char name_in[],char party[]){
    
    list *p = new list;
    p = head;
    
    while(p!=NULL){
        if(strcmp(p->party,party)==0)
            p->listCan.updatePoll(name_in);
        
        p=p->next;
    }
    
    return 1;
}



/*
    @purpose: update ranking about single candidate, we will call updatePoll of listCandidate
 
    @param name_in[]
        the name of candidate who need to update
 
    @param party[]
        the name of party which candidate join.
 
    @return 1
        when we add done
 */

int listParty::updateThinking(char name_in[],char party[]){
    
    list *p = new list;
    p = head;
    
    while(p!=NULL){
        if(strcmp(p->party,party)==0)
            p->listCan.updateThinking(name_in);
        
        p=p->next;
    }
    
    return 1;
}



