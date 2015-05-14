//Cody Herberholz, CS202, Program #3
//song.h


#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;



class G_node;



//
class String
{
    public:
        String();
        ~String();
        String(char *);
        String(const String &);
        friend bool operator != (const String &, char *);
        friend bool operator != (char *, const String &);
        friend bool operator != (const String &, const String &);
        friend bool operator == (const String &, char *);
        friend bool operator == (char *, const String &);
        friend bool operator == (const String &, const String &);
        friend String operator + (const String &, char *);
        friend String operator + (char *, const String &);
        friend String operator + (const String &, const String &);
        friend ostream & operator << (ostream &, const String &);
        friend istream & operator >> (istream &, String &);
        String & operator += (const String &);
        String & operator += (char *);
        String & operator = (const String &);
        

    protected:
        char * string;
        int length;
};



//
class Song: public String
{
    public:
        Song();
        ~Song();
        Song(const Song &);
        Song *& go_next();
        int compare();
        void rate();
        int insert();
        int remove();

    protected:
        int rating; //keeps track of if song is liked or displiked
        String name;
        String artist;
        String * genre;
        Song * next;
};



//
class Vertex
{
    public: 
        Vertex();
        ~Vertex();
        void set_null();

    protected:
        G_node * head;
        String genre;
};



//
class G_node: public Song
{
    public:
        G_node();
        G_node *& go_next();

    protected:
        Vertex * adjacent;
        G_node * next;
};
