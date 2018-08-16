//My name: Dat Pham
//class number: CS163
//project number: 4
//Purpose:
/*
 we are using table ADT using binary tree.
 we will develop a function for insert, remove, search infor about concept of data structure and display
 */
#include <iostream>
#include "binarytree.h"
using namespace std;


// Advantage class

//constructor of advantage

advantage::advantage(){
    advan = NULL;
}


//destructor of advantage class

advantage::~advantage(){
    
    if(advan){
        delete []advan;
    }
}



/*
 @purpose: add advantage into object advantage
 
 @param adv[]
 array character for advantage
 
 @return 1
 when we add done
 */

int advantage::addInfor(char adv[]){
    
    advan = new char[strlen(adv)];
    stpcpy(advan, adv);
    
    return 1;
}



/*
 @purpose: copy advantage from object advantage to other object of advantage
 
 @param _adv
    object of advantage
 
 @return 1
 when we add done
 */

int advantage::copy(advantage &_adv){
    
    _adv.advan = new char[strlen(advan)+1];
    strcpy(_adv.advan, advan);
    return 1;
}



/*
 @purpose: display content of advantage
 
 @return 1
 when we add done
 */

int advantage::display(){
    cout<<"\t + "<<advan<<"\n";
    return 1;
}




//List of Advantage class

//constructor of listAdvantage class

listAdvantage::listAdvantage(){
    
    head = NULL;
}



//destructor of listAdvantage class

listAdvantage::~listAdvantage(){
    
//    ad_node *p = new ad_node;
//    if(head){
//        while(head!=NULL){
//            
//            p = head;
//            head = head->next;
//            delete p;
//        }
//    }
}



/*
 @purpose: add object advantage into list of advantage
 
 @param adv
        object advantage
 
 @return 1
 when we add done
 */

int listAdvantage::addList(advantage &adv){
    
    if(!head){
        head = new ad_node;
        adv.copy(head->data);
        //head->data= adv;
        head->next = NULL;
    }else{
        ad_node *temp = new ad_node;
        adv.copy(temp->data);
        //temp->data = adv;
        temp->next = head;
        head = temp;
    }
    return 1;
}



/*
 @purpose: display content of list of advantage
 
 @return 1
 when we add done
 */

int listAdvantage::display(){
    ad_node *temp = new ad_node;
    temp = head;
    cout<<"\nAdvantage: \n";
    while(temp != NULL){
        temp->data.display();
        temp = temp->next;
    }
    return 1;
}




//constructor of disadvantage class

disadvantage::disadvantage(){
    disadvan = NULL;
}



//destructor of candidate class

disadvantage::~disadvantage(){
    
    if(disadvan){
        delete[] disadvan;
    }
}



/*
 @purpose: add disadvantage into object disadvantage
 
 @param disadv[]
 array character for disadvantage
 
 @return 1
 when we add done
 */

int disadvantage::addInfor(char disadv[]){
    
    disadvan = new char[strlen(disadv)+1];
    stpcpy(disadvan, disadv);
    
    return 1;
}



/*
 @purpose: copy disadvantage from object disadvantage to other object of disadvantage
 
 @param _disadv
 object of disadvantage
 
 @return 1
 when we add done
 */

int disadvantage::copy(disadvantage &_disadv){
    
    _disadv.disadvan = new char[strlen(disadvan)+1];
    strcpy(_disadv.disadvan, disadvan);
    return 1;
}



/*
 @purpose: display content of disadvantage 
 
 @return 1
 when we add done
 */

int disadvantage::display(){
    cout<<" "<<disadvan;
    return 1;
}


//constructor of list of disavantage class


listDisadvantage::listDisadvantage(){
    
    head = NULL;
}



//destructor of listDisadvantge class

listDisadvantage::~listDisadvantage(){
//    
//    dis_node *p = new dis_node;
//    if(head){
//        
//        while(head!=NULL){
//        
//            p = head;
//            head = head->next;
//            delete p;
//        }
//    }
}



/*
 @purpose: add object disadvantage into list of disadvantage
 
 @param disadv
    object disadvantage
 
 @return 1
 when we add done
 */

int listDisadvantage::addList(disadvantage &disadv){
    
    if(!head){
        head = new dis_node;
        disadv.copy(head->data);
        //head->data= disadv;
        head->next = NULL;
    }else{
        dis_node *temp = new dis_node;
        disadv.copy(temp->data);
        //temp->data = disadv;
        temp->next = head;
        head = temp;
    }
    return 1;
}



