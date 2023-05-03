#pragma once
#include<string>
class Request{
    std::string searchText;
    int responseNum;

public:
    Request(std::string _searchText, int _responseNum);
//getters and tostring
};