#ifndef _LOGIN_H_
#define _LOGIN_H_

#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <string>
#include <QString>
#include <QHeaderView>

#include "../../common/include/gameInfo.h"
#include "../include/serverManager.h"

class Login : public QWidget {
public:
    explicit Login(const ServerManager& sm,std::list<GameInfo> games, std::list<std::string> maps);
private:
	const ServerManager& serverManager;
    std::list<GameInfo> games;
    std::list<std::string> maps;
    QLabel labelOut;
    QTableWidget tableWidget;
    QPushButton exitButton;
    QPushButton joinGameButton;
    QPushButton createGameButton;
    void exit();
    void join(uint32_t game);
};


#endif
