#pragma once

#include <qobject.h>
#include <qmainwindow.h>
#include <qapplication.h>
#include <qdebug.h>
#include <qpainter.h>
#include <qframe.h>
#include <qlayout.h>
#include <qslider.h>
#include <qlabel.h>
#include <qradiobutton.h>
#include <qpushbutton.h>
#include <windows.h>
#include <qstringliteral.h>
#include <qpixmap.h>
#include <json.hpp>
#include <lmcons.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <QNetworkAccessManager>
#include <QMap>
#include <iostream>

#include "Utils.h"
#include "md5.h"
#include "Downloader.h"
#include "Login.h"

using json = nlohmann::json;
namespace fs = std::filesystem;

class MainGUI : public QObject {

	Q_OBJECT

private:
	Login* lclass;
	Utils* utils;
	Downloader* dl;
	QApplication* app;
	QMainWindow* win;
	QNetworkAccessManager* request_manager;
	QFrame* line;
	QLabel* label0;
	QLabel* label1;
	QLabel* label2;
	QLabel* label3;
	QLabel* label4;
	QLabel* label5;
	QLabel* label6;
	QLabel* label7;
	QLabel* label8;
	QLabel* label9;
	QLabel* label10;
	QLabel* label11;
	QLabel* label12;
	QLabel* label13;
	QLabel* label14;
	QLabel* label15;
	QLabel* label16;
	QLabel* memory_l;
	QFrame* server;
	QLabel* imageLabel;
	QByteArray answer;
	QLabel* name_l;
	QLabel* description_l;
	QWidget* play_w;
	QWidget* error_w;
	QLabel* play_l;
	QLabel* error_l;
	int memory;
	int server_id;
	int prev_server_id;
	int download_progress;
	int total_files;
	bool debug;
	std::string server_path;
	std::string server_version;
	std::string launcher_name;
	std::string launcher_path;
	std::string libraries;
	std::string asset_index;
	std::vector<std::string> hash_list;
	std::vector<std::string> file_whitelist;
	std::string mlclass;
	std::string IP;
public:
	QSlider* memory_s;
	QRadioButton* debug_b;
	QPushButton* left;
	QPushButton* right;
	QPushButton* play_b;
	MainGUI(QApplication*, QMainWindow*, Login*);
signals:

public slots:
	void initGUI();
	void setMemory(int);
	void debugMode();
	void changeServer();
	void changeServerFinished(QNetworkReply*);
	void drawImage();
	void flipLeft();
	void flipRight();
	void play();
	void getLibraries();
	void downloadGameFiles(QNetworkReply*);
	void gameDownloadFinished();
	void requestAssetIndex();
	void getVersionInfo(QNetworkReply*);
	void getAssetIndex(QNetworkReply*);
	void clearDir();
	void requestFileWhitelist();
	void getFileWhitelist(QNetworkReply*);
};

