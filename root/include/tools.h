#ifndef TOOLS
#define TOOLS

#include <set>
#include <locale>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "makefile.h"
#include "gmake_options.h"

namespace fs = std::filesystem;

static const std::string MAIN_FUNCT = "intmain(";
static const std::string INCLUDE_STMT = "#include";
static const std::string INCLUDE_L_DLMTR = "\"";
static const std::string INCLUDE_R_DLMTR = "\"";

// filesystem helper
std::vector<fs::path> listdir(const std::string& dir);
std::vector<fs::path> filterPath(const std::vector<fs::path>& paths, const std::vector<std::string>& ext);
bool readFileDependencies(const std::string& filename, std::vector<std::string> &deps, bool* isMain=NULL);
bool readFileDeepDependencies_(const std::string& filename, std::vector<std::string> &deps);
bool readFileDeepDependencies(const std::string& filename, std::vector<std::string> &deps);
bool writeMakefile(const Makefile& makefile, const std::string& folder);
bool readGmake(const std::string& filepath, GmakeOptions& gmake);

// string operations
bool startWith(const std::string& str, const std::string& sub);
bool endWith(const std::string& str, const std::string& sub);
void eraseAll(std::string &str, const std::string& sub);
std::string trim(const std::string& str);
std::string toUpper(const std::string& str);

template<typename T>
bool contains(const std::vector<T> &v, const T& value){
    return (std::find(v.begin(), v.end(), value) != v.end());
}

#endif
