/****************************************************************************
 *                                                                          *
 *      THIS CLASS DETERMINES WHICH FILE TO USE FOR THE DESIRED OPTION      *  
 *                                                                          *
 ****************************************************************************/

/* 
 * File:   RubixCube.cpp
 * Author: Heidi Dye
 * 
 * Created on June 8, 2019, 12:10 PM
 */

#include "RubixCube.h"

//default constructor
//set all the values as false
RubixCube::RubixCube() 
{
    breakfast = false;
    dinnerOrLunch = false;
    dessert = false;
    eatIn = false;
    eatOut = false;
    casualSitDown = false;
    specialty = false;
    fastFood = false;
    intermediate = false;
    expert = false;
    beginner = false;
    whichFileReader = 0;
    whichPlaceToEatAt = 0;
}

//copy constructor
RubixCube::RubixCube(const RubixCube& orig) 
{
    this->breakfast = orig.breakfast;
    this->dinnerOrLunch = orig.dinnerOrLunch;
    this->dessert = orig.dessert;
    this->eatIn = orig.eatIn;
    this->eatOut = orig.eatOut;
    this->casualSitDown = orig.casualSitDown;
    this->specialty = orig.specialty;
    this->fastFood = orig.fastFood;
    this->intermediate = orig.intermediate;
    this->expert = orig.expert;
    this->beginner = orig.beginner;
    this->whichFileReader = orig.whichFileReader;
    this->whichPlaceToEatAt = orig.whichPlaceToEatAt;
}

//destructor
RubixCube::~RubixCube() 
{
    
}

//assignment overload
const RubixCube& RubixCube::operator =(const RubixCube& rhs)
{
    //self assignment check
    if(&rhs == this) return *this;
    this->breakfast = rhs.breakfast;
    this->dinnerOrLunch = rhs.dinnerOrLunch;
    this->dessert = rhs.dessert;
    this->eatIn = rhs.eatIn;
    this->eatOut = rhs.eatOut;
    this->casualSitDown = rhs.casualSitDown;
    this->specialty = rhs.specialty;
    this->fastFood = rhs.fastFood;
    this->intermediate = rhs.intermediate;
    this->expert = rhs.expert;
    this->beginner = rhs.beginner;
    this->whichFileReader = rhs.whichFileReader;
    this->whichPlaceToEatAt = rhs.whichPlaceToEatAt;
    
    return *this;
}

//setters
void RubixCube::setBreakfast()
{
    breakfast = true;
}

void RubixCube::setDinnerOrLunch()
{
    dinnerOrLunch = true;
}

void RubixCube::setDessert()
{
    dessert = true;
}

void RubixCube::setEatIn()
{
    eatIn = true;
}

void RubixCube::setEatOut()
{
    eatOut = true;
}

void RubixCube::setCasualSitDown()
{
    casualSitDown = true;
}

void RubixCube::setSpecialty()
{
    specialty = true;
}

void RubixCube::setFastFood()
{
    fastFood = true;
}

void RubixCube::setIntermediate()
{
    intermediate = true;
}

void RubixCube::setExpert()
{
    expert = true;
}

void RubixCube::setBeginner()
{
    beginner = true;
}

void RubixCube::setWhichFileReader(int val)
{
    whichFileReader = val;
}

void RubixCube::setWhichPlaceToEatAt(int val)
{
    whichPlaceToEatAt = val;
}

void RubixCube::setFileName(string fileName)
{
    this->fileName = fileName;
}


//getter member functions
bool RubixCube::getBreakfast()
{
    return breakfast;
}

bool RubixCube::getDinnerOrLunch()
{
    return dinnerOrLunch;
}

bool RubixCube::getDessert()
{
    return dessert;
}

bool RubixCube::getEatIn()
{
    return eatIn;
}

bool RubixCube::getEatOut()
{
    return eatOut;
}

bool RubixCube::getCasualSitDown()
{
    return casualSitDown;
}

bool RubixCube::getSpecialty()
{
    return specialty;
}

