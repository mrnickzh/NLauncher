#include "Login.h"

Login::Login(QApplication* a, QMainWindow* w) {
	nickname = "";
	password = "";
	answer = "";
	manager = new QNetworkAccessManager(a);
	nick_l = new QLabel("Nickname", w);
	pass_l = new QLabel("Password", w);
	nick_e = new QLineEdit(w);
	pass_e = new QLineEdit(w);
	login_b = new QPushButton("Login", w);
};

void Login::setNickname(const QString& val) {
	nickname = val.toUtf8();
};

void Login::setPassword(const QString& val) {
	password = val.toUtf8();
};

void Login::loginRequest() {
	std::string strurl = "http://192.168.100.117:5000/login/nickname=" + nickname + "&password=" + password;
	QString url = QString::fromUtf8(strurl.c_str());
	connect(manager, &QNetworkAccessManager::finished, this, &Login::replyFinished);
	manager->get(QNetworkRequest(QUrl(url)));
};

void Login::replyFinished(QNetworkReply* reply) {
	disconnect(manager, &QNetworkAccessManager::finished, this, &Login::replyFinished);
	answer = reply->readAll();
	qDebug() << answer;
	if (json::accept(answer.data()) and answer != "404" and answer != "400") {
		json jsondata;
		jsondata = json::parse(std::string(answer.data()));
		uuid = jsondata["uuid"];
		access_token = jsondata["accessToken"];
		nick_l->hide();
		pass_l->hide();
		nick_e->hide();
		pass_e->hide();
		login_b->hide();
		emit loginSuccess();
	}
	else {
		msgBox.setText("Login error. Check your nickname and password");
		msgBox.exec();
	}
};