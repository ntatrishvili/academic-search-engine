#include "Author.h"

Author::Author(std::string _name, std::string _affiliation) : name(_name), affiliation(_affiliation) {}

std::string Author::getName() { return name; };
std::string Author::getAffiliation() { return affiliation; };
std::string Author::toString()
{
    return name + ", " + affiliation;
}