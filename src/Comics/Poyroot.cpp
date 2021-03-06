/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Poyroot.h"

#include <QDebug>

Poyroot::Poyroot(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("poyroot");
    m_info.name           = QString("Pöyrööt");
    m_info.color          = QColor(160, 207, 79);
    m_info.authors        = QStringList() << "Arttu Seppälä" << "Liisa Seppälä" << "Tiia Pelkola";
    m_info.homepage       = QUrl("http://www.poyroot.fi");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.poyroot.fi/sarjakuvat/");
}

QUrl Poyroot::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/poyroot_[^\"]*)\"");
}
