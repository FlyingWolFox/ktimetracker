/*

    kicontheme.cpp: Lowlevel icon theme handling.

    This file is part of the KDE project, module kdecore.
    SPDX-FileCopyrightText: 2000 Geert Jansen <jansen@kde.org>
    SPDX-FileCopyrightText: 2000 Antonio Larrosa <larrosa@kde.org>
    SPDX-FileCopyrightText: 2026 FlyingWolFox <49326973+FlyingWolFox@users.noreply.github.com>

    Modified 2026 by FlyingWolFox:
    Extracted initTheme and initThemeHelper from KF6 and adapted it to work with KF5.
    Unnecessary code was removed.

    SPDX-License-Identifier: LGPL-2.0-only
*/

#include "kicontheme.h"

#include "debug.h"

#include <KColorSchemeManager>
#include <KConfigGroup>
#include <KLocalizedString> // KLocalizedString::localizedFilePath. Need such functionality in, hmm, QLocale? QStandardPaths?
#include <KSharedConfig>

#include <QAction>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QMap>
#include <QResource>
#include <QSet>
#include <QTimer>

#include <qplatformdefs.h>

#include <array>
#include <cmath>
#include <iostream>

Q_GLOBAL_STATIC(QString, _themeOverride)

Q_LOGGING_CATEGORY(KICONTHEMES, "kf.iconthemes.backport")

// not available in KF5
// #include <BreezeIcons>

// do init only once and avoid later helpers to mess with it again
static bool initThemeUsed = false;

// startup function to set theme once the app got constructed
static void initThemeHelper()
{
    // make sure we add application install path to search path, for e.g. bundles on Windows
    if (initThemeUsed) {
        // do that similar to QCoreApplicationPrivate::appendApplicationPathToLibraryPaths() with minimal extra API use
        QString path = QCoreApplication::applicationFilePath();
        path.truncate(path.lastIndexOf(QLatin1Char('/')));
        if (const QString ourPath = path + QStringLiteral("/kiconthemes5"); QFile::exists(ourPath)) {
            QCoreApplication::addLibraryPath(ourPath);
        }
    }

    // KF5 Backport:
    // We cannot load binary resources (BreezeIcons::initIcons), but we
    // MUST set the fallback theme so Qt knows where to look if icons are missing.
    if (QIcon::fallbackThemeName().isEmpty()) {
        QIcon::setFallbackThemeName(QStringLiteral("breeze"));
    }

    // only do further stuff if we requested it
    if (!initThemeUsed) {
        return;
    }

    // KF5 Backport: Check if we are in a KDE session.
    // If so, the platform plugin (plasma-integration) handles the icons automatically.
    if (!qEnvironmentVariableIsEmpty("KDE_FULL_SESSION")) {
        return;
    }

    // Alternative: If a theme is already set (by the platform theme), don't override it.
    if (!QIcon::themeName().isEmpty() && QIcon::themeName() != QLatin1String("hicolor")) {
        return;
    }

    // get config, with fallback to kdeglobals
    const auto config = KSharedConfig::openConfig();

    // enforce the theme configured by the user, with kdeglobals fallback
    // if not set, use Breeze
    const QString themeToUse = KConfigGroup(config, "Icons").readEntry("Theme", QStringLiteral("breeze"));

    // use Qt API to really fully override the engine, if we set KIconEngine the Key in our plugin will
    // enforce that our engine is used
    // https://codereview.qt-project.org/c/qt/qtbase/+/563241
    QIcon::setThemeName(themeToUse);

    // Tell KIconTheme about the theme, in case KIconLoader is used directly
    *_themeOverride() = themeToUse;
    qCDebug(KICONTHEMES) << "KIconTheme::initTheme() enforces the icon theme:" << themeToUse;

    // postpone until QGuiApplication applies initial palette
    QTimer::singleShot(0, [] {
        // KF5 Backport: KColorSchemeManager is not a singleton in KF5.
        // We instantiate a new one and parent it to the application so it persists.
        // This loads the color schemes from disk.
        new KColorSchemeManager(QCoreApplication::instance());
    });
}

void KIconThemeBackport::initTheme()
{
    // inject paths only once
    if (!initThemeUsed) {
        // inject our icon engine in the search path
        // it will be used as the first found engine for a suffix will be taken
        // this must be done before the QCoreApplication is constructed
        const auto paths = QCoreApplication::libraryPaths();
        for (const auto &path : paths) {
            if (const QString ourPath = path + QStringLiteral("/kiconthemes5"); QFile::exists(ourPath)) {
                QCoreApplication::addLibraryPath(ourPath);
            }
        }
    }

    // initThemeHelper will do the remaining work via Q_COREAPP_STARTUP_FUNCTION(initThemeHelper)
    initThemeUsed = true;
}

Q_COREAPP_STARTUP_FUNCTION(initThemeHelper)
