#ifndef CLIENT_H
#define CLIENT_H

#pragma once
#include <string>
#include "Feed.h"

// connects to the API
//  static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp);
// used to build the query, replaces all the spaces with '+'s to build the url
std::string replaceSpacesWithPlus(const std::string &input);
// builds the url
std::string queryBuilder();
// takes the response from the API as a string
// and stores it in a file
void saveData(std::string &response);
// reads the file with the stored data and
// parses it to an object of the Feed class
Feed *createFeed();
// acts as a menu uniting and piping all the functions in the Client class
Feed *getData();
// store the feed in a human-readable .txt file
void storeFeed(Feed* feed);
#endif // CLIENT_H