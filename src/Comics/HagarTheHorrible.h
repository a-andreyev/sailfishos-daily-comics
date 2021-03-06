/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef HAGARTHEHORRIBLE_H
#define HAGARTHEHORRIBLE_H

#include "../Comic.h"

class HagarTheHorrible : public Comic
{
    Q_OBJECT

public:
    explicit HagarTheHorrible(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // HAGARTHEHORRIBLE_H
