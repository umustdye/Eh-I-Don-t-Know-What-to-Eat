/* 
 * File:   Eh... You Choose.cpp
 * Author: Heidi Dye
 *
 * Created on May 10, 2019, 6:54 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>

using namespace std;

//classes
class Chooser
{
private:
    //holds the size of the array
    int optionNumber;
    //array of options
    string* optionList;
    //holds the index where the random option is chosen
    int randomIndex;
    string fileName;
    string filePurpose;
    
public:
    //default constructor
    Chooser();
    //constructor
    Chooser(int optionNumber, string* optionList);
    //destructor
    ~Chooser();
    //copy constructor
    Chooser(const Chooser&);
    //assignment overload
    Chooser operator=(const Chooser&);
    //choose a random number
    string randomOption();
    //delete a choice if the girlfriend says no
    void deleteOption();
    //getter functions
    int getRandomIndex();
    int getOptionNumber();
    void editDelete(int indexForDeleting);
    void editAdd(string newOption);
    void writeToFile();
    void writeToFile2();
    //setters
    void setFileName(string filename);
    void setFilePurpose(string filePurpose);
      
};

//functions
int mainPrompt();  //for the menu
bool reanimator(); //for the menu
void option_1(); //if the user wants to save their options (restaurant names for example)
void option_2(); //choose a random option from a preexisting file
void option_3(); //if the user wants to add a new restaurant option for example
void option_4(); //if the user wants to delete a restaurant option for example
void kittyCatProof(int); //to make sure the user entered an integer value;

int main(int argc, char** argv) {

   //go to the menu for the first time 
    mainPrompt();
    //continues to go to the menu until the user doesn't want to anymore
    while (reanimator ())
    {
        mainPrompt();
    }
    //exits the program once done
    cout << "Thank you for using the Eh... You Choose Program. Goodbye\n";
    return 0;
}

int mainPrompt()
{
    int option=0;
    
    cout << "Welcome to the Eh... You can Choose Program\n" <<endl;
    cout << "Please select the number of a corresponding choice from one of the options below: \n";
    cout << "--------------------------------------------------\n";
    //if the user wants to save their options (restaurant names for example)
    cout << "1. Create a new file for options to choose from ~"<<endl;
    //choose a random option from a preexisting file
    cout << "2. Choose a random option from a file ~"<<endl;
    //if the user wants to add a new restaurant option for example
    cout << "3. Add another option to an existing file ~"<<endl;
    //if the user wants to add a new restaurant option for example
    cout << "4. Delete an option from an existing option ~"<<endl;
            
    cin >> option;
    
    //check if the option is numerical
    bool valid;
    valid = option;
    if (!valid)
    {
        cin.clear ();
        cin.ignore (10000, '\n');
        cout<< "Sorry, invalid input. Please enter a numerical value between 1 - 4\n";
        return 1; 
    }
    
    if (option == 1)
    {
        option_1();
    }
    
    if (option == 2)
    {
        option_2(); 
    }
    
    if (option == 3)
    {
        option_3();
    }
    
    if (option == 4)
    {
        option_4();
    }
                 
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

void option_1()
{
    //ask the user for the name of the file they wish to create
    cin.ignore();
    string filename;
    cout << "Enter name of the file you want to save options to: ";
    getline(cin, filename, '\n');
    
    //get the purpose of this file for name reasons
    string filePurpose;
    cout << "What is the purpose of this file? (for example: Restaurant Chooser): ";
    getline(cin, filePurpose);
    
    //this is for the size of the optionList array
    int optionNumber = 0;
    cout << "How many options do you have?: ";
    cin >> optionNumber;
    
    //input validation
    kittyCatProof(optionNumber);
    
    //create a dynamic array to hold all the options from the user
    string* optionList = new string [optionNumber];

    //for dummy input for the option
    string listItem;
    
    cin.ignore();
    
    //save all the options into the optionList array
    for(int i=0;i<optionNumber;i++)
    {
        cout << "Enter name of option #" << i+1 << ": ";
        getline(cin, listItem);
        optionList[i] = listItem;
    }  
    
    
    //create the object to save the file
    ofstream outFile;   
    
    //open the file
    outFile.open(filename.c_str()); 
    
    //write the data to the file
    if (outFile)
    {
       //purpose of this file for name reasons
        outFile << filePurpose << endl;
        //how many options are there
        outFile << optionNumber << endl;

       //write the individual list items to the array
        for(int i=0;i<optionNumber;i++) 
        {
            outFile << optionList[i] << endl;
        }
        

        //close the file
        outFile.close();

        cout << "Wrote the " <<filePurpose<<" to file: " << filename << endl;

    }
    
    //if there was an error in writing to the file
    else 
    {
        cout << "Could not write data to " <<filename << endl;
        exit(1);
    }
    
    //delete the dynamic array
    delete[]optionList;
    optionList = NULL;
}

void option_2()
{
    //how many options are there?
    int optionNumber;
    //purpose of this file for name reasons
    string filePurpose;
    
    cin.ignore();
    string filename;
    cout << "Enter name of the file you want to read: ";
    getline(cin,filename,'\n');     
    
    //create an object for file reading
    ifstream inFile;   
    
    //open the file
    inFile.open(filename.c_str()); 
    
    //if the file is able to be opened
    
    if (inFile)
    {
        //create a new dynamic array to hold the file's options         
        string* optionList = new string[optionNumber];
        string optionLine;
        
        std::getline(inFile, filePurpose);
        
        inFile >> optionNumber;

        string blankLine;
        //read in the options
        std::getline(inFile, blankLine);
        for(int i=0;i<optionNumber;i++) 
        {
            std::getline(inFile, optionLine);
            optionList[i] = optionLine;
        }

        //close the file
        inFile.close();

        cout << "Read the file: " << filename << endl;
        
        /*//output the file just in case
        cout<<"File purpose: "<<filePurpose<<endl;
        cout<<"Array size: "<<optionNumber<<endl;
        for(int i=0; i<optionNumber; i++)
        {
            cout<<optionList[i]<<"  ";
        }
        cout<<endl;*/
        
        //make an instance for the chooser class
        Chooser choose(optionNumber, optionList);
        
        //if the girlfriend does not like the option chosen
        bool notThat = true;
        
        //to see if the girlfriend agrees or disagrees
        char notThatChoice, y, Y;
        
        //for the string option that is returned from the class
        string option;
        //display random values until the girlfriend agrees with an option
        
        do
        {
            //output the random option
            option = choose.randomOption();
            cout <<"Your randomly chosen option: ";
            cout <<option<<endl;

            //ask if the girlfriend is unhappy with the option
            cout<<"Does this option satisfy your girlfriend? Select 'Y' for yes, and any other key if no"<<endl;
            cin>>notThatChoice;
            
            if (((notThatChoice == 'y') || (notThatChoice == 'Y')))
            {
                notThat = false;
            }
            
            //there would be no more choices left
            if(choose.getOptionNumber() == 1)
            {
                cout<<"There are no more options left..."<<endl;
                notThat = false;
            }
            
            //delete the randomly chosen option from the array
            choose.deleteOption();
        }while(notThat == true);
        
        
        //delete the dynamic array
        delete[]optionList;
        optionList = NULL;
    }
    
    //if the file could not be opened
    else 
    {
        cout << "Could not read " <<filename << endl;
        exit(1);
    }
}

