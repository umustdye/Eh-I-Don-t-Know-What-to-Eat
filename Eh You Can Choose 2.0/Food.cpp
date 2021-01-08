/********************************************************************
 *                                                                  *
 *                 PARENT CLASS FOR EATIN AND EATOUT                *
 *                                                                  *    
 ********************************************************************/

/* 
 * File:   Food.cpp
 * Author: Heidi Dye
 * 
 * Created on June 7, 2019, 8:43 PM
 */

#include "Food.h"

//default constructor
Food::Food() 
{
    whatMeal = "";
    typeOfFood = "";
    averagePricePerPerson = 0.0;
}

//constructor
Food::Food(string whatMeal, string typeOfFood, double averagePricePerPerson)
{
    this->whatMeal = whatMeal;
    this->typeOfFood = typeOfFood;
    this->averagePricePerPerson = averagePricePerPerson;
}

//copy constructor
Food::Food(const Food& orig) 
{
    this->whatMeal = orig.whatMeal;
    this->typeOfFood = orig.typeOfFood;
    this->averagePricePerPerson = orig.averagePricePerPerson;
}

//destructor
Food::~Food() 
{
    
}

//assignment overload
const Food& Food::operator=(const Food& rhs)
{
    //self assignment check
    if(&rhs == this)return *this;
    
    //copy over variables...Meh
    this->whatMeal = rhs.whatMeal;
    this->typeOfFood = rhs.typeOfFood;
    this->averagePricePerPerson = rhs.averagePricePerPerson;
}

//setter member functions
void Food::setWhatMeal(string whatMeal)
{
    this->whatMeal = whatMeal;
}

void Food::setTypeOfFood(string typeOfFood)
{
    this->typeOfFood = typeOfFood;
}

void Food::setAveragePricePerPerson(double averagePricePerPerson)
{
    this->averagePricePerPerson = averagePricePerPerson;
}

//getter member functions
string Food::getWhatMeal()
{
    return whatMeal;
}

string Food::getTypeOfFood()
{
    return typeOfFood;
}

double Food::getAveragePricePerPerson()
{
    return averagePricePerPerson;
}

//output the whatMeal, typeOfFood, and averagePricePerPerson
void Food::output()
{
    cout<<"Meal Type: "<<whatMeal<<endl;
    cout<<"Type of Cuisine: "<<typeOfFood<<endl;
    cout<<"Average Price Per Person: $"<<fixed<<setprecision(2)<<averagePricePerPerson<<endl;
}