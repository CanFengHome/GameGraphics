//
//  FileUtils.cpp
//  SharpEngine
//
//  Created by ccf on 16/9/27.
//  Copyright © 2016年 ccf. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "FileUtils.h"

NS_SP_BEGIN

namespace Utils
{
    std::string readFile(const std::string& filePath)
    {
        std::ifstream inStream;
        // ensures ifstream objects can throw exceptions:
        inStream.exceptions (std::ifstream::badbit);
        try
        {
            // Open files
            inStream.open(filePath);
            std::stringstream strStream;
            // Read file's buffer contents into streams
            strStream << inStream.rdbuf();
            // close file handlers
            inStream.close();
            // Convert stream into string
            return strStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
        return "";
    }
}


NS_SP_END

















