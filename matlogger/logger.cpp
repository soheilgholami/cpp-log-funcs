#include "logger.hpp"

Logger::Logger(const std::string &name,
               const std::string &dir)
{
    if (name.empty()) 
        throw std::invalid_argument("[Logger] Log name cannot be empty!");

    std::filesystem::path dir = dir.empty()
                                    ? std::filesystem::path(std::getenv("HOME")) / "logs"
                                    : std::filesystem::path(dir);
    std::filesystem::create_directories(dir);

    logger_ = XBot::MatLogger2::MakeLogger((dir / name).string());
    if (!logger_) 
        throw std::runtime_error("[Logger] Failed to create MatLogger2: " + (dir / name).string());

    appender_ = XBot::MatAppender::MakeInstance();
    if (!appender_) 
        throw std::runtime_error("[Logger] Failed to create MatAppender");

    appender_->add_logger(logger_);
    appender_->start_flush_thread();
}

void Logger::log(const std::string &key, double value)
{
    Eigen::Matrix<double, 1, 1> v(value);
    if (!logger_) 
        throw std::runtime_error("[Logger] MatLogger2 is not created, cannot log: " + key);
    logger_->add(key, v);
}

void Logger::flush()
{
    if (!logger_) 
        throw std::runtime_error("[Logger] MatLogger2 is not created, cannot log: " + key);
    logger_->flush_available_data();
}