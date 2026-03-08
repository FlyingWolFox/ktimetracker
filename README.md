<!--
# SPDX-FileCopyrightText: 2021 Alexander Potashev <aspotashev@gmail.com>
# SPDX-FileCopyrightText: 2024 Thiago Masato Costa Sueto <thiago.sueto@kde.org>
# SPDX-FileCopyrightText: 2026 FlyingWolFox <49326973+FlyingWolFox@users.noreply.github.com>
# SPDX-License-Identifier: CC-BY-SA-4.0
-->

# KTimeTracker

KTimeTracker fork with continuing Qt5 support and more frequent releases.

This fork keeps the `kf5` branch up to date with upstream master as best it can, dropping Qt6-only features and porting the rest. It also adds some features of my own, but these are also available in the master branch (Qt6).

Qt5 releases will continue using the 5.x version namespace, while Qt6 releases will use <latest>-0fwfX (e.g. 6.0.0-0fwf1), debian style.

Qt5 efforts are mostly to get stuff working on Linux Mint 22, based on ubuntu noble, and some debian packaging related stuff will be in the `kf5` branch. Qt6 efforts are mostly to get a version with the latest changes + some patches of my own, so I can use it on Windows.

Fork Features:

- Releases are up to date with upstream: Latest features and fixes on both Qt5 and Qt6 versions
- More frequent releases: New features and fixes are always available

Original README:

---

![pipeline](https://invent.kde.org/pim/ktimetracker/badges/master/pipeline.svg?ignore_skipped=true)

[KTimeTracker](https://apps.kde.org/ktimetracker/) tracks time spent on various tasks. It is useful for tracking hours to be billed to different clients or just to find out what percentage of your day is spent playing Doom or reading Slashdot.

You can install KTimeTracker on Linux via [Discover](appstream://org.kde.ktimetracker.desktop) or as a [Flatpak on Flathub](https://flathub.org/apps/org.kde.ktimetracker).

For developers and bug reporters we provide [Flatpak Nightlies](https://cdn.kde.org/flatpak/ktimetracker-nightly/org.kde.ktimetracker.flatpakref).

<a href='https://flathub.org/apps/org.kde.ktimetracker'><img width='150' alt='Download on Flathub' src='https://flathub.org/api/badge?locale=en'/></a>

The last Windows build for KTimeTracker before the port for Qt6 can be downloaded [here](https://invent.kde.org/pim/ktimetracker/-/jobs/1629409/artifacts/file/.kde-ci-packages/ktimetracker-kf5-265-windows-cl-msvc2019-x86_64.exe) ([full file list and checksum](https://invent.kde.org/pim/ktimetracker/-/jobs/1629409/artifacts/browse/.kde-ci-packages/))

If you'd like to contribute to KTimeTracker, see [CONTRIBUTING.md](CONTRIBUTING.md).

## Structure

* [src/dialogs/](src/dialogs): dialogs used for small tasks (creating tasks, editing time, history, export)
* [src/export/](src/export): the logic for exporting backup copies in multiple formats
* [src/file/](src/file): the main session file in `~/.local/share/ktimetracker/ktimetracker.ics`
* [src/import/](src/import): used to import GNOME Planner files
* [src/model/](src/model): the base for events/tasks/projects
* [src/settings/](src/settings): the Settings dialog, as well as the KConfigXT files
* [src/widgets/](src/widgets): specialized widgets (search bar, percent progress bar, context menus)

The `kf5` branch includes the latest Qt5 version. It will no longer receive updates.

The `master` branch includes the latest Qt6 version. It does not have a Windows build.

## Building

The easiest way to make changes and test KTimeTracker during development is to build it with [kdesrc-build](https://community.kde.org/Get_Involved/development/Build_software_with_kdesrc-build).

To build it as a standalone app:

```bash
cmake -B build/ -DCMAKE_INSTALL_PREFIX=$HOME/kde/usr
cmake --build build/
cmake --install build/
```

Use `-DBUILD_TESTING=ON` to enable tests.

## Credits

KTimeTracker was originaly written by Sirtaj Singh Kang and named KArm. The word "karm" means "work" in the author's native Punjabi.

KTimeTracker was inspired by Harald Tveit Alvestrand's very useful utility called titrax; we added some eyecandy and functionality like subtasks.
