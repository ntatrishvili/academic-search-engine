# Academic Search Engine

The module provides a framework to easily search through the Arxiv academic library. It can be used by students/researchers to find related papers and make their academic life better.
## Table of Contents
- User Manual
    - Description
    - How to Run the Code
- Developer Manual
    - How The Project Is Structured
    - External Libraries Used
    - Class Descriptions
        - The Structure of the Data
        - The Client
    - Possible Future Modifications
    
---
## User Manual

The aim of the project is to give user a chance to search for academic papers in the fields of Computer Science, Economics, Electrical Engineering, Mathematics, Physics, Quantitive Biology, Quantitive Finance and Statistics written in English language

### How to run the code

Disclaimer: The code can be run only on Linux infrastructure.

##### To start the code:
- run the `make install`, then `make` command from linux terminal to build the `main.out` file
- run the `main.out` executeble to start the program

#### To navigate in the program:
- follow the instructions
- type in your search in the terminal
- choose 1 if you want to view the data in the files made in the content folder
- choose 2 if you want to view in the files in the terminal

---
## Developer Manual

### How The Project Is Structured

- The `.cpp` and the `.h` source files are in the `/src ` directory
- The `.o` files will be generated in the `/obj` directory.
- The final binary is the main.out file (also generated) that could be invoked in the root of this project 
- The shell script files generated by Conan are in the `/build` directory.
- The `xml` files generated during the program execution are in the `./content` directory 
---
### External Libraries Used

- The `arxiv API` was used to get the semi-organised data of academic papers
- The `Conan` package manager was used to download the external dependencies (`libcurl` and `rapidXML`)
- The `libcurl` library was used to send `HTTP requests` to the `arxiv API` and get the data
- The `rapidXML` library was used to parse the received data into classes and modify
- The `vector` library was used to store data of the same type in a collection
- The `string` library was used to store and modify strings
---
### Class Descriptions
The `./src` directory includes all the `.h` and `.cpp` files used in the program

#### The Structure of the Data
The data is structured in a way that for a sent request,
- we receive a `feed`, that has an unique id and multiple `entries`,
- each `entry` is a separate academic paper related to our search. It has the following fields:
     - unique `Id`
     - time the paper was last `updated`
     - time the paper was first `published`
     - the `title` of the paper
     - the short `summary` of what the paper contains
     - the list of `authors` of the paper
     - the `link` to the website containing the whole paper
     - the `comment` (optional)
- the `comment` of the entry includes:
    - the number of `pages`,
    - the number of `figures`
    - the number of `tables`
    - the official name of the journal, where paper was published (if so)
- each `author` in the authors list of the entry includes:
    - the full `name` of the author
    - the `affiliation` of the author (workspace)

Each class has a `toString()` method to display the data stored inside in an efficient, human-readable way

#### Client
 The Client class includes:
-  `writeCallBack`- to make the request for curl
- `queryBuilder` - to build the HTTP Get request
-  `savaData` - to store the received data from the request to an `.xml` file,
- `createFeed` - to take the data from the `.xml` file and store it in the classes
- `getData()` - to unite all these methods in a menu-like structure
- `displayData()` - to properly show the data to the user (gives 2 options, terminal or stored in a file)
- `storeFeed()` - to store the data in a file

---
### Possible Future Modifications
The future plan for project is to add a GUI to make the program more visually appealing