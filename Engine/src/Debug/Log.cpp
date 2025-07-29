#include "Genesis/Debug/Log.h"
#include <iostream>

namespace Genesis::Log {

    void InfoRaw(const std::string& message) {
        std::cout << "[Info] " << message << std::endl;
    }

    // You can overload this later for Warning, Error, etc.
}
