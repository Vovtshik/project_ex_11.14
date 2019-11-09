#include "../std_lib_facilities.h"

void in_file_text(string& name_file, vector<string>&vs);                                              // The function of reading text from file to vector.
void number_characters_each_category(const string&s, int& al, int& sp, int& di);                      // The function for counting the characters of each category in a string and passing the results by reference in arguments.
void out_file_string(const string& nout, string& nin, const int& al, const int& sp, const int& di);   // Function for outputting to the file the results of counting characters of each category:

int main()
{
    vector<string>vs;
    cout << "Enter file name to read text:\n";
    string name_in;
    cin >> name_in;
    in_file_text(name_in, vs);
    int alpha = 0;
    int space = 0;
    int digit = 0;
    for(string s: vs)
    {
        number_characters_each_category(s, alpha, space, digit);
    }
    cout << "Enter a file name to record the character counts for each category:\n";
    string name_out;
    cin >> name_out;
    out_file_string(name_out, name_in, alpha, space, digit);
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
        /* {
            stringstream ss(temp);
            for(string s; ss >> s;)
            {
                vs.push_back(s);
            }
        } */
        {
            stringstream ss(temp);
            string str_t;
            for(char ch; ss.get(ch);)
            {
                if(isalpha(ch))
                {
                    
                    if(isalpha(ss.peek()))
                        str_t += ch;
                    else
                    {
                        str_t += ch;
                        vs.push_back(str_t);
                        str_t.clear();
                    }
                }
                else
                {
                    str_t = ch;
                    vs.push_back(str_t);
                }
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


void out_file_string(const string& nout, string& nin, const int& al, const int& sp, const int& di)
{
    ofstream ost{nout};
    if (!ost) error("Unable to open output file ", nout);
    ost << "In the text from the " << nin << " file, the number of characters in the categories: letters - " << al << "; whitespace characters - " << sp << "; decimal digits - " << di << ".\n";
}