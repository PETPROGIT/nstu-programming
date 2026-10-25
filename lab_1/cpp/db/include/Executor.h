#pragma once

#include "Command.h"
#include "Storage.h"

#include <string>
#include <vector>

namespace Db {

void Execute(Storage& st, Command cmd, const std::string& name,
             const std::vector<std::string>& args);

}