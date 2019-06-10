#ifndef _LOGIN_H_
#define _LOGIN_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>

class Login : public QWidget {
public:
    explicit Login(QWidget *parent = 0);
private:
    QLabel labelOut;
    QPushButton exitButton;
    QPushButton joinGameButton;
    QPushButton createGameButton;
};


#endif
