//My name: Dat Pham
//class number: CS163
//project number: 1
//Purpose:
/*
 we are using ADT for managing a list of product.
 we will develop a function for update infor and display
 */

#include "newsItem.h"

using namespace std;


/*
 //constructor of product class
 
 */

newItem::newItem(){
    title = NULL;
    comment = NULL;
    coutLike = 0;
    coutComment = 0;
    coutView = 0;
    keyWord = NULL;
}



/*
 
 destructor of product class
 */

newItem::~newItem(){
    title = NULL;
    comment = NULL;
    coutLike = 0;
    coutComment = 0;
    coutView = 0;
    keyWord = NULL;
}


/*
 @purpose: show all of newItem into hashtable
 
 @return 1
 when we add done
 */

int newItem::display(){
    cout<<"\nTitle: "<<title<<"\n";
    cout<<"\nComment: "<<comment<<"\n";
    cout<<"\nQuantity Like: "<<coutLike<<"\n";
    cout<<"\nQuantity Comment: "<<coutComment<<"\n";
    cout<<"\nQuantity View: "<<coutView<<"\n";
    cout<<"\nkeyword: "<<keyWord<<"\n";
    return 1;
}



/*
 @purpose: add information of newitem into item_node
 
 @param _title[]
 array character for title of newitem
 @param _comment[]
 array character for  comment  of newitem
 @param _coutlike
 quantity of like
 @param _coutView
 quantity of View
 @param _coutComment
 quantity of comment
 @param _keyword
 array character for keyword of newitem
 
 @return true
 when we add done
 */

int newItem::addNew(char _title[], char _comment[], int _coutLike, int _coutView, int _coutComment, char _keyWord[]){
    
    title = new char[strlen(_title) + 1];
    strcpy(title, _title);
    
    comment = new char[strlen(_comment) + 1];
    strcpy(comment, _comment);
    
    keyWord = new char[strlen(_keyWord) + 1];
    strcpy(keyWord, _keyWord);
    
    coutLike = _coutLike;
    coutView = _coutView;
    coutComment = _coutComment;
    
    return 1;
}


























