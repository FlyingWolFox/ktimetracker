/*

    This file is part of the KDE project, module kdecore.
    SPDX-FileCopyrightText: 2000 Geert Jansen <jansen@kde.org>
    SPDX-FileCopyrightText: 2000 Antonio Larrosa <larrosa@kde.org>
    SPDX-FileCopyrightText: 2026 FlyingWolFox <49326973+FlyingWolFox@users.noreply.github.com>

    Modified 2026 by FlyingWolFox:
    Extracted initTheme from KF6 and adapted it to work with KF5.
    Unnecessary code was removed.

    SPDX-License-Identifier: LGPL-2.0-only
*/

#ifndef KICONTHEME_BACKPORT_H
#define KICONTHEME_BACKPORT_H

#include <QList>
#include <QLoggingCategory>
#include <QString>
#include <QStringList>

#include <memory>

class KIconThemeBackport
{
public:
    /*!
     * Enforces the Breeze icon theme (including our KIconEngine for re-coloring).
     *
     * If the user has configured a different icon set, that one will be taken.
     *
     * (following the settings in the application configuration with fallback to kdeglobals)
     *
     * Must be called before the construction of the first Q(Core)Application, as it
     * might need to modify plugin loading and installs a startup function.
     *
     * If the application is already using the KDE platform theme, the icon set will not
     * be touched and the platform theme will ensure proper theming.
     *
     * Does setup the needed KColorSchemeManager to follow the system color mode starting
     * with version 6.6.
     *
     * Ported from KF6 to work with KF5.
     *
     * \since 6.3
     */
    static void initTheme();
};

#endif
