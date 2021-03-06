/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DILBERT_H
#define DILBERT_H

#include "../Comic.h"

class Dilbert : public Comic
{
    Q_OBJECT

public:
    explicit Dilbert(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // DILBERT_H
