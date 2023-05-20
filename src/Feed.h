#include<string>
#include<vector>
class Entry;
// class Request;

class Feed{
    // Request request;
    std::string id;
    std::vector<Entry> entries;
public:
    Feed();

    void addEntry();
    void filterEntries();
    void sortEntries();
    static void fillInfo(Feed feed);

    //add getters and toString

};