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
        std::cout << "\n CodeVault Menu \n";
        std::cout << "1. Add Snippet\n";
        std::cout << "2. List Snippets\n";
        std::cout << "3. Save to File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";

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
                break;
            case 3:
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