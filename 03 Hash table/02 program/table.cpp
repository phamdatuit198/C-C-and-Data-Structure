//
// table.cpp
// DAT PHAM
// CS163
// Program 3

/*
 Purpose: we are using ADT for managing operation of table
 This is a function of table class. Opearation of the table in here.
 */

#include "table.hpp"
#include  <cstring>


/*
    Constructor of course
 */

table::table(int size){
    
        hash_table_size = size;
        hash_table = new n_course*[size];
        for(int i=0;i<size;i++)
            hash_table[i] = NULL;
}



/*
    Destructor of course
 */

table::~table(){
    
    if(hash_table){
        for(int i = 0; i<hash_table_size; i++){
            n_course *temp = hash_table[i];
            while(temp != NULL){
                n_course *current = temp;
                temp = temp->next;
                delete current;
            }
        }
        delete []hash_table;
    }
}



/*
 
@purpose: choose location for new course
@param key
    array of character course name
@return
    return location of the new course
 
*/

int table::hashfunction(char *key){
    
    int sum = 0;
    int lengh = strlen(key);
    
    for(int i=0;i<lengh;i++)
        sum += key[i];
    
    return sum % hash_table_size;
}




/*
 
 @purpose: add course object into table
 
 @param _keyvalue[]
    Array character of course name
 
 @param to_add
    Object course class
 
 @return:
    0 when argument is NULL
    1 when we insert done
 
 */


int table::insert(char _keyvalue[], course & to_add){
    
    //check argument is NULL or it's not
    if(_keyvalue == NULL || to_add.isEmpty() == 0)
        return 0;
    
    int num = hashfunction(_keyvalue);
    
    if(!hash_table[num]){
        
        hash_table[num] = new n_course;
        hash_table[num]->data_course.copy(to_add);
        hash_table[num]->next = NULL;
        
    }else{
        
        n_course *temp = hash_table[num];
        hash_table[num] = new n_course;
        hash_table[num]->data_course.copy(to_add);
        hash_table[num]->next = temp;
    
    }
    return 1;
}




/*
 @purpose: search object course in table
 
 @param _nameCourse[]
    array character for course name
 @param found
    object of course when we found course match then we will copy into found and return
 
 @return 1
    1: when we found element, then copy into found object
    0: when we can't find anything at key
 */

int table::retrieveByName(char _nameCourse[], course * & found){
    
    int result = 0; //variable is define to catch value return from checkName function
    int i=0;
    int flg = 0;    //variable is have value is one if we have something matches
    
    //check argument is NULL or it's not
    
    if(_nameCourse==NULL)
        return 0;
    
    //get location because table organize by course name. Then we can get again location if we search by name
    int num = hashfunction(_nameCourse);
    n_course *temp = hash_table[num];
    
    //traversal list
    while(temp != NULL){
        result= temp->data_course.checkName(_nameCourse);
        if(result == 1){
            found[i].copy(temp->data_course);
            i++;
            flg = 1;
        }
        temp =temp->next;

    }
    
    //check have data match or it's not
    if(flg == 1)
        return 1;
    else
        return 0;
}




/*
 @purpose: search object course in table
 
 @param _numCourse[]
    array character for course number
 @param found
    object of course when we found course match we will copy into found and return

 @return 1
    1: when we found element, then copy into found object
    0: when we can't find anything at key
 */


int table::retrieveByNumber(char _numCourse[], course * & found){
    
    int result = 0;         //variable is define to catch value return from checkName function
    int i = 0;
    int flg = 0;            //variable is have value is one if we have something matches
    
    //check argument is NULL or it's not
    
    if(_numCourse==NULL)
        return 0;
    
    //traversal table
    for(int i = 0;i<hash_table_size;i++){
        n_course *temp = hash_table[i];
        while(temp != NULL){
            result = temp->data_course.checkNumber(_numCourse);
            if(result == 1){
                found[i].copy(temp->data_course);
                i++;
                flg = 1;
            }
            temp =temp->next;
        }
    }
    
    //check have data match or it's not
    if (flg == 1)
        return 1;
    else
        return 0;

}



/*
 
 @purpose: display information of table
 
 @return
    0: if data member is NULL
    1: when we are be done
 */


int table::displayAll(){
    
    if(!hash_table)
        return 0;
    
    for (int i = 0;i < hash_table_size;i++){
        
        n_course *temp = hash_table[i];
        
        while(temp != NULL){
            temp->data_course.display();
            temp =temp->next;
        }
    }
    
    return 1;
    
}






