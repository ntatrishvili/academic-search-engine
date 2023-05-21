#pragma once
#include <string>

class Comment
{
    int pageNum;
    int figureNum;
    int tableNum;
    std::string commentText;

public:
    Comment(int _pagesNum, int _figuresNum, int _tablesNum, std::string _commentText);
    Comment(int _pagesNum, int _figuresNum, int _tablesNum);
    Comment(int _pagesNum, int _figuresNum);
    Comment(int _pagesNum);
    Comment();

    ~Comment(){}
    
    int getPageNum();
    int getFigureNum();
    int getTableNum();
    std::string getCommentText();
    std::string toString();
};