/*****************************************************************************
 ** Author: Dat Pham
 ** Week 8
 ** Project 8.b
 ** Date: May 22, 2017
 ** Description: Write PreferredProject class inherit from CustomerProject class
 
 ***************************************************************************/


#include "PreferredProject.hpp"


/*****************************************************************************
**
** Description: Constructor enter value for variable from user.
** Param: double initial_hours,double initial_materials, double initial_transportation
**
****************************************************************************/


PreferredProject::PreferredProject(double initial_hours,double initial_materials, double initial_transportation):CustomerProject(initial_hours,initial_materials,initial_transportation){}



/*****************************************************************************
 **
 ** Description: Caculated bill amount. This function difference with bill amount of RegularProject class
 ** Return: double
 **
 ****************************************************************************/


double PreferredProject::billAmount(){
    
    double costForHours=0;
    double costMaterials = (double)(getMaterials() * 85)/100;
    double costTransportation = (double)(getTransportation() *90)/100;
    
    if(getHours()>100)
        costForHours=100*80;
    else
        costForHours=getHours()*80;
    
    return costForHours+costMaterials+costTransportation;
}
