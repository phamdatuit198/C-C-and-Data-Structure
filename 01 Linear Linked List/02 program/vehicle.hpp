//
//  vehicle.h
//
//  DAT PHAM
//  Program1
//  CS163

//Purpose:
//Purpose:
/* This file contains the information about vehiclelist.
 Then, show a list of vehicle */



#include<iostream>


//***Structure of typeCar***

struct n_typeCar{
    char *type;         //type vehicle
    n_typeCar *next;
};



/*
 information about list of type car
 */


class listTypeCar{
    
public:
    
    listTypeCar();                                      //constructor of listTypeCar class
    ~listTypeCar();                                     //destructor of listTypeCar class
    
    int insert(char type[]);                            //insert function into list type
    int copy(listTypeCar &_listTypeCar);                //copy function from listType to another listType
    int addPoint(int &point,listTypeCar &_listType);    //add point for vehicle
    int deductPoint(int &point,listTypeCar &_listType); //deduct point for vehicle
    void display();                                     //display information
private:
    n_typeCar *head;
    n_typeCar *tail;
};



// ***Structure of featureCar***

struct n_featureCar{
    char *feature;
    n_featureCar *next;
};




/*
 information about list of feature car
 */

class listFeatureCar{
    
    public:
    
        listFeatureCar();                                           //constructor of listFeatureCar class
        ~listFeatureCar();                                          //destructor of listFeatureCar class
    
        int insert(char feature[]);                                 //insert function into list Feature
        int copy(listFeatureCar &_listFeatureCar);       //copy function from listFeature to another FeatureType
        int addPoint(int &point,listFeatureCar &_listFeature);      //add point for vehicle
        int deductPoint(int &point,listFeatureCar &_listFeature);   //deduct point for vehicle
        void display();                                             //display information
    private:
        n_featureCar *head;
        n_featureCar *tail;
};



/*
 information about vehicle
 */

class vehicle{
    
    public:
    
        vehicle();                  //constructor of vehicle class
        ~vehicle();                 //destructor of vehicle class
    
        int insert(char _make[],char _model[],char _year[], char _price[], char _gas[], listTypeCar &_listType, char _engineSize[], char _numPeople[], listFeatureCar &_listFeature);  //insert information into vehicle
        int copy(vehicle &_vehicle);        //copy function from vehicle to another vehicle
        int wishCar(vehicle &_vehicle);     //add point for vehicle
        int disCar(vehicle &_vehicle);      //deduct point for vehicle
        int checkPoint(vehicle &_vehicle);  //compare point of two difference vehicle
        void display();                     //display information
        void displayMake();
    
    private:
    
        char *make;
        char *model;
        char *year;
        char *price;
        char *gas;
        listTypeCar listType;
        char *engineSize;
        char *numPeople;
        listFeatureCar listFeature;
    
        int point;

};



//***Structure of Vehicle***

struct n_vehicle{

    vehicle vehicle;
    n_vehicle *next;

};



//list of vehicle

class listVehicle{
    
    public:
        listVehicle();              //constructor of vehicle class
        ~listVehicle();             //destructor of vehicle class
        void display();
        void displayMake();
        int loadData();             //Load data from file
        int loadListType(char _type[],listTypeCar &_listTypeCar); //Load list type car
        int loadListFeature(char _type[],listFeatureCar &_listFeatureCar); //Load Feature Car
        int insert(vehicle &_vehicle);// insert function into list of vehicles
        int wishCar(vehicle &_vehicle);// add point for vehicle
        int disCar(vehicle &_vehicle);// deduct point for vehicle
        void displayHighest();           //display vehicle what has highest point
    
    private:
        n_vehicle *head;
        n_vehicle *tail;

};

