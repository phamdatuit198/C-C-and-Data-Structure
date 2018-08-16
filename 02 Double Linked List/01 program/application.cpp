//My name: Dat Pham
//class number: CS163
//project number: 2
//Purpose:
/*
 this is a man function of software. the software will call main() function first
 we will enter list of product from File Data
 Enter order to list order
 saparate orders that don't have in warehouse
 */



#include "product.h"
#include "queueOrder.h"
#include "stackOrder.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int size; // the number order customer need to order
    int coutOrder=0; // cout order of customer
    char buffer[1000];// read from file
    char *tempName;// name product of file
    char *tempBarcode;//Barcode product of file
    char *tempDes;//description product of file
    char *tempManufacturer;//manufacturer of file
    int tempQuality;//quality product of file by int
    char *quality;// quality by char
    
    char nameOrder[300];// name of product you need to order
    int qualityOrder=1; //how many product you need
    
    char myChoise='N'; // choose continue
    bool checkOrder = false;// check order
    bool checkMoveStack = false;
    
    product myProduct;
    order myOrder;
    listProduct myListProduct;
    listOrder myListOrder;
    orderWaiting myOrderWaiting;
    listOrderWaiting myListOrderWaiting;
    
    ifstream lineFile;
    lineFile.open("productlist.txt");
  
    
    while (!lineFile.eof())
    {
        lineFile.getline(buffer, 1000, '\n');
        if (strlen(buffer) > 0)
        {
           
            tempBarcode = strtok (buffer, "#");
            tempName = strtok (NULL, "#");
            tempDes = strtok (NULL, "#");
            tempManufacturer = strtok (NULL, "#");
            quality = strtok (NULL, "#");
            
            cout << "\n*******************************\n";
            cout << "\nBarcode: " << tempBarcode;
            cout << "\nName: " << tempName;
            cout << "\nSo DES: " << tempDes;
            cout << "\nManufacturer: " << tempManufacturer;
            cout << "\nQuality: " << quality;
            cout << "*******************************\n\n";
            //conver quality from char to int
            tempQuality= atoi(quality);
            
            myProduct.addNew(tempBarcode, tempName, tempDes, tempManufacturer, tempQuality);
            myListProduct.addNew(myProduct);
        }
    }
    myListProduct.display();
    
    //ADD ORDER
    do{
        cout<<"\nHow many order you need ";
        cin>>size;
        
        //set size for ListOrder
        myListOrder.setSizeOfArray(size);
        //set size for ListOrderWaiting
        myListOrderWaiting.setSizeOfArray(size);
        checkMoveStack = true;
        for(int i = 0;i<size;i++){
            cout<<"\nEnter name of product: ";
            fflush(stdin);
            cin>>nameOrder;
            cout<<"\nEnter quality you need to get: ";
            cin>>qualityOrder;
   
            myOrder.addOrder(nameOrder, qualityOrder);
            //check product have list product or no
            checkOrder= myListProduct.checkItem(nameOrder);
            if(checkOrder==false){
                myOrderWaiting.addOrderWaiting(nameOrder, qualityOrder);
                myListOrderWaiting.addListOrderWaiting(myOrderWaiting,checkMoveStack);
                checkMoveStack = false;
            }

            myListOrder.addListOrder(myOrder);
            coutOrder++;
            
        }
     
        if(coutOrder==size){
            cout<<"\nDo you need order anymore (Y/N) ";
            cin>>myChoise;
            if(myChoise == 'Y'){
                coutOrder = 0;
            }
        }
        
    }while(coutOrder!=size);
    //display
    myListOrder.peek();
    cout<<"\nList of Order: \n";
    myListOrder.display();
    
    myListOrderWaiting.display();
    myListOrderWaiting.peek();
    
    
}





