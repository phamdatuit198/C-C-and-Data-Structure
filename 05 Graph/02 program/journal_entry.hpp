//
//  journal_entry.hpp
//  graph
//
//  My name: Dat Pham
//  class number: CS163
//  project number: 5
//  Purpose:
/*
    Define some function for journal_entry class
 */




// Information of journal entry class



class journal_entry
{
    public:
   
        journal_entry(void);                            //constructor of journal_entry
        ~journal_entry(void);                           //destructor of journal_entry class
        int create_entry(char * title, char * notes);   //insert value for data member
        int copy_entry(journal_entry & a_new_entry);    //copy data member of object to another object of journal_entry
        int isEmpty(journal_entry &check_entry);        //check object is empty or it's not
        bool compare (char * is_it_a_match);
        char* getTitle();                               //getting title variable
        char* getNotes();                               //getting notes variable
        int display();
    private:
        char * title;                                   //variable title of journal_entry object
        char * notes;                                   //variable notes of journal_entry object
};

