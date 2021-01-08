

/* 
 * File:   Final Project 17a version 2.cpp
 * Author: Heidi Dye
 *
 * Created on June 7, 2019, 8:28 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include "Food.h"
#include "EatOut.h"
#include "FastFood.h"
#include "CasualSitDown.h"
#include "Specialty.h"
#include "EatIn.h"
#include "RubixCube.h"
#include "StaticQueue.h"


using namespace std;


//function declarations
//read in the various EatOut file
//if fileToRead = 1
void fileReaderEatOut(string fileName, int option);

//output a random fastFood item and continue if the user is not happy
void fastFood(string fileName);

//output a random casualSitDownItem and continue if the user is not happy
void casualSitDown(string fileName);

//output a random specialty item and continue if the user is not happy
void specialty(string fileName);

//read in various EatIn file
//if fileToRead = 0
void fileReaderEatIn(string fileName);

//prepare a an array with incremented values
void numArray(int size, int*);
//return this to the queue
void randNumArray(int size, int*);

//main menu
void customerService();

//get answers for what the user wants and set them in the RubixCube
void swissArmyKnife();

//if the user wants to choose another option from the menu
bool reanimator();

//error checking for integers
void kittyCatProof(int);

//range checking for numerical values
void rangeCheck(int, int, int);
/*
 * RubixCube:find appropriate values from classes and write to static queue
 * class Food, EatOut(FastFood, CausualSitDown, WineAndDine), 
 * EatIn(DinnerOrLunch, Breakfast, Dessert)
 * have a random chooser just in case the user can't decide 
 */
int main(int argc, char** argv) 
{

    //go to the menu for the first time 
    customerService();
    //continues to go to the menu until the user doesn't want to anymore
    while (reanimator())
    {
        customerService();
    }
    //exits the program once done 
    cout << "Thank you for using the Eh... You Choose Program. Goodbye\n"<<endl;
    return 0;
}

//main menu
void customerService()
{
    cout<<" Welcome to the Eh... I Don't Know What to Eat Program!"<<endl;
    cout<<"--------------------------------------------------------\n"<<endl;
    cout<<"Please choose the number corresponding to the desired option from the following prompts..."<<endl;
    swissArmyKnife();
}

bool reanimator ()
{
    char choice, Y,y;
    cout << "Would you like to select another option from the main menu?\n";
    cout<< "PRESS Y TO CONTINUE, OR ANY OTHER KEY TO QUIT\n";
    cin>> choice; 
    if( choice == 'y' || choice == 'Y') return true; //go back to the main menu
    else return false; //exit the menu option  
}

void swissArmyKnife()
{
    //make an instance of the RubixCube class to set the appropriate values
    RubixCube rubixCube;
    int option = 0;
    //range checking purposes
    int min = 1;
    int max = 3;
    
    //get the value for the type of meal
    cout<<"Which Meal Time: (select 1, 2, or 3)"<<endl;
    cout<<"1.) Breakfast ~"<<endl;
    cout<<"2.) Dinner/Lunch ~"<<endl;
    cout<<"3.) Dessert ~"<<endl;
    cin>>option;
    //check to see if the option is a numerical value
    kittyCatProof(option);
    //check to see if the option is in range
    rangeCheck(min, max, option);
    if(option == 1)
    {
        rubixCube.setBreakfast();
    }
    if(option == 2)
    {
        rubixCube.setDinnerOrLunch();
    }
    if(option == 3)
    {
        rubixCube.setDessert();
    }
    
    //reset the value of option just in case
    option = 0;
    min = 1;
    max = 2;
    //set the value for if the user wants to go somewhere to eat or make something at home
    cout<<"How do you wish to obtain your meal: (enter 1 or 2)"<<endl;
    cout<<"1.) Go somewhere to eat ~"<<endl;
    cout<<"2.) Make something to eat at home ~"<<endl;
    cin>>option;    
    //check to see if the option is a numerical value
    kittyCatProof(option);
    //check to see if the option is in range
    rangeCheck(min, max, option);
    
    if(option == 1)
    {
        rubixCube.setEatOut();
        
        //reset the value of option
        option = 0;
        min = 1;
        max = 3;
        //see what type of place the user wants to get their food from
        cout<<"What type of place would like to get your food from: (enter 1, 2, or three)"<<endl;
        cout<<"1.) Fast Food ~"<<endl;
        cout<<"2.) Casual Sit Down (A diner for example) ~"<<endl;
        cout<<"3.) Specialty (dinner theater show for example) ~"<<endl;
        cin>>option;    
        //check to see if the option is a numerical value
        kittyCatProof(option);
        //check to see if the option is in range
        rangeCheck(min, max, option);
        if(option == 1)
        {
            rubixCube.setFastFood();
        }
        if(option == 2)
        {
            rubixCube.setCasualSitDown();
        }
        if(option == 3)
        {
            rubixCube.setSpecialty();
        }
        
        //reset the value of option
        option = 0;
    }
    if(option == 2)
    {
        rubixCube.setEatIn();
        //reset the value for option
        option = 0;
        min = 1;
        max = 3;
        //get the difficulty level from the user
        cout<<"What difficulty level do you prefer to cook at: (Enter 1, 2, or 3)"<<endl;
        cout<<"1.) Beginner ~"<<endl;
        cout<<"2.) Intermediate ~"<<endl;
        cout<<"3.) Expert ~"<<endl;
        cin>>option;
        //check to see if the option is a numerical value
        kittyCatProof(option);
        //check to see if the option is in range
        rangeCheck(min, max, option);
        if(option == 1)
        {
            rubixCube.setBeginner();
        }
        if(option == 2)
        {
            rubixCube.setIntermediate();
        }
        if(option == 3)
        {
            rubixCube.setExpert();
        }
    }
    
    //USE THE RUBIX CUBE TO FIND THE APPROPRIATE FILE NAME
    rubixCube.findWhereToEat();
    
    //save the file name to a string
    string fileName = rubixCube.getFileName();
    
    //determine which file reader to go to
    if(rubixCube.getWhichFileReader() == 0)
    {
        fileReaderEatIn(fileName);
    }
    
    if(rubixCube.getWhichFileReader() == 1)
    {
        int placeToEatAt = rubixCube.getWhichPlaceToEatAt();
        fileReaderEatOut(fileName, placeToEatAt);
    }
    
    
            
}

