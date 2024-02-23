#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::ifstream in(argv[1]);
        std::string outfile_name = std::string(argv[1]).append(".replace");
        std::ofstream out(outfile_name);
        std::string s;
        std::string string_replace;

        if (in.is_open())
        {
            while (in)
            {
                getline(in, s);
                string_replace.append(s);
                // out << s;
                if (in.eof())
                    break ;
                // out << "\n";
                string_replace.append("\n");
            }
            int find_index = 0;
            std::string new_string;
            int i = 0;
            std::string argv_2 = argv[2];
            std::string argv_3 = argv[3];
            while (find_index < string_replace.length())
            {
                int pos = string_replace.find(argv_2, find_index);
                if (pos != std::string::npos)
                {
                    new_string += string_replace.substr(find_index, pos - find_index);
                    new_string += argv_3;
                    find_index = pos + argv_2.length();
                }
                else
                {
                    new_string += string_replace.substr(find_index);
                    break ;
                }
            }
            out << new_string;
        }
        else
            std::cout << "ifstream error!" << '\n';
    }
    else
        std::cout << "argument error!" << '\n';
}   