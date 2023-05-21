#include "Comment.h"

Comment::Comment(int _pagesNum, int _figuresNum, int _tablesNum, std::string _commentText) : pageNum(_pagesNum), figureNum(_figuresNum), tableNum(_tablesNum), commentText(_commentText) {}
Comment::Comment(int _pagesNum, int _figuresNum, int _tablesNum) : pageNum(_pagesNum), figureNum(_figuresNum), tableNum(_tablesNum)
{
    commentText = "";
}
Comment::Comment(int _pagesNum, int _figuresNum) : pageNum(_pagesNum), figureNum(_figuresNum)
{
    commentText = "";
    tableNum = 0;
}
Comment::Comment(int _pagesNum) : pageNum(_pagesNum)
{
    commentText = "";
    tableNum = 0;
    figureNum = 0;
}
Comment::Comment()
{
    commentText = "";
    tableNum = 0;
    figureNum = 0;
    pageNum = 0;
}

int Comment::getPageNum() { return pageNum; }

int Comment::getFigureNum() { return figureNum; }

int Comment::getTableNum() { return tableNum; }

std::string Comment::getCommentText() { return commentText; }

std::string Comment::toString()
{
    std::string pageStr = getPageNum() != 0 ? "\tpages:" + std::to_string(pageNum) : "";
    std::string figureStr = getFigureNum() != 0 ? "\tfigures:" + std::to_string(figureNum) : "";
    std::string tableStr = getTableNum() != 0 ? "\ttables:" + std::to_string(tableNum) : "";
    std::string commentStr = getCommentText() != "" ? "\tComment Text:" + getCommentText() : "";
    return "Comment:" + pageStr + figureStr + tableStr + commentStr;
}