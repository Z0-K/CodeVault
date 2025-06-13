#include "snippet_utils.hpp"
#include <algorithm>

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

    bool is_white_space_only = std::all_of(snippet.begin(), snippet.end(), [](char c){
        return std::isspace(static_cast<unsigned char>(c));
    });

    if(snippet.empty() || is_white_space_only){
        std::cout << "Empty or whitespace-only snippet. Not added.\n";
        return;
    }

    snippets.push_back(snippet);
    std::cout <<"Snippet added.\n";
}

void listSnippets(const std::vector<std::string>& snippets){
    if(snippets.empty()){
        std::cout << "No snippets available.\n";
        return;
    }

    std::cout << "\n --Snippets --\n";
    for(size_t i=0; i < snippets.size(); i++){
        std::cout << "[" << i + 1 << "]\n" << snippets[i] << "\n";
    }
}