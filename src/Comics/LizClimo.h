/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef LIZCLIMO_H
#define LIZCLIMO_H

#include "../Comic.h"

class LizClimo : public Comic
{
    Q_OBJECT

public:
    explicit LizClimo(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // LIZCLIMO_H
