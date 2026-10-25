#pragma once

#include "Storage.h"

#include <string>

namespace Db {

void LoadFromFile(const std::string& path, Storage& st);
void SaveToFile(const std::string& path, Storage& st);

}