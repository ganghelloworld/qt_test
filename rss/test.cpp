#include "rss_http_engine.h"
#include "rss_entry.h"
#include "rss_list_model.h"
#include "rss_tag.h"
#include <QDebug>
#include <QString>
#include <QApplication>
#include <QThread>
#include <QTextCodec>
#include <QListView>
#include <QStringList>
#include <QStringListModel>

RSSListModel* prlm = 0;
class ShowDataThread : public QThread
{
public:
	ShowDataThread(){};
	//ShowDataThread(RSSListModel* r): prlm(r){};
	//RSSListModel* getModel() const {return prlm;};
	void run();
};
void ShowDataThread::run()
{
	QList<QString> url;
	url.push_back("http://localhost:8080/hello/example.xml");
	url.push_back("http://blog.sina.com.cn/rss/1191258123.xml");
	prlm = new RSSListModel(url);
	qDebug() << "in run" << prlm->getState();
	exec();
}
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	ShowDataThread sdt;
	sdt.start();

	while(prlm == 0 || prlm->getState() != RSSListModel::finished)
	{
		sleep(1);
	}
	if(prlm->rowCount() > 0)
	{
		/*
		qDebug() << "IN===============================================";
		QStringList numbers;
		numbers << "One" << "Two" << "Three" << "Four" << "Five";
		QAbstractItemModel *model = new QStringListModel(numbers);
		*/
		QListView *view = new QListView;
		view->setModel(prlm);
		view->show();
	}
	else
	{
		qDebug() << "RSSListModel is empty";
	}
	app.exec();

	return 1;
}
