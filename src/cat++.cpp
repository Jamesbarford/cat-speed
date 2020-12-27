#include <string>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    void read_file(char *path);
    try
    {
        if (argc == 1)
            std::cout << argv[0] << std::endl;
        else
            while (--argc > 0)
                read_file(*++argv);
    }
    catch (...)
    {
        std::cerr << "error writing stdout" << std::endl;
        exit(1);
    }

    exit(0);
}

void read_file(char *path)
{
    std::string line;
    std::ifstream infile(path);
    while (std::getline(infile, line))
        std::cout << line << std::endl;
    infile.close();
}
