#pragma once
#include <string>
#include <sstream>
#include <iostream>

namespace Genesis::Log {
    void InfoRaw(const std::string& message);

    template<typename... Args>
    void Info(Args&&... args) {
        std::ostringstream oss;
        (oss << ... << args);
        InfoRaw(oss.str());
    }
}

#define LOG_INFO(...) Genesis::Log::Info(__VA_ARGS__)
