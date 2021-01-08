/********************************************************************
 *                                                                  *
 *                 PARENT CLASS FOR EATIN AND EATOUT                *
 *                                                                  *    
 ********************************************************************/

/* 
 * File:   Food.h
 * Author: Heidi2
 *
 * Created on June 7, 2019, 8:43 PM
 */

#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <iomanip>

using namespace std;

class Food {
public:
    //THE BIG FOUR
    //default constructor
    Food();
    //constructor
    Food(string whatMeal, string typeOfFood, double averagePricePerPerson);
    //copy constructor
    Food(const Food& orig);
    //destructor
    virtual ~Food();
    //assignment overload
    const Food& operator=(const Food& rhs);
    
    //setters
    void setWhatMeal(string whatMeal);
    void setTypeOfFood(string TypeOfFood);
    void setAveragePricePerPerson(double averagePricePerPerson);
    
    //getters
    string getWhatMeal();
    string getTypeOfFood();
    double getAveragePricePerPerson();
    
    //output the whatMeal, typeOfFood, and averagePricePerPerson
    void output();
    
private:
    //is it dinner and lunch, breakfast, or dessert
    string whatMeal;
    //is it Italian, Mexican, Pizzeria, etc
    string typeOfFood;
    //how much does it cost per person
    double averagePricePerPerson;

};

#endif /* FOOD_H */