void kittyCatProof(int input)
{
    bool valid;
    valid = input;
        if (!valid)
        {
            cin.clear ();
            cin.ignore (10000, '\n');
            cout<< "Sorry, invalid input. Please try again and enter a numerical value\n";
            exit(1); 
        }
}

void rangeCheck(int min, int max, int option)
{
    bool valid = true;
    
    if(option<min || option>max)
    {
        valid = false;
    }
    if(valid == false)
    {
        cout<<"Sorry, input is not in range. Please try again and enter a value that is between "<<min<<" and "<<max<<endl;
        exit(1);
    }
    
}

void fileReaderEatOut(string fileName, int option)
{
    ifstream inFile;
    inFile.open(fileName.c_str());
    int howManyOptions = 0;
    if(inFile)
    {
        //so that the program knows how big to make the EatIn class array
        inFile >> howManyOptions;
        //for numerical values 
        string blankLine;
        std::getline(inFile, blankLine);
        //make an array of objects
        CasualSitDown casualSitDown[howManyOptions];
        //dummy values for reading in
        string whatMeal;
        string typeOfFood;
        double averagePricePerPerson;
        string nameOfPlace;
        string typeOfExperience;
        string bestKnownFor;
        
        //set in the values into the array one element at a time
        for(int i = 0; i<howManyOptions; i++)
        {
            std::getline(inFile, whatMeal);
            casualSitDown[i].setWhatMeal(whatMeal);
            std::getline(inFile, typeOfFood);
            casualSitDown[i].setTypeOfFood(typeOfFood);
            inFile >> averagePricePerPerson;
            casualSitDown[i].setAveragePricePerPerson(averagePricePerPerson);
            std::getline(inFile, blankLine);
            std::getline(inFile, nameOfPlace);
            casualSitDown[i].setNameOfPlace(nameOfPlace);
            std::getline(inFile, typeOfExperience);
            casualSitDown[i].setTypeOfExperience(typeOfExperience);
            std::getline(inFile, bestKnownFor);
            casualSitDown[i].setBestKnownFor(bestKnownFor);
            
        }
        
        //make an array of incremented values
        int* valueArray = new int[howManyOptions];
        //fill the array with incremented values 
        numArray(howManyOptions, valueArray);
        //randomize the order
        randNumArray(howManyOptions, valueArray);
        //Static Queue
        StaticQueue queue(howManyOptions);
       
        //copy over the values from the valueArray
        for(int i=0; i<howManyOptions; i++)
        {
            queue.enqueue(valueArray[i]);
        }

        //list off options until the user is happy
        bool happy = false;
        //to see if the user is with their option happy
        int answer = 0;
        //for error checking
        int min = 1;
        int max = 2;
        int index = 0;
        while(!happy)
        {
            //casualSitDown[queue.valueAt(index)].output();
            casualSitDown[queue[index]].output();
            queue.dequeue();
            cout<<"Are you happy with this choice: (Enter 1 or 2)"<<endl;
            cout<<"1.) Yes ~"<<endl;
            cout<<"2.) No ~"<<endl;
            cin >>answer;
            //check if a numerical value
            kittyCatProof(answer);
            //check if it is in range
            rangeCheck(min, max, answer);
            //if the user is happy
            if(answer == 1)
            {
                happy = true;
            }
            if(queue.dequeue() == -1)
            {
                cout<<"You are out of options my friend..."<<endl;
                happy = true;
            }
            index++;
                    
        }
        

        //delete dynamic data
        delete[]valueArray;
        valueArray = NULL;
        //close the file
        inFile.close();
        cout << "Read the File: "<<fileName<<endl;
        
    }
    
    else
    {
        cout<<"Could not Read "<<fileName<<endl;
        exit(1);
    }
}



