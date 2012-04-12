#ifndef RSS_HTTP_ENGINE_H
#define RSS_HTTP_ENGINE_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "rss_list_model.h"
class RSSListModel;
class RSSHttpEngine: public QObject
{
Q_OBJECT
public:
	RSSHttpEngine();
	RSSHttpEngine(RSSListModel* pr);
	void sendUrl(const QString url);
	bool getIsFinished() const;

public slots:
	void finishedSendUrl(QNetworkReply*);
private:
	QNetworkAccessManager nam;
	bool oneIsFinished;
	RSSListModel* pRlm;
};

#endif //RSS_HTTP_ENGINE_H
