/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheBoondocks.h"

#include <QDebug>

TheBoondocks::TheBoondocks(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("theboondocks");
    m_info.name           = QString("The Boondocks");
    m_info.color          = QColor(175, 121, 83);
    m_info.authors        = QStringList("Aaron McGruder");
    m_info.homepage       = QUrl("http://www.gocomics.com/boondocks");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1996-04-19", Qt::ISODate);
    m_info.endDate        = QDate::fromString("2006-03-26", Qt::ISODate);
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/boondocks");
}

QUrl TheBoondocks::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
