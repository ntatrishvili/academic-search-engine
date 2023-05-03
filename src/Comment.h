#pragma once
#include<string>

class Comment{
    int pageNum;
    int figureNum;
    int tableNum;
    std::string commentText;

public:
    Comment(int _pagesNum, int _figuresNum, int _tablesNum, std::string _commentText);
    int getPageNum();
    int getFigureNum();
    int getTableNum();
    std::string toString();
};