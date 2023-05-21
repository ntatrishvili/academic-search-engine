#pragma once
#include<string>

class Author
{
    std::string name;
    std::string affiliation;

public:
    //constructors for all cases
    Author(std::string _name, std::string _affiliation);
    Author(std::string _name);
    Author();
    //destructor
    ~Author(){}
    //getters for all fields
    std::string getName();
    std::string getAffiliation();
    //toString to print the class well (for testing)
    std::string toString();
};