#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
using namespace std;

//constants
const string INPUT_FILE = "input.txt";
const int EXPECTED_RECORDS = 4;

//movie class defination
class Movie
{
private:
    string title;
    int yearReleased;
    string screenWriter;
public 
    Movie();
    Movie(string, t, int y, string s);

    void setTitle(const string& t);
    void setYearReleased(int y);
    void setScreenWriter(const string& s);

    string getTitle() const;
    int getYearReleased() const;
    string getScreenWriter() const;

    void print() const;
};

//function prototype
void readMovies(vector<Movie>& movies);

int main()
{
    vector<Movie> movies;

    readMovies(movies);

    cout << "\n------------ Movie List ------------\n\n ";

    for (size_t i = 0; i < movies.size(); i++)
    {
        movies[i].print();
        cout << endl;
    }
    return 0;
}

//default constructor 
Movie::Movie()
{
    title = "";
    yearReleased = 0;
    screenWriter = "";
} 

//overloaded constructor 
Movie::Movie(string t, int y, string s)
{
    setTitle(t);
    setYearReleased(y);
    setScreenWriter(s);
}

//setters
void Movie::setTitle(const string& t)
{ 
    title = t;
} 

void Movie::setYearReleased(int y)
{
    if (y > 1800 && y < 3000)
        yearReleased = y;
    else 
    {
        cout << "Error: Invalid year. Setting to 0.\n";
        yearReleased = 0;
    }
} 

void Movie::setScreenWriter(const string& s)
{
    screenWriter = s;
}

//Getters
string Movie::getTitle() const
{
    return title;
}

int Movie::getYearReleased() const
{
    return yearReleased;
}

string Movie::getScreenWriter() const
{
    return screenWriter;
}

//print()
void Movie::print() const
{
    cout << "Movie: " << title << endl;
    cout << "     Year released: " << yearReleased << endl;
    cout << "     Screenwriter: " << screenWriter << endl;
}

//readMovies() reads movie data from the file into the vector
void readMovies(vector<Movie>& movies)
{
    ifstream fin(INPUT_FILE);

    if (!fin)
    {
        cout << "Error: Could not open " << INPUT_FILE << endl;
        return;
    }
    string title;
    string yearString;
    string writer;

    while (getline(fin, title))
    {
        getline(fin, yearString);
        getline(fin, writer);

        int year = stoi(yearString);

        Movie temp;
        temp.setTitle(title);
        temp.setYearReleased(year);
        temp.setScreenWriter(writer);

        movies.push_back(temp);
    }
    fin.close();
}