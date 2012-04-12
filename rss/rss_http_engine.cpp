#include "rss_http_engine.h"
#include <QDebug>

RSSHttpEngine::RSSHttpEngine()
{
	connect(&nam, SIGNAL(finished(QNetworkReply*)), SLOT(finishedSendUrl(QNetworkReply*)));
}
RSSHttpEngine::RSSHttpEngine(RSSListModel* pr) :
	pRlm(pr)
{
	connect(&nam, SIGNAL(finished(QNetworkReply*)), SLOT(finishedSendUrl(QNetworkReply*)));
}

void RSSHttpEngine::sendUrl(const QString s)
{
	QUrl url(s);
	oneIsFinished = false;
	nam.get(QNetworkRequest(url));
}
bool RSSHttpEngine::getIsFinished() const
{
	return oneIsFinished;
}
void RSSHttpEngine::finishedSendUrl(QNetworkReply* reply)
{
	QVariant statusCodeV = 
		reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	QVariant redirectionTargetUrl= 
		reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
	if(reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();
		QString* string = new QString(bytes);
		//qDebug() << string << endl;
		pRlm->addOneRSS(string);
		oneIsFinished = true;
	}
	else
	{
		qDebug() << "replay->error";
	}
	reply->deleteLater();
}
