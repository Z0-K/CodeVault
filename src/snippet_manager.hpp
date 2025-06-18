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
        void list_snippets(const std::string &filename);
        void save_to_file(const std::string &filename);
        void load_from_file(const std::string &filename);
        void search_snippets();
        void filter_by_tag();
        void edit_snippet_by_id();
        void delete_snippet_by_id();
        void add_favorite_snippet();
        void list_favorites();
};

#endif

