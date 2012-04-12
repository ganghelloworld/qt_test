#ifndef RSS_ENTRY_H
#define RSS_ENTRY_H

#include <QString>
#include <QList>
#include <QObject>
#include <QMetaType>
/*
   RSSEntry is a entry of one rss request

   One RSSEntry has a RSSChannel and some RSSItem, normal
   at least one RSSItem, at most 15 RSSItems
*/
class RSSChannel
{
public:
	QString title;
	QString link;
	QString desc;
	QString language;
public:
	void set(QString*, const int, const int);
};
class RSSItem
{
public:
	QString title;
	QString link;
	QString desc;
	QString guid;
	QString author;
	QString pubDate;
public:
	void set(QString*, const int, const int);
};
class RSSEntry
{
public:
	RSSChannel channel;
	QList<RSSItem> items;
	QString *pXml;
public:
	RSSEntry(){};
	RSSEntry(const RSSEntry&);
	RSSEntry(QString *);
	void init();
};
Q_DECLARE_METATYPE(RSSEntry);
#endif //RSS_ENTRY_H
