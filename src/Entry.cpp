#include "Entry.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
// constructors
Entry::Entry(std::string id, std::tm updateDate, std::tm publishDate, std::string title,
             std::string summary, std::vector<Author *> authors, std::string link, Comment *comment)
    : id(id), updateDate(updateDate), publishDate(publishDate), title(title), summary(summary),
      authors(authors), link(link), comment(comment)
{
}
Entry::Entry()
{
    id="";
    title = "";
    summary = "";
    link = "";
    comment = new Comment();
}

std::string Entry::getId() { return id; }

std::tm Entry::getUpdateDate() { return updateDate; }

std::tm Entry::getPublishDate() { return publishDate; }

std::string Entry::getTitle() { return title; }

std::string Entry::getSummary() { return summary; }

std::vector<Author *> Entry::getAuthors()
{
    std::vector<Author *> cpyAuthors;
    try
    {
        // copy the Authors to a new vector
        for (int i = 0; i < authors.size(); i++)
        {
        //    cpyAuthors.push_back(new Author(authors[i]));
        }
        return cpyAuthors;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "could not copy authors!!" << std::endl<<ex.what()<<std::endl;
    }
    return cpyAuthors;
}

std::string Entry::getLink() { return link; }

std::string Entry::toString()
{
    //assemble a string for authors
    std::string authorsStr;
    for (const auto &author : authors)
    {
        authorsStr += "\n\t" + author->toString();
    }

    //assemble strings for the dates
    std::stringstream ss;
    ss << std::put_time(&updateDate, "%Y-%m-%d");
    std::string updateDateStr = ss.str();
    // Do the same for the publishDate
    std::stringstream ss2;
    ss2 << std::put_time(&publishDate, "%Y-%m-%d");
    std::string publishDateStr = ss2.str();


    return "Entry:\n"
            "\tID: " +
            id +
            "\n\tUpdate Date: " + updateDateStr +
            "\n\tPublish Date: " + publishDateStr +
            "\n\tTitle: " + title +
            "\n\tSummary: " + summary +
            "\n\tAuthors:" + authorsStr +
            "\n\tLink: " + link;
}