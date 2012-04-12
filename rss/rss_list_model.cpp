#include "rss_list_model.h"
#include <QDebug>
#include <QString>

RSSListModel::RSSListModel(QObject *parent) : QAbstractListModel(parent)
{
	initRSSHttpEngine();
}

RSSListModel::RSSListModel(const QList<RSSEntry*>& rel, QObject *parent):
	QAbstractListModel(parent), rssEntryList(rel)
{
	initRSSHttpEngine();
}

RSSListModel::RSSListModel(QList<QString>& qsl, QObject *parent):
	QAbstractListModel(parent)
{
	initRSSHttpEngine();
	state_ = loading;
	for(int i = 0; i < qsl.size(); i++)
	{
		pRhe->sendUrl(qsl[i]);
	}
	//setUrl(qsl);
}
void RSSListModel::setUrl(QList<QString>& qsl)
{
}
int RSSListModel::rowCount(const QModelIndex &parent) const
{
	return rssEntryList.size();
}
void RSSListModel::initRSSHttpEngine()
{
	state_ = noStart;
	pRhe = new RSSHttpEngine(this);
}
int RSSListModel::getState() const
{
	return state_;
}
void RSSListModel::addOneRSS(QString* pXml)
{
	//qDebug() << *pXml;
	RSSEntry *r = new RSSEntry(pXml);
	rssEntryList.push_back(r);
	state_ = finished;
	qDebug() << "rssEntryList size = " << rssEntryList.size();
}
QVariant RSSListModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= rssEntryList.size())
		return QVariant();

	if (role == Qt::DisplayRole)
		return QVariant::fromValue(rssEntryList.at(index.row())->channel.title);
	else
		return QVariant();
}
