#include "MainGUI.h"

MainGUI::MainGUI(QApplication* a, QMainWindow* w, Login* lc) {
	lclass = lc;
	utils = new Utils;
	launcher_name = "NLauncher";
	IP = "192.168.3.107:5000";
	std::string homefolder = getenv("USERPROFILE");
	launcher_path = homefolder + "\\AppData\\Roaming\\" + launcher_name;
	if (!fs::is_directory(launcher_path) || !fs::exists(launcher_path)) {
		fs::create_directory(launcher_path);
	}
	dl = new Downloader;
	request_manager = new QNetworkAccessManager;
	app = a;
	win = w;
	memory = 4096;
	server_id = 0;
	prev_server_id = 0;
	debug = false;
	line = new QFrame;
	memory_s = new QSlider(Qt::Horizontal, w);
	memory_l = new QLabel("Memory", w);
	label0 = new QLabel("0", w);
	label1 = new QLabel("2", w);
	label2 = new QLabel("4", w);
	label3 = new QLabel("6", w);
	label4 = new QLabel("8", w);
	label5 = new QLabel("10", w);
	label6 = new QLabel("12", w);
	label7 = new QLabel("14", w);
	label8 = new QLabel("16", w);
	label9 = new QLabel("18", w);
	label10 = new QLabel("20", w);
	label11 = new QLabel("22", w);
	label12 = new QLabel("24", w);
	label13 = new QLabel("26", w);
	label14 = new QLabel("28", w);
	label15 = new QLabel("30", w);
	label16 = new QLabel("32", w);
	debug_b = new QRadioButton("Debug", w);
	server = new QFrame;
	left = new QPushButton("<", w);
	right = new QPushButton(">", w);
	imageLabel = new QLabel(w);
	name_l = new QLabel(w);
	description_l = new QLabel(w);
	play_b = new QPushButton("Play", w);
	play_w = new QWidget;
	play_l = new QLabel(play_w);
	label0->hide();
	label1->hide();
	label2->hide();
	label3->hide();
	label4->hide();
	label5->hide();
	label6->hide();
	label7->hide();
	label8->hide();
	label9->hide();
	label10->hide();
	label11->hide();
	label12->hide();
	label13->hide();
	label14->hide();
	label15->hide();
	label16->hide();
	memory_l->hide();
	memory_s->hide();
	debug_b->hide();
	left->hide();
	right->hide();
	imageLabel->hide();
	name_l->hide();
	description_l->hide();
	play_b->hide();
	play_w->hide();
	play_l->hide();
};

void MainGUI::initGUI() {
	line->setGeometry(380, 0, 350, 405);
	line->setStyleSheet(QString(".QFrame{background-color: gray; border-radius: 10px;}"));
	win->layout()->addWidget(line);
	memory_l->setGeometry(520, 80, 80, 20);
	memory_l->show();
	memory_l->raise();
	memory_s->setRange(0, 16);
	memory_s->setTickInterval(1);
	memory_s->setValue(memory/2048);
	memory_s->setGeometry(390, 120, 320, 20);
	memory_s->show();
	memory_s->raise();
	label0->setGeometry(383, 110, 20, 10);
	label0->setAlignment(Qt::AlignCenter);
	label0->show();
	label0->raise();
	label1->setGeometry(402, 110, 20, 10);
	label1->setAlignment(Qt::AlignCenter);
	label1->show();
	label1->raise();
	label2->setGeometry(422, 110, 20, 10);
	label2->setAlignment(Qt::AlignCenter);
	label2->show();
	label2->raise();
	label3->setGeometry(442, 110, 20, 10);
	label3->setAlignment(Qt::AlignCenter);
	label3->show();
	label3->raise();
	label4->setGeometry(462, 110, 20, 10);
	label4->setAlignment(Qt::AlignCenter);
	label4->show();
	label4->raise();
	label5->setGeometry(482, 110, 20, 10);
	label5->setAlignment(Qt::AlignCenter);
	label5->show();
	label5->raise();
	label6->setGeometry(502, 110, 20, 10);
	label6->setAlignment(Qt::AlignCenter);
	label6->show();
	label6->raise();
	label7->setGeometry(520, 110, 20, 10);
	label7->setAlignment(Qt::AlignCenter);
	label7->show();
	label7->raise();
	label8->setGeometry(540, 110, 20, 10);
	label8->setAlignment(Qt::AlignCenter);
	label8->show();
	label8->raise();
	label9->setGeometry(560, 110, 20, 10);
	label9->setAlignment(Qt::AlignCenter);
	label9->show();
	label9->raise();
	label10->setGeometry(580, 110, 20, 10);
	label10->setAlignment(Qt::AlignCenter);
	label10->show();
	label10->raise();
	label11->setGeometry(598, 110, 20, 10);
	label11->setAlignment(Qt::AlignCenter);
	label11->show();
	label11->raise();
	label12->setGeometry(618, 110, 20, 10);
	label12->setAlignment(Qt::AlignCenter);
	label12->show();
	label12->raise();
	label13->setGeometry(638, 110, 20, 10);
	label13->setAlignment(Qt::AlignCenter);
	label13->show();
	label13->raise();
	label14->setGeometry(658, 110, 20, 10);
	label14->setAlignment(Qt::AlignCenter);
	label14->show();
	label14->raise();
	label15->setGeometry(678, 110, 20, 10);
	label15->setAlignment(Qt::AlignCenter);
	label15->show();
	label15->raise();
	label16->setGeometry(698, 110, 20, 10);
	label16->setAlignment(Qt::AlignCenter);
	label16->show();
	label16->raise();
	debug_b->setGeometry(390, 160, 100, 20);
	debug_b->show();
	debug_b->raise();
	server->setGeometry(90, 75, 200, 250);
	server->setStyleSheet(QString(".QFrame{background-color: gray; border-radius: 10px;}"));
	win->layout()->addWidget(server);
	left->setGeometry(20, 175, 50, 50);
	left->show();
	left->raise();
	right->setGeometry(310, 175, 50, 50);
	right->show();
	right->raise();
	play_b->setGeometry(150, 340, 80, 30);
	play_b->show();
	play_b->raise();
	changeServer();
};

