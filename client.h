//Cody Herberholz, CS202, Program #3
//client.h



#include "song.h"



class List;
class Graph;
class Hash;



//
class Client//: public String
{
    public:
        Client();
        ~Client();
        void operation();
        int prompt();

    protected:
        List * cll;
        Graph * graph;
        Hash * hash;
};



//
class List
{
    public:
        List();
        ~List();
        int insert();
        int remove();
        int remove_all();
        int retrieve();
        void display() const;

    protected:
        Song * rear;

};



//
class Graph
{
    public: 
        Graph(int gsize=10);
        ~Graph();
        int insert_edge(char * current_vertex, char * to_attach);
        int find_location(char * key_value);
        void display_vertices() const;
        void display_adjacent() const;

    protected:
        Vertex * alist;
        int list_size;
};



//
class Hash
{
    public:
        Hash(int hsize=20);
        ~Hash();
        int retrieve(char * search_song);

    protected:
        Song ** hash_table;
        int hash_size;
};