void option_3()
{
    //how many options are there?
    int optionNumber;
    //purpose of this file for name reasons
    string filePurpose;
    
    cin.ignore();
    string filename;
    cout << "Enter name of the file you want to read: ";
    getline(cin,filename,'\n');     
    
    //create an object for file reading
    ifstream inFile;   
    
    //open the file
    inFile.open(filename.c_str()); 
    
    //if the file is able to be opened
    if (inFile)
    {
        //create a new dynamic array to hold the file's options         
        string* optionList = new string[optionNumber];
        string optionLine;
        
        std::getline(inFile, filePurpose);
        inFile >> optionNumber;

        string blankLine;
        //read in the options
        std::getline(inFile, blankLine);
        for(int i=0;i<optionNumber;i++) 
        {
            std::getline(inFile, optionLine);
            optionList[i] = optionLine;
        }

        
        //close the file
        inFile.close();

        cout << "Read the file: " << filename << endl;
        
        //output the file
        
        cout<<"File purpose: "<<filePurpose<<endl;
        cout<<"Array size: "<<optionNumber<<endl;
        for(int i=0; i<optionNumber; i++)
        {
            cout<<"#"<<i+1<<": "<<optionList[i]<<"  ";
        }
        cout<<endl;
        
        
        //get the new option from the user
        string newOption;
        cout<<"Enter the new option you wish to add: ";
        getline(cin, newOption);
        
        //make an instance for the chooser class
        Chooser choose(optionNumber, optionList);
        //send the newOption to the array
        choose.editAdd(newOption);
        //choose.setFileName(filename);
        choose.setFilePurpose(filePurpose);
        //rewrite the new array into the file
        choose.writeToFile();
        
        //delete the dynamic arrays
        delete[]optionList;
        optionList = NULL;
    }
    
    //if the file could not be opened
    else 
    {
        cout << "Could not read " <<filename << endl;
        exit(1);
    }
}

