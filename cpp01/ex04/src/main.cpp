
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, char **argv)
{
    if (argc != 4)
        return (std::cout << "Please add: file name, string 1 and string 2" << std::endl, 1);
    std::string file_name = argv[1];
    std::string str1 = argv[2];
    if (str1.empty())
        return(std::cerr << "Error: string 1 cannot be empty" << std::endl, 1);
    std::string str2 = argv[3];
    std::ifstream infile(file_name, std::ios::in);
    if (!infile)
        return (std::cerr << "Error: file doesn't exist" << std::endl, 1);
    std::stringstream buffer;

    buffer << infile.rdbuf(); 
    infile.close();

    std::string content = buffer.str();

    int content_len = content.length();
    int str1_len = str1.length();
    int str2_len = str2.length();
    std::cout << "---THIS IS THE FILE BEFORE----" << std::endl;
    std::cout << content << std::endl;
    int i = 0;
    while (i < content_len)
    {
        if (content.compare(i, str1_len, str1, 0, str1_len) == 0)
        {
            content.erase(i, str1_len);
            content_len = content.length();
            content.insert(i, str2);
            i += str2_len;
        }
        else
            i++;
    }
    std::cout << "---THIS IS THE FILE AFTER----" << std::endl;
    std::cout << content << std::endl;
    std::ofstream outfile(file_name + ".replace");
    outfile << content;
    outfile.close();

    return 0;
}