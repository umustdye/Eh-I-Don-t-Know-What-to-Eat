/********************************************************************
 *                                                                  *
 *              DERIVED FROM EATOUT AND FOOD CLASS                  *   
 *                                                                  *    
 ********************************************************************/

/* 
 * File:   Specialty.cpp
 * Author: Heidi Dye
 * 
 * Created on June 8, 2019, 10:20 AM
 */

#include "Specialty.h"

//default constructor
Specialty::Specialty() 
    :EatOut()
{
    typeOfPlace = "";
}

//constructor for just Specialty
Specialty::Specialty(string typeOfPlace)
    :EatOut()
{
    this->typeOfPlace = typeOfPlace;
}

//constructor for Specialty and EatOut
Specialty::Specialty(string nameOfPlace, string typeOfExperience, string typeOfPlace)
    :EatOut(nameOfPlace, typeOfExperience)
{
    this->typeOfPlace = typeOfPlace;
}

//constructor for EatOut, Food, and Specialty
Specialty::Specialty(string whatMeal, string typeOfFood, double averagePricePerPerson, string nameOfPlace, string typeOfExperience, string typeOfPlace)
    :EatOut(whatMeal, typeOfFood, averagePricePerPerson, nameOfPlace, typeOfExperience)
{
    this->typeOfPlace = typeOfPlace;
}

//copy constructor
Specialty::Specialty(const Specialty& orig) 
    :EatOut(orig)
{
    this->typeOfPlace = orig.typeOfPlace;
}

//destructor
Specialty::~Specialty() 
{
    
}

//assignment overload
const Specialty& Specialty::operator =(const Specialty& rhs)
{
    //self assignment check
    if(&rhs == this) return *this;
    EatOut::operator=(rhs);
    this->typeOfPlace = rhs.typeOfPlace;
}

//setter member variables
void Specialty::setTypeOfPlace(string typeOfPlace)
{
    this->typeOfPlace = typeOfPlace;
}

//getter member functions
string Specialty::getTypeOfPlace()
{
    return typeOfPlace;
}

//output EatOut, Food, specialty
void Specialty::output()
{
    EatOut::output();
    cout<<"Type Of Place: "<<typeOfPlace<<endl;
}