/*
 @purpose: display content of listdisadvantage
 
 @return 1
 when we add done
 */

int listDisadvantage::display(){
    dis_node *temp = new dis_node;
    temp = head;
    cout<<"\nDisavantage: \n";
    while(temp != NULL){
        temp->data.display();
        temp = temp->next;
    }
    return 1;
}


//Concept class

//constructor of concept class

concept::concept(){
    name = NULL;
    dataStructure = NULL;
    
    
}



//destructor of concept class

concept::~concept(){
    
    delete[] name;
    
    delete[] dataStructure;
    
}



/*
 @purpose: add information of concept into object concept
 
 @param _name[]
    array character for name
 
 @param _dataStructure[]
    array character for dataStructure
 
 @return 1
 when we add done
 */

int concept::addInfor(char _name[], char _dataStructure[]){
    
    if(name)
        delete []name;
    name = new char[strlen(_name)+1];
    stpcpy(name, _name);
    
    if(dataStructure)
        delete []dataStructure;
    dataStructure = new char[strlen(_dataStructure)+1];
    stpcpy(dataStructure,_dataStructure);
    
    
    return 1;
}



/*
 @purpose: copy concept from object concept to other object of concept
 
 @param _concept
    object of concept
 
 @return 1
 when we add done
 */

int concept::copy(concept &_concept){
    
    _concept.name = new char [strlen(name)+1];
    strcpy(_concept.name, name);
    
    _concept.dataStructure = new char [strlen(dataStructure) + 1];
    strcpy(_concept.dataStructure, dataStructure);
    
    return 1;
}



/*
 @purpose: display content of concept
 
 @return 1
 when we add done
 */

int concept::display(){
    cout<<"\nName of Concept: "<<name;
    cout<<"\nData Structure: "<<dataStructure;
    //listadvan.display();
    //listdisadvan.display();
    return 0;
}



/*
 @purpose: get variable name of concept
 
 @return name
 when we add done
 */

char * concept::getName(){
    return name;
}



/*
 @purpose: get dataStructure of concept
 
 @return dataStructure
 when we add done
 */

char * concept::getdataStructure(){
    return dataStructure;
}



//Binarytree class

//constructor of binarytree class

binarytree::binarytree(){
    root = NULL;
}



//destructor of binarytree class

binarytree::~binarytree(){
    destroyTree(root);
}



/*
 @purpose: destroy binary search tree
 
 @param root
        node of binary search tree
 
 
 @return 1
 when we add done
 */

