/****************************************************************************
 *                                                                          *
 *      THIS CLASS DETERMINES WHICH FILE TO USE FOR THE DESIRED OPTION      *  
 *                                                                          *
 ****************************************************************************/

/* 
 * File:   RubixCube.h
 * Author: Heidi Dye
 *
 * Created on June 8, 2019, 12:10 PM
 */

#ifndef RUBIXCUBE_H
#define RUBIXCUBE_H
#include <string>

using namespace std;

class RubixCube {
public:
    //THE BIG FOUR
    //constructor
    RubixCube();
    //copy constructor
    RubixCube(const RubixCube& orig);
    //destructor
    virtual ~RubixCube();
    //assignment overload
    const RubixCube& operator=(const RubixCube&);
    
    //setters....prepare yourself...okay
    //assigns the variables as true if needed
    void setBreakfast();
    void setDinnerOrLunch();
    void setDessert();
    void setEatIn();
    void setEatOut();
    void setCasualSitDown();
    void setSpecialty();
    void setFastFood();
    void setIntermediate();
    void setExpert();
    void setBeginner();
    void setWhichFileReader(int val);
    void setWhichPlaceToEatAt(int val);
    void setFileName(string fileName);
    
    //getter member functions
    bool getBreakfast();
    bool getDinnerOrLunch();
    bool getDessert();
    bool getEatIn();
    bool getEatOut();
    bool getCasualSitDown();
    bool getSpecialty();
    bool getFastFood();
    bool getIntermediate();
    bool getExpert();
    bool getBeginner();
    int getWhichFileReader();
    int getWhichPlaceToEatAt();
    string getFileName();

    
    //Swissarmy knife functions help to find the appropriate files
    //based on which member variables are true
    //eatIn or eatOut
    void findWhereToEat();
    //ONLY FOR EATIN
    //difficulty level: beginner, intermediate, or expert
    //returns the name of the file
    void findDifficulty();
    //ONLY FOR EATOUT
    //which type of place does the user want to eat
    //returns the name of the file
    void findTypeOfPlace();
    
private:
    //for type of meal
    bool breakfast;
    bool dinnerOrLunch;
    bool dessert;
    //for if the user wants to eat somewhere or make something to eat at home
    bool eatIn;
    bool eatOut;
    //eatOut options
    //eat at like a casual restaurant or diner
    bool casualSitDown;
    //places like Chuck E Cheeses or Medieval Times
    bool specialty;
    //McDonald's or like KFC
    bool fastFood;
    //eatIn options
    //difficulty levels
    bool intermediate;
    bool expert;
    bool beginner;
    //sets in findWhereToEat() 
    //0 == EatIn and 1==EatOut
    int whichFileReader;
    //sets in eatOut
    //0==FastFood, 1==CasualSitDown, 2==Specialty
    int whichPlaceToEatAt;
    string fileName;

};

#endif /* RUBIXCUBE_H */

