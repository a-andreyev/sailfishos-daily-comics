/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SIGMUND_H
#define SIGMUND_H

#include "../Comic.h"

class Sigmund : public Comic
{
    Q_OBJECT

public:
    explicit Sigmund(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SIGMUND_H
