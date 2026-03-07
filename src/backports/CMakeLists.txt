# SPDX-FileCopyrightText: 2026 FlyingWolFox <49326973+FlyingWolFox@users.noreply.github.com>
# SPDX-License-Identifier: GPL-3.0-only

target_sources(ktt-backports
    PRIVATE
    kicontheme.cpp kicontheme.h
)

# KF5 version (Optional, usually unnecessary for building)
find_package(BreezeIcons)

target_link_libraries(ktt-backports
    PRIVATE
    ktt-deps
    KF5::ConfigWidgets
)
