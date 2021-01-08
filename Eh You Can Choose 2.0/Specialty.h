/********************************************************************
 *                                                                  *
 *              DERIVED FROM EATOUT AND FOOD CLASS                  *   
 *                                                                  *    
 ********************************************************************/

/* 
 * File:   Specialty.h
 * Author: Heidi Dye
 *
 * Created on June 8, 2019, 10:20 AM
 */

#ifndef SPECIALTY_H
#define SPECIALTY_H
#include "EatOut.h"

using namespace std;

class Specialty : public EatOut 
{
public:
    //BIG FOUR
    Specialty();
    //constructor for just Specialty
    Specialty(string typeOfPlace);
    //constructor for Specialty and EatOut
    Specialty(string nameOfPlace, string typeOfExperience, string typeOfPlace);
    //constructor for Specialty, EatOut, and Food
    Specialty(string whatMeal, string typeOfFood, double averagePricePerPerson, string nameOfPlace, string typeOfExperience, string typeOfPlace);
    //copy constructor
    Specialty(const Specialty& orig);
    //destructor
    virtual ~Specialty();
    //assignment overload
    const Specialty& operator=(const Specialty&);
    
    //setter member functions
    void setTypeOfPlace(string typeOfPlace);
    
    //getter member functions
    string getTypeOfPlace();
    
    //output EatOut Specialty, and Food
    void output();

private:
    
    //is it an arcade type of place? Ice Cream Parlor? Cafe?
    string typeOfPlace;

};

#endif /* SPECIALTY_H */

