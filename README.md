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
-   Add snippets to Favorite category
-   List Favorite snippets
-   Delete snippet by ID

## How to use

1. Compile the program with C++17+ compiler:

    ```
    g++ src/main.cpp src/snippet_manager.cpp -o codevault

    ```

2. Run the application:

    ```
    ./codevault
    ```

3. Use the menu to interact.

## File format(snippets.txt)

Snippets are stored in a plain-text file like this:

    ```
    ID: 1
    Title: HTML
    Tag: html
    Favorite: 0
    Content:
    <h1> HTML </h1>
    ```

Each snippet includes:

1. An auto-incemented numeric ID
2. Title and tag on separate lines
3. Code content(multi-line)

### Licence

MIT License — feel free to use and modify.
