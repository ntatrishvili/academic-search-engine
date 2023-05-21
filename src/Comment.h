#ifndef COMMENT_H
#define COMMENT_H

#pragma once
#include <string>

class Comment
{
    int pageNum;
    int figureNum;
    int tableNum;
    std::string commentText;

public:
    //constructors for all cases
    Comment(int _pagesNum, int _figuresNum, int _tablesNum, std::string _commentText);
    Comment(int _pagesNum, int _figuresNum, int _tablesNum);
    Comment(int _pagesNum, int _figuresNum);
    Comment(int _pagesNum);
    Comment();

    //destructor
    ~Comment(){}
    
    //getters to access the fields
    int getPageNum();
    int getFigureNum();
    int getTableNum();
    std::string getCommentText();

    //toString to output the class better
    std::string toString();
};

#endif  // COMMENT_H