#include"Comment.h"

// Comment::Comment(int _pagesNum, int _figuresNum, int _tablesNum, std::string _commentText);

int Comment::getPageNum(){
    return Comment::pageNum;
}

int Comment::getFigureNum(){
    return figureNum;
}

int Comment::getTableNum(){
    return tableNum;
}

std::string Comment::toString(){
    // std::string pageStr = pageNum!=0? "pages: " + (string)pageNum : "";
    // std::string figuretr = figureNum!=0? "figures: " + (string)figureNum : "";
    // std::string tableStr = tableNum!=0? "tables: " + (string)tableNum : "";

    // return pageStr + figureStr + tableStr;
    return "testinCommentToString";
}