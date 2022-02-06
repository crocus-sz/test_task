#ifndef FILE_H
#define FILE_H

#include <string>

class File {
    private:
        std::string oldpath;
        std::string newpath;
        std::string file_name;
        std::string whole_path;

    public:
        File();
        ~File();
        void readPathToFile();
        void fileMovingFunction();
        void readNameFile();
        void checkIfFileExist(std::string file_arg);
        void checkIfPathExist(std::string &checkPath);
        void createNewDir(std::string path_name);
        void moveFile();
        void checkIfPathWriteCorrect(std::string &path);
};

#endif