void MainGUI::setMemory(int val) {
	memory = val * 2048;
};

void MainGUI::debugMode() {
	debug = true;
	AllocConsole();
	freopen("conout$", "a", stdout);
};

void MainGUI::changeServer() {
	std::string strurl = "http://" + IP + "/server/id=" + std::to_string(server_id);
	QString url = QString::fromUtf8(strurl.c_str());
	connect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::changeServerFinished);
	request_manager->get(QNetworkRequest(QUrl(url)));
};

void MainGUI::changeServerFinished(QNetworkReply* reply) {
	disconnect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::changeServerFinished);
	answer = reply->readAll();
	if (!json::accept(answer.data()) or answer == "404" or answer == "" or server_id < 0) {
		server_id = prev_server_id;
		return;
	};
	json jsondata;
	jsondata = json::parse(std::string(answer.data()));
	std::string server_name = jsondata["name"];
	std::string server_description = jsondata["description"];
	std::string server_image = jsondata["img"];
	server_path = jsondata["path"];
	server_version = jsondata["version"];
	if (jsondata["modloader"] == "fabric")
		mlclass = "-DFabricMcEmu=net.minecraft.client.main.Main net.fabricmc.loader.impl.launch.knot.KnotClient";
	else if (jsondata["modloader"] == "forge")
		mlclass = "net.minecraftforge.fml.common.launcher.FMLTweaker";
	name_l->setGeometry(140, 240, 100, 10);
	name_l->setText(QString::fromUtf8(server_name));
	name_l->setAlignment(Qt::AlignCenter);
	name_l->show();
	name_l->raise();
	description_l->setGeometry(140, 255, 100, 40);
	description_l->setText(QString::fromUtf8(server_description));
	description_l->setAlignment(Qt::AlignCenter);
	description_l->show();
	description_l->raise();
	QString img_link = QString::fromUtf8("http://" + IP + "/file/path=sprevs&" + server_image);
	dl->setTarget(img_link, QString::fromUtf8(std::string(launcher_path+"\\sprev.jpg")));
	dl->download();
	connect(dl, SIGNAL(done()), this, SLOT(drawImage()));
	prev_server_id = server_id;

};

void MainGUI::drawImage() {
	disconnect(dl, SIGNAL(done()), this, SLOT(drawImage()));
	QPixmap image(QString::fromUtf8(std::string(launcher_path + "\\sprev.jpg")));
	imageLabel->setPixmap(image);
	imageLabel->setGeometry(140, 125, 100, 100);
	imageLabel->show();
	imageLabel->raise();
};

void MainGUI::flipLeft() {
	server_id = server_id - 1;
	changeServer();
};

