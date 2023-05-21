#include <curl/curl.h>
#include <fstream>
#include <sstream>
#include "rapidxml.hpp"
#include <iostream>
#include <string.h>
#include "Feed.h"
#include "client.h"

static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append(contents, size * nmemb);
    return size * nmemb;
}
std::string queryBuilder()
{
    std::string myQuery;
    std::string inputt;
    std::cout << "please write the key words you want to search by: " << std::endl;
    std::cin >> inputt;
    myQuery = "http://export.arxiv.org/api/query?search_query=all:" + inputt + "&start=0&max_results=10";
    return myQuery;
}

void saveData(std::string &response)
{
    rapidxml::xml_document<> doc;

    // save the whole data as an xml
    std::ofstream feed("content/feed.xml", std::ofstream::out);
    if (feed.is_open())
    {
        char* cpy = const_cast<char *>(response.c_str());
        doc.parse<0>(cpy);
        rapidxml::xml_node<> *rootNode = doc.first_node("feed");

        //write the modified response in feed
        feed << response;
        feed.close();
    }
    else
    {
        std::cerr << "Opening data.xml file failed!" << std::endl;
    }
}

// Feed createFeed(){
//     Feed* myFeed = new Feed();
//     rapidxml::xml_document<> doc;
//     std::ofstream feed("content/feed.xml", std::ofstream::out);

    

// }


void getData()
{
    CURL *curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl)
    {
        std::string url = queryBuilder();
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            saveData(response);
        }

        curl_easy_cleanup(curl);
    }
}