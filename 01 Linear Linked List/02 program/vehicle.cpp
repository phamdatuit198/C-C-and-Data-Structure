//
//  DAT PHAM
//  CS163
//  Program1
//
//Purpose:
/*
 we are using ADT for managing a list of vehicle.
 we will develop a function for insert, add point and find vehicle that has highest point
 */

#include "vehicle.hpp"
#include <iostream>
#include <fstream>
using namespace std;


/*
 
 constructor of vehicle class
 
*/

vehicle::vehicle(){
    make = NULL;
    model = NULL;
    year = NULL;
    price = NULL;
    gas = NULL;
    engineSize = NULL;
    numPeople = NULL;
    
    point = 0;
}



/*
 
 destructor of vehicle class
 
*/


vehicle::~vehicle(){
    if(make)
        delete []make;
    if(model)
        delete []model;
    if(year)
        delete []year;
    if(price)
        delete []price;
    if(gas)
        delete []gas;
    if(engineSize)
        delete []engineSize;
    if(numPeople)
        delete [] numPeople;
    point =0;
}



/*
 @purpose: add information of vehicle into object vehicle
 
 @param _make
        array character of name manufacturer
 @param _model
        array character of name model
 @param _year
        array character of year
 @param _price
        array character of price
 @param _gas
        array character of gas
 @param _listType
        object of listTypeCar
 @param _engineSize
        array character of engine size
 @param _numPeople
        array character of number of people
 @param _listFeature
        object of listFeatureCar
 @return 1
    when we add done
 */

int vehicle::insert(char _make[], char _model[], char _year[], char _price[], char _gas[], listTypeCar &_listType, char _engineSize[], char _numPeople[], listFeatureCar &_listFeature){
    
    make = new char[strlen(_make)+1];
    strcpy(make, _make);
    
    
    model = new char[strlen(_model)+1];
    strcpy(model,_model);
    
    
    year = new char[strlen(_year)+1];
    strcpy(year,_year);
    
    
    price = new char[strlen(_price)+1];
    strcpy(price,_price);
    
    
    gas = new char[strlen(_gas)+1];
    strcpy(gas,_gas);
    
    
    engineSize = new char[strlen(_engineSize)+1];
    strcpy(engineSize,_engineSize);
    
    
    numPeople = new char[strlen(_numPeople)+1];
    strcpy(numPeople,_numPeople);
    
    listType.copy(_listType);
    
    listFeature.copy(_listFeature);

    return 1;
}


/*
 
 @purpose: copy from object vehicle to another object vehicle
 
 @param _vehicle
        object vehicle
 @return:
        1 when we insert done
 
*/

int vehicle::copy(vehicle &_vehicle){
    
    make = new char[strlen(_vehicle.make)+1];
    strcpy(make, _vehicle.make);
    
    
    model = new char[strlen(_vehicle.model)+1];
    strcpy(model,_vehicle.model);
    
    
    year = new char[strlen(_vehicle.year)+1];
    strcpy(year,_vehicle.year);
    
    
    price = new char[strlen(_vehicle.price)+1];
    strcpy(price,_vehicle.price);
    
    
    gas = new char[strlen(_vehicle.gas)+1];
    strcpy(gas,_vehicle.gas);
    
    
    engineSize = new char[strlen(_vehicle.engineSize)+1];
    strcpy(engineSize,_vehicle.engineSize);
    
    
    numPeople = new char[strlen(_vehicle.numPeople)+1];
    strcpy(numPeople,_vehicle.numPeople);
    
    listType.copy(_vehicle.listType);
    
    listFeature.copy(_vehicle.listFeature);
    
    return 1;
}



/*
 
 @purpose: add point for vehicle
 
 @param _vehicle
        object of vehicle class
 @return:
        1 when we insert done
 
 */

