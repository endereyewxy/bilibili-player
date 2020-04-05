//
// Created by endereyewxy@gmail.com on 3/30/20.
//

#include <QApplication>
#include <QtCore/QTranslator>

#include "gui/WinMain.h"
#include "util/Config.h"
#include "util/Network.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setOrganizationName("endereyewxy");
    QCoreApplication::setOrganizationDomain("endereyewxy@gmail.com");
    QCoreApplication::setApplicationName("bilibili-player");
    QCoreApplication::setApplicationVersion("0.0.1-SNAPSHOT");

    QApplication app(argc, argv);

    Config::init();
    QTranslator translator;
    if (!Config::userTranslation.isEmpty() && translator.load(Config::userTranslation, ":/lang"))
        QCoreApplication::installTranslator(&translator);
    Network::init();
    Video::init();

    WinMain win;
    return QApplication::exec();
}
