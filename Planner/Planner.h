#ifndef PLANNER_H
#define PLANNER_H

#include "sqlite3.h"
#include <string>


class Planner {
    private:
        const char* pathToDB = R"(/home/crocus/test_tasks/Planner/planner.db)";
    public:
        Planner();
        ~Planner();
        void AppLoop();
        void WelcomeMenu();
        void showMenu();
        static int createTable(const char* path);
        static int createDB(const char* path);
        static int insertData(const char* path, std::string name, std::string note, std::string date);
        static int selectData(const char* path);
        void showAllEvents();
        void addOneEvent();
        void deleteOneEvent();
        
};


#endif
