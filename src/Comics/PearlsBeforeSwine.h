/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef PEARLSBEFORESWINE_H
#define PEARLSBEFORESWINE_H

#include "../Comic.h"

class PearlsBeforeSwine : public Comic
{
    Q_OBJECT

public:
    explicit PearlsBeforeSwine(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // PEARLSBEFORESWINE_H