bool RubixCube::getFastFood()
{
    return fastFood;
}

bool RubixCube::getIntermediate()
{
    return intermediate;
}

bool RubixCube::getExpert()
{
    return expert;
}

bool RubixCube::getBeginner()
{
    return beginner;
}

int RubixCube::getWhichFileReader()
{
    return whichFileReader;
}

int RubixCube::getWhichPlaceToEatAt()
{
    return whichPlaceToEatAt;
}

string RubixCube::getFileName()
{
    return fileName;
}

//use the appropriate bool values to get the appropriate fileName
void RubixCube::findWhereToEat()
{
    if(eatOut == true)
    {
        RubixCube::setWhichFileReader(1);
        findTypeOfPlace();
    }
    
    if(eatIn == true)
    {
        RubixCube::setWhichFileReader(0);
        findDifficulty();
    }
} 

void RubixCube::findDifficulty()
{
    //beginner level recipes
    if (breakfast == true && beginner == true)
    {
        RubixCube::setFileName("BeginningBreakFast.txt");
    }
    
    if (dinnerOrLunch == true && beginner == true)
    {
        RubixCube::setFileName("BeginningDinner.txt");
    }
    
    if (dessert == true && beginner == true)
    {
        RubixCube::setFileName("BeginningDessert.txt");
    }
    
    //intermediate level recipes
    if (breakfast == true && intermediate == true)
    {
        RubixCube::setFileName("IntermediateBreakfast.txt");
    }
    
    if (dinnerOrLunch == true && intermediate == true)
    {
        RubixCube::setFileName("IntermediateDinner.txt");
    }
    
    if (dessert == true && intermediate == true)
    {
        RubixCube::setFileName("IntermediateDessert.txt");
    }
    
    //expert level Recipes
    if (breakfast == true && expert == true)
    {
        RubixCube::setFileName("ExpertBreakFast.txt");
    }
    
    if (dinnerOrLunch == true && expert == true)
    {
        RubixCube::setFileName("ExpertDinner.txt");
    }
    
    if (dessert == true && expert == true)
    {
        RubixCube::setFileName("ExpertDessert.txt");
    }
}

void RubixCube::findTypeOfPlace()
{
    //fastfood
    if (fastFood == true && breakfast == true)
    {
        RubixCube::setWhichPlaceToEatAt(0);
        RubixCube::setFileName("FastFoodBreakFast.txt");
        
    }
    
    if (fastFood == true && dinnerOrLunch == true)
    {
        RubixCube::setWhichPlaceToEatAt(0);
        RubixCube::setFileName("FastFoodDinner.txt");
    }
    
    if(fastFood == true && dessert == true)
    {
        RubixCube::setWhichPlaceToEatAt(0);
        RubixCube::setFileName("FastFoodDessert.txt");
    }
    
    //CASUALSITDOWN
    if (casualSitDown == true && breakfast == true)
    {
        RubixCube::setWhichPlaceToEatAt(1);
        RubixCube::setFileName("CasualSitDownBreakfast.txt");
    }
    
    if (casualSitDown == true && dinnerOrLunch == true)
    {
        RubixCube::setWhichPlaceToEatAt(1);
        RubixCube::setFileName("CasualSitDownDinner.txt");
    }
    
    if(casualSitDown == true && dessert == true)
    {
        RubixCube::setWhichPlaceToEatAt(1);
        RubixCube::setFileName("CasualSitDownDessert.txt");
    }
    
    //Specialty
    if (specialty == true && breakfast == true)
    {
        RubixCube::setWhichPlaceToEatAt(2);
        RubixCube::setFileName("SpecialtyBreakfast.txt");
    }
    
    if (specialty == true && dinnerOrLunch == true)
    {
        RubixCube::setWhichPlaceToEatAt(2);
        RubixCube::setFileName("SpecialtyDinner.txt");
    }
    
    if(specialty == true && dessert == true)
    {
        RubixCube::setWhichPlaceToEatAt(2);
        RubixCube::setFileName("SpecialtyDessert.txt");
    }
}