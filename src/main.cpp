#include <iostream>
#include <vector>
#include <string>
#include "snippet_manager.hpp"
#include <limits>

int main(){
    SnippetManager manager;
    const std::string filename = "snippets.txt";
    int choice;

    while(true){
        std::cout << "------------------\n";
        std::cout << "!--CodeVault Menu--!\n";
        std::cout << "------------------\n";
        std::cout << "1. Add Snippet\n";
        std::cout << "2. List Snippets\n";
        std::cout << "3. Save to File\n";
        std::cout << "4. Load from File\n";
         std::cout << "------------------\n";
        std::cout << "5. Search Snippets\n";
        std::cout << "6. Filter Snippets by Tag\n";
        std::cout << "7. Edit Snippet by ID\n";
        std::cout << "8. Delete Snippet by ID\n";
        std::cout << "------------------\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: \n";

        if(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice){
            case 1:
            manager.add_snippet();
                break;
            case 2:
            manager.list_snippets();
                break;
            case 3:
            manager.save_to_file(filename);
                break;
            case 4:
            manager.load_from_file(filename);
                break;
            case 5:
            manager.search_snippets();
                break;
            case 6:
            manager.filter_by_tag();
                break;
            case 7:
            manager.edit_snippet_by_id();
            manager.save_to_file(filename);
                break;
            case 8:
            manager.delete_snippet_by_id();
            manager.save_to_file(filename);
                break;
            case 0:
                std::cout << "Exiting CodeVault. GoodBye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    }
    
    return 0;
}