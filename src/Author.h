#ifndef AUTHOR_H
#define AUTHOR_H

#pragma once
#include<string>

class Author
{
    std::string name;
    std::string affiliation;

public:
    //constructors for all cases
    Author();
    Author(std::string _name);
    Author(std::string _name, std::string _affiliation);
    Author(const Author& theOther);
    //destructor
    ~Author(){}
    //getters for all fields
    std::string getName();
    std::string getAffiliation();
    //toString to print the class well (for testing)
    std::string toString();
};


#endif  // AUTHOR_H