void option_4()
{
    //how many options are there?
    int optionNumber;
    //purpose of this file for name reasons
    string filePurpose;
    
    cin.ignore();
    string filename;
    cout << "Enter name of the file you want to read: ";
    getline(cin,filename,'\n');     
    
    //create an object for file reading
    ifstream inFile;   
    
    //open the file
    inFile.open(filename.c_str()); 
    
    //if the file is able to be opened
    if (inFile)
    {
        //create a new dynamic array to hold the file's options         
        string* optionList = new string[optionNumber];
        string optionLine;
        
        std::getline(inFile, filePurpose);
        inFile >> optionNumber;

        string blankLine;
        //read in the options
        std::getline(inFile, blankLine);
        for(int i=0;i<optionNumber;i++) 
        {
            std::getline(inFile, optionLine);
            optionList[i] = optionLine;
        }

        
        //close the file
        inFile.close();

        cout << "Read the file: " << filename << endl;
        
        //output the file
        
        cout<<"File purpose: "<<filePurpose<<endl;
        cout<<"Array size: "<<optionNumber<<endl;
        for(int i=0; i<optionNumber; i++)
        {
            cout<<"#"<<i+1<<": "<<optionList[i]<<"  ";
        }
        cout<<endl;
        
        
        //get the element position to delete
        int deleteIndex;
        cout<<"Enter the number corresponding to the option you wish to delete: ";
        cin >>deleteIndex;
        
        //input validation
        kittyCatProof(deleteIndex);
        
        //make an instance for the chooser class
        Chooser choose(optionNumber, optionList);
        //send the newOption to the array
        choose.editDelete(deleteIndex);
        //choose.setFileName(filename);
        choose.setFilePurpose(filePurpose);
        //rewrite the new array into the file
        choose.writeToFile2();
        
        //delete the dynamic arrays
        delete[]optionList;
        optionList = NULL;
    }
    
    //if the file could not be opened
    else 
    {
        cout << "Could not read " <<filename << endl;
        exit(1);
    }
}

//default constructor
Chooser::Chooser()
{
    optionNumber = 0;
    optionList = new string[optionNumber];
}

//Constructor
Chooser::Chooser(int optionNumber, string* optionList)
{
    this->optionNumber = optionNumber;
    this->optionList = new string[this->optionNumber];
    //copy over all the values from the file to the class
    for(int i=0; i<optionNumber; i++)
    {
        this->optionList[i] = optionList[i];
    }
}        

