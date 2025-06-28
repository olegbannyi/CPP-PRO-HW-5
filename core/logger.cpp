#include "logger.h"
#include <fstream>
#include <string>

Logger::Logger(std::string logpath) : logpath_(std::move(logpath)), flashed_(false)
{
}

Logger::Logger(Logger &&other) noexcept
{
    logpath_ = other.logpath_;
    ss_.clear();
    if (!other.flashed_)
    {
        ss_ << other.ss_.str();
    }
    flashed_ = other.flashed_;

    other.flashed_ = true;
    other.ss_.clear();
    other.logpath_ = "";
}

Logger& Logger::operator=(Logger&& other)
{
    logpath_ = other.logpath_;
    ss_.clear();
    if (!other.flashed_)
    {
        ss_ << other.ss_.str();
    }
    flashed_ = other.flashed_;

    other.flashed_ = true;
    other.ss_.clear();
    other.logpath_ = "";

    return *this;
}

void Logger::flash()
{
    if (flashed_ || logpath_.empty())
    {
        return;
    }
    std::ofstream logfile(logpath_);

    if (logfile.is_open())
    {
        logfile << ss_.str() << std::endl;
        logfile.close();
    }

    flashed_ = true;
}

void Logger::write(const std::string &log)
{
    ss_ << log;
}
