//My name: Dat Pham
//class number: CS163
//project number: 1
//Purpose:
/* this file contains the information about managing presidential candidates and managing
	a list of the Presidential candidates. We need to keep track of propertie for name, major, how they rank*/
#include <iostream>
#include <cctype>

//Create a class to represent a single Candidate with a name, major, thinking, ranking

class candidate{

	public:
		candidate();
		~candidate();
    
        int addNew(char name_in[], char major_in[],char thinking_in[], int rank_in);
		int updatePoll(char name_in[]);
		int updateThinking(char name_in[]);
		int display();
		
		
	private:
		char *nameCan;
		char *major;
		int rankThePoll;
		char *thinking;

};



// define node of list candidate
// for each node has candidate, *next
struct node{
	candidate Inforcandidate;
	node * next;
};



// Create a class to represent a list of Candidate.
// Using Linear Linked List for display, and the list has two node head and tail

class listCandidate{
	
	public:
		listCandidate();
		~listCandidate();
    
		int addListCandidate(candidate newCandidate);
		int updatePoll(char name_in[]);
		int updateThinking(char name_in[]);
		int display();
	private:
		node * head;
		node * tail;	
};



//define node of list party
// for each node has listCandidate, party, *next

struct list{
    listCandidate listCan;
    char party[200];
    list * next;
};



// Create a class to represent a list of Party.
// Using Linear Linked List for display, and the list has two node head and tail

class listParty{
    
    public:
        listParty();
        ~listParty();
        int addListParty(listCandidate _listCandidate,char party[]);
        int updatePoll(char name_in[],char party[]);
        int updateThinking(char name_in[],char party[]);
        //int findParty(char party[]);
        int display();
    
    private:
        list *head;
        list *tail;
};






