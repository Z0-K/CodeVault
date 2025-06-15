#ifndef SNIPPET_MANAGER_HPP
#define SNIPPET_MANAGER_HPP

#include "snippet.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

class SnippetManager{
    private: 
        std::vector<Snippet> snippets;
        int nextID = 1;

    public: 
        void add_snippet();
        void list_snippets();
        void save_to_file(const std::string &filename);
        void load_from_file(const std::string &filename);
        void searchSnippets();
};


#endif

