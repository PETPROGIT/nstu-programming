#include "Command.h"
#include "Executor.h"
#include "Storage.h"
#include "StorageFile.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    std::string file, query;
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "--file" && i + 1 < argc) file = argv[++i];
        else if (a == "--query" && i + 1 < argc) query = argv[++i];
    }

    std::istringstream qs(query);
    std::string cmd_s, name;
    qs >> cmd_s >> name;

    std::vector<std::string> args;
    std::string t;
    while (qs >> t) args.push_back(t);

    Db::Command cmd = Db::ParseCommand(cmd_s);
    Db::Storage st;
    Db::LoadFromFile(file, st);
    Db::Execute(st, cmd, name, args);
    Db::SaveToFile(file, st);
    Db::ClearStorage(st);
    return 0;
}