int vehicle::wishCar(vehicle &_vehicle){
    
    if(strcmp(make, _vehicle.make)==0)
        point = point +2;
    if(strcmp(model, _vehicle.model)==0)
        point = point +2;
    if(strcmp(year, _vehicle.year)==0)
        point = point +2;
    if(strcmp(price, _vehicle.price)==0)
        point = point +2;
    if(strcmp(gas, _vehicle.gas)==0)
        point = point +2;
    if(strcmp(engineSize, _vehicle.engineSize)==0)
        point = point +2;
    if(strcmp(numPeople, _vehicle.numPeople)==0)
        point = point +2;
    
    listType.addPoint(point, _vehicle.listType);
    listFeature.addPoint(point,_vehicle.listFeature);
    return 1;
}



/*
 
 @purpose: deduct point for vehicle
 
 @param _vehicle
        object of vehicle class
 @return:
        1 when we insert done
 
 */

int vehicle::disCar(vehicle &_vehicle){
    
    if(strcmp(make, _vehicle.make)==0)
        point = point -1;
    if(strcmp(model, _vehicle.model)==0)
        point = point -1;
    if(strcmp(year, _vehicle.year)==0)
        point = point -1;
    if(strcmp(price, _vehicle.price)==0)
        point = point -1;
    if(strcmp(gas, _vehicle.gas)==0)
        point = point -1;
    if(strcmp(engineSize, _vehicle.engineSize)==0)
        point = point -1;
    if(strcmp(numPeople, _vehicle.numPeople)==0)
        point = point -1;
    
    listType.deductPoint(point, _vehicle.listType);
    listFeature.deductPoint(point,_vehicle.listFeature);

    return 1;
}

/*
 
 @purpose: compare point from two different vehicles
 @param _vehicle
        object of vehicle class
 @return
        1: if point of argument object greater than point of current object
        0: if point of argument object lease than point of current object

 */

int vehicle::checkPoint(vehicle &_vehicle){
    
    if(point <_vehicle.point)
        return 1;
    else
        return 0;
    
}


/*
 
 @purpose: display information for single vehicle
 
 @return nothing
 
 */

void vehicle::displayMake(){
    
    cout<<"\n######";
    cout<<"\nMake: "<<make;
    cout<<"\nModel: "<<model;
    
}




/*
 
 @purpose: display information for single vehicle
 
 @return nothing
 
*/

void vehicle::display(){
    
    cout<<"\n######";
    cout<<"\nMake: "<<make;
    cout<<"\nModel: "<<model;
    cout<<"\nYear: "<<year;
    cout<<"\nPrice: "<<price;
    cout<<"\nGas: "<<gas;
    cout<<"\nEngineSize: "<<engineSize;
    cout<<"\nNumber of People:"<<numPeople;
    cout<<"\nList Type of Car: ";listType.display();
    cout<<"\nList Feature of Car: ";listFeature.display();
    cout<<"\nPoint wish: "<<point;
    
}



/*
 
 constructor of listVehicle class
 
*/

listVehicle::listVehicle(){
    
    int result = loadData();
    //display();
    if(result==1)
        cout<<"\nLoading data success!\n";
    else
        cout<<"\nUnable to open file! \n";
}



/*
 
 destructor of listVehicle class
 
*/


