//Cody Herberholz, CS202, Program #3
//client.h
//This file contains the Client, List, Graph, and Hash classes. This makes up the 
//three data structures and main class that interacts with all three data structures.
//The Hash Table contains objects of each song being passed into the data structure.
//Once a Song is passed to the Hash table a pointer is set to it and similataniously 
//passed to the graph so it contains a pointer to the song objects in the Hash.
//Then when the user goes through songs they will have the opportunity to like
//or dislike a song. When a song is liked it will be added to the List class.



#include "song.h"



//Declares classes so they can be used before created
class List;
class Graph;
class Hash;



//This class acts as the main interface with the user and manages the flow of the
//program. The Constructor/Destructor initialize and deallocate the data within
//the Client class. The class acts a medium between the three data structures and 
//loads in the required data from an external data file.
class Client
{
    public:
        Client(); //Constructor
        ~Client(); //Destructor
        void load_songs(); //Loads songs in from external file
        void operation(); //runs the main program interface
        int main_prompt(); //Main menu for the user
        int search_prompt(); //Menu that allows user to choose artist/genre

    protected:
        List * cll; //Pointer to CLL
        Graph * graph; //Pointer to Graph
        Hash * hash; //Pointer to Hash
};



//This class holds the user's station with all their favorites which are add from
//the hash or graph when a song is liked by the user. It will insert, remove, 
//remove all, retrieve, and display songs within the CLL. The user will have
//the opportunity to browse the station and if they dislike a song it will 
//be removed from the CLL.
class List
{
    public:
        List(); //Constructor
        ~List(); //Destructor
        void insert(); //Inserts L_node into CLL
        int remove(); //Removes L_node from CLL
        int remove_all(L_node *& rear); //Removes all L_nodes in CLL
        int retrieve(); //Retrieves L_node from CLL
        void display() const; //Displays songs from L_node

    protected:
        L_node * rear; //points to rear of CLL

};



//This class is a graph data structure ADT that links together songs of different
//genres to immerse the user in a radio station of different varieties of songs
//based off of genre relationships. This class will seperate the genres and find
//their locations within the vertex array in order to link them up. This class
//will also display songs in an order based off these relationships.
class Graph
{
    public: 
        Graph(int gsize=10); //Creates graph with 10 genres
        ~Graph(); //Destructor
        void load_songs(Song * to_attach); //Loads songs into Graph
        int find_location(Song * to_attach); //Finds index of song genres
        void display_vertices(); //Displays songs in a genre
        void display_adjacent() const; //Displays songs based off genre relationships

    protected:
        Vertex * alist; //Pointer that is set to Vertex
        int list_size; //Size of Graph
};



//This Class is a Hash Table data structure ADT that takes in the objects of songs
//and hashes them into an index based off of the moded total of the value of each
//character value. This class loads in songs via external data file and retrieves
//data by hashing artists provided by the user.
class Hash
{
    public:
        Hash(int hsize=20); //Creates hash table of size 20
        ~Hash(); //Destructor
        int load_songs(ifstream & read, Song & to_add); //Loads songs
        int retrieve(List * playlist); //Retrieves a Song

    protected:
        Song ** hash_table; //Pointer to an array of pointers towards chained songs
        int hash_size; //Size of Hash Table
};

