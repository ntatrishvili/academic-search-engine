#include <curl/curl.h>
#include <iostream>
#include <string.h>
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

void getData()
{
    CURL *curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl)
    {
        // curl_easy_setopt(curl, CURLOPT_URL, "http://export.arxiv.org/api/query?search_query=all:electron&start=0&max_results=10");
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
            std::cout << response << std::endl;
        }

        curl_easy_cleanup(curl);
    }
}