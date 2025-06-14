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

// void listSnippets(const std::vector<std::string>& snippets){
//     if(snippets.empty()){
//         std::cout << "No snippets available.\n";
//         return;
//     }

//     std::cout << "\n --Snippets --\n";
//     for(size_t i=0; i < snippets.size(); i++){
//         std::cout << "[" << i + 1 << "]\n" << snippets[i] << "\n";
//     }
// }

// void saveSnippetsToFile(const std::vector<std::string>& snippets, const std::string& filename){
//     std::ofstream outFile(filename);
//     if(!outFile){
//         std::cerr << "Err opening file: " << filename << "\n";
//         return;
//     }

//     for(const auto& snippet: snippets){
//         outFile << "--- SNIPPET ---\n";
//         outFile << snippet << "\n";
//     }

//     outFile.close();
//     std::cout<< "Snippets saved to " << filename << "\n";
// }

