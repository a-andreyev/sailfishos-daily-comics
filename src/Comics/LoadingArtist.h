/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef LOADINGARTIST_H
#define LOADINGARTIST_H

#include "../Comic.h"

class LoadingArtist : public Comic
{
    Q_OBJECT

public:
    explicit LoadingArtist(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // LOADINGARTIST_H
