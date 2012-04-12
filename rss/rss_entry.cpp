#include "rss_entry.h"
#include "rss_tag.h"
#include <QString>
#include <QDebug>

QString pickUp(const QString* src, int sPos, int ePos,
			const QString& sTag, const QString& eTag)
{
	int se;
	int s = src->indexOf(sTag, sPos);
	int e = src->indexOf(eTag, sPos);
	if(s >= 0 && s < ePos && e < ePos && s < e) 
	{
		s += sTag.length();
		se = src->indexOf(">", s) + 1;
		if(se > s && se < e)
			return src->mid(se, e-se);
	}
	return NULL;
}

RSSEntry::RSSEntry(QString* p) :
	pXml(p)
{
	init();
}

RSSEntry::RSSEntry(const RSSEntry& re)
{
	pXml = re.pXml;
	channel = re.channel;
	items = re.items;
}
void RSSEntry::init()
{
	int start = pXml->indexOf(RSSTag::ItemS, 0);
	channel.set(pXml, pXml->indexOf(RSSTag::ChannelS, 0), start);

	int end = pXml->indexOf(RSSTag::ItemE, start);
	while(end > 0 && start > 0 && end > start)
	{
		RSSItem r;
		r.set(pXml, start, end);
		items.push_back(r);
		start = pXml->indexOf(RSSTag::ItemS, end + RSSTag::ItemE.length());
		end = pXml->indexOf(RSSTag::ItemE, start);
	}
	for(int i = 0; i < items.size(); i++)
	{
		qDebug() << "title" << items[i].title;
		/*
		qDebug() << "link" << items[i].link;
		qDebug() << "desc" << items[i].desc;
		qDebug() << "guid" << items[i].guid;
		qDebug() << "author" << items[i].author;
		qDebug() << "pubDate" << items[i].pubDate;
		*/
		qDebug() << "===========================================";
	}
}
void RSSItem::set(QString* src, const int start, const int end)
{
	title = pickUp(src, start, end, RSSItemTag::TitleS, RSSItemTag::TitleE);
	link = pickUp(src, start, end, RSSItemTag::LinkS, RSSItemTag::LinkE);
	desc = pickUp(src, start, end, RSSItemTag::DescS, RSSItemTag::DescE);
	guid = pickUp(src, start, end, RSSItemTag::GuidS, RSSItemTag::GuidE);
	author = pickUp(src, start, end, RSSItemTag::AuthorS, RSSItemTag::AuthorE);
	pubDate = pickUp(src, start, end, RSSItemTag::PubDateS, RSSItemTag::PubDateE);
}

void RSSChannel::set(QString* src, const int start, const int end)
{
	title = pickUp(src, start, end, RSSChannelTag::TitleS, RSSChannelTag::TitleE);
	link = pickUp(src, start, end, RSSChannelTag::LinkS, RSSChannelTag::LinkE);
	desc = pickUp(src, start, end, RSSChannelTag::DescS, RSSChannelTag::DescE);
	language = pickUp(src, start, end, RSSChannelTag::LanguageS, RSSChannelTag::LanguageE);

	qDebug() << "title" << title;
	/*
	qDebug() << "link" << link;
	qDebug() << "desc" << desc;
	qDebug() << "language" << language;
	*/
}
