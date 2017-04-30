//Cody Herberholz, CS202, Program #3
//song.cpp
//This file contains the implementation of the String, Song, L_node, G_node, and 
//Vertex classes. The String Class contains mainly overloaded operators to help
//ease the use of character arrays. Song handles the Song object itself and then 
//the L_node, G_node, and vertex help set up the Hash, Graph, and CLL data 
//structures.



#include "song.h"



//Constructor of the String Class that initializes its data members
String::String(): string(0), length(0) {}



//Destructor that deallocates String's data members
String::~String()
{
    delete [] string;
    string = NULL;
}



//Constructor that takes in a char
String::String(char *) 
{
    string = NULL;
    length = 0;
}



//Copy Constructor
String::String(const String & source)
{
    if(&source == this) return;

    if(string)
        delete [] string;

    length = source.length;
    string = new char[length + 1];
    strcpy(string, source.string);
}



//Task:   Provides use of length outside of its own class
//Input:  None
//Output: Returns length
int String::get_size() const
{
    return length;
}



//Task:   Compares a String and char
//Input:  String and char
//Output: True if match and false if not
bool operator == (const String & str, char * check)
{
    if(strcmp(str.string, check) == 0)
        return true;
    
    return false;
}



//Task:   Compares a char and String
//Input:  char and String
//Output: True if match and false if not
bool operator == (char * check, const String & str)
{
    if(strcmp(check, str.string) == 0)
        return true;
    
    return false;
}



//Task:    Compares a String and String
//Input:   String and String
//Output:  True if match and false if not
bool operator == (const String & str, const String & str2)
{
    if(strcmp(str.string, str2.string) == 0)
        return true;

    return false;
}



//Task:   Displays a String
//Input:  Ostream and String
//Output: Returns the ostream variable
ostream & operator << (ostream & out, const String & source)
{
    out << source.string << endl;
    return out;
}



//Task:   Reads in from a file and stores the data in String
//Input:  Ifstream and String
//Output: Returns the ifstream variable
ifstream & operator >> (ifstream & read, String & source)
{
    if(source.string)
        delete [] source.string;

    char temp[80] = {'\0'};
    read.get(temp, 80,';');
    read.ignore(80,';');
    source.length = strlen(temp);
    source.string = new char[source.length + 1];
    strcpy(source.string, temp);

    return read;
}



//Task:   Reads in from the istream and stores the data in a String
//Input:  Ostream and String
//Output: Returns the istream variable
istream & operator >> (istream & read, String & source)
{
    if(source.string)
        delete [] source.string;

    char temp[80] = {'\0'};
    read.get(temp, 80,'\n');
    cout << "Are you sure?" << endl;
    read.ignore(80,'\n');
    source.length = strlen(temp);
    source.string = new char[source.length + 1];
    strcpy(source.string, temp);

    return read;
}



//Task:   Concatinates the string to the current string in the object
//Input:  String
//Output: Outputs the string with a string added to the original
String & String::operator += (const String & source)
{
    this->length += source.length;
    char * temp = new char[this->length + 1];
    strcpy(temp, this->string);
    strcat(temp, source.string);
    this->string = temp;

    return *this;
}



//Task:   Concatinates the char to the current string in the object
//Input:  Char
//Output: Outputs the String with the char added onto the original
String & String::operator += (char * add_to)
{
    this->length += strlen(add_to);
    char * temp = new char[this->length + 1];
    strcpy(temp, this->string);
    strcat(temp, add_to);
    this->string = temp;

    return *this;
}



//Task:   Checks for self assignment and then sets current string to equal incoming string
//Input:  String
//Output: Returns the current string object
String & String::operator = (const String & source)
{
    if(&source == this) return *this;
    
    if(this->string)
        delete [] string;

    this->length = source.length;
    this->string = new char[length + 1];
    strcpy(this->string, source.string);

    return *this;
}



//Task:   Checks for self assignment via strcmp and then sets the string to take
//        on to equal the incoming char
//Input:  Char
//Output: Returns the current String object
String & String::operator = (char * to_add)
{
    if(this->string)   
        if(strcmp(to_add, this->string) == 0) return *this;

    if(this->string)
        delete [] string;
    
    this->length = strlen(to_add);
    this->string = new char[length + 1];
    strcpy(this->string, to_add);

    return *this;
}



//Task:   Takes an int and returns what resides in that element of the char string
//Input:  Int
//Output: Returns what is in the element of the char string
char & String::operator [] (int index) const
{
    return string[index];
}



//Constructor of the Song class that initializes its data members and creates a
//String array of two genres
Song::Song(): rating(0), name(0), artist(0), next(0)
{
    genre = new String[2];
}



//Destructor that deallocates Song's data members
Song::~Song()
{
    delete [] genre;
    genre = NULL;
}



//Task:   Outputs the name, artist, and genres of a song
//Input:  Ostream and Song
//Output: Ostream variable
ostream & operator << (ostream & out, const Song & source)
{
    out << "\nSong: " << source.name << endl;
    out << "Artist: " << source.artist << endl;
    out << "Genre: " << source.genre[0] << ',' << source.genre[1] << endl;
    return out;
} 



