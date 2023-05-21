#pragma once
#include<string>

class Author
{
    std::string name;
    std::string affiliation;

public:
    Author(std::string _name, std::string _affiliation);
    Author(std::string _name);
    Author();
    ~Author(){}
    std::string getName();
    std::string getAffiliation();
    std::string toString();
};