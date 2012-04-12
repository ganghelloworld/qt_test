#ifndef RSS_TAG_H
#define RSS_TAG_H
class RSSTag
{
public:
	static QString ChannelS;
	static QString ChannelE;
	static QString ItemS;
	static QString ItemE;
};

class RSSChannelTag
{
public:
	static QString TitleS;
	static QString TitleE;
	static QString LinkS;
	static QString LinkE;
	static QString DescS;
	static QString DescE;
	static QString LanguageS;
	static QString LanguageE;
};

class RSSItemTag
{
public:
	static QString TitleS;
	static QString TitleE;
	static QString LinkS;
	static QString LinkE;
	static QString DescS;
	static QString DescE;
	static QString GuidS;
	static QString GuidE;
	static QString AuthorS;
	static QString AuthorE;
	static QString PubDateS;
	static QString PubDateE;
};


#endif //RSS_TAG_H
