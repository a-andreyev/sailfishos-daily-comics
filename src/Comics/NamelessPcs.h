/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef NAMELESSPCS_H
#define NAMELESSPCS_H

#include "../Comic.h"

class NamelessPcs : public Comic
{
    Q_OBJECT

public:
    explicit NamelessPcs(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // NAMELESSPCS_H
