/********************************************************************
 *                                                                  *
 *              DERIVED FROM EATOUT AND FOOD CLASS                  *   
 *                                                                  *    
 ********************************************************************/

/* 
 * File:   FastFood.h
 * Author: Heidi2
 *
 * Created on June 7, 2019, 11:25 PM
 */

#ifndef FASTFOOD_H
#define FASTFOOD_H
#include "Food.h"
#include "EatOut.h"
#include <iostream>

using namespace std;

class FastFood : public EatOut 
{
public:
    //BIG FOUR
    //default constructor
    FastFood();
    //constructor for just FastFood
    FastFood(int numberOfMostPopularMenuItem);
    //constructor for FastFood and EatOut
    FastFood(string nameOfPlace, string typeOfExperience, int numberOfMostPopularMenuItems);
    //constructor for FastFood, EatOut, and Food
    FastFood(string whatMeal, string typeOfFood, double averagePricePerPerson, string nameOfPlace, string typeOfExperience, int numberOfMostPopularMenuItems);
    //copy constructor
    FastFood(const FastFood& orig);
    //destructor
    virtual ~FastFood();
    //assignment overload
    const FastFood& operator=(const FastFood&);
    
    //setter member functions
    //input one value at a time into the mostPopularMenuItems
    void setMenuItem(int index, string menuItem);
    void setNumberOfMostPopularMenuItems(int numberOfMostPopularMenuItems);
    
    //getter member functions
    //get one menu item
    string getMenuItem(int index);
    int getNumberOfMostPopularMenuItems();
    
    //output EatOut FastFood, and Food
    void output();
    
private:
    string* mostPopularMenuItems;
    int numberOfMostPopularMenuItems;
};

#endif /* FASTFOOD_H */

