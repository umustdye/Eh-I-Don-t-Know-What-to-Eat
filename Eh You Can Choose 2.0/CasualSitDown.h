/********************************************************************
 *                                                                  *
 *              DERIVED FROM EATOUT AND FOOD CLASS                  *   
 *                                                                  *    
 ********************************************************************/

/* 
 * File:   CasualSitDown.h
 * Author: Heidi2
 *
 * Created on June 8, 2019, 12:33 AM
 */

#ifndef CASUALSITDOWN_H
#define CASUALSITDOWN_H
#include "EatOut.h"
#include "Food.h"

using namespace std;

class CasualSitDown : public EatOut 
{
public:
    //THE BIG FOUR
    //default constructor
    CasualSitDown();
    //constructor for just CasualSitDown
    CasualSitDown(string bestKnownFor);
    //constructor for CasualSitDown and EatOut
    CasualSitDown(string nameOfPlace, string typeOfExperience, string bestKnownFor);
    //constructor for CasualSitDown, EatOut, and Food
    CasualSitDown(string whatMeal, string typeOfFood, double averagePricePerPerson, string nameOfPlace, string typeOfExperience, string bestKnownFor);
    //copy constructor
    CasualSitDown(const CasualSitDown& orig);
    //destructor
    virtual ~CasualSitDown();
    //assignment overload
    const CasualSitDown& operator=(const CasualSitDown&);
    
    //setter member functions
    void setBestKnownFor(string bestKnownFor);
    
    //getter member functions
    string getBestKnownFor();
    
    //output EatOut CasualSitDown, and Food
    void output();
private:
    //number one popular menu item, their speciality
    string bestKnownFor;
};

#endif /* CASUALSITDOWN_H */

