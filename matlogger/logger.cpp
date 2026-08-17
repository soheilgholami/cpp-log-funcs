#include "logger.hpp"

Logger::Logger(const std::string &log_name,
               const std::string &log_dir)
{
    if (log_name.empty())
        throw std::invalid_argument("[Logger] Log name cannot be empty!");

    std::filesystem::path dir =
        std::filesystem::path(REPO_ROOT) / (log_dir.empty() ? "log" : log_dir);
    std::filesystem::create_directories(dir);

    auto now = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(now);

    std::tm tm{};
#if defined(_WIN32)
    localtime_s(&tm, &tt);
#else
    localtime_r(&tt, &tm);
#endif

    std::ostringstream fname;
    fname << log_name << "__"
          << std::put_time(&tm, "%Y_%m_%d__%H_%M_%S") << ".mat";

    std::filesystem::path file = dir / fname.str();
    logger_ = XBot::MatLogger2::MakeLogger(file.string());
    if (!logger_)
        throw std::runtime_error("[Logger] Failed to create MatLogger2: " + file.string());

    appender_ = XBot::MatAppender::MakeInstance();
    if (!appender_)
        throw std::runtime_error("[Logger] Failed to create MatAppender");

    appender_->add_logger(logger_);
    appender_->start_flush_thread();
}

Logger::~Logger()
{
    if (logger_)
        logger_->flush_available_data();
}

void Logger::log(const std::string &key, double value)
{
    if (!logger_)
        throw std::runtime_error("[Logger] MatLogger2 is not created, cannot log: " + key);

    Eigen::Matrix<double, 1, 1> v;
    v(0, 0) = value;
    logger_->add(key, v);
}

void Logger::flush()
{
    if (!logger_)
        throw std::runtime_error("[Logger] flush() failed! No MatLogger2 found.");
    logger_->flush_available_data();
}