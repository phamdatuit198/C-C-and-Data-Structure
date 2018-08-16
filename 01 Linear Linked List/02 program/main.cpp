//
//  DAT PHAM
//  Program1
//  CS163
//Purpose:
/*
 Client will contact with ADT and display information about vehicle, then Client will contact with ADT and display wish car.
 
 This is a man function of software. the software will call main() function first
 we will load list of vehicle from File Data
 Enter something that you need with wish car
 Enter something that you don't like with wish car
 
 */


#include <iostream>

#include "vehicle.hpp"

using namespace std;


/*
@purpose: Enter some information that you dislike about car
        argument will be loaded from main function when we done, argument will have informtion about car that yoi dislike
@param &disVehicle
        object vehicle that is a vehicle you dislike
 
@return 1 when we done
*/



int enterDisLike(vehicle &disVehicle){
    
    char myChooseType = 'Y';        //Choose type car next or it isn't
    char myChooseFeature = 'Y';     //Choose feature next or it isn't
    
    char d_typeCar[100];            //name of type car you dislike
    char d_featureCar[100];         //feature of car you dislike
    char d_make[30];                //manufacturer that you dislike
    char d_model[100];              //model that you dislike
    char d_year[10];                //year of car that you dislike
    char d_price[10];               //price of car that you dislike
    char d_gas[50];                 //Electric or Gas you dislike
    char d_engineSize[50];          //Size of engine that you dislike
    char d_numberPeople[5];         //number of sitting that you dislike
    
    listTypeCar myDisType;          //object of listTypeCar that you dislike
    listFeatureCar myDisFeature;    //object of listFeatureCar that you dislike
    
    //Enter information you dislike of your wishcar
    cin.ignore();
    cout<<"\nEnter Manufacturer you dislike: ";
    cin>>d_make;
    
    
    
    cout<<"\nEnter model you dislike: ";
    cin>>d_model;
    
    
    cout<<"\nEnter year you dislike: ";
    cin>>d_year;
    
    
    cout<<"\nEnter price you dislike: ";
    cin>>d_price;
    
    cout<<"\nEnter gas you dislike: ";
    cin>>d_gas;
    
    cout<<"\nEnter engineSize you dislike: ";
    cin>>d_engineSize;
    
    cout<<"\nEnter number people you dislike: ";
    cin>>d_numberPeople;
    
    //push type car into listTypeCar that you dislike
    do{
        cout<<"\nEnter type car you dislike: ";
        cin.ignore(100,'\n');
        cin.get(d_typeCar,100);
        
        cout<<"\n Do you want to add type car more: (Y/N) ";
        cin>>myChooseType;
        
        //insert into listTypeCar that you dislike
        myDisType.insert(d_typeCar);
        
    }while(myChooseType =='Y');
    
    //push feature car into listFeatureCar that you dislike
    do{
        cout<<"\nEnter feature you dislike: ";
        cin.ignore(100,'\n');
        cin.get(d_featureCar,100);
        
        myDisFeature.insert(d_featureCar);
        
        cout<<"\n Do you want to feature more: (Y/N) ";
        cin>>myChooseFeature;
        
    }while(myChooseFeature=='Y');
    
    //push information into vehicle class. This is really the car you that has information you don't like
    
    disVehicle.insert(d_make, d_model, d_year, d_price, d_gas, myDisType, d_engineSize, d_numberPeople, myDisFeature);
    return 1;
}



/*
 @purpose: Enter some information that you like about car
        argument will be loaded from main function when we done, argument will have informtion about car that you like
 @param &myWishVehicle
        object vehicle that is a vehicle you like
 
 @return 1 when we done
 */


int enterLike(vehicle &myWishVehicle){
    
    listTypeCar myDisType;          //object of listTypeCar that you dislike
    listFeatureCar myDisFeature;    //object of listFeatureCar that you dislike
    
    
    char myChooseType = 'Y';        //Choose type car next or it isn't
    char myChooseFeature = 'Y';     //Choose feature next or it isn't
    
    char type[100];                 //name of type car you like
    char featureCar[100];           //feature of car you like
    char make[30];                  //manufacturer that you like
    char model[100];                //model that you like
    char year[10];                  //year of car that you like
    char price[10];                 //price of car that you like
    char gas[50];                   //Electric or Gas you like
    char engineSize[50];            //Size of engine that you like
    char numberPeople[5];           //number of sitting that you like
    
    listTypeCar myWishType;         //object of listTypeCar that you like
    listFeatureCar myWishFeature;   //object of listFeatureCar that you like
    
    //Now input information you like
    
    cout<<"\nEnter Manufacturer you need: ";
    cin.get(make, 30);
    cin.ignore(30,'\n');
    
    cout<<"\nEnter model you need: ";
    cin.get(model, 100);
    cin.ignore(100,'\n');
  
    
    cout<<"\nEnter year you need: ";
    cin>>year;
 
    cout<<"\nEnter price you need: ";
    cin>>price;
   
    
    cout<<"\nEnter gas you need: ";
    cin>>gas;
   
    
    cout<<"\nEnter engineSize you need: ";
    cin>>engineSize;
    
    cout<<"\nEnter numberPeople you need: ";
    cin>>numberPeople;
    
    
    //push type car into listTypeCar that you like
    
    do{
        cout<<"\nEnter type car you need: ";
        cin.ignore(100,'\n');
        cin.get(type,100);
        
        cout<<"\n Do you want to add type car more: (Y/N) ";
        cin>>myChooseType;
        //insert into listTypeCar that you like
        myWishType.insert(type);

    }while(myChooseType =='Y');
    
    //push feature car into listFeatureCar that you like
    do{
        cout<<"\nEnter feature you need: ";
        cin.ignore(100,'\n');
        cin.get(featureCar,100);
        
        //insert into listFeatureCar that you like
        myWishFeature.insert(featureCar);
        
        cout<<"\n Do you want to feature more: (Y/N) ";
        cin>>myChooseFeature;
        
        
    }while(myChooseFeature=='Y');
    
    //push information into vehicle class. This is really the car you that has information you like
    
    myWishVehicle.insert(make, model, year, price, gas, myWishType, engineSize, numberPeople, myWishFeature);
    
  return 1;
}

int main() {
    
    vehicle myWishVehicle;      //vehicle you like
    vehicle disVehicle;         //vehicle you dislike
    listVehicle myListVehicle;  //ListVehicle dealer have
    
    //display all vehicle in list of vehicle
    cout<<"\n\nDisplay all information of list vehicle\n";
    myListVehicle.display();
    cout<<"\n\nDisplay only manufacturer and model\n";
    myListVehicle.displayMake();
    
    enterLike(myWishVehicle);
    //add point for car into list vehicle
    myListVehicle.wishCar(myWishVehicle);
    //show information vehicle that you like
    
    cout<<"\n\nDisplay information vehicle that you need\n";
    myWishVehicle.display();
    
    enterDisLike(disVehicle);
    //deduct point for car into list vehicle
    myListVehicle.disCar(disVehicle);
    //show information vehicle that you dislike
    
    cout<<"\n\nDisplay information vehicle that you dislike\n";
    disVehicle.display();

    //display all vehicles in the list that had change point
    cout<<"\n\ndisplay all vehicles in the list that had change point\n";
    myListVehicle.display();
    
    //display vehicle that has highest point
    cout<<"\n##################";
    cout<<"\nDisplay the vehicles based on the highest point value\n";
    myListVehicle.displayHighest();
    return 0;
}

