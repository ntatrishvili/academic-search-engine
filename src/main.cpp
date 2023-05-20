#include <iostream>
#include "Client.h"
#include "XMLParser.h"

int ParseData();

int main() {
   // Feed feed;
    //get the request from the user
    

    //fetch data from the arxiv
    getData();
    //convert the data and write it in the classes
    //ParseData();
    //sort and filter the received data with the additional filters
   // filterData();
    return 0;
}


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
