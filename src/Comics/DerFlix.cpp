/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DerFlix.h"

#include <QDebug>

DerFlix::DerFlix(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("derflix");
    m_info.name           = QString("Der Flix");
    m_info.color          = QColor(0, 97, 162);
    m_info.authors        = QStringList("Felix Görmann");
    m_info.homepage       = QUrl("http://www.der-flix.de");
    m_info.country        = QLocale::Germany;
    m_info.language       = QLocale::German;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.der-flix.de");
}

QUrl DerFlix::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(/images/heldentage/[^\"]*)\"");
}
