#ifndef ENTRY_H
#define ENTRY_H

#pragma once

#include <ctime>
#include <vector>
#include "Author.h"
#include "Comment.h"

class Entry
{
    std::string id;
    std::tm updateDate;
    std::tm publishDate;
    std::string title;
    std::string summary;
    std::vector<Author*> authors;
    std::string link;
    Comment *comment;

public:
    // constructors
    Entry(std::string id, std::tm updateDate, std::tm publishDate, std::string title,
          std::string summary, std::vector<Author *> authors, std::string link, Comment *comment);
    Entry();
    // destructor
    ~Entry()
    {
        // first delete every author
        for (int i = 0; i < authors.size(); i++)
        {
            delete authors.at(i);
        }
        // then delete the 'authors' vector
        authors.clear();

        //delete the comment if it exists
        if(comment != nullptr){
            delete comment;
        }
    }
    // all the getters for the fields
    std::string getId();
    std::tm getUpdateDate();
    std::tm getPublishDate();
    std::string getTitle();
    std::string getSummary();
    std::vector<Author*> getAuthors();
    std::string getLink();
    // toString to output the class better
    std::string toString();
};


#endif  // ENTRY_H