# CodeVault

**CodeVault** is a terminal based CLI snippet manager written in C++.
Lightweight, offline alternative to GitHub Gists - designed to quickly store, view and manage code snippets locally.

## Features

-   Add a code snippet with title, tag and content
-   Save snippets to a local file (snippet.txt)
-   Load snippets from a file
-   List all stored snippets
-   Search snippets by title, tag or content keyword
-   Filter snippets by tag
-   Edit snippet by ID
-   Delete snippet by ID

## How to use

    1. Compile the program with C++17+ compiler:

    ```
    g++ -std=c++17 -o codevault main.cpp snippet_manager.cpp

    ```

    2. Run the application:

    ```
    ./codevault
    ```

    3. Use the menu to interact.
