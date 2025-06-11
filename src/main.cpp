#include <iostream>
#include <vector>
#include <string>
#include <snippet_utils.hpp>

int main(){
    std::vector<std::string> snippets;
    const std::string filename = "snippets.txt";
    int choice;

    while(true){
        std::cout << "\n CodeVault Menu \n";
        std::cout << "1. Add Snippet\n";
        std::cout << "2. List Snippets\n";
        std::cout << "3. Save to File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                std::cout << "Exiting CodeVault.";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    }
    
    return 0;
}