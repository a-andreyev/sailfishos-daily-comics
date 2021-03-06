/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SARAHSSCRIBBLES_H
#define SARAHSSCRIBBLES_H

#include "../Comic.h"

class SarahsScribbles : public Comic
{
    Q_OBJECT

public:
    explicit SarahsScribbles(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SARAHSSCRIBBLES_H
