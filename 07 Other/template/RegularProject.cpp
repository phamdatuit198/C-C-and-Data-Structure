/*****************************************************************************
 ** Author: Dat Pham
 ** Week 8
 ** Project 8.b
 ** Date: May 22, 2017
 ** Description: Write RegularProject class inherit from CustomerProject class
 
 ***************************************************************************/

#include "RegularProject.hpp"



/*****************************************************************************
 **
 ** Description: Constructor enter value for variable from user.
 ** Param: double initial_hours,double initial_materials, double initial_transportation
 **
 ****************************************************************************/
RegularProject::RegularProject(double initial_hours,double initial_materials, double initial_transportation):CustomerProject(initial_hours,initial_materials,initial_transportation){}



/*****************************************************************************
 **
 ** Description: Caculated bill amount, override base class
 ** Return: double
 **
 ****************************************************************************/


double RegularProject::billAmount(){
    return 80*getHours()+getMaterials()+getTransportation();
}
