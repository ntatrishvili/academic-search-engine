#include"Entry.h"
#include"Request.h"
//string is included twice

class Feed{
    Request request;
    std::string id;
    std::vector<Entry> entries;
public:
    Feed();
    
    void filterEntries();
    void sortEntries();
    //add getters and toString

};