//Cody Herberholz, CS202, Program #3
//song.cpp



#include "song.h"



//
String::String(): string(0), length(0) {}



//
String::~String()
{
    delete [] string;
}



//
String::String(char *) {}



//
String::String(const String &)
{

}



//
bool operator != (const String & str, char * check)
{
    return (str.string != check);
}



//
bool operator != (char * check, const String & str)
{

    return (check != str.string);
}



//
bool operator != (const String & str, const String & str2)
{

    return (str.string != str2.string);
}



//
bool operator == (const String & str, char * check)
{

    return (str.string == check);
}



//
bool operator == (char * check, const String & str)
{

    return (check == str.string);
}



//
bool operator == (const String & str, const String & str2)
{

    return (str.string == str2.string);
}



//
String operator + (const String & str, char * check)
{
    char * temp = new char[str.length+strlen(check)+1];
    strcpy(temp,str.string);
    strcat(temp, check);

    return String(temp);
}



//
String operator + (char * check, const String & str)
{
    char * temp = new char[str.length + strlen(check) + 1];
    strcpy(temp, str.string);
    strcat(temp, check);

    return String(temp);   
}



//
String operator + (const String & str, const String & str2)
{
    char * temp = new char[str.length + str2.length + 1];
    strcpy(temp, str.string);
    strcat(temp, str2.string);
    return String(temp);
}



//
ostream & operator << (ostream & out, const String & source)
{
    out << source.string << endl;
    return out;
}



//
istream & operator >> (istream & in, String & source)
{
    char temp[80] = {'\0'};
    in.get(temp, 80,'\n');
    source.length = strlen(temp);
    source.string = new char[source.length + 1];
    strcpy(source.string, temp);

    return in;
}



//
String & String::operator += (const String & source)
{
    length += source.length;
    char * temp = new char[length + source.length + 1];
    strcpy(temp, string);
    strcat(temp, source.string);
    string = temp;

    return *this;
}



//
String & String::operator += (char * add_to)
{
    length += strlen(add_to);
    char * temp = new char[length + strlen(add_to) + 1];
    strcpy(temp, string);
    strcat(temp, add_to);
    string = temp;

    return *this;
}



//
String & String::operator = (const String & source)
{
    if(&source == this) return *this;

    if(string)
        delete [] string;
    
    length = source.length;
    string = new char[length + 1];
    strcpy(string, source.string);

    return *this;
}



//
Song::Song(): rating(0), name(0), artist(0), genre(0), next(0) {}



//
Song::~Song()
{
    
//    delete genre;
//    genre = NULL;
}



//
Song::Song(const Song & source)
{


}



//
Song *& Song::go_next()
{
    return next;
}



//
int Song::compare()
{

    return 0;
}



//
void Song::rate()
{

}


//
int Song::insert()
{

    return 0;
}



//
int Song::remove()
{

    return 0;
}



//
G_node::G_node(): adjacent(0), next(0)  {}



//
G_node *& G_node::go_next()
{
    return next;
}



//
Vertex::Vertex(): head(0), genre(0)  {}



//
Vertex::~Vertex()
{

}



//
void Vertex::set_null()
{
    head = NULL;
    genre = NULL;
}