//destructor
Chooser::~Chooser()
{
    delete[]optionList;
}

//copy constructor
Chooser::Chooser(const Chooser& chooser)
{
    this->optionNumber = chooser.optionNumber;
    
    //copy over dynamic data
    this->optionList = new string[this->optionNumber];
    
    //deep copy
    for(int i=0; i<this->optionNumber; i++)
    {
        this->optionList[i] = chooser.optionList[i];
    }
}

//assignment overload
Chooser Chooser::operator =(const Chooser& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    
    this->optionNumber = rhs.optionNumber;
    
    //delete the preexisting array
    delete[]this->optionList;
    this->optionList = NULL;
    
    //create a new array for optionList
    this->optionList = new string[this->optionNumber];
    
    //deep copy
    for(int i=0; i<this->optionNumber; i++)
    {
        this->optionList[i]=rhs.optionList[i];
    }
    
    //return
    return *this;
}

string Chooser::randomOption()
{
    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //choose a random position in the array
    this->randomIndex = rand()% this->optionNumber;
    //cout<<"Random Index: "<<randomIndex<<endl;
   
    //return the option at the randomIndex numbered element
    string option;
    for(int i = 0; i<optionNumber; i++)
    {
        if(i == randomIndex)
        {
            option = optionList[i];
        }
    }
    //cout<<"Option from function: "<<option<<endl;
    return option;
}

void Chooser::deleteOption()
{
    //so that OptionNumber has one less element
    optionNumber = optionNumber - 1;
    
    //make a temp array to hold in the shifted values
    string* tempOptionList = new string[optionNumber];
    
    //copy over the options into the smaller temp array
    //if the randomIndex is at the end of the array
    if(randomIndex == optionNumber)
    {
        //copy all the elements over
        //if the element is at the end of the array
        for(int i=0; i<optionNumber; i++)
        {
            tempOptionList[i]=optionList[i];
        }
    }
    
    //if the element is in the beginning of the array
    else if (randomIndex == 0)
    {
        for (int i=0; i<optionNumber; i++)
        {
            tempOptionList[i]=optionList[i+1];
        }
    }

    //if the randomIndex is in the middle of the array
    else
    {
        //copy all the elements over up until the randomIndex
        for(int i=0; i<randomIndex; i++)
        {
            tempOptionList[i]=optionList[i];
        }
    
        //skip over the randomIndex when copying over
        for(int i =randomIndex; i<optionNumber; i++)
        {
            tempOptionList[i]= optionList[i+1];
        }
    }
    //delete the original optionList array
    delete[]optionList;
    optionList = NULL;
    
    //create a new optionList Array
    this->optionList = new string[optionNumber];
    
    //copy over the values from the temp array
    for(int i=0; i<optionNumber; i++)
    {
        optionList[i] = tempOptionList[i];
    }
    
    
    //delete the tempOptionList array
    delete[]tempOptionList;
    tempOptionList = NULL;
}

int Chooser::getRandomIndex()
{
    return randomIndex;
}

int Chooser::getOptionNumber()
{
    return optionNumber;
}

void Chooser::editAdd(string newOption)
{
    //make our array one element larger than it was before
    optionNumber = optionNumber + 1;
    
    //make a temp array for the larger value
    string* tempOptionList = new string[optionNumber];
    
    //copy over the values
    for(int i=0; i<optionNumber-1; i++)
    {
        tempOptionList[i]=optionList[i];
    }
    
    //add the new option at the end of the array
    tempOptionList[optionNumber - 1] = newOption;
    
    //delete the original optionList
    delete[]optionList;
    optionList = NULL;
    
    //make a new array for optionList
    optionList = new string[optionNumber];
    
    //copy the values from temp to optionList
    for (int i=0; i<optionNumber; i++)
    {
        optionList[i] = tempOptionList[i];
    }
    
    
    //delete the temp array
    delete[]tempOptionList;
    tempOptionList = NULL;
}

