KTimeTracker 5.1.0 (release date: 2026-01-18)
--------
- Fixed "Bug 415499 - Cannot build on latest Ubuntu" (Ubuntu 20.04 Focal Fossa).
  Downgraded KCalCore/KCalendarCore dependency version.
- Fixed "Bug 417988 - Columns displayed do not match configuration"
- Fixed time formatting in "Hours:Minutes" mode on 32 bit architectures
- Fixed crashes when trying to open a corrupted .ics file
- Fixed column time sorting. Sorting is now done numerically instead of lexicographically
- Added the option to display the current task in the window title
- Added the option to display the currently active tasks and the session times in
  the window title instead of the currently opened ical file.
- Exposed startNewSession via dbus
- Added a new export type: CSV log of all entries
  The new export type exports all entries, or all entries in a given time
  period if specified, in CSV format.
- Updated all icons in the app with the new Plasma design
- Added translations
- Removed file:// prefix from the ical file path shown in the window title
- Fixed a possible crash related to idle time detection
- Made some performance optimizations

KTimeTracker 5.0.1 (release date: 2019-12-21)
--------
- Fixed "Bug 415387 - Application icon is not installed"

KTimeTracker 5.0 (release date: 2019-12-19)
--------
- Ported to KDE Frameworks 5
- Nearly all the code touched by refactoring
- Removed KParts support
- Removed web interface in PHP
- Removed CLI commands for tasks manupulation
- Simplified configuration dialog internals, previously implemented as KCM shared libraries
- Added unit tests (using Qt Test)
- Rewrote D-Bus functional tests and benchmark in Python3 (py.test), previously written as Bash scripts
- Ported to KF5::IdleTime for idle detection, thus removing dependency on X11
- Do not create empty .ics file if it does not exist
- Fixed "Bug 325683 - Both "mark as complete" and "mark as incomplete" are mapped to ctrl+m"
- Reworked the export dialog, added preview of exportable text
- Added appstream XML metadata
- Added dedicated dialog "Edit Task Time" to increment/decrement time spent on a task

KTimeTracker 4.1 (Jul 2008 -- KDE 4.1 Release)
--------
- Renamed KArm (KDE 3) to ktimetracker (KDE 4)
- Added "Manage History" functionality (including comments on events)
- Moved DCOP interface to DBUS
- Added Drag&Drop
- Added context-sensitive whatsthis help ("you have already created a task and can start timing")
- If you quit karm, tasks can continue to get timing

KArm 1.6 
--------
- Added checkbox to show completed tasks

KArm 1.5 (Feb, 2005 -- KDE 3.4 Release)
--------
- Added import of Imedio Planner files
- Added DCOP interface
- api docs now build
- Enable CSV export to a remote server
- If another program changes current ical file, KArm now refreshes
- Added testing subdirectory
- Add ability to use remote resources for ical file

Karm 1.4 (Aug 19, 2004 -- KDE 3.3 Release)
--------
- Add confirm messagebox on "reset all times" action
- Improve messagebox text for "copy totals to clipboard" action
- Add preference setting to allow user to turn off logging
- Add CSV export
- Don't crash if timer running when you change storage file
- If storage read-only, disable actions that change data
- Honor user's timezone
- Save tree state (open/closed) between sessions
- Edit task dialog: show full desktop name, not just desktop number
- Sort data in time columns numerically, not alphabetically
- Allow negative task times
- Modify desktop tracking so timers delay before switching when desktop
  switches. So if user switches rapidly, time log won't fill up with lots of
useless entries.
- Advanced locking (bug #71292)

KArm 1.3 (Feb 3, 2004 -- KDE 3.2 Release)
--------
- Desktop tracking added
- Active task indication in the system tray
- Uses iCalendar format for data storage
- Stores start/stop history
- Settings dialog converted to icon format
- "Reset Session Times" re-reversed and renamed to "Start New Session" for
  clarity.
- New timecard report
- Ability to mark tasks as complete
- Basic locking

KArm 1.2
--------
- "Reset Session Times" wouldn't get reset correctly.
  Thanks to dwayne for reporting and to Scott Monachello for
  the fix.                                              closes: #34343

KArm 1.1
--------
- clocks are stopped and times saved upon exit

KArm 0.6
--------
- It is now possible to type in the time like 3:20, or 3:20 + 1:10
- The two QListBoxes with time and description has been replaced with one
  QListView. This makes the interface nicer, and simplifies a lot internally.

KArm 0.3
--------
- Fixes edit task bugs
- Complies to new FSSTND

KArm 0.2
--------
- Now supports floating toolbar
- Documentation converted to linuxdoc
