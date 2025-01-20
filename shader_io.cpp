#include <iostream>
#include <fstream>

std::string LoadShaderAsString(const std::string &filename){    
    std::string result = "";
    std::string line = "";
    std::ifstream file(filename);

    if (file.is_open())
    {
        while (std::getline(file,line))
        {
            result += line + '\n';
        }
    }
        
    return result;
}