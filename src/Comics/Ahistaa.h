/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef AHISTAA_H
#define AHISTAA_H

#include "../Comic.h"

class Ahistaa : public Comic
{
    Q_OBJECT

public:
    explicit Ahistaa(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // AHISTAA_H
