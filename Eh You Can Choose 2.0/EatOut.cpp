/********************************************************************
 *                                                                  *
 *                   DERVIVED FROM FOOD CLASS                       *
 *        PARENT CLASS TO FASTFOOD, CASUAL, AND SPECIALTY           *                                            
 *                                                                  *
 ********************************************************************/

/* 
 * File:   EatOut.cpp
 * Author: Heidi2
 * 
 * Created on June 7, 2019, 10:22 PM
 */

#include "EatOut.h"
#include "Food.h"

//default constructor
EatOut::EatOut() 
    :Food()
{
    nameOfPlace = "";
    typeOfExperience = "";
}

//constructor for just EatOut
EatOut::EatOut(string nameOfPlace, string typeOfExperience)
    :Food()
{
    this->nameOfPlace = nameOfPlace;
    this->typeOfExperience = typeOfExperience;
}

//constructor for both Food and EatOut
EatOut::EatOut(string whatMeal, string typeOfFood, double averagePricePerPerson, string nameOfPlace, string typeOfExperience)
    :Food(whatMeal, typeOfFood, averagePricePerPerson)
{
    this->nameOfPlace = nameOfPlace;
    this->typeOfExperience = typeOfExperience;
}

//copy constructor
EatOut::EatOut(const EatOut& orig)
    :Food(orig)
{
    this->nameOfPlace = orig.nameOfPlace;
    this->typeOfExperience = orig.typeOfExperience;
}

//destructor
EatOut::~EatOut() 
{
    
}

//assignment overload
const EatOut& EatOut::operator =(const EatOut& rhs)
{
    //self assignment check
    if(&rhs == this) return *this;
    
    //copy over values for the food class
    Food::operator=(rhs);
    
    //copy over EatOut member variables
    this->nameOfPlace = rhs.nameOfPlace;
    this->typeOfExperience = rhs.typeOfExperience;
    
    //return the copy
    return *this;
}

//setter member functions
void EatOut::setNameOfPlace(string nameOfPlace)
{
    this->nameOfPlace = nameOfPlace;
}

void EatOut::setTypeOfExperience(string typeOfExperience)
{
    this->typeOfExperience = typeOfExperience;
}

//getter member functions
string EatOut::getNameOfPlace()
{
    return nameOfPlace;
}

string EatOut::getTypeOfExperience()
{
    return typeOfExperience;
}

//output both EatOut and Food
void EatOut::output()
{
    cout<<"Name of Place: "<<nameOfPlace<<endl;
    cout<<"Type of Food Place: "<<typeOfExperience<<endl;
    //output food
    Food::output();
}
