#pragma once

#include <matlogger2/matlogger2.h>
#include <matlogger2/utils/mat_appender.h>

#include <Eigen/Core>
#include <filesystem>
#include <string>
#include <stdexcept>

class Logger
{
public:
    explicit Logger(const std::string &log_name, const std::string &log_dir);

    template <typename Derived>
    void log(const std::string &key, const Eigen::MatrixBase<Derived> &mat)
    {
        if (!logger_)
            throw std::runtime_error("[Logger] MatLogger2 is not created, cannot log: " + key);
        logger_->add(key, mat.eval());
    }

    void log(const std::string &key, double value);
    
    void flush();

private:
    XBot::MatLogger2::Ptr logger_;
    XBot::MatAppender::Ptr appender_;
};
