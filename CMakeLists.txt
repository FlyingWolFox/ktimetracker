# SPDX-FileCopyrightText: 2019, 2022, 2023 Alexander Potashev <aspotashev@gmail.com>
# SPDX-FileCopyrightText: 2019 Andreas Sturmlechner <asturm@gentoo.org>
# SPDX-FileCopyrightText: 2019 Friedrich W. H. Kossebau <kossebau@kde.org>
# SPDX-FileCopyrightText: 2019 Pino Toscano <pino@kde.org>
# SPDX-FileCopyrightText: 2022 Christophe Giboudeaux <christophe@krop.fr>
# SPDX-FileCopyrightText: 2023 Thiago Masato Costa Sueto <thiago.sueto@kde.org>
# SPDX-FileCopyrightText: 2024 Konstantin Avadov <konstantin.avadov@yahoo.com>
# SPDX-FileCopyrightText: 2026 FlyingWolFox <49326973+FlyingWolFox@users.noreply.github.com>

# SPDX-License-Identifier: BSD-2-Clause

cmake_minimum_required(VERSION 3.16)
set(APP_VERSION_NUMBER "5.1.0")
project(ktimetracker VERSION ${APP_VERSION_NUMBER})

# Older versions have this bug: https://bugs.kde.org/show_bug.cgi?id=451946
set(KF5_MIN_VERSION "5.101.0")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(ECM ${KF5_MIN_VERSION} CONFIG REQUIRED)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

include(ECMAddAppIcon)
include(ECMInstallIcons)
include(ECMQtDeclareLoggingCategory)
include(ECMSetupVersion)
include(FeatureSummary)

ecm_setup_version(${APP_VERSION_NUMBER}
    VARIABLE_PREFIX KTIMETRACKER
    VERSION_HEADER src/ktimetracker-version.h
)

set(QT_REQUIRED_VERSION "5.14.0")
find_package(Qt5 ${QT_REQUIRED_VERSION} CONFIG REQUIRED
    DBus
    Gui
    Widgets
    Xml
)

# TODO merge these two find_package(KF5) calls when KF 5.63.0 matures
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    Config
    ConfigWidgets
    CoreAddons
    DBusAddons
    DocTools
    I18n
    IdleTime
    JobWidgets
    KIO
    Notifications
    XmlGui
    TextWidgets
    CalendarCore
    IconThemes
)
find_package(KF5CalendarCore 4.82.0 CONFIG REQUIRED)

if(NOT WIN32)
    find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
        WindowSystem
    )
endif()

add_subdirectory(icons)
add_subdirectory(doc)
add_subdirectory(src)

install(FILES org.kde.ktimetracker.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})

ki18n_install(po)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

include(KDEGitCommitHooks)
kde_configure_git_pre_commit_hook(CHECKS JSON_SCHEMA CLANG_FORMAT)
