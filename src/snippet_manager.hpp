#ifndef SNIPPET_MANAGER_HPP
#define SNIPPET_MANAGER_HPP

#include "snippet.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class SnippetManager{
    private: 
        std::vector<Snippet> snippets;
        int nextID = 1;

    public: 
        void add_snippet();
};


#endif

