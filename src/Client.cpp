#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <curl/curl.h>
#include "rapidxml.hpp"
#include "Client.h"

static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append(contents, size * nmemb);
    return size * nmemb;
}

std::string replaceSpacesWithPlus(const std::string &input)
{
    std::string result;
    for (char c : input)
    {
        if (c == ' ')
        {
            result = result + '+';
        }
        else
        {
            result = result + c;
        }
    }
    return result;
}

std::string queryBuilder()
{
    std::string myQuery;
    std::string input;
    std::cout << "please write the key words you want to search by: " << std::endl;
    std::getline(std::cin, input);
    input = replaceSpacesWithPlus(input);
    myQuery = "http://export.arxiv.org/api/query?search_query=all:" + input + "&start=0&max_results=10";
    return myQuery;
}

void saveData(std::string &response)
{
    // make the xml document
    rapidxml::xml_document<> doc;

    // save the whole data as an xml
    std::ofstream feed("content/feed.xml", std::ofstream::out);
    if (feed.is_open())
    {
        char *cpy = const_cast<char *>(response.c_str());
        // do not parse depricated NUL characters
        doc.parse<rapidxml::parse_non_destructive>(cpy);

        // write the modified response in feed
        feed << response;
        feed.close();
    }
    else
    {
        std::cerr << "Opening the file failed!" << std::endl;
    }
}

Feed *createFeed()
{
    // create the feed object
    Feed *myFeed = new Feed();
    // open the file
    std::ifstream feed("content/feed.xml");
    if (!feed.is_open())
    {
        std::cerr << "Failed to open data.xml file!" << std::endl;
        return myFeed;
    }
    rapidxml::xml_document<> doc;

    std::vector<char> buffer((std::istreambuf_iterator<char>(feed)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    if (buffer.empty())
    {
        std::cerr << "XML buffer is empty!" << std::endl;
        return myFeed;
    }

    // Parse the whole file into the doc
    doc.parse<0>(&buffer[0]);
    // Now starts parsing the nodes in doc into the class objects
    // Access the root node
    rapidxml::xml_node<> *rootNode = doc.first_node("feed");
    std::vector<Entry *> entries;
    // Access the child nodes (entries)
    for (rapidxml::xml_node<> *entryNode = rootNode->first_node("entry"); entryNode; entryNode = entryNode->next_sibling("entry"))
    {
        rapidxml::xml_node<> *node;
        // assembling the authors
        std::vector<Author *> authors;
        for (rapidxml::xml_node<> *entryNode2 = entryNode->first_node("author"); entryNode2; entryNode2 = entryNode2->next_sibling("author"))
        {
            std::string name, affiliation = "";
            node = entryNode2->first_node("name");
            if (node)
            {
                name = node->value();
            }
            node = entryNode2->first_node("arxiv:affiliation");
            if (node)
            {
                affiliation = node->value();
            }
            Author *auth = new Author(name, affiliation);
            authors.push_back(auth);
        }
        // assembling the comment
        Comment *comment = new Comment();
        // TODO THE COMMENT
        int pages = 0, figures = 0, tables = 0;
        node = entryNode->first_node("arxiv:comment");
        if (node)
        {
            rapidxml::xml_node<> *node2;
            node2 = node->first_node("");
            if (node2)
            {
                // pages = std::stoi(node->value());
            }
            std::string commentText = "";

            Comment *comment = new Comment(pages, figures, tables, commentText);
        }

        // assembling the rest of the entry
        std::string id = "", title = "", summary = "", link = "";

        // id
        node = entryNode->first_node("id");
        if (node)
        {
            id = node->value();
        }

        // title
        node = entryNode->first_node("title");
        if (node)
        {
            title = node->value();
        }

        // summary
        node = entryNode->first_node("summary");
        if (node)
        {
            summary = node->value();
        }

        // link
        node = entryNode->first_node("link");
        if (node)
        {
            link = node->value();
        }

        // //update and publish times
        std::tm updateTime;
        std::tm publishTime;

        Entry *entry = new Entry(id, updateTime, publishTime, title, summary, authors, link, comment);
        myFeed->addEntry(entry);
    }
    feed.close();
    return myFeed;
}

Feed *getData()
{
    Feed *f = new Feed();

    // create the HTTP request
    CURL *curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl)
    {
        // assemble the request url
        std::string url = queryBuilder();

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        // send the request
        res = curl_easy_perform(curl);
        // check if the get was successful
        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            // if it was successful
            // save the data in a .xml file
            saveData(response);
            // parse the data into a class
            Feed *f = createFeed();
            // return the parsed data
            return f;
        }
        curl_easy_cleanup(curl);
        // return an empty feed if something went wrong
        return f;
    }
}

void storeFeed(Feed *feed)
{
    // makes a file to store the readable data
    std::ofstream file("./content/ReadableData.txt");
    if (file.is_open())
    {
        // if the open was successful stores the data
        file << feed->toString();
        file.close();
        std::cout << "You can now view the information about these papers in the ReadableData.txt file" << std::endl;
    }
    else
    {
        // if the open was not successful, outputs the error
        std::cerr << "Failed to open the file." << std::endl;
    }
}

void displayData(Feed *feed)
{
    std::cout << "\nPhew! That was a lot! \nAll the papers are here!! How would you like to view them? Choose:\n1 to store them in a file\n2 to display them in the terminal\n\n";
    int choice;
    std::cin >> choice;
    if (choice == 1)
    {
        storeFeed(feed);
    }
    else if (choice == 2)
    {
        std::cout << feed->toString();
    }
    else
    {
        std::cerr << "Sorry, that option is not available yet!" << std::endl;
    }
}