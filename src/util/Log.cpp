//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#include "Log.h"

#include <QtCore/QDateTime>
#include <QtCore/QDebug>

Log Log::m_instance; // NOLINT(cert-err58-cpp)

Log &Log::instance() noexcept {
    return m_instance;
}

void Log::log(Log::Level level, Log::Cause cause, const QString &msg) noexcept {
    auto time = QDateTime::currentDateTime();
    m_instance.m_logs.push_back(std::make_tuple(time, level, cause, msg));
    qDebug() << time << level << cause << msg;
    emit m_instance.newLog(time, level, cause, msg);
}

void Log::info(Log::Cause cause, const QString &msg) noexcept {
    log(Info, cause, msg);
}

void Log::warn(Log::Cause cause, const QString &msg) noexcept {
    log(Warn, cause, msg);
}

void Log::error(Log::Cause cause, const QString &msg) noexcept {
    log(Error, cause, msg);
}

void Log::fatal(Log::Cause cause, const QString &msg) noexcept {
    log(Fatal, cause, msg);
}

QString Log::level(Log::Level level) noexcept {
    switch (level) {
        case Info:
            return "INFO";
        case Warn:
            return "WARN";
        case Error:
            return "ERROR";
        case Fatal:
            return "FATAL";
    }
    Q_ASSERT(false);
}

QString Log::cause(Log::Cause cause) noexcept {
    switch (cause) {
        case API:
            return "API";
        case Network:
            return "Network";
        case File:
            return "File";
    }
    Q_ASSERT(false);
}
