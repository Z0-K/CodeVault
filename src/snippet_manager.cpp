#include "snippet_manager.hpp"

void SnippetManager::add_snippet(){
    Snippet s;
    s.id = nextID++;

    std::cout << "\nEnter snippet title: ";
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
        std::cout<<"----------\n" << s.id 
                << "\n" <<s.title
                << "\n" <<s.tag
                << "\n" <<s.content
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
        outFile <<  s.id
                << "\nTitle: "<< s.title
                << "\nTag: " << s.tag
                << "\nContent:" << s.content
                <<"<<<END>>>\n";
    }

    std::cout<< "Snippets saved to " << filename << "\n";
}

void SnippetManager::load_from_file(const std::string &filename){
    std::ifstream inFile(filename);
    if(!inFile){
        std::cerr << "No snippets file found.\n";
        return;
    }

    std::string line;
    while(std::getline(inFile, line)){
        Snippet s;
        try{
            s.id = std::stoi(line);
        } catch(...){
            std::cerr << "Corrupted ID.\n";
            continue;
        }

        std::getline(inFile, s.title);
        std::getline(inFile, s.tag);

        std::string content;
        while (std::getline(inFile, line) && line != "<<<END>>>") {
            content += line + "\n";
        }
        s.content = content;

        snippets.push_back(s);
        if (s.id >= nextID) {
            nextID = s.id + 1;
        }

    }

    std::cout << "Loaded " << snippets.size() << " snippets from file.\n";
}

void SnippetManager::search_snippets(){
    int option;
    std::string query;

    std::cout << "\nSearch by: \n";
    std::cout << "1. Title\n";
    std::cout << "2. Tag\n";
    std::cout << "3. Content Keyword\n";
    std::cout << "Enter choice: ";
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<< "Enter search query: ";
    std::getline(std::cin, query);

    bool found = false;
    for(const auto &s: snippets){
        bool match = false;
        switch (option){
            case 1:
                match = s.title.find(query) != std::string::npos;
                break;
            case 2:
                match = s.tag.find(query) != std::string::npos;
                break;
            case 3:
                match = s.content.find(query) != std::string::npos;
                break;
            default: 
                std::cout << "Invalid search option.\n";
                return;
        }

        if(match){
            found = true;
            std::cout<<"----------";
            std::cout<<"\nID: "<<s.id<<"\n";
            std::cout<<"Title: "<<s.title<<"\n";
            std::cout<<"Tag: "<<s.tag<<"\n";
            std::cout<<"Content: \n"<<s.content<<"\n";
            std::cout<<"----------\n";
        }
    }

    
    if(!found){
        std::cout<<"No matching snippets found.\n";
    }

}

void SnippetManager::delete_snippet_by_id(){
    if(snippets.empty()){
        std::cout<<"No snippet to delete.\n";
        return;
    }

    int id{};
    std::cout<<"Enter ID of snippet to delete: ";
    std::cin >> id;

    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input. Please enter a number.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"Are you sure you want to delete snippet ID "<<id<<"? (y/n): ";
    char confirm{};
    std::cin>>confirm;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(confirm != 'y' && confirm != 'Y'){
        std::cout<<"Deletion canceled.\n";
        return;
    }

    auto snipp_id = std::find_if(snippets.begin(), snippets.end(), [id](const Snippet &s){
        return s.id == id;
    });

    if(snipp_id != snippets.end()){
        snippets.erase(snipp_id);
        std::cout << "Snippet with ID "<< id <<" deleted.\n";
    } else{
        std::cout<<"No snippet found with ID "<< id << ".\n";
    }
}

void SnippetManager::filter_by_tag(){
    std:: string tag;
    std::cout << "Enter tag to filter by: ";
    std::getline(std::cin, tag);

    bool found = false;
    for(const auto &s: snippets){
        if(s.tag == tag){
            found = true;
            std::cout<<"------------------------------\n";
            std::cout<<"\nID: "<<s.id<<"\n";
            std::cout<<"Title: "<<s.title<<"\n";
            std::cout<<"Tag: "<<s.tag<<"\n";
            std::cout<<"Content: \n"<<s.content<<"\n";
            std::cout<<"------------------------------\n";
        }
    }

    if(!found){
        std::cout<<"No snippets found with tag: "<<tag<<" .\n";
    }
}

void SnippetManager::edit_snippet_by_id(){
    int id;
    std::cout<<"Enter ID of snippet to edit: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto iter = std::find_if(snippets.begin(), snippets.end(), [id](const Snippet &s){
        return s.id == id;
    });

    if(iter == snippets.end()){
        std::cout <<"No snippet found with ID "<<id<<".\n";
        return;
    }

    Snippet &s = *iter;
    std::cout << "\nCurrent Snippet:\n";
    std::cout << "Title: "<<s.title<<"\n";
    std::cout << "Tag: "<<s.tag<<"\n";
    std::cout << "Content: \n"<<s.content<<"\n";

    std::cout << "What do you want to edit? (1 = Title, 2 = Tag, 3 = Content): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch(choice){
        case 1:
        {
            std::string new_title;
            std::cout<<"Enter new title: ";
            std::getline(std::cin, new_title);
            s.title = new_title;
            std::cout <<"Title updated.\n";
            break;
        }
        case 2:
        {
            std::string new_tag;
            std::cout <<"Enter new tag: ";
            std::getline(std::cin, new_tag);
            s.tag = new_tag;
            std::cout << "Tag updated.\n";
            break;
        }
        case 3:
        {
            std::string new_content, line;
            std::cout << "Enter new content (end with empty line): \n";
            while(true)
            {
                std::getline(std::cin, line);
                if(line.empty()) break;
                new_content += line + "\n";
            }

            if(!new_content.empty()){
                s.content = new_content;
                std::cout <<"Content updated.\n";
            } else {
                std::cout << "Content not changed.\n";
            }
            break;
        }
        default: 
            std::cout<<"Invalid choice.\n";
    }



}