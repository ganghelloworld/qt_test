#ifndef RSS_LIST_MODEL_h
#define RSS_LIST_MODEL_h

#include <QAbstractListModel>
#include <QList>
#include "rss_entry.h"
#include "rss_http_engine.h"


class RSSHttpEngine;

//static enum RSSListModelState{noStart, loading, finished};
class RSSListModel : public QAbstractListModel
{
	Q_OBJECT
public:
	RSSListModel(QObject *parent = 0);
	RSSListModel(const QList<RSSEntry*>& rel, QObject *parent = 0);
	RSSListModel(QList<QString>& qsl, QObject *parent = 0);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	int getState() const;
	void setUrl(QList<QString>& qsl);
	void addOneRSS(QString* xml);
private:
	void initRSSHttpEngine();

	QList<RSSEntry*> rssEntryList;
	RSSHttpEngine* pRhe;
	int state_; 
public:
	static const int noStart = 0;
	static const int loading = 1;
	static const int finished = 2;
};
#endif //RSS_LIST_MODEL_h
