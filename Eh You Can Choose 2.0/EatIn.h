/********************************************************************
 *                                                                  *
 *                   DERVIVED FROM FOOD CLASS                       *                                           
 *                                                                  *
 ********************************************************************/

/* 
 * File:   EatIn.h
 * Author: Heidi Dye
 *
 * Created on June 8, 2019, 10:40 AM
 */

#ifndef EATIN_H
#define EATIN_H
#include "Food.h"

using namespace std;

class EatIn : public Food
{
public:
    //BIG FOUR
    //default constructor
    EatIn();
    //constructor for just EatIn
    EatIn(string levelOfDifficulty, double timeOfCompletion, string linkToRecipe, string nameOfDish, string veganFriendly);
    //constructor for EatIn and Food
    EatIn(string whatMeal, string typeOfFood, double averagePricePerPerson, string levelOfDifficulty, double timeOfCompletion, string linkToRecipe, string nameOfDish, string veganFriendly);
    //copy constructor
    EatIn(const EatIn& orig);
    //destructor
    virtual ~EatIn();
    //assignment overload
    const EatIn& operator=(const EatIn&);
    
    //setter member functions
    void setLevelOfDifficulty(string levelOfDifficulty);
    void setTimeOfCompletion(double timeOfCompletion);
    void setLinkToRecipe(string linkToRecipe);
    void setNameOfDish(string nameOfDish);
    void setVeganFriendly(string veganFriendly);
    
    //getter member functions
    string getLevelOfDifficulty();
    double getTimeOfCompletion();
    string getLinkToRecipe();
    string getNameOfDish();
    string getVeganFriendly();
    
    //output Food and EatIn
    void output();
private:
    //beginner, intermediate, or advanced
    string levelOfDifficulty;
    //how long it takes to prepare and cook
    double timeOfCompletion;
    //literally a site link to find the recipe and instructions
    string linkToRecipe;
    //what is the dish called, French Toast for example
    string nameOfDish;
    //holds yes or no if the dish is vegan friendly
    string veganFriendly;
            
};

#endif /* EATIN_H */

