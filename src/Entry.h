#include<ctime>
#include<vector>
#include"Author.h"
#include"Comment.h"
#include"Category.h"

class Entry{
    std::string id;
    std::tm updateDate;
    std::tm publishDate;
    std::string title;
    std::string summary;
    std::vector<Author> authors;
    std::string link;
    Comment comment;
    Category category;
public:
    Entry();
//add getters and tostring
};