#include <QString>
#include "rss_tag.h"

QString RSSTag::ChannelS = "<channel";
QString RSSTag::ChannelE = "</channel>";
QString RSSTag::ItemS = "<item";
QString RSSTag::ItemE = "</item>";

QString RSSChannelTag::TitleS = "<title";
QString RSSChannelTag::TitleE = "</title>";
QString RSSChannelTag::LinkS = "<link";
QString RSSChannelTag::LinkE = "</link>";
QString RSSChannelTag::DescS = "<description";
QString RSSChannelTag::DescE = "</description>";
QString RSSChannelTag::LanguageS = "<language";
QString RSSChannelTag::LanguageE = "</language>";

QString RSSItemTag::TitleS = "<title";
QString RSSItemTag::TitleE = "</title>";
QString RSSItemTag::LinkS = "<link";
QString RSSItemTag::LinkE = "</link>";
QString RSSItemTag::DescS = "<description";
QString RSSItemTag::DescE = "</description>";
QString RSSItemTag::GuidS = "<guid";
QString RSSItemTag::GuidE = "</guid>";
QString RSSItemTag::AuthorS = "<author";
QString RSSItemTag::AuthorE = "</author>";
QString RSSItemTag::PubDateS = "<pubDate";
QString RSSItemTag::PubDateE = "</pubDate>";
