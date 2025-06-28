#pragma once

#include <sstream>
#include <string>
class Logger
{
    std::string logpath_;
    std::stringstream ss_;
    bool flashed_;

  public:
    explicit Logger(std::string);
    Logger(Logger &&) noexcept;
    ~Logger() = default;
    Logger &operator=(Logger &&other);
    void write(const std::string &);
    void flash();
};
