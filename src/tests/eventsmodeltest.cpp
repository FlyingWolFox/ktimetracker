/*
    SPDX-FileCopyrightText: 2026 Gemini CLI
    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#include "model/eventsmodel.h"
#include "model/event.h"
#include <QTest>

class EventsModelTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testEarliestStartDateEmpty();
    void testEarliestStartDate();
};

void EventsModelTest::testEarliestStartDateEmpty()
{
    EventsModel model;
    QDateTime now = QDateTime::currentDateTime();
    QDateTime earliest = model.earliestStartDate();
    // It should be roughly 'now'
    QVERIFY(std::abs(now.secsTo(earliest)) < 2);
}

void EventsModelTest::testEarliestStartDate()
{
    EventsModel model;
    QDateTime d1 = QDateTime(QDate(2020, 1, 1), QTime(10, 0));
    QDateTime d2 = QDateTime(QDate(2021, 1, 1), QTime(10, 0));
    QDateTime d3 = QDateTime(QDate(2019, 1, 1), QTime(10, 0));

    KCalendarCore::Event::Ptr e1(new KCalendarCore::Event());
    e1->setDtStart(d1);
    model.addEvent(new Event(e1));

    KCalendarCore::Event::Ptr e2(new KCalendarCore::Event());
    e2->setDtStart(d2);
    model.addEvent(new Event(e2));

    KCalendarCore::Event::Ptr e3(new KCalendarCore::Event());
    e3->setDtStart(d3);
    model.addEvent(new Event(e3));

    QCOMPARE(model.earliestStartDate(), d3);
}

QTEST_MAIN(EventsModelTest)

#include "eventsmodeltest.moc"
