#ifndef SNIPPET_HPP 
#define SNIPPET_HPP

#include <string>

struct Snippet{ 
    int id;
    std::string title;
    std::string tag;
    std::string content;
    bool is_favorite = false;
};

#endif