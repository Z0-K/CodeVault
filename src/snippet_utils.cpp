#include "snippet_utils.hpp"

void addSnippet(std::vector<std::string>& snippets){
    std::string snippet;
    std::cout << "Enter your code snippet: \n";
    std::cout << "!END WITH AN EMPTY LINE! \n";
    std::string line;
    snippet = "";

    while(true){
        std::getline(std::cin, line);
        if (line.empty()) break;
        snippet += line + "\n";
    }

    snippets.push_back(snippet);
    std::cout <<"Snippet added.\n";
}