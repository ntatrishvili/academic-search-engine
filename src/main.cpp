#include <iostream>
#include <cstring>
#include "Client.h"
#include "XMLParser.h"
#include "Feed.h"
int ParseData();

int main(){
    //get the request from the user

    
    std::tm publishDate;
    std::tm updateDate;

    // Set the values for publishDate
    std::memset(&publishDate, 0, sizeof(publishDate)); // Initialize to all zeroes
    publishDate.tm_year = 122; // Year since 1900 (e.g., 2022 - 1900 = 122)
    publishDate.tm_mon = 0; // Month (January is 0)
    publishDate.tm_mday = 1; // Day of the month (1-31)

    // Set the values for updateDate
    std::memset(&updateDate, 0, sizeof(updateDate)); // Initialize to all zeroes
    updateDate.tm_year = 122; // Year since 1900 (e.g., 2022 - 1900 = 122)
    updateDate.tm_mon = 3; // Month (April is 3)
    updateDate.tm_mday = 15; // Day of the month (1-31)
    Comment* c1=new Comment(12,4, 3, "nia");
    Author* a1 = new Author("Nia", "BME");
    Author* a2 = new Author("Samer", "Unemplyed");
    Author* a3 = new Author("Ameni", "Bday Queen");
    std::vector<Author*> auths;
    auths.push_back(a1);
    auths.push_back(a2);
    auths.push_back(a3);

    Entry* entry = new Entry("123", updateDate, publishDate, "satauri", "descroption", auths, "https.com", c1 );
    Entry* entry2 = new Entry();

    Feed* feed = new Feed();
    feed->addEntry(*entry);
    feed->addEntry(*entry2);
    std::cout<<feed->toString()<<std::endl;
    //fetch data from the arxiv
    // getData();
    //convert the data and write it in the classes
    //ParseData();
    //sort and filter the received data with the additional filters
   // filterData();
    return 0;
}


// int main() {
//    // Feed feed;
//     //get the request from the user

    
//     std::tm publishDate;
//     std::tm updateDate;

//     // Set the values for publishDate
//     std::memset(&publishDate, 0, sizeof(publishDate)); // Initialize to all zeroes
//     publishDate.tm_year = 122; // Year since 1900 (e.g., 2022 - 1900 = 122)
//     publishDate.tm_mon = 0; // Month (January is 0)
//     publishDate.tm_mday = 1; // Day of the month (1-31)

//     // Set the values for updateDate
//     std::memset(&updateDate, 0, sizeof(updateDate)); // Initialize to all zeroes
//     updateDate.tm_year = 122; // Year since 1900 (e.g., 2022 - 1900 = 122)
//     updateDate.tm_mon = 3; // Month (April is 3)
//     updateDate.tm_mday = 15; // Day of the month (1-31)
//     Comment* c1=new Comment(12,4, 3, "nia");
//     Author* a1 = new Author("Nia", "BME");
//     Author* a2 = new Author("Samer", "Unemplyed");
//     Author* a3 = new Author("Ameni", "Bday Queen");
//     std::vector<Author*> vec;
//     vec.push_back(a1);
//     vec.push_back(a2);
//     vec.push_back(a3);

//     Entry* entry = new Entry("123", updateDate, publishDate, "satauri", "descroption", vec, "https.com", c1 );
//     Entry* entry2 = new Entry();
//     std::cout<<entry2->getLink()<<std::endl;

//     std::cout<<entry->toString()<<std::endl;
//     // std::cout<<c1->toString()<<std::endl;
//     // std::cout<<c2->toString()<<std::endl;
//     // std::cout<<c3->toString()<<std::endl;
//     // std::cout<<c4->toString()<<std::endl;
//     // std::cout<<c5->toString()<<std::endl;


//     //fetch data from the arxiv
//     // getData();
//     //convert the data and write it in the classes
//     //ParseData();
//     //sort and filter the received data with the additional filters
//    // filterData();
//     return 0;
// }


// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include "rapidxml.hpp"

// using namespace rapidxml;

// int main() {
//     // Read the XML file
//     std::ifstream file("./debiloba.txt");
//     std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
//     buffer.push_back('\0'); // Null-terminate the buffer

//     xml_document<> doc;
//     doc.parse<0>(&buffer[0]); // Parse the buffer

//     // // Access the root node
//     xml_node<>* rootNode = doc.first_node("feed");
 
//     // Access the child nodes (entries)
//     for (xml_node<>* entryNode = rootNode->first_node("entry"); entryNode; entryNode = entryNode->next_sibling("entry")) {
//         // Access the data within each entry
//         xml_node<>* titleNode = entryNode->first_node("title");
//         xml_node<>* publishedNode = entryNode->first_node("published");
//         xml_node<>* summaryNode = entryNode->first_node("summary");

//        if (titleNode && publishedNode && summaryNode) {
//             // Extract the data
//             std::string title = titleNode->value();
//             std::string published = publishedNode->value();
//             std::string summary = summaryNode->value();

//             // Print the extracted data
//             std::cout << "Title: " << title << std::endl;
//             std::cout << "Published: " << published << std::endl;
//             std::cout << "Summary: " << summary << std::endl;
//             std::cout << std::endl;
//        }
//     }
//     file.close();
//     return 0;
// }
