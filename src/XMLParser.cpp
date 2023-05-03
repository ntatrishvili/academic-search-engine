#include <iostream>
#include <fstream>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Feed.h"

ParseData(Feed &feed)
{
    rapidxml::file<> xmlFile("../content/data.xml");
    rapidxml::xml_document<> xmlDoc;
    xmlDoc.parse<0>(xmlFile.data());

    rapidxml::xml_node<>* rootNode = xmlDoc.first_node("root");
    if (rootNode)
    {
        for (rapidxml::xml_node<>* node = rootNode->first_node("item"); node; node = node->next_sibling("item"))
        {
            = node->first_attribute("id")->value();
            const char* value = node->value();
            std::cout << "Name: " << name << ", Value: " << value << std::endl;
        }
    }

    return 0;
}