void MainGUI::flipRight() {
	server_id = server_id + 1;
	changeServer();
};

void MainGUI::play() {
	download_progress = 0;
	total_files = 0;
	play_w->setFixedSize(200, 50);
	play_w->show();
	play_l->setGeometry(20, 20, 160, 20);
	play_l->setText("Getting file list...");
	play_l->show();
	requestFileWhitelist();
};

void MainGUI::downloadGameFiles(QNetworkReply* reply) {
	disconnect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::downloadGameFiles);
	answer = reply->readAll();
	qDebug() << answer;
	if (!json::accept(answer.data()) or answer == "404" or answer == "" or server_id < 0) {
		return;
	};
	std::string path_server = launcher_path + "\\" + server_path;
	if (!fs::is_directory(path_server) || !fs::exists(path_server)) {
		fs::create_directory(path_server);
	}
	json jsondata;
	jsondata = json::parse(std::string(answer.data()));
	total_files = 1;
	for (int i = 0; i < jsondata.size(); i++) {
		play_l->setText(QString::fromUtf8("Checking files " + std::to_string(i) + "/" + std::to_string(jsondata.size())));
		std::string link = jsondata[i]["link"];
		std::string name = jsondata[i]["name"];
		std::string path = jsondata[i]["path"];
		std::string hash = jsondata[i]["hash"];
		hash_list.push_back(hash);
		path = utils->ReplaceAll(path, "/", "\\");
		std::vector<std::string> folders = utils->split(path, "\\");
		std::string cpath;
		std::cout << "checking " + name << std::endl;
		if (!std::filesystem::exists(launcher_path + "\\" + path + "\\" + name)) {
			for (int j = 0; j < folders.size(); j++) {
				fs::create_directory(launcher_path + "\\" + cpath + "\\" + folders[j]);
				cpath += "\\" + folders[j];
			}
			std::cout << "downloading " + name << std::endl;
			QString file_link = QString::fromUtf8("http://" + IP + "/file/path=" + link + "&" + name);
			dl->setTarget(file_link, QString::fromUtf8(std::string(launcher_path + "\\" + path + "\\" + name)));
			total_files += 1;
		}
		else {
			std::string fpath = launcher_path + "\\" + path + "\\" + name;
			std::ifstream hashfile(fpath.c_str(), std::ios::binary);
			std::stringstream buffer;
			buffer << hashfile.rdbuf();
			hashfile.close();
			if (md5(buffer.str()) != hash && !std::any_of(file_whitelist.begin(), file_whitelist.end(), [&fpath](const auto& s) { return fpath.find(s) != std::string::npos; })) {
				std::cout << "downloading " + name << std::endl;
				QString file_link = QString::fromUtf8("http://" + IP + "/file/path=" + link + "&" + name);
				dl->setTarget(file_link, QString::fromUtf8(std::string(launcher_path + "\\" + path + "\\" + name)));
				total_files += 1;
			}
		}
	}
	connect(dl, SIGNAL(done()), this, SLOT(gameDownloadFinished()));
	dl->download();
	gameDownloadFinished();
};

void MainGUI::getLibraries() {
	libraries = launcher_path + "\\" + server_path + "\\versions\\" + server_version + "\\client.jar;";
	std::string path = launcher_path + "\\" + server_path + "\\libraries";
	for (auto dir_entry : std::filesystem::recursive_directory_iterator(path))
	{
		if (fs::is_regular_file(dir_entry.path().string())) {
			libraries += dir_entry.path().string() + ";";
		}
	}
};

void MainGUI::clearDir() {
	for (auto dir_entry : std::filesystem::recursive_directory_iterator(launcher_path + "\\" + server_path))
	{
		if (fs::is_regular_file(dir_entry.path().string())) {
			std::string fpath = dir_entry.path().string();
			std::ifstream hashfile(fpath.c_str(), std::ios::binary);
			std::stringstream buffer;
			buffer << hashfile.rdbuf();
			hashfile.close();
			if (!std::count(hash_list.begin(), hash_list.end(), md5(buffer.str())) && !std::any_of(file_whitelist.begin(), file_whitelist.end(), [&fpath](const auto& s) { return fpath.find(s) != std::string::npos; })) {
				std::cout << "removing " + fpath << std::endl;
				std::filesystem::remove(fpath);
			}
		}
	}
};

void MainGUI::requestFileWhitelist() {
	std::string strurl = "http://" + IP + "/filewl/id=" + std::to_string(server_id);
	QString url = QString::fromUtf8(strurl.c_str());
	connect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::getFileWhitelist);
	request_manager->get(QNetworkRequest(QUrl(url)));
}

