// #include <iostream>
// #include <fstream>
// #include <map>

// void func(std::ifstream& fd)
// {
//     std::map<std::string, std::string> m;
//     std::string line;

//     while (std::getline(fd, line))
//     {
//         size_t delimiter = line.find("|");
//         std::string key = line.substr(0, delimiter);
//         std::string value = line.substr(delimiter + 1, line.length());

//         m[key] = value;
//     }

//     std::map<std::string, std::string>::iterator it = m.begin();
//     for(it = m.begin(); it != m.end(); it++)
//         std::cout << it->first << "=" << it->second << '\n';

// }

// int main(int argc, char **argv)
// {
//     std::ifstream file(argv[1]);

//     if (!file.is_open())
//         std::cout << "err!!";
//     else
//         func(file);
// }

#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input_string = "10 20 30 40 50";
    std::istringstream iss(input_string);

    int num;
    while (iss >> num) {
        std::cout << "Read number: " << num << std::endl;
    }

    return 0;
}