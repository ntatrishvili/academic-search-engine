#include"Feed.h"

// Feed::addEntry(const Entry& entry){
//     entries.push_back(entry);
// }

// Feed::fillInfo(){
//     rapidxml::file<> xmlFile("../content/data.xml");
    
//     std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
//     buffer.push_back('\0');

//     // Parse the buffer
//     xml_document<> doc;
//     doc.parse<0>(&buffer[0]); 
    
//     // // Access the root node
//     xml_node<>* rootNode = doc.first_node("feed");
 
//     // Access the child nodes (entries)
//     for (xml_node<>* entryNode = rootNode->first_node("entry"); entryNode; entryNode = entryNode->next_sibling("entry")) {
//         Entry entry = new Entry()
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