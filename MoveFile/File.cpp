#include "File.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>


File::File() {
    moveFile();
}

void File::moveFile() {
    readPathToFile();
    fileMovingFunction();
}

File::~File() {
}

void File::readPathToFile() {
    std::cout << "Enter current path to file: ";
    std::cin >> oldpath;
    checkIfPathExist(oldpath);

    readNameFile();
    checkIfFileExist(file_name);

    std::cout << "Enter new path to file: ";
    std::cin >> newpath;
    checkIfPathExist(newpath);
}

void File::readNameFile() {
    std::cout << "Enter name of the file: ";
    std::cin >> file_name;
}

void File::fileMovingFunction() {
    std::filesystem::rename(whole_path, newpath+file_name);
    std::cout << "File moved to new directory!" << std::endl;
    
}

void File::checkIfFileExist(std::string file_arg) {

    whole_path = oldpath + file_name; //whole path to file 
    std::ifstream file;
    file.open(whole_path);
    if(!file) {
        std::cout << "File does not exist!" << std::endl;
        exit(0);
    }
    else {
        std::cout << "File is exist!" << std::endl;
    }
}

void File::checkIfPathExist(std::string &checkPath) {
    struct stat sb;
    std::string create_dir_choose;
    bool is_newpath_empty = newpath == "";
    
    if (stat(checkPath.c_str(), &sb) == 0){
        std::cout << "Dir is exist!" << std::endl;
        checkIfPathWriteCorrect(checkPath);
    }
    
    else {
        std::cout << "Dir does not exist!" << std::endl;
        if(is_newpath_empty) exit(0); // don't create new directory
        else {
            // creating new directory olny for newpath
            std::cout << "Do you want create new directory? [y/N] ";
            std::cin >> create_dir_choose;
            if(create_dir_choose == "y" or create_dir_choose == "Y") {
                createNewDir(checkPath);
                checkIfPathWriteCorrect(checkPath);
                std::cout << "Directory created succsessfully" << std::endl;
            }
            else exit(0);
        }
    }
}

void File::createNewDir(std::string path_name) {
    std::filesystem::create_directory(path_name);
}
void File::checkIfPathWriteCorrect(std::string &path) {
    // all path need to have '/' in the end

    if(path[path.length() - 1] != '/') {
        path += "/";
    }
}
