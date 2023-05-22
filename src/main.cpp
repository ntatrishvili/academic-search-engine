#include <iostream>
#include <cstring>
#include "Client.h"
#include "Feed.h"


int main()
{
    Feed* feed= new Feed();
    feed->addEntry(new Entry());
    // fetch data from the arxiv and write it to the feed object
    std::cout<<"\nThe following program will give you a chance to find the exact academic paper you need! follow the instructions and enjoy!\n\n";
    feed = getData();

    //Display the data to the user in their chosen way
    displayData(feed);

    // store the feed in a txt file
    storeFeed(feed);
    // sort and filter the received data with the additional filters
    // filterData();
    return 0;
}

// int main()
// {
//     // get the request from the user

//     std::tm publishDate;
//     std::tm updateDate;

//     // Set the values for publishDate
//     std::memset(&publishDate, 0, sizeof(publishDate)); // Initialize to all zeroes
//     publishDate.tm_year = 122;                         // Year since 1900 (e.g., 2022 - 1900 = 122)
//     publishDate.tm_mon = 0;                            // Month (January is 0)
//     publishDate.tm_mday = 1;                           // Day of the month (1-31)

//     // Set the values for updateDate
//     std::memset(&updateDate, 0, sizeof(updateDate)); // Initialize to all zeroes
//     updateDate.tm_year = 122;                        // Year since 1900 (e.g., 2022 - 1900 = 122)
//     updateDate.tm_mon = 3;                           // Month (April is 3)
//     updateDate.tm_mday = 15;                         // Day of the month (1-31)
//     Comment *c1 = new Comment(12, 4, 3, "nia");
//     Author *a1 = new Author("Nia", "BME");
//     Author *a2 = new Author("Samer", "Unemplyed");
//     Author *a3 = new Author("Ameni", "Bday Queen");
//     std::vector<Author *> auths;
//     auths.push_back(a1);
//     auths.push_back(a2);
//     auths.push_back(a3);

//     Entry *entry = new Entry("123", updateDate, publishDate, "satauri", "descroption", auths, "https.com", c1);
//     Entry *entry2 = new Entry();

//     Feed *feed = new Feed();
//     feed->addEntry(entry);
//     feed->addEntry(entry2);
//     // std::cout<<feed->toString()<<std::endl;
//     // fetch data from the arxiv
//     getData();
//     // convert the data and write it in the classes
//     // ParseData();
//     // sort and filter the received data with the additional filters
//     // filterData();
//     return 0;
// }