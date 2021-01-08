/********************************************************************
 *                                                                  *
 *                   DERVIVED FROM FOOD CLASS                       *
 *        PARENT CLASS TO FASTFOOD, CASUAL, AND SPECIALTY           *                                            
 *                                                                  *
 ********************************************************************/

/* 
 * File:   EatOut.h
 * Author: Heidi2
 *
 * Created on June 7, 2019, 10:22 PM
 */

#ifndef EATOUT_H
#define EATOUT_H
#include <iostream>
#include "Food.h"

using namespace std;

class EatOut : public Food 
{
public:
    //THE BIG FOUR
    //default constructor
    EatOut();
    //constructor for just EatOut
    EatOut(string nameOfPlace, string typeOfExperience);
    //constructor for both EatOutand Food
    EatOut(string whatMeal, string typeOfFood, double averagePricePerPerson, string nameOfPlace, string typeOfExperience);
    //copy constructor
    EatOut(const EatOut& orig);
    //destructor
    virtual ~EatOut();
    //assignment overload
    const EatOut& operator=(const EatOut&);
    
    //setter member functions
    void setNameOfPlace(string nameOfPlace);
    void setTypeOfExperience(string typeOfExperience);
    
    //getter member functions
    string getNameOfPlace();
    string getTypeOfExperience();
    
    //output
    void output();
    
private:
    //name of the place to eat at
    string nameOfPlace;
    //is it a casual sit down, fast food, or specialty
    string typeOfExperience;

};

#endif /* EATOUT_H */

