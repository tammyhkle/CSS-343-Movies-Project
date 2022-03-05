/**
 * @file RentalManager.cpp
 * @author Le, Tammy
 * @brief RentalManager class - Processes data from the Store's Inventory, Customers, and Transactions/ Commands
 * Notes:
 * Files are read in from main 
 * readMovies, readInventory, readCustomers, readCommands
 * @date 2022-02-26
 **/
#include "RentalManager.h"

// constructor default
RentalManager::RentalManager() {}
// destructor
RentalManager::~RentalManager() {}

//reads in movies
void RentalManager::readMovies(istream& inFile)
{}
//reads in item data and builds inventory
void RentalManager::readInventory(istream& inFile)
{
    Item* item;
    char itemType;
    char genre;

    while (true) 
    {
        inFile >> genre;
        if (inFile.eof())
        {
            break;
        }
        itemType = "M";
        item = this->movieFac.createItem(itemType, genre);
        
        if(item == nullptr)
        {
            string invalidLine = "";
            getline(inFile, invalidLine);
            continue;
        }
        infile.get();
        item->setItem(inFile);
        catalouge.insertItem(item);
    }
    cout << catalouge << endl;
}
//read in cutomer and build customer profile
void RentalManager::readCustomer(istream& inFile)
{}
//reads in commands data and performs the command
void RentalManager::readCommands(istream& inFile, Storage& catalouge, HashMap& customer)
{
    char commandType;
    int customerID;
    char genre;
    Transaction* command;

    while (true)
    {
        inFile >> commandType;
        if (inFile.eof()) 
        {
            break;
        }
        //transaction factory
        command = this->transFac.createTransaction(commandType);
        if (command == nullptr)
        {
            string invalidLine = "";
            getline(inFile, invalidLine);
            continue;
        }
        inFile.get();

        if (commandType == 'D')
        {
            command->doTransaction(catalouge, customerMap);
        }
        command->setData(inFile);
        command->doTransaction(catalouge, customerMap);
    }
}
//operator ostream<<
ostream &operator<<(ostream &, const BSTree &)
{
}