listVehicle::~listVehicle(){
    
    n_vehicle *temp = new n_vehicle;
    
    while(head!=NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}


/*
 
 @purpose: Load data about information vehicle from data file
 
 @return 1 if file can open
 @return 0 if file can't open
 
 */

int listVehicle::loadData(){
    
    char *make;
    char *model;
    char *year;
    char *price;
    char *gas;
    char *listType;
    char *engineSize;
    char *numPeople;
    char *listFeature;
    char buffer[1000];
    
    ifstream lineFile("vehicles.txt");
    if(lineFile.is_open()){
    
    
        while (!lineFile.eof())
        {
            
            listTypeCar myListTypeCar;
            listFeatureCar myListFeatureCar;
            vehicle myVehicle;
            lineFile.getline(buffer, 1000, '\n');
            if (strlen(buffer) > 0)
            {
                make = strtok (buffer,"#");
                model = strtok (NULL,"#");
                year = strtok (NULL,"#");
                price = strtok (NULL,"#");
                gas = strtok (NULL,"#");
                listType = strtok (NULL,"#");
                engineSize = strtok (NULL,"#");
                numPeople = strtok (NULL,"#");
                listFeature = strtok (NULL,"#");
                
                //create list type of car
                
                int resultType=loadListType(listType,myListTypeCar);
                if(resultType==0)
                    cout<<"\nLoad List Type Wrong!";
                else
                    cout<<"\nLoading data success!";
                //create list type of feature Car
                
                int resultFeature = loadListFeature(listFeature, myListFeatureCar);
                if(resultFeature==0)
                    cout<<"\nLoad List Feature Wrong!";
                else
                    cout<<"\nLoading data success!";
                
                myVehicle.insert(make, model, year, price, gas, myListTypeCar, engineSize, numPeople, myListFeatureCar);
                
            }
            insert(myVehicle);
        }
       
        return 1;
    }else
        return 0;
    
}



/*
 
 @purpose: Load data about information type of car from data file
 
 @param: _type
        Array of character list type of car from data file
 
 @param: _listTypeCar
        Object listTypeCar class
 
 @return 1 if we can insert into listTypeCar object
 @return 0 if _type is NULL
 
 */


int listVehicle::loadListType(char _type[],listTypeCar &_listTypeCar){
    
    char *typeCar;
    int resultInsert=0;
    if(_type==NULL)
        return 0;
    else{
        
        typeCar = strtok(_type, ",");
    
        while(typeCar!=NULL){
            resultInsert=_listTypeCar.insert(typeCar);
            if(resultInsert==0)
                cout<<"\nLoad List Type Wrong!";
            else
                cout<<"\nLoading data success!";
            typeCar = strtok(NULL,",");

        }
   
        return 1;
    }
}



/*
 
 @purpose: Load data about information feature of car from data file
 
 @param: _feature
 Array of character list feature of car from data file
 
 @param: _listFeatureCar
        Object listFeatureCar class
 
 @return 1 if we can insert into listFeatureCar object
 @return 0 if _feature is NULL
 
 */

int listVehicle::loadListFeature(char _feature[], listFeatureCar &_listFeatureCar){
    
    char *featureCar;
    int resultInsert = 0;
    if(_feature==NULL)
        return 0;
    else{
        featureCar = strtok(_feature, ",");
    
        while(featureCar!=NULL){
            resultInsert= _listFeatureCar.insert(featureCar);
            if(resultInsert==0)
                cout<<"\nLoad List Feature Wrong!";
            else
                cout<<"\nLoading data success!";
            featureCar = strtok(NULL,",");
        
        }

        return 1;
    }
}



/*
 @purpose: add new vehicle into list of vehicle
 
 @param _vehicle
        object of vehicle
 @return 1
        when we done
*/

int listVehicle::insert(vehicle &_vehicle){

    if(!head){
        head = new n_vehicle;
        head->vehicle.copy(_vehicle);
        head->next = NULL;
      
        tail=head;
        
    }
    else{
        
        n_vehicle *temp = new n_vehicle;
        temp->vehicle.copy(_vehicle);
        temp->next = NULL;
        
        tail->next = temp;
        tail = temp;
    }
    return 1;

}



/*
 
 @purpose: add point for vehicle of list vehicles
 
 @param _vehicle
        object of vehicle class
 @return:
        1 when we insert done
 
 */

int listVehicle::wishCar(vehicle &_vehicle){

    n_vehicle *temp = new n_vehicle;
    temp = head;
    while(temp!=NULL){
        temp->vehicle.wishCar(_vehicle);
        temp = temp->next;
    }
    return 1;
}



/*
 
 @purpose: deduct point for vehicle of list vehicles
 
 @param _vehicle
        object of vehicle class
 @return:
        1 when we insert done
 
 */

int listVehicle::disCar(vehicle &_vehicle){
    
    n_vehicle *temp = new n_vehicle;
    temp = head;
    while(temp!=NULL){
        temp->vehicle.disCar(_vehicle);
        temp = temp->next;
    }
    return 1;
}



/*
 
 @purpose: display information for single vehicle that has highest point
 
 @return nothing
 
*/

void listVehicle::displayHighest(){
    
    n_vehicle *temp1 = new n_vehicle;
    n_vehicle *temp2 = new n_vehicle;
    n_vehicle *max = new n_vehicle;
    int result=0;
    temp1 = head;
    
    max = head;
    while(temp1!=NULL){
        temp2=temp1->next;
        while(temp2!=NULL){
            result= temp1->vehicle.checkPoint(temp2->vehicle);
            if(result == 1)
                max = temp2;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    
    max->vehicle.display();
    
}


/*
 
 @purpose: display information for single listVehicle about make and model
 
 @return nothing
 
 */

void listVehicle::displayMake(){
    
    n_vehicle *temp = new n_vehicle;
    
    temp = head;
    while(temp!=NULL){
        temp->vehicle.displayMake();
        temp=temp->next;
    }
}




/*
 
 @purpose: display information for single listVehicle
 
 @return nothing
 
*/

void listVehicle::display(){

    n_vehicle *temp = new n_vehicle;

    temp = head;
    while(temp!=NULL){
        temp->vehicle.display();
        temp=temp->next;
    }
}




//****LIST TYPE CAR CLASS*****

/*
 
 constructor of listTypeCar class
 
*/

listTypeCar::listTypeCar(){
    head = NULL;
    tail = NULL;
}



/*
 
 destructor of listTypeCar class
 
*/

listTypeCar::~listTypeCar(){
    n_typeCar *temp = new n_typeCar;
    
    while(head!=NULL){
        temp = head;
        head = head->next;
        delete temp;
    }

    
}



/*
 
 @purpose: add type of vehicle into list of type car
 
 @param _type
        array character of name type vehicle
 @return: 
    0 when type is NULL
    1 when we insert done

*/

int listTypeCar::insert(char _type[]){
    
    if(_type == NULL)
        return 0;
    else{
        if(!head){
            head = new n_typeCar;
            head->type = new char[strlen(_type)+1];
            strcpy(head->type, _type);
            head->next = NULL;

            tail=head;
        }else{
            n_typeCar *temp = new n_typeCar;
            temp->type = new char[strlen(_type)+1];
            strcpy(temp->type, _type);
            temp->next = NULL;
        
            tail->next = temp;
            tail = temp;
    
        }
        return 1;
    }
}



/*
 
 @purpose: copy from object listTypeCar to another object listTypeCar
 
 @param _listTypeCar
        object listTypeCar class
 @return:
        1 when we insert done
 
*/

int listTypeCar::copy(listTypeCar &_listTypeCar){
    
    if(! _listTypeCar.head)
        return 0;
    else{
        n_typeCar *temp;
        temp = _listTypeCar.head;
        while(temp!= NULL){
            insert(temp->type);
            temp=temp->next;
        }
        
        return 1;
    }

}



/*
 
 @purpose: add point for vehicle if same type
 
 @param _listType
        object of listTypeCar class
 @param point
        point of vehicle
 @return:
        0: if don't have listType
        1: when we insert done
 
 */

int listTypeCar::addPoint(int &point,listTypeCar &_listType){
    
    if(!_listType.head)
        return 0;
    else{
        n_typeCar *temp1 = new n_typeCar;
        n_typeCar *temp2 = new n_typeCar;
        temp1 = _listType.head;
        
        while(temp1!=NULL){
            temp2 = head;
            
            while(temp2!=NULL){
                if(strcmp(temp1->type, temp2->type)==0)
                    point = point +2;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return 1;
    }
}



/*
 
 @purpose: deduct point for vehicle if same type
 
 @param _listType
        object of listTypeCar class
 @param point
        point of vehicle
 @return:
        0: if don't have listType
        1: when we insert done
 
 */

int listTypeCar::deductPoint(int &point, listTypeCar &_listType){

    if(!_listType.head)
        return 0;
    else{
        n_typeCar *temp1 = new n_typeCar;
        n_typeCar *temp2 = new n_typeCar;
        temp1 = _listType.head;
        
        while(temp1!=NULL){
            temp2 = head;
            
            while(temp2!=NULL){
                if(strcmp(temp1->type, temp2->type)==0)
                    point = point - 1;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return 1;
    }

}


/*
 
 @purpose: display information for single listTypeCar
 
 @return nothing
 
*/

void listTypeCar::display(){
    
    n_typeCar *temp = new n_typeCar;
    temp = head;
    
    while(temp != NULL){
        cout<<""<<temp->type<<" , ";
        temp = temp->next;
    }
}



//**** LIST OF FEATURE CLASS******



/*
 
 costructor of listFeatureCar class
 
*/

listFeatureCar::listFeatureCar(){
    head = NULL;
    tail = NULL;
}



/*
 
 destructor of listFeatureCar class
 
*/


listFeatureCar::~listFeatureCar(){
    
    n_featureCar *temp = new n_featureCar;
    while(head!=NULL){
            temp = head;
            head = head->next;
            delete temp;
    }

}



/*
 
 @purpose: add feature of vehicle into list of feature car
 
 @param _feature
    array character of name feature 
 @return:
    0 when _feature is NULL
    1 when we insert done
 
 */

int listFeatureCar::insert(char _feature[]){
    
    if(_feature==NULL)
        return 0;
    else{
        if(!head){
            head = new n_featureCar;
            head->feature = new char[strlen(_feature)+1];
            strcpy(head->feature, _feature);
            head->next = NULL;
            tail=head;
        }else{
            n_featureCar *temp = new n_featureCar;
            temp->feature = new char[strlen(_feature)+1];
            strcpy(temp->feature, _feature);
            temp->next = NULL;
        
            tail->next = temp;
            tail = temp;
        
        }
        return 1;
    }
}



/*
 
 @purpose: copy from object listFeatureCar to another object listFeatureCar
 
 @param _listFeatureCar
        object of listFeatureCar class
 @return:
        1 when we insert done
 
 */

int listFeatureCar::copy(listFeatureCar &_listFeatureCar){
    
    if(! _listFeatureCar.head)
        return 0;
    else{
        n_featureCar *temp = new n_featureCar;
        temp = _listFeatureCar.head;
        while(temp!= NULL){
            insert(temp->feature);
            temp=temp->next;
        }
        
        
        return 1;
    }
}


/*
 
 @purpose: add point for vehicle if same feature
 
 @param _listFeature
        object of listFeatureCar class
 @param point
        point of vehicle
 @return:
        0: if don't have listFeature
        1: when we insert done
 
 */


int listFeatureCar::addPoint(int &point,listFeatureCar &_listFeature){
    
    if(!_listFeature.head)
        return 0;
    else{
        n_featureCar *temp1 = new n_featureCar;
        n_featureCar *temp2 = new n_featureCar;
        temp1 = _listFeature.head;
        
        while(temp1!=NULL){
            temp2 = head;
            while(temp2!=NULL){
                if(strcmp(temp1->feature, temp2->feature)==0)
                    point = point +2;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return 1;
    }
}



/*
 
 @purpose: deduct point for vehicle if same feature
 
 @param _listFeature
        object of listFeatureCar class
 @param point
        point of vehicle
 @return:
        0: if don't have listFeature
        1: when we insert done
 
 */

int listFeatureCar::deductPoint(int &point, listFeatureCar &_listFeature){

    if(!_listFeature.head)
        return 0;
    else{
        n_featureCar *temp1 = new n_featureCar;
        n_featureCar *temp2 = new n_featureCar;
        temp1 = _listFeature.head;
        
        while(temp1!=NULL){
            temp2 = head;
            while(temp2!=NULL){
                if(strcmp(temp1->feature, temp2->feature)==0)
                    point = point -1;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return 1;
    }

}




/*
 
 @purpose: display information for single listFeatureCar
 
 @return nothing
 
*/

void listFeatureCar::display(){
    
    n_featureCar *temp = new n_featureCar;
    temp = head;
    while(temp != NULL){
        cout<<""<<temp->feature<<",";
        temp = temp->next;
    }
    
}















