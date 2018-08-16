//My name: Dat Pham
//class number: CS163
//project number: 4
//Purpose:
/* 
 this file contains the information about binary tree and managing
a list of the advantage and disadavantage. we will create, insert, serch, remove by concept, remove by datastructure in binary search tree.
 
 */

#include <iostream>

/*
 Create a class to advantage with
 information about variable and function of advantage
 */

class advantage{
    
    public:
        advantage();
        ~advantage();
        int addInfor(char advan[]);
        int copy(advantage &_advan);
        int display();
    private:
        char *advan; //content of advantage
};





// define node of advantage
// for each node has data, *next

struct ad_node{
    advantage data;
    ad_node *next;
};



/*
 Create a class to list Advantage with
 information about variable and function of list of advantage
 */

class listAdvantage{
    
    public:
        listAdvantage();
        ~listAdvantage();
        int addList(advantage &adv);
        int display();
    private:
        ad_node *head;
};



/*
 
 Create a class to disadvantage with
 information about disvariable and function of disadvantage
 
*/

class disadvantage{
    
    public:
        disadvantage();
        ~disadvantage();
        int addInfor(char disadvan[]);
        int copy(disadvantage &_disadvan);
        int display();
    private:
        char *disadvan;
};



// define node of disadvantage
// for each node has data, *next

struct dis_node{
    
    disadvantage data;
    dis_node *next;
};



/*
 Create a class to list disadvantage with
 information about variable and function of list of disadvantage
 */

class listDisadvantage{
    
    public:
        listDisadvantage();
        ~listDisadvantage();
        int addList(disadvantage &_disadv);
        int display();
    private:
        dis_node *head;
};



/*
 Create a class to concept with
 information about variable and function of concept
 */

class concept{
    
public:
    concept();
    ~concept();
  
    int addInfor(char name[], char dataStructure[]);
    int copy(concept &_concept);
    int display();
    char *getName();
    char *getdataStructure();
    
private:
    char *name;
    char *dataStructure;
    
};



// define node of disadvantage
// for each node has data, *next

struct node{
    
    concept data;
    listAdvantage listadvan;
    listDisadvantage listdisadvan;
    node *left;
    node *right;
};



/*
 Create a class to binarytree with
 information about variable and function of binarytree
 */

class binarytree{
    public:
        binarytree();
        ~binarytree();
        int destroyTree(node *root);
        int insert(concept &keyValue,listAdvantage _listadvan,listDisadvantage _listdisadvan);
        int insert(concept &keyValue,listAdvantage _listadvan,listDisadvantage _listdisadvan, node * & root);
    
        int retrive(char keyValue[]);
        int retrive(char keyValue[],node * & root);
    
        int removeByConcept(char keyValue[]);
        int removeByConcept(char keyValue[],node *&root);
    
        int removeByDataStruc(char keyValue[]);
        int removeByDataStruc(char keyValue[], node *&root);
    
        int removeAll();
    
        void print_inorder();
        void inorder(node* p);
    private:
        node *root;
};