void MainGUI::getFileWhitelist(QNetworkReply* reply) {
	disconnect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::getFileWhitelist);
	answer = reply->readAll();
	qDebug() << answer;
	if (!json::accept(answer.data()) or answer == "404" or answer == "" or server_id < 0) {
		return;
	};
	json jsondata;
	jsondata = json::parse(std::string(answer.data()));
	for (auto path : jsondata) {
		file_whitelist.push_back(utils->ReplaceAll(path, "/", "\\"));
	}
	requestAssetIndex();
}

void MainGUI::requestAssetIndex() {
	std::string strurl = "https://launchermeta.mojang.com/mc/game/version_manifest.json";
	QString url = QString::fromUtf8(strurl.c_str());
	connect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::getVersionInfo);
	request_manager->get(QNetworkRequest(QUrl(url)));
}

void MainGUI::getVersionInfo(QNetworkReply* reply) {
	disconnect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::getVersionInfo);
	QByteArray answer = reply->readAll();
	json jsondata;
	jsondata = json::parse(std::string(answer.data()));
	for (int i = 0; i < jsondata["versions"].size(); i++) {
		if (jsondata["versions"][i]["id"] == server_version) {
			std::string strurl = jsondata["versions"][i]["url"];
			QString url = QString::fromUtf8(strurl.c_str());
			qDebug() << url;
			connect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::getAssetIndex);
			request_manager->get(QNetworkRequest(QUrl(url)));
			break;
		}
	}
}

void MainGUI::getAssetIndex(QNetworkReply* reply) {
	disconnect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::getAssetIndex);
	QByteArray answer = reply->readAll();
	json jsondata;
	jsondata = json::parse(std::string(answer.data()));
	asset_index = jsondata["assetIndex"]["id"];
	std::string strurl = "http://" + IP + "/serverfiles/id=" + std::to_string(server_id);
	QString url = QString::fromUtf8(strurl.c_str());
	connect(request_manager, &QNetworkAccessManager::finished, this, &MainGUI::downloadGameFiles);
	request_manager->get(QNetworkRequest(QUrl(url)));
}

void MainGUI::gameDownloadFinished() {
	download_progress += 1;
	play_l->setText(QString::fromUtf8("Downloading files... " + std::to_string(download_progress) + "/" + std::to_string(total_files)));
	if (download_progress == total_files) {
		disconnect(dl, SIGNAL(done()), this, SLOT(gameDownloadFinished()));
		play_l->hide();
		play_w->hide();
		clearDir();
		getLibraries();
		std::string java_path;
		if (debug)
			java_path = launcher_path + "\\" + server_path + "\\java\\bin\\java.exe";
		else
			java_path = launcher_path + "\\" + server_path + "\\java\\bin\\javaw.exe";
		std::string launch_command = "-Dos.name=Windows10 -Dos.version=10.0 -Djava.library.path=" + launcher_path + "\\" + server_path + "\\versions\\" + server_version + "\\natives -cp " + libraries + " -Xmx" + std::to_string(memory) + "M -XX:+UnlockExperimentalVMOptions -XX:+UseG1GC -XX:G1NewSizePercent=20 -XX:G1ReservePercent=20 -XX:MaxGCPauseMillis=50 -XX:G1HeapRegionSize=32M -Dfml.ignoreInvalidMinecraftCertificates=true -Dfml.ignorePatchDiscrepancies=true -Djava.net.preferIPv4Stack=true -Dminecraft.applet.TargetDirectory=" + launcher_path + "\\" + server_path + " -Dlog4j.configurationFile=" + launcher_path + "\\" + server_path + "\\assets\\log_configs\\client-" + server_version + ".xml net.minecraft.launchwrapper.Launch --username " + lclass->nickname + " --version " + server_version + " --gameDir " + launcher_path + "\\" + server_path + " --assetsDir " + launcher_path + "\\" + server_path + "\\assets --assetIndex " + asset_index + " --uuid " + lclass->uuid + " --accessToken " + lclass->access_token + " --userType mojang --tweakClass " + mlclass + " --width 925 --height 530";
		std::cout << "Full launch command: " + launch_command << std::endl;
		std::cout << "Starting the game..." << std::endl;
		utils->startup(java_path.c_str(), const_cast<char*>(launch_command.c_str()));
	}
};