void fileReaderEatIn(string fileName)
{
    ifstream inFile;
    inFile.open(fileName.c_str());
    int howManyOptions = 0;
    if(inFile)
    {
        //so that the program knows how big to make the EatIn class array
        inFile >> howManyOptions;
        //for numerical values 
        string blankLine;
        std::getline(inFile, blankLine);
        //make an array of objects
        EatIn eatIn[howManyOptions];
        //dummy values for reading in
        string whatMeal;
        string typeOfFood;
        double averagePricePerPerson;
        string levelOfDifficulty;
        double timeOfCompletion;
        string linkToRecipe;
        string nameOfDish;
        string veganFriendly;
        
        //set in the values into the array one element at a time
        for(int i = 0; i<howManyOptions; i++)
        {
            std::getline(inFile, whatMeal);
            eatIn[i].setWhatMeal(whatMeal);
            std::getline(inFile, typeOfFood);
            eatIn[i].setTypeOfFood(typeOfFood);
            inFile >> averagePricePerPerson;
            eatIn[i].setAveragePricePerPerson(averagePricePerPerson);
            std::getline(inFile, blankLine);
            std::getline(inFile, levelOfDifficulty);
            eatIn[i].setLevelOfDifficulty(levelOfDifficulty);
            inFile >> timeOfCompletion;
            eatIn[i].setTimeOfCompletion(timeOfCompletion);
            std::getline(inFile, blankLine);
            std::getline(inFile, linkToRecipe);
            eatIn[i].setLinkToRecipe(linkToRecipe);
            std::getline(inFile, nameOfDish);
            eatIn[i].setNameOfDish(nameOfDish);
            std::getline(inFile, veganFriendly);
            eatIn[i].setVeganFriendly(veganFriendly);
            
        }
        
        //make an array of incremented values
        int* valueArray = new int[howManyOptions];
        //fill the array with incremented values 
        numArray(howManyOptions, valueArray);
        //randomize the order
        randNumArray(howManyOptions, valueArray);
        //Static Queue
        StaticQueue queue(howManyOptions);
        //copy over the values from the valueArray
        for(int i=0; i<howManyOptions; i++)
        {
            queue.enqueue(valueArray[i]);
        }

        //list off options until the user is happy
        bool happy = false;
        //to see if the user is with their option happy
        int answer = 0;
        //for error checking
        int min = 1;
        int max = 2;
        int index = 0;
        while(!happy)
        {
            //eatIn[queue.valueAt(index)].output();
            eatIn[queue[index]].output();
            queue.dequeue();
            cout<<"Are you happy with this choice: (Enter 1 or 2)"<<endl;
            cout<<"1.) Yes ~"<<endl;
            cout<<"2.) No ~"<<endl;
            cin >>answer;
            //check if a numerical value
            kittyCatProof(answer);
            //check if it is in range
            rangeCheck(min, max, answer);
            //if the user is happy
            if(answer == 1)
            {
                happy = true;
            }
            if(queue.dequeue() == -1)
            {
                cout<<"You are out of options my friend..."<<endl;
                happy = true;
            }
            index++;
                    
        }
        

        //delete dynamic data
        delete[]valueArray;
        valueArray = NULL;
        //close the file
        inFile.close();
        cout << "Read the File: "<<fileName<<endl;
        
    }
    
    else
    {
        cout<<"Could not Read "<<fileName<<endl;
        exit(1);
    }
}

void numArray(int size, int* valueArray)
{
    for(int i = 0; i<size; i++)
    {
        valueArray[i] = i;
    }
}

void randNumArray(int size, int* valueArray)
{
    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Shuffle elements by randomly exchanging each with one other.
    for (int i=0; i<size; i++) 
    {
        //get a random index
        int r = rand() % size;
        int temp = valueArray[i]; 
        valueArray[i] = valueArray[r]; 
        valueArray[r] = temp;
    }    
}