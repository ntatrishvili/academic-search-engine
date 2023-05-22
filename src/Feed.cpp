#include"Feed.h"
#include<iostream>
Feed::Feed(){}
Feed::Feed(std::string _id) : id(_id) {}
Feed::Feed(std::vector<Entry> _entries) : entries(_entries) {}
Feed::Feed(std::string _id, std::vector<Entry> _entries):id(_id), entries(_entries){};

// Getter for the feed ID
std::string Feed::getId() {
    return id;
}
void Feed::addEntry(const Entry& entry){
    try{
        entries.push_back(entry);
    }
    catch(const std::exception& ex){
        std::cout<<"could not add entry!\n";
    }
}

// void Feed::fillInfo(std::string address){
// }


std::string Feed::toString() {
    std::string result;
    result = "Entries:\n";

    for (int i=0; i<entries.size(); i++) {
        result += "----------------\n";
        try{
            result += entries[i].toString();
        }
        catch(const std::exception& ex){
            std::cout<<"problem at #"<<i<<"\n";
        }
        result += "----------------\n";
    }

    return result;
}