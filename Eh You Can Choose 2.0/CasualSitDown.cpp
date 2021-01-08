/********************************************************************
 *                                                                  *
 *              DERIVED FROM EATOUT AND FOOD CLASS                  *   
 *                                                                  *    
 ********************************************************************/

//NOTE TO SELF, CONTINUE AND WRITE THE SECOND CONSTRUCTOR FOR JUST CASUALSITDOWN

/* 
 * File:   CasualSitDown.cpp
 * Author: Heidi2
 * 
 * Created on June 8, 2019, 12:33 AM
 */

#include "CasualSitDown.h"

//default constructor
CasualSitDown::CasualSitDown() 
    :EatOut()
{
    bestKnownFor = "";
}

//constructor for just CasuualSitDown
CasualSitDown::CasualSitDown(string bestKnownFor)
    :EatOut()
{
    this->bestKnownFor = bestKnownFor;
}

//constructor for CasualSitDown and EatOUt
CasualSitDown::CasualSitDown(string nameOfPlace, string typeOfExperience, string bestKnownFor)
    :EatOut(nameOfPlace, typeOfExperience)
{
    this->bestKnownFor = bestKnownFor;
}

//constructor for EatOut, Food, and CasualSitDown
CasualSitDown::CasualSitDown(string whatMeal, string typeOfFood, double averagePricePerPerson, string nameOfPlace, string typeOfExperience, string bestKnownFor)
    :EatOut(whatMeal, typeOfFood, averagePricePerPerson, nameOfPlace, typeOfExperience)
{
    this->bestKnownFor = bestKnownFor;
}

//copy constructor
CasualSitDown::CasualSitDown(const CasualSitDown& orig) 
    :EatOut(orig)
{
    this->bestKnownFor = orig.bestKnownFor;
}

//destructor
CasualSitDown::~CasualSitDown() 
{
    
}

//assignment overload
const CasualSitDown& CasualSitDown::operator =(const CasualSitDown& rhs)
{
    //self assignment check
    if(&rhs == this) return *this;
    EatOut::operator=(rhs);
    this->bestKnownFor = rhs.bestKnownFor;
}

//setter member variables
void CasualSitDown::setBestKnownFor(string bestKnownFor)
{
    this->bestKnownFor = bestKnownFor;
}

//getter member functions
string CasualSitDown::getBestKnownFor()
{
    return bestKnownFor;
}

//output EatOut, Food, and CasualSitDown
void CasualSitDown::output()
{
    EatOut::output();
    cout<<"Best Known For: "<<bestKnownFor<<endl;
}