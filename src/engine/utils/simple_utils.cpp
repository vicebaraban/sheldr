#include "simple_utils.h"


bool isStringInVector(const std::vector<std::string>& vec, const std::string& str) {
    for (const std::string& element : vec) {
        if (element == str) {
            return true;
        }
    }
    return false;
}