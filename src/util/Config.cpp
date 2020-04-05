//
// Created by endereyewxy@gmail.com on 4/4/20.
//

#include "Config.h"

#include <QtCore/QDir>
#include <QtCore/QSettings>

QString Config::userAgent;
QString Config::session;
QString Config::library;
QString Config::defaultPlaylist;
bool    Config::downloadWhenCreated;
bool    Config::automaticFullscreen;

#define GET_VALUE(key) key = settings.value(# key)
#define SET_VALUE(key) settings.setValue(# key, key)

void Config::init() {
    QSettings settings;
    GET_VALUE(userAgent).toString();
    GET_VALUE(session).toString();
    GET_VALUE(library).toString();
    GET_VALUE(defaultPlaylist).toString();
    GET_VALUE(downloadWhenCreated).toBool();
    GET_VALUE(automaticFullscreen).toBool();
    if (library.isEmpty() || !QDir(library).exists())
        library = QDir::homePath();
}

void Config::save() {
    QSettings settings;
    SET_VALUE(userAgent);
    SET_VALUE(session);
    SET_VALUE(library);
    SET_VALUE(defaultPlaylist);
    SET_VALUE(downloadWhenCreated);
    SET_VALUE(automaticFullscreen);
}
