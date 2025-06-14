#include "snippet_manager.hpp"
#include <algorithm>


void SnippetManager::add_snippet(){
    Snippet s;
    s.id = nextID++;

    std::cout << "Enter snippet title: ";
    std::getline(std::cin, s.title);

    std::cout << "Enter snippet tag: ";
    std::getline(std::cin, s.tag);

    std::cout<<"Enter you code snippet: (end with empty line)\n";
    std::string line;
    s.content = "";

    while(true){
        std::getline(std::cin, line);
        if (line.empty()) break;
        s.content += line + "\n";
    }

    bool is_white_space_only = std::all_of(s.content.begin(), s.content.end(), [](char c){
        return std::isspace(static_cast<unsigned char>(c));
    });

    if(s.content.empty() || is_white_space_only){
        std::cout << "Empty or whitespace-only snippet. Not added.\n";
        return;
    }

    snippets.push_back(s);
    std::cout <<"Snippet added.\n";
}

void SnippetManager::list_snippets(){
    for(const auto &s : snippets){
        std::cout << "\nID: " <<s.id 
                << "\nTitle: " <<s.title
                << "\nTag: " <<s.tag
                << "\nContent:\n" <<s.content
                <<"----------\n";
    }
}

void SnippetManager::save_to_file(const std::string &filename){
    std::ofstream outFile(filename);
    if(!outFile){
        std::cerr << "Error: Unable to opening file: " << filename << "\n";
        return;
    }

    for(const auto& s: snippets){
        outFile << "\nID: "<<  s.id
                << "\nTitle: "<< s.title
                << "\nTag: " << s.tag
                << "\nContent: " << s.content
                << "\n<<<END>>>";
    }

    std::cout<< "Snippets saved to " << filename << "\n";
}

