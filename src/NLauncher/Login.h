#pragma once

#include <string>
#include <json.hpp>
#include <qapplication.h>
#include <qobject.h>
#include <qstring.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <qdebug.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qmainwindow.h>
#include <qmessagebox.h>

#include "md5.h"

using json = nlohmann::json;

class Login : public QObject {

	Q_OBJECT

private:
	QByteArray answer;
	QNetworkAccessManager* manager;
	QMessageBox msgBox;
public:
	std::string nickname;
	std::string password;
	std::string uuid;
	std::string access_token;
	std::string IP;
	QLabel* nick_l;
	QLabel* pass_l;
	QLineEdit* nick_e;
	QLineEdit* pass_e;
	QPushButton* login_b;
	Login(QApplication*, QMainWindow*);
	void replyFinished(QNetworkReply*);
	std::string getReply();
signals:
	void loginSuccess();
public slots:
	void setNickname(const QString&);
	void setPassword(const QString&);
	void loginRequest();
};

