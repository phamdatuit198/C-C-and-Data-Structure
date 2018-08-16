//
// bstTable.cpp
// DAT PHAM
// CS163
// Program 4

/*
 Purpose: we are using ADT for managing operation of table
 This is a function of table class. Opearation of the table in here.
 */

#include "bstTable.hpp"
#include  <cstring>
#include <cstdlib>

/*
    Constructor of course
*/

bstTable::bstTable(){
    root = NULL;
}



/*
    Destructor of course
*/


bstTable::~bstTable(){
    if(root!=NULL)
        destroyTree(root);
}




/*
 @purpose: destroy binary search tree
 
 @param root
    root of binary search tree
 
 
 @return:
    0: if root isn't exits
    1: when we add done
*/



int bstTable::destroyTree(n_course *& root){
    
    if(!root)
        return 0;
    
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
    return 1;
    
}




/*
 
 @purpose: wapper function add course object into table
 
 @param to_add
    Object course class
 
 @return:
    0 when argument is NULL
    1 when we insert done
 
*/



int bstTable::insert(course &to_add){
    
   //check argument is NULL or it's not
    
    if(to_add.isEmpty() == 0)
        return 0;
    
    return insert(to_add,root);
}



/*
 
 @purpose: add course object into table
 
 @param to_add
    Object course class
 @param root
    note root of the bst
 
 @return:
    0 when argument is NULL
    1 when we insert done
 
 */



int bstTable::insert(course & to_add,n_course * & root){
    
    if(!root){
        root = new n_course();
        root->data_course.copy(to_add);
        root->left = NULL;
        root->right = NULL;
    }else{
        if(to_add.getValue() < root->data_course.getValue())
            return insert(to_add,root->left);
        if(to_add.getValue() >= root->data_course.getValue())
            return insert(to_add,root->right);

    }
    return 1;
}



/*
 
 @purpose: return number of course number
    Example: CS163 return 163
 
 @param *key
    pointer of number course
 
 @return:
    number of course number
 
*/



int bstTable::countKey(char *key){
    
    int sum = 0;
    int j=0;
    char value[3];
    
    int lengh = strlen(key);
    
    for(int i=2;i<lengh;i++){
        value[j]= key[i];
        j++;
    }
    sum = atoi(value);
    return sum;
    
}




/*
 
 @purpose: wapper function search object course in table by range
 
 @param _from[]
    array character for course number
 @param _to[]
    array character for course number
 @param found
    object of course when we found course match then we will copy into found and return
 
 @return 1
    1: when we found element, then copy into found object
    0: when we can't find anything at key
 
*/



int bstTable::retrieveRange(char _from[],char _to[], course * & found){
   
    //check argument is null, or they aren't
    
    if(_from == NULL || _to == NULL)
        return 0;
    
    int numFrom = countKey(_from);          //get value of the _from
    int numTo = countKey(_to);              //get value of the _to
    int index = -1;                         //variable element that we found anything or it's not
   
    //call function recursion retrieve
    
    retrieveRange(numFrom, numTo, index, found, root);
    
    //return client if we found anything.
    
    if(index != -1)
        return 1;
    else
        return 0;
}



/*
 
 @purpose: wapper function search object course in table by range
 
 @param _from[]
        interger of course number
 @param _to[]
        interger of course number
 @param index
        index of the array element that we found
 @param found
        object of course when we found course match then we will copy into found and return
 @param root
        node root of the binary search tree
 

 @return 1
    1: when we found element, then copy into found object
    0: when we can't find anything at key

*/




int bstTable::retrieveRange(int _from,int _to,int & index, course * & found, n_course * & root){
    
    if(!root)
        return 0;

    
    retrieveRange(_from, _to,index, found,root->left);
    if(_to >= root->data_course.getValue()&&_from <= root->data_course.getValue()){
        index++;
        found[index].copy(root->data_course);
    }
    retrieveRange(_from, _to,index, found,root->right);
    return 1;
}



/*
 
 @purpose: wapper function search object course in table by course number
 
 @param _numCourse[]
        array character for course number
 @param found
        object of course when we found course match we will copy into found and return
 
 @return 1
        1: when we found element, then copy into found object
        0: when we can't find anything at key
 
*/



int bstTable::retrieveByNumber(char _numCourse[], course * & found){
    
    
    if(_numCourse == NULL)
        return 0;
    
    int num = countKey(_numCourse);
    int index = -1;
    
    retrieveByNumber(num,index, found, root);
    if(index != -1)
        return 1;
    else
        return 0;
}



/*
 
 @purpose: function recursion search object course in table by number course
 
 @param valueKey
    interger of course number
 @param index
    index of the array element that we found
 @param found
    object of course when we found course match then we will copy into found and return
 @param root
    node root of the binary search tree
 
 @return 1
    1: when we found element, then copy into found object
    0: when we can't find anything at key
 
*/



int bstTable::retrieveByNumber(int valueKey, int & index, course * & found, n_course * &root){
    
    if(!root)
        return 0;
   
    if(valueKey < root->data_course.getValue())
        return retrieveByNumber(valueKey, index, found,root->left);
    if(valueKey > root->data_course.getValue())
        return retrieveByNumber(valueKey, index, found,root->right);
    if(valueKey == root->data_course.getValue()){
        index++;
        found[index].copy(root->data_course);
        return retrieveByNumber(valueKey, index, found,root->right);
    }
    return 1;
}



/*
 
 @purpose: wapper display information of table
 
 @return
    return value of recursion inorder

*/



int bstTable::displayAll(){
    return inorder(root);
    
}



/*
 
 @purpose: display information of table
 
 @return
    0: if root isn't exits
    1: when we are be done
 
*/



int bstTable::inorder(n_course *root){
    
    if(!root)
        return 0;
   
    if(root->left) inorder(root->left);
    root->data_course.display();
    if(root->right) inorder(root->right);
    
    return 1;
    
}



/*
 
 @purpose: wapper function to remove course
 
 @return
    0: if argument is null
    1: when we are be done
 
*/



int bstTable::remove(char *_numCourse){
    
    if(!_numCourse)
        return 0;
    
    return remove(_numCourse,root);
}



/*
 
 @purpose: recursion function to remove course
 
 @return
    0: if root is null
    1: when we are be done
 
*/



int bstTable::remove(char *_numCourse, n_course *& root){

    if(!root)
        return 0;
    
    if(root->left) remove(_numCourse,root->left);
    
    if(root->right) remove(_numCourse,root->right);

    if(root->data_course.checkNumber(_numCourse) == 1){
        n_course *temp = root;
        if (root->left == NULL){
            root = root->right;    // Node has one child in right
            delete temp;
        }
        else if (root->right == NULL){
            root = root->left;// Node has one child in left
            delete temp;
        }else // Node has two children
            {
                n_course *s = root;
                n_course *q = s->right;
            
                // s la cha cua q, q la Node phai nhat cua cay con trai cua P
                while (q->left != NULL)
                {
                    s = q;
                    q = q->left;
                }
                //temp->data = q->data;
                temp->data_course.copy(q->data_course);
                if(s!=root)
                    s->left = q->right;
                else
                    s->right = q->right;
                delete q;
            }

    }
    return 1;
}



/*
 
 @purpose: remove binary search tree
 
 @return
    0: if we don't have tree before
    1: when we are be done
 
 */

int bstTable::removeAll(){
    
    if(!root)
        return 0;
    
    destroyTree(root);
    
    root = NULL;
    
    return 1;
}


