
/*****************************************************************************
 ** Author: Dat Pham
 ** Week 5
 ** Project 5.b
 ** Date: April 29, 2017
 ** Description: using bubble sort function to sort array of box
 ***************************************************************************/


#include <iostream>
#include <string.h>
#include "Box.hpp"
using namespace std;


/*****************************************************************************
 **
 ** Description: swap two Box together
 ** Param: box1 data type is Box
 ** Param: box2 data type is Box
 **
 ****************************************************************************/

void swap(Box &box1,Box &box2){
    
    Box temp = box1;
    box1 = box2;
    box2 = temp;
}




/*****************************************************************************
 **
 ** Description: using bubble sort for array of box
 ** Param: arrayBox data type is Box
 ** Param: size of array
 ** return: void
 ****************************************************************************/

void boxSort(Box *& arrayBox,int size){
    
    for(int i = size-1; i >= 0;i--){
    
        for(int j=1;j<=i;j++){
            
            if(arrayBox[j-1].calcVolume() < arrayBox[j].calcVolume())
                swap(arrayBox[j-1], arrayBox[j]);
        }
    
    }
    
}





//int main()
//{
//    Box *box = new Box[5];
//    box[0].setLength(5);
//    box[0].setWidth(2);
//    box[0].setHeight(7);
//    
//    box[1].setLength(4);
//    box[1].setWidth(3);
//    box[1].setHeight(1);
//    
//    box[2].setLength(6);
//    box[2].setWidth(1);
//    box[2].setHeight(1);
//    
//    box[3].setLength(2);
//    box[3].setWidth(3);
//    box[3].setHeight(4);
//    
//    box[4].setLength(1);
//    box[4].setWidth(3);
//    box[4].setHeight(5);
//    
//    boxSort(box, 5);
//    
//    for(int i=0;i<5;i++)
//        cout<<""<<box[i].calcVolume()<<endl;
//    
//    return 1;
//}
