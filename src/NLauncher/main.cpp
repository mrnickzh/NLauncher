#include "Login.h"
#include "MainGUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow* w = new QMainWindow;
    Login* login = new Login(&a, w);
    MainGUI* maingui = new MainGUI(&a, w, login);
    login->nick_l->setGeometry(310, 140, 100, 10);
    login->nick_l->show();
    login->pass_l->setGeometry(310, 180, 100, 10);
    login->pass_l->show();
    login->nick_e->setGeometry(310, 150, 100, 20);
    login->nick_e->show();
    login->pass_e->setGeometry(310, 190, 100, 20);
    login->pass_e->show();
    login->pass_e->setEchoMode(QLineEdit::Password);
    login->login_b->setGeometry(310, 220, 100, 30);
    login->login_b->show();
    w->setFixedSize(720, 405);
    w->show();
    QObject::connect(login->nick_e, SIGNAL(textEdited(const QString&)), login, SLOT(setNickname(const QString&)));
    QObject::connect(login->pass_e, SIGNAL(textEdited(const QString&)), login, SLOT(setPassword(const QString&)));
    QObject::connect(login->login_b, SIGNAL(clicked()), login, SLOT(loginRequest()));
    QObject::connect(login, SIGNAL(loginSuccess()), maingui, SLOT(initGUI()));
    QObject::connect(maingui->memory_s, SIGNAL(valueChanged(int)), maingui, SLOT(setMemory(int)));
    QObject::connect(maingui->debug_b, SIGNAL(clicked()), maingui, SLOT(debugMode()));
    QObject::connect(maingui->left, SIGNAL(clicked()), maingui, SLOT(flipLeft()));
    QObject::connect(maingui->right, SIGNAL(clicked()), maingui, SLOT(flipRight()));
    QObject::connect(maingui->play_b, SIGNAL(clicked()), maingui, SLOT(play()));
    return a.exec();
}
