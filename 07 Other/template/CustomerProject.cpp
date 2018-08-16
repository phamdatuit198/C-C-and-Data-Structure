/*****************************************************************************
 ** Author: Dat Pham
 ** Week 8
 ** Project 8.b
 ** Date: May 22, 2017
 ** Description: Write CustomerProject is base class
 
 ***************************************************************************/

#include "CustomerProject.hpp"



/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user
 ** Param: initial_hour with data type is double
 ** Param: initial_materials with data type is double
 ** Param: initial_transportation with data type is double
 **
 ****************************************************************************/

CustomerProject::CustomerProject(double initial_hours,double initial_materials, double initial_transportation){
    
    setHours(initial_hours);
    setMaterials(initial_materials);
    setTransportation(initial_transportation);
}



/*****************************************************************************
 **
 ** Description: set hours and enter data member hour with parameter
 **
 ****************************************************************************/



void CustomerProject::setHours(double initial_hours){
    hours = initial_hours;
}



/*****************************************************************************
 **
 ** Description: set materials and enter data member material with parameter
 **
 ****************************************************************************/

void CustomerProject::setMaterials(double initial_materials){
    materials = initial_materials;
}



/*****************************************************************************
 **
 ** Description: set transportation and enter data member transportation with parameter
 **
 ****************************************************************************/

void CustomerProject::setTransportation(double initial_transportation){
    transportation = initial_transportation;
}



/*****************************************************************************
 **
 ** Description: get hours and return hours variable
 ** return: double
 **
 ****************************************************************************/


double CustomerProject::getHours(){
    return hours;
}



/*****************************************************************************
 **
 ** Description: get material and return material variable
 ** return: double
 **
 ****************************************************************************/

double CustomerProject::getMaterials(){
    return materials;
}



/*****************************************************************************
 **
 ** Description: get transportation and return transportation variable
 ** return: double
 **
 ****************************************************************************/

double CustomerProject::getTransportation(){
    return transportation;
}


