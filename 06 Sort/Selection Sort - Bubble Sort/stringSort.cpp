
/*****************************************************************************
 ** Author: Dat Pham
 ** Week 5
 ** Project 5.a
 ** Date: April 29, 2017
 ** Description: using selection sort function to sort array of string
 ***************************************************************************/


#include <iostream>
#include <string.h>
using namespace std;


/*****************************************************************************
 **
 ** Description: swap two string together
 ** Param: str1 data type is string
 ** Param: str2 data type is string
 **
 ****************************************************************************/

void swap(std::string &str1, std::string &str2){
    
    std::string temp = str1;
    str1 = str2;
    str2 = temp;
}



/*****************************************************************************
 **
 ** Description: Compare to string together
 ** Param: str1 data type is string
 ** Param: str2 data type is string
 ** return: true if str1>str2.
 ****************************************************************************/

bool compareString(std::string str1, std::string str2){
    
    for(int i=0;i<str1.length();i++)
        str1[i] = toupper(str1[i]);
    
    for(int j=0;j<str2.length();j++)
        str2[j] = toupper(str2[j]);
    
    if(str1>str2)
        return true;
    else
        return false;
}



/*****************************************************************************
 **
 ** Description: using selection sort for array of string
 ** Param: arrayStr
 ** Param: size of array
 ** return: void
 ****************************************************************************/



void stringSort(std::string *& arrayStr,int size){
    
    for(int i=0;i<size-1;i++){
        int minPos = i;
        
        for(int j=i+1;j<size;j++)
            if(compareString(arrayStr[minPos],arrayStr[j]))
                minPos = j;
        
        if(minPos != i)
            swap(arrayStr[i],arrayStr[minPos]);
            
    }
}





//int main()
//{
//    std::string *str = new std::string[5];
//    str[0] = "dattttttttttt";
//    str[1]="DATTTTT";
//    str[2]= "DAT";
//    str[3]= "DATTT";
//    str[4] = "datttttt";
//   
//    stringSort(str,5);
//    
//    for(int i=0;i<5;i++)
//        cout<<""<<str[i]<<endl;
//    
//    return 1;
//}