int binarytree::destroyTree(node *root){
    
    if(root != NULL){
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
    return 1;
}


/*
 @purpose: insert information node of binarytree 
 
 @param _value
    object of concept
 
 @param _listadvan
    object of listAdvantage
 
 @param _listdisadvan
    object of listDisadvantage
 
 @return 1
 when we add done
 */


int binarytree::insert(concept &_value,listAdvantage _listadvan,listDisadvantage _listdisadvan){
    insert(_value,_listadvan,_listdisadvan, root);
    return 1;
}



/*
 @purpose: insert information node of binarytree
 
 @param _value
 object of concept
 
 @param _listadvan
 object of listAdvantage
 
 @param _listdisadvan
 object of listDisadvantage
 
 @return 1
 when we add done
 */

int binarytree::insert(concept &_value,listAdvantage _listadvan,listDisadvantage _listdisadvan, node *& _root){
    
    if(!_root){
        _root = new node();
        _value.copy(_root->data);
        _root->listadvan = _listadvan;
        _root->listdisadvan = _listdisadvan;
        _root->left = _root->right = NULL;
        return 1;
    }else{
        if(strlen(_value.getName()) < strlen(_root->data.getName()))
            return insert(_value,_listadvan,_listdisadvan, _root->left);
        if(strlen(_value.getName()) >= strlen(_root->data.getName()))
            return insert(_value,_listadvan,_listdisadvan,_root->right);
    }
    
    return 1;
}



/*
 @purpose: Call function retrive has two argument
 
 @param _keyvalue[]
 array of character concept that we loaded from application.
 
 
 @return 1
 when we add done
 */

int binarytree::retrive(char _keyvalue[]){
    retrive(_keyvalue,root);
    return 1;
}



/*
 @purpose: search concept in binarytree
 
 @param _keyvalue[]
    array of character concept that we loaded from application.
 
 @param _root
    node of binarytree
 @return 1
 when we add done
 */

int binarytree::retrive(char _keyvalue[], node *& _root){
    
    if(!_root){
        cout<<"\nNothing element at key!";
        return 0;
    }
    else{
        if(strlen(_keyvalue) < strlen(_root->data.getName()))
            return retrive(_keyvalue, _root->left);
        if(strlen(_keyvalue) > strlen(_root->data.getName()))
            return retrive(_keyvalue,_root->right);
        if(strlen(_keyvalue) == strlen(_root->data.getName())){
           if (strcmp(_keyvalue, _root->data.getName()) == 0)
               cout<<"\nHave element at key!\n";
           else
               retrive(_keyvalue,_root->right);
        }
    }
    return 1;
}



/*
 @purpose: Call function removebyConcept
 
 @param _keyvalue[]
 array of character concept that we loaded from application.
 
 
 @return 1
 when we add done
 */

int binarytree::removeByConcept(char _keyvalue[]){
    
    removeByConcept(_keyvalue,root);
    return 1;
}



/*
 @purpose: Remove node by concept
 
 @param _keyvalue[]
 array of character concept that we loaded from application.
 
 @param root
 node of binary of tree.
 
 @return 1
 when we add done
 */

int binarytree::removeByConcept(char _keyvalue[], node *&_root){
    
    if(!_root){
        return 0;
    }
    else{
        if(strlen(_keyvalue) < strlen(_root->data.getName()))
            return removeByConcept(_keyvalue, _root->left);
        if(strlen(_keyvalue) > strlen(_root->data.getName()))
            return removeByConcept(_keyvalue,_root->right);
        if(strlen(_keyvalue) == strlen(_root->data.getName())){
            if (strcmp(_keyvalue, _root->data.getName()) == 0){
             
                node *temp = _root;
                if (_root->left == NULL) _root = _root->right;    // Node chi co cay con phai
                else if (_root->right == NULL) _root = _root->left;   // Node chi co cay con trai
                else // Node co ca 2 con
                {
                    node *s = _root;
                    node *q = s->left;
                    // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
                    while (q->right != NULL)
                    {
                        s = q;
                        q = q->right;
                    }
                    temp->data = q->data;
                    s->right = q->left;
                    delete q;
                }
            }
            else
                return removeByConcept(_keyvalue,_root->right);
        }
    }
    return 1;
}


/*
 @purpose: Call function removebyDataStruc
 
 @param _keyvalue[]
 array of character data structure that we loaded from application.
 
 
 @return 1
 when we add done
 */

int binarytree::removeByDataStruc(char _keyvalue[]){
    removeByDataStruc(_keyvalue, root);
    return 1;
}



/*
 @purpose: Remove node by data structure
 
 @param _keyvalue[]
    array of character data structure that we loaded from application.
 
 @param root
        node of binary of tree.
 
 @return 1
 when we add done
 */

int binarytree::removeByDataStruc(char _keyvalue[],node *&_root){
    if(!_root)
        return 0;
    else{
        if(_root->left)
             removeByDataStruc(_keyvalue,_root->left);
        
            cout<<"\ncheck: "<<_root->data.getdataStructure()<<"\n";
            if(strcmp(_root->data.getdataStructure(),_keyvalue) == 0)
            {
                node *temp = _root;
                if (_root->left == NULL) _root = _root->right;    // Node chi co cay con phai
                else if (_root->right == NULL) _root = _root->left;   // Node chi co cay con trai
                else // Node co ca 2 con
                {
                    node *s = _root;
                    node *q = s->left;
                    // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
                    while (q->right != NULL)
                    {
                        s = q;
                        q = q->right;
                    }
                    temp->data = q->data;
                    s->right = q->left;
                    delete q;
                }

            }
        
        if(_root->right)
             removeByDataStruc(_keyvalue,_root->right);

    }
    return 1;
}




/*
 @purpose: remove all of node in the binary tree. we will call destroyTree function
 
 @return 1
 when we add done
 */
int binarytree::removeAll(){
    destroyTree(root);
    return 1;
}



/*
 @purpose: call inoder function.
 
 @return 1
 when we add done
 */

void binarytree::print_inorder()
{
  return inorder(root);
}


/*
 @purpose: display content of binarytree. 
          We will display from smallest length of name concept to largest length of name concept
 
 @param p
    node of binary tree
 @return 1
 when we add done
 */

void binarytree::inorder(node* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        p->data.display();
        p->listadvan.display();
        p->listdisadvan.display();
        if(p->right) inorder(p->right);
    }
    else return;
}