//Task:   Reads in data from a file into a song
//Input:  ifstream and Song 
//Output: Returns ifstream variable
ifstream & operator >> (ifstream & read, Song & dest)
{
    int i = 0;
    char new_song[50] = {'\0'};
    char new_artist[50] = {'\0'};
    char new_genre[50] = {'\0'};

    read.get(new_song, 50, ';');
    read.ignore(50, ';');
    read.get(new_artist, 50, ';');
    read.ignore(50, ';');
    while(read.peek() != '\n' && read.peek() != EOF)
    {

        read.get(new_genre, 50, ';');
        read.ignore(50,';');
        dest.genre[i] = new_genre;
        ++i;
    }

    if(read.peek() != EOF)
    {
        dest.name = new_song;
        dest.artist = new_artist;
    }

    return read;
}



//Task:   Sets the current Song object to equal a new Song
//Input:  Song
//Output: Current Song object
Song & Song::operator = (Song & source)
{
    if(&source == this) return *this;

    this->rating = source.rating;
    this->name = source.name;
    this->artist = source.artist;
    for(int i = 0; i < 2; ++i)
        this->genre[i] = source.genre[i];
    this->next = source.next;
    return *this;
}




//Copy Constructor
Song::Song(const Song & source)
{
    if(&source == this) return;

    rating = source.rating;
    name = source.name;
    artist = source.artist;
    for(int i = 0; i < 2; ++i)
        genre[i] = source.genre[i];
    next = source.next;

}



//Task:   Returns next to other class
//Input:  None
//Output: Next
Song *& Song::go_next()
{
    return next;
}



//Task:   Allows user to choose whether they like a song or not
//Input:  Pointer to the CLL
//Output: Displays Like/unlike display
void Song::rate(List * playlist)
{
    int num = 0;

    cout << " _____________" << endl;
    cout << "|1)Like   :)  |" << endl;
    cout << "|2)Unlike :(  |" << endl;
    cout << "|-------------|" << endl;

    cout << "Enter Selection: " << endl;
    cin >> num;
    cin.ignore(100, '\n');

    if(1 == num)
    {
        rating = 1;
//        playlist->insert();
    }
}



//Task:   Read in from file into the object of Song coming from Client and then 
//        set the currently empty Song to equal that Song in order to add to the 
//        hash table
//Input:  Ifstream and Song
//Output: Two filled objects
void Song::insert(ifstream & read, Song & to_add)
{
        read >> to_add;
        *this = to_add;
}



//Task:   Works as the hash function to make a random number to mod with the hash 
//        size by adding together all the individual character values of artist 
//        using the overloaded subscript operator
//Input:  None
//Output: Returns randum number to mod for hashing
int Song::hash_artist()
{
    int index = 0;
    int len = artist.get_size();

    for(int i = 0; i < len; ++i)
        index += artist[i];    

    cout << artist; //creates list for user at beginning to choose artist from

    return index;
}



//Task:   Returns first element of genre to help make the Vertex Array
//Input:  None
//Output: Genre
String & Song::get_genre() const
{
    
    return genre[0];
}



//Constructor of L_node which initializes its data members
L_node::L_node(): tune(0), next(0) {}



//Task:   Returns next for other classes to have access
//Input:  None
//Output: Next
L_node *& L_node::go_next() 
{
    return next;
}



//Constructor that initializes all its data members
Vertex::Vertex(): head(0), genre(0)  {}



//Destructor that deallocates all of its data members by deleting any LLL branching off
Vertex::~Vertex()
{
    if(!head) return;

    while(head)
    {
        G_node * temp = head->go_next();
        delete head;
        head = temp;
    }
}



//Task:   Reads through the file from the beginning and puts the genre I need 
//        within genre and then the rest in the garbage string
//Input:  Ifstream
//Output: The Genre for vertex
void Vertex::load_genre(ifstream & read)
{
    String garbage;

    for(int i = 0; i < 4; ++i)
    {
        if(i == 2)
            read >> genre;
        else
            read >> garbage;
    }
}



//Task:   Compares genre of current object with incoming genre
//Input:  Song
//Output: Returns true if they match and false if not
bool Vertex::compare(Song * match)
{
    String temp;
    temp = match->get_genre();

    if(genre == temp)
        return true;

    return false;
}



//Task:   Inserts song and calls function that sets adjacent pointer to vertex
//Input:  Song, pointer to vertex, and index
//Output: Sets pointers to create graph
void Vertex::insert(Song * to_add, Vertex * alist, int & index)
{
    G_node * current = NULL;

    current = new G_node;
    current->set_adjacent(alist, index);
    current->go_next() = head;
    head = current;
    current->insert_song(to_add);
}



//Task:   Returns genre for other classes to use
//Input:  None
//Output: Genre
String & Vertex::get_genre()
{
    return genre;
}



//Constructor of G_node that initializes all of its data members
G_node::G_node(): tune(0), adjacent(0), next(0)  {}



//Task:   Returns next so other classes can have access
//Input:  None
//Output: Next
G_node *& G_node::go_next()
{
    return next;
}



//Task:   Sets adjacent to equal the address of a specific vertex element
//Input:  Vertex pointer and index
//Output: None
void G_node::set_adjacent(Vertex * alist, int & index)
{
    adjacent = &alist[index];
}



//Task:   Sets current song pointer to point to the incoming song pointer
//Input:  Song
//Output: Sets a pointer to point to another pointer
void G_node::insert_song(Song * to_add) 
{
    tune = to_add;

}

