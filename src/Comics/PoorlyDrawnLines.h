/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef POORLYDRAWNLINES_H
#define POORLYDRAWNLINES_H

#include "../Comic.h"

class PoorlyDrawnLines : public Comic
{
    Q_OBJECT

public:
    explicit PoorlyDrawnLines(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // POORLYDRAWNLINES_H