void Chooser::editDelete(int indexForDeleting)
{
    //so that OptionNumber has one less element
    optionNumber = optionNumber - 1;
    indexForDeleting = indexForDeleting - 1;
    
    //make a temp array to hold in the shifted values
    string* tempOptionList = new string[optionNumber];
    
    //copy over the options into the smaller temp array
    //if the indexForDeleting is at the end of the array
    if(indexForDeleting == optionNumber)
    {
        //copy all the elements over
        //if the element is at the end of the array
        for(int i=0; i<optionNumber; i++)
        {
            tempOptionList[i]=optionList[i];
        }
    }
    
    //if the element is in the beginning of the array
    else if (indexForDeleting == 0)
    {
        for (int i=0; i<optionNumber; i++)
        {
            tempOptionList[i]=optionList[i+1];
        }
    }

    //if the indexForDeleting is in the middle of the array
    else
    {
        //copy all the elements over up until the indexForDeleting
        for(int i=0; i<indexForDeleting; i++)
        {
            tempOptionList[i]=optionList[i];
        }
    
        //skip over the indexForDeleting when copying over
        for(int i = indexForDeleting; i<optionNumber; i++)
        {
            tempOptionList[i]= optionList[i+1];
        }
    }
    //delete the original optionList array
    delete[]optionList;
    optionList = NULL;
    
    //create a new optionList Array
    this->optionList = new string[optionNumber];
    
    //copy over the values from the temp array
    for(int i=0; i<optionNumber; i++)
    {
        optionList[i] = tempOptionList[i];
    }
    
   
    //cout array just in case
    for(int i =0; i<optionNumber; i++)
    {
        cout<<optionList[i]<<" ";
    }
    cout<<endl;
    
    //delete the tempOptionList array
    delete[]tempOptionList;
    tempOptionList = NULL; 
   
}

void Chooser::writeToFile()
{
    //ask the user for the name of the file they wish to write the file to
    //cin.ignore();
    string fileName;
    cout << "Enter name of the file you want to save options to: ";
    getline(cin, fileName, '\n');
    //create the object to save the file
    ofstream outFile;   
    
    //open the file
    outFile.open(fileName.c_str()); 
    
    //write the data to the file
    if (outFile)
    {
       //purpose of this file for name reasons
        outFile << filePurpose << endl;
        //how many options are there
        outFile << optionNumber << endl;

       //write the individual list items to the array
        for(int i=0;i<optionNumber;i++) 
        {
            outFile << optionList[i] << endl;
        }
        

        //close the file
        outFile.close();

        cout << "Wrote the " <<filePurpose<<" to file: " << fileName << endl;

    }
    
    //if there was an error in writing to the file
    else 
    {
        cout << "Could not write data to " <<fileName << endl;
        exit(1);
    }
    
}

void Chooser::setFileName(string filename)
{
    this->fileName = filename;
}

void Chooser::setFilePurpose(string filePurpose)
{
    this->filePurpose= filePurpose;
}

void Chooser::writeToFile2()
{
    //ask the user for the name of the file they wish to write the file to
    cin.ignore();
    string fileName;
    cout << "Enter name of the file you want to save options to: ";
    getline(cin, fileName, '\n');
    //create the object to save the file
    ofstream outFile;   
    
    //open the file
    outFile.open(fileName.c_str()); 
    
    //write the data to the file
    if (outFile)
    {
       //purpose of this file for name reasons
        outFile << filePurpose << endl;
        //how many options are there
        outFile << optionNumber << endl;

       //write the individual list items to the array
        for(int i=0;i<optionNumber;i++) 
        {
            outFile << optionList[i] << endl;
        }
        

        //close the file
        outFile.close();

        cout << "Wrote the " <<filePurpose<<" to file: " << fileName << endl;

    }
    
    //if there was an error in writing to the file
    else 
    {
        cout << "Could not write data to " <<fileName << endl;
        exit(1);
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