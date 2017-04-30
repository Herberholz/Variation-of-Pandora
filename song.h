//Cody Herberholz, CS202, Program #3
//song.h
//This file contains the String, Song, L_node, G_node, and Vertex classes. There 
//isn't much Inheretance within this program. Most the classses classify as a 
//"has a" relationship. The String class takes in Character arrays and simplifies
//the use of them by using operator overloading to conduct different operations 
//to manage them. The L_node, G_node, and Vertex are pathways between the data
//structures and Song itself.



#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;



//Used to Declare classes at start in order to use certain instance of them
class List;
class G_node;



//This is my String Class. The purpose of the String class is to make the use of 
//Character arrays easier to manage. You are still using character arrays but
//underneath the guise of the String class which has several overloaded operators
//as tools to use at your disposal.
class String
{
    public:
        String();
        ~String();
        String(char *);
        String(const String &);
        int get_size() const; //returns length of string
        friend bool operator == (const String &, char *);
        friend bool operator == (char *, const String &);
        friend bool operator == (const String &, const String &);
        friend ostream & operator << (ostream &, const String &);
        friend ifstream & operator >> (ifstream &, String &); //overloaded for file Input
        friend istream & operator >> (istream &, String &); //overloaded for iostream input
        String & operator += (const String &);
        String & operator += (char *);
        String & operator = (const String &);
        String & operator = (char *);
        char & operator [] (int) const; //returns an element of a character array

    protected:
        char * string; //character array holding input 
        int length; //length of string
};



//This class is meant to manage the Songs themselves. You are given the tools to 
//do I/O, use = , compare, rate the song, insert a song, hash the artist, remove
//a song, and return a genre.
class Song
{
    public:
        Song();
        ~Song();
        friend ostream & operator << (ostream &, const Song &);
        friend ifstream & operator >> (ifstream &, Song &); //overloaded for file input
        Song & operator = (Song &);
        Song(const Song &);
        Song *& go_next();
        void rate(List * playlist);
        void insert(ifstream & read, Song & to_add);
        int hash_artist();
        String & get_genre() const;

    protected:
        int rating; //keeps track of if song is liked or displiked
        String name; //name of song
        String artist; 
        String * genre; //holds more than one genre
        Song * next;
};



//This class is a node connected to the list class. It holds a song pointer 
//which points to a song object in the hash table
class L_node
{
    public:
        L_node();
        L_node *& go_next();
        

    protected:
        Song * tune; //points to song in hash table
        L_node * next;
};



//This class provides a way to fill out a graph correctly. It loads the genres,
//compares, and inserts.
class Vertex
{
    public: 
        Vertex();
        ~Vertex();
        void load_genre(ifstream &);
        bool compare(Song *);
        void insert(Song *, Vertex * alist, int & index);
        String & get_genre();

    protected:
        G_node * head;
        String genre;
};



//This is the node for the graph. It helps link a vertex element with another vertex
//element. It can set adjacent pointer and then insert a song.
class G_node
{
    public:
        G_node();
        G_node *& go_next();
        void set_adjacent(Vertex * alist, int & index);
        void insert_song(Song * to_add);

    protected:
        Song * tune;
        Vertex * adjacent;
        G_node * next;
};
