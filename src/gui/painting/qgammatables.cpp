/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <private/qdrawhelper_p.h>

QT_BEGIN_NAMESPACE


QDrawHelperGammaTables::QDrawHelperGammaTables(qreal smoothing)
{
    const qreal gray_gamma = 2.31;
    for (int i=0; i<256; ++i)
        qt_pow_gamma[i] = uint(qRound(qPow(i / qreal(255.), gray_gamma) * 2047));
    for (int i=0; i<2048; ++i)
        qt_pow_invgamma[i] = uchar(qRound(qPow(i / qreal(2047.0), 1 / gray_gamma) * 255));

    refresh(smoothing);
}

void QDrawHelperGammaTables::refresh(qreal smoothing)
{
    for (int i=0; i<256; ++i) {
        qt_pow_rgb_gamma[i] = uchar(qRound(qPow(i / qreal(255.0), smoothing) * 255));
        qt_pow_rgb_invgamma[i] = uchar(qRound(qPow(i / qreal(255.), 1 / smoothing) * 255));
    }
}

QT_END_NAMESPACE
