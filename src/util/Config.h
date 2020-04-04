//
// Created by endereyewxy@gmail.com on 4/4/20.
//

#ifndef BILIBILI_PLAYER_CONFIG_H
#define BILIBILI_PLAYER_CONFIG_H


#include <QtCore/QString>

class Config {
public:
    static QString userAgent;
    static QString session;
    static QString library;
    static QString defaultPlaylist;
    static bool downloadWhenCreated;
    static bool automaticFullscreen;

    static void init();

    static void save();
};


#endif //BILIBILI_PLAYER_CONFIG_H
