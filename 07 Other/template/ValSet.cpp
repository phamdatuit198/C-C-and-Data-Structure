/*****************************************************************************
 ** Author: Dat Pham
 ** Week 8
 ** Project 8.a
 ** Date: May 22, 2017
 ** Description: Write a template class called ValSet, which represent a mathematical set of value
 
 ***************************************************************************/


#include "ValSet.hpp"


/*****************************************************************************
 **
 ** Description: Default constructor enter value for variable from user.
 **
 ****************************************************************************/



template <class T>
ValSet<T>::ValSet(){
    sizeArray = 10;
    aptr = new T[sizeArray];
    value = 0;
}



/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user.
 ** Param: value with data type is T
 **
 ****************************************************************************/


template <class T>
ValSet<T>::ValSet(int size){
    sizeArray = size;
    aptr = new T[sizeArray];
    value = 0;
}



/*****************************************************************************
 **
 ** Description: Copy constructor copy two object together
 ** Param: value with data type is ValSet
 **
 ****************************************************************************/


template <class T>
ValSet<T>::ValSet(const ValSet &to_copy){
    sizeArray = to_copy.sizeArray;
    aptr = new T[sizeArray];
    
    for(int i =0; i<sizeArray ; i++)
        aptr[i] = to_copy.aptr[i];
    value = to_copy.value;
}



/*****************************************************************************
 **
 ** Description: Destructor delete array of value
 ** Param: value with data type is int
 **
 ****************************************************************************/


template <class T>
ValSet<T>::~ValSet(){
    
    if (sizeArray > 0)
        delete []aptr;
    value = 0;
    sizeArray = 0;
}



/*****************************************************************************
 **
 ** Description: function return the number of values currently in the valset
 ** Return: number of value with data type is int
 **
 ****************************************************************************/


template <class T>
int ValSet<T>::size() const{
    return value;
}



/*****************************************************************************
 **
 ** Description: function return the number of values currently in the valset
 ** Return: boolean if value is zero, and return false otherwise
 **
 ****************************************************************************/


template <class T>
bool ValSet<T>::isEmpty(){
    
    if(value == 0)
        return true;
    else
        return false;
}




/********************************************************************************************************
 **
 ** Description: function should take a parameter of type T and return true if that value is in the ValSet
 ** Return: boolean if value is zero, and return false otherwise
 **
 ********************************************************************************************************/


template <class T>
bool ValSet<T>::contains(T to_compare){
    for(int i = 0;i<sizeArray;i++){
        if (operator[](i) == to_compare)
            return true;
    }
    return false;
}



/********************************************************************************************************
 **
 ** Description: function should take a parameter of type T and add to array of ValSet
 **
 ********************************************************************************************************/



template <class T>
void ValSet<T>::add(T to_add){
    
    //check value is already in the ValSet or it is not
    if(!contains(to_add)){
        
        if(value == sizeArray){
            int newSize = sizeArray*2;
            T *temp = aptr;
            aptr = new T[newSize];
            for (int i=0;i<sizeArray;i++)
                aptr[i] = temp[i];
            
            //delete old array
            delete [] temp;
            
            //set sizeArray
            sizeArray = newSize;
            aptr[value] = to_add;
            value++;
        }else{
            aptr[value] = to_add;
            value++;
        }
    }else{
        //don't do everything
    }
    
}



/********************************************************************************************************
 **
 ** Description: That contains all of the values in the ValSet
 ** Return: vector data type
 **
 ********************************************************************************************************/



template<class T>
vector<T> ValSet<T>::getAsVector(){
    vector<T> array(sizeArray);
    for(int i = 0; i< sizeArray;i++)
        array[i] = aptr[i];
    
    return array;
}



/********************************************************************************************************
 **
 ** Description: Overload assignment operator []
 ** Parameter: sub with data type is int
 ** Return: T
 ********************************************************************************************************/



template <class T>
T &ValSet<T>::operator[](int sub){
    if(sub < 0 || sub >= sizeArray){
        cout<<"Error: subscript out of range. \n";
        exit(0);
    }else
        return aptr[sub];
}


/*****************************************************************************
 **
 ** Description: overloading operator "=" for copy data two object
 ** Param: to_copy with data type is ValSet
 ** Return: ValSet
 **
 ****************************************************************************/



template <class T>
ValSet<T> &ValSet<T>::operator=(ValSet to_copy){
    
    sizeArray = to_copy.sizeArray;
    aptr = new T[sizeArray];
    
    for(int i =0; i<sizeArray ; i++)
        aptr[i] = to_copy.aptr[i];
    value = to_copy.value;

    return *this;
}



/********************************************************************************************************
 **
 ** Description: function should remove value from array
 ** Return: void
 **
 ********************************************************************************************************/



template<class T>
void ValSet<T>::remove(T to_remove){
    
    for(int i=0;i<sizeArray;i++){
        
        if (operator[](i) == to_remove){
            for(int j=i;j<sizeArray-1;j++){
                cout<<"change : "<<aptr[j]<<endl;
                aptr[j]=aptr[j+1];
                cout<<"to : "<<aptr[j]<<endl;
            }
            value--;
        }
    }
    
}

template class ValSet<int>;
template class ValSet<char>;
template class ValSet<string>;















