#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <map>

#include "shader_io.h"


bool LoadShaderAsString(std::string &shaderSource, const std::string &filename) {
    std::ifstream sourceFile(filename, std::ios::in | std::ios::binary);
    if (!sourceFile.is_open()) {
        std::cerr << "ERROR::SHADER::FILE_NOT_FOUND: " << filename << std::endl;
        return false;
    }

    std::stringstream sourceStream;
    sourceStream << sourceFile.rdbuf();
    shaderSource = sourceStream.str();
    return true;
}

bool loadShadersFromFolder(const std::string& folderPath, std::map<std::string, std::string>& shaderMap) {
    try {
        for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {
                // Get the file name (without extension) as the key
                std::string fileName = entry.path().stem().string();

                // Add the file name and full path to the map
                shaderMap[fileName] = entry.path().string();

            }
        }
        return true;
        
    } catch (const std::exception& e) {
        std::cerr << "ERROR::SHADER::LOAD_FROM_FOLDER: " << e.what() << std::endl;
        return false;
    }
}


std::string getResourcePath(const std::string& relativePath) {
    std::filesystem::path executablePath = std::filesystem::current_path();
    std::filesystem::path resourcePath = executablePath / relativePath;

    return resourcePath.string();
}

// std::string getResourcePath(const std::string& relativePath) {
//     try {
//     std::filesystem::path executablePath = std::filesystem::current_path();
//     std::filesystem::path resourcePath = executablePath / relativePath;

//         if (!std::filesystem::exists(resourcePath)) {
//             throw std::runtime_error("Resource path does not exist: " + resourcePath.string());
//         }

//     return resourcePath.string();
//     } catch (const std::exception& e) {
//         std::cerr << "ERROR::RESOURCE::PATH_ERROR: " << e.what() << std::endl;
//         return "";
//     }
// }