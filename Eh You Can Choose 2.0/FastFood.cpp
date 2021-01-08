/********************************************************************
 *                                                                  *
 *              DERIVED FROM EATOUT AND FOOD CLASS                  *   
 *                                                                  *    
 ********************************************************************/

/* 
 * File:   FastFood.cpp
 * Author: Heidi2
 * 
 * Created on June 7, 2019, 11:25 PM
 */

#include "FastFood.h"

//default constructor
FastFood::FastFood()
        :EatOut()
{
    int numberOfMostPopularMenuItems = 0;
    mostPopularMenuItems = new string[numberOfMostPopularMenuItems];
}

//constructor for just FastFood
FastFood::FastFood(int numberOfMostPopularMenuItem)
    :EatOut()
{
    this->numberOfMostPopularMenuItems = numberOfMostPopularMenuItems;
    this->mostPopularMenuItems = new string[numberOfMostPopularMenuItems];
}

//constructor for EatOut and FastFood
FastFood::FastFood(string nameOfPlace, string typeOfExperience, int numberOfMostPopularMenuItems)
    :EatOut(nameOfPlace, typeOfExperience)
{
    this->numberOfMostPopularMenuItems = numberOfMostPopularMenuItems;
    this->mostPopularMenuItems = new string[numberOfMostPopularMenuItems];
}

//constructor for Food, EatOut, and FastFood
FastFood::FastFood(string whatMeal, string typeOfFood, double averagePricePerPerson, string nameOfPlace, string typeOfExperience, int numberOfMostPopularMenuItems)
    :EatOut(whatMeal, typeOfFood, averagePricePerPerson, nameOfPlace, typeOfExperience)
{
    this->numberOfMostPopularMenuItems = numberOfMostPopularMenuItems;
    this->mostPopularMenuItems = new string[numberOfMostPopularMenuItems];
}

//copy Constructor
FastFood::FastFood(const FastFood& orig) 
    :EatOut(orig)
{
    this->numberOfMostPopularMenuItems = orig.numberOfMostPopularMenuItems;
    this->mostPopularMenuItems = new string[numberOfMostPopularMenuItems];
    //deep copy
    for(int i = 0; i<orig.numberOfMostPopularMenuItems; i++)
    {
        this->mostPopularMenuItems[i] = orig.mostPopularMenuItems[i];
    }
}

//destructor
FastFood::~FastFood() 
{
    delete[]this->mostPopularMenuItems;
    this->mostPopularMenuItems = NULL;
}

//Assignment Overload
const FastFood& FastFood::operator=(const FastFood& rhs)
{
    //self check
    if(&rhs == this) return *this;
    
    //copy over everything from EatOut
    EatOut::operator=(rhs);
    
    //delete any dynamic data
    delete[]this->mostPopularMenuItems;
    mostPopularMenuItems =NULL;
    
    //copy over values
    this->numberOfMostPopularMenuItems = rhs.numberOfMostPopularMenuItems;
    this->mostPopularMenuItems = new string[rhs.numberOfMostPopularMenuItems];
    
    //deep copy
    for(int i=0; i<rhs.numberOfMostPopularMenuItems; i++)
    {
        this->mostPopularMenuItems[i] = rhs.mostPopularMenuItems[i];
    }
    
    return *this;
}

//setter member functions
void FastFood::setMenuItem(int index, string menuItem)
{
    this->mostPopularMenuItems[index] = menuItem;
}

void FastFood::setNumberOfMostPopularMenuItems(int numberOfMostPopularMenuItems)
{
    this->numberOfMostPopularMenuItems = numberOfMostPopularMenuItems;
}

//getter member variables
string FastFood::getMenuItem(int index)
{
    return mostPopularMenuItems[index];
}

int FastFood::getNumberOfMostPopularMenuItems()
{
    return numberOfMostPopularMenuItems;
}

//output EatOut, Food, and FastFood
void FastFood::output()
{
    EatOut::output();
    cout<<"Most Popular Menu Items: "<<endl;
    //output all the mostPopularMenuItems
    for(int i = 0; i<numberOfMostPopularMenuItems; i++)
    {
        cout<<" "<<mostPopularMenuItems[i]<<endl;
    }
}