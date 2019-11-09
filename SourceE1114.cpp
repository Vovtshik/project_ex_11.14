#include "../std_lib_facilities.h"

void in_file_text(string& name_file, vector<string>&vs);            // The function of reading text from file to vector.
void number_characters_each_category(const string&s, int& al, int& sp, int& di);
void out_file_text(vector<string>& vs, string& name_file);          // The function of writing text from a vector to a file.

int main()
{
    vector<string>vs;
    cout << "Enter file name to read text:\n";
    string name;
    cin >> name;
    in_file_text(name, vs);
    int alpha = 0;
    int space = 0;
    int digit = 0;
    

    cout << "Enter a file name for recording converted text:\n";
    cin >> name;
    out_file_text(vsr, name);
    return 0;
}

void in_file_text(string& name_file, vector<string>&vs)
{
    ifstream ist(name_file);
    if(!ist) error("Unable to open input file ", name_file);
    ist.exceptions(ist.exceptions() | ios_base::badbit);
    string new_line = "\n";
    for(string temp; getline(ist, temp);)
    {
        {
            stringstream ss(temp);
            for(string s; ss >> s;)
            {
                vs.push_back(s);
            }
        }
        if(!ist.eof())
            vs.push_back(new_line);
    }
}

void number_characters_each_category( const string&s, int& al, int& sp, int& di)
{
    for(char ch: s)
    {
        if(isspace(ch))
            ++sp;
        else if(isalpha(ch))
            ++al;
        else if(isdigit(ch))
            ++di;
        else
            continue;
    }
}


void out_file_text(vector<string>& vs, string& name_file)
{
    ofstream ost{name_file};
   if (!ost) error("Unable to open output file ", name_file);
   for(string x: vs)
   {
        if(x != "\n")
            ost << x << " ";
        else
        {
            ost << x;
        }
   }
}