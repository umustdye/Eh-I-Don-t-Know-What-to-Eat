/********************************************************************
 *                                                                  *
 *                   DERVIVED FROM FOOD CLASS                       *                                           
 *                                                                  *
 ********************************************************************/

/* 
 * File:   EatIn.cpp
 * Author: Heidi Dye
 * 
 * Created on June 8, 2019, 10:41 AM
 */

#include "EatIn.h"

//default constructor
EatIn::EatIn()
    :Food()
{
    levelOfDifficulty = "";
    timeOfCompletion = 0.0;
    linkToRecipe = "";
    nameOfDish = "";
    veganFriendly = "";
}

//constructor for just EatIn
EatIn::EatIn(string levelOfDifficulty, double timeOfCompletion, string linkToRecipe, string nameOfDish, string veganFriendly)
    :Food()
{
    this->levelOfDifficulty = levelOfDifficulty;
    this->timeOfCompletion = timeOfCompletion;
    this->linkToRecipe = linkToRecipe;
    this->nameOfDish = nameOfDish;
    this->veganFriendly = veganFriendly;
}

//default constructor for Food and EatIn
EatIn::EatIn(string whatMeal, string typeOfFood, double averagePricePerPerson, string levelOfDifficulty, double timeOfCompletion, string linkToRecipe, string nameOfDish, string veganFriendly)
    :Food(whatMeal, typeOfFood, averagePricePerPerson)
{
    this->levelOfDifficulty = levelOfDifficulty;
    this->timeOfCompletion = timeOfCompletion;
    this->linkToRecipe = linkToRecipe;
    this->nameOfDish = nameOfDish;
    this->veganFriendly = veganFriendly;
}

//copy constructor
EatIn::EatIn(const EatIn& orig)
    :Food(orig)
{
    this->levelOfDifficulty = orig.levelOfDifficulty;
    this->timeOfCompletion = orig.timeOfCompletion;
    this->linkToRecipe = orig.linkToRecipe;
    this->nameOfDish = orig.nameOfDish;
    this->veganFriendly = orig.veganFriendly;
}

//destructor
EatIn::~EatIn() 
{
    
}

//assignment overload
const EatIn& EatIn::operator=(const EatIn& rhs)
{
    //self assignment check
    if(&rhs == this) return *this;
    
    //copy over Food variables
    Food::operator=(rhs);
    
    //copy over EatIn variables
    this->levelOfDifficulty = rhs.levelOfDifficulty;
    this->timeOfCompletion = rhs.timeOfCompletion;
    this->linkToRecipe = rhs.linkToRecipe;
    this->nameOfDish = rhs.nameOfDish;
    this->veganFriendly = rhs.veganFriendly;
}

//setter member variables
void EatIn::setLevelOfDifficulty(string levelOfDifficulty)
{
    this->levelOfDifficulty = levelOfDifficulty;
}

void EatIn::setTimeOfCompletion(double timeOfCompletion)
{
    this->timeOfCompletion = timeOfCompletion;
}

void EatIn::setLinkToRecipe(string linkToRecipe)
{
    this->linkToRecipe = linkToRecipe;
}

void EatIn::setNameOfDish(string nameOfDish)
{
    this->nameOfDish = nameOfDish;
}

void EatIn::setVeganFriendly(string veganFriendly)
{
    this->veganFriendly = veganFriendly;
}

//getter member functions

string EatIn::getLevelOfDifficulty()
{
    return levelOfDifficulty;
}

double EatIn::getTimeOfCompletion()
{
    return timeOfCompletion;
}

string EatIn::getLinkToRecipe()
{
    return linkToRecipe;
}

string EatIn::getNameOfDish()
{
    return nameOfDish;
}

string EatIn::getVeganFriendly()
{
    return veganFriendly;
}

//output Food and EatIn
void EatIn::output()
{
    cout<<"Name of the Dish: "<<nameOfDish<<endl;
    cout<<"Level of Difficulty: "<<levelOfDifficulty<<endl;
    cout<<"Time of Completion: "<<timeOfCompletion<<"h"<<endl;
    Food::output();
    cout <<"Vegan Friendly: "<<veganFriendly<<endl;
    cout<<"Recipe Link: "<<linkToRecipe<<endl;
}