#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>

using namespace std;

struct Article {
    string title;
    string author;
    string summary;
};

class SearchEngine {
public:
    SearchEngine(string articles_folder_path, string stop_words_file_path);
    vector<Article> search(string query, vector<string> options);

private:
    void preprocessArticles();
    void loadStopWords();
    void tokenize(string& text, vector<string>& words);
    vector<string> removeStopWords(vector<string>& words);
    void indexArticles();
    vector<Article> searchQuery(string query, vector<string> options);

    string articles_folder_path_;
    string stop_words_file_path_;
    vector<string> stop_words_;
    unordered_map<string, vector<int>> index_;
    vector<Article> articles_;
};

#endif
