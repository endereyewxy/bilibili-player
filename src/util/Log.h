//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#ifndef BILIBILI_PLAYER_LOG_H
#define BILIBILI_PLAYER_LOG_H


#include <QtCore/QLinkedList>

class Log : public QObject {
Q_OBJECT

public:
    enum Level {
        Info,
        Warn,
        Error,
        Fatal
    };
    enum Cause {
        API,
        Network,
        File,
        Settings
    };

    static Log &instance() noexcept;

    static void log(Level level, Cause cause, const QString &msg) noexcept;

    static void info(Cause cause, const QString &msg) noexcept;

    static void warn(Cause cause, const QString &msg) noexcept;

    static void error(Cause cause, const QString &msg) noexcept;

    static void fatal(Cause cause, const QString &msg) noexcept;

    static QString level(Level level) noexcept;

    static QString cause(Cause cause) noexcept;

signals:

    void newLog(const QDateTime &time, Level level, Cause cause, const QString &msg);

private:
    QLinkedList<std::tuple<QDateTime, Level, Cause, QString>> m_logs;

    static Log m_instance;
};


#endif //BILIBILI_PLAYER_LOG_H
