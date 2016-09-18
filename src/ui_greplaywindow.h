/********************************************************************************
** Form generated from reading UI file 'greplaywindow.ui'
**
** Created: Tue May 7 23:23:07 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GREPLAYWINDOW_H
#define UI_GREPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gReplayWindow
{
public:
    QWidget *centralwidget;
    QFrame *gameFrame;
    QTextEdit *textEditGame;
    QFrame *deskFrame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnClose;
    QPushButton *btnNext;
    QPushButton *btnUndo;
    QPushButton *btnGoTo;
    QLineEdit *editGoToNum;
    QLineEdit *editAutoPlayInterval;
    QLabel *labelInterval;
    QPushButton *btnStop;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gReplayWindow)
    {
        if (gReplayWindow->objectName().isEmpty())
            gReplayWindow->setObjectName(QString::fromUtf8("gReplayWindow"));
        gReplayWindow->resize(601, 439);
        centralwidget = new QWidget(gReplayWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gameFrame = new QFrame(centralwidget);
        gameFrame->setObjectName(QString::fromUtf8("gameFrame"));
        gameFrame->setGeometry(QRect(0, 0, 601, 421));
        gameFrame->setFrameShape(QFrame::NoFrame);
        gameFrame->setFrameShadow(QFrame::Raised);
        textEditGame = new QTextEdit(gameFrame);
        textEditGame->setObjectName(QString::fromUtf8("textEditGame"));
        textEditGame->setGeometry(QRect(420, 10, 171, 261));
        textEditGame->setReadOnly(true);
        deskFrame = new QFrame(gameFrame);
        deskFrame->setObjectName(QString::fromUtf8("deskFrame"));
        deskFrame->setGeometry(QRect(10, 10, 400, 400));
        deskFrame->setFrameShape(QFrame::StyledPanel);
        deskFrame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(deskFrame);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 400, 400));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnClose = new QPushButton(gameFrame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(510, 370, 81, 23));
        QFont font;
        font.setPointSize(10);
        btnClose->setFont(font);
        btnNext = new QPushButton(gameFrame);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(510, 280, 81, 23));
        btnUndo = new QPushButton(gameFrame);
        btnUndo->setObjectName(QString::fromUtf8("btnUndo"));
        btnUndo->setGeometry(QRect(420, 280, 81, 23));
        btnUndo->setFont(font);
        btnGoTo = new QPushButton(gameFrame);
        btnGoTo->setObjectName(QString::fromUtf8("btnGoTo"));
        btnGoTo->setGeometry(QRect(420, 340, 81, 23));
        btnGoTo->setFont(font);
        editGoToNum = new QLineEdit(gameFrame);
        editGoToNum->setObjectName(QString::fromUtf8("editGoToNum"));
        editGoToNum->setGeometry(QRect(510, 340, 81, 20));
        editGoToNum->setFont(font);
        editAutoPlayInterval = new QLineEdit(gameFrame);
        editAutoPlayInterval->setObjectName(QString::fromUtf8("editAutoPlayInterval"));
        editAutoPlayInterval->setGeometry(QRect(510, 310, 81, 20));
        editAutoPlayInterval->setFont(font);
        labelInterval = new QLabel(gameFrame);
        labelInterval->setObjectName(QString::fromUtf8("labelInterval"));
        labelInterval->setGeometry(QRect(420, 310, 81, 16));
        labelInterval->setFont(font);
        btnStop = new QPushButton(gameFrame);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setGeometry(QRect(420, 370, 81, 23));
        btnStop->setFont(font);
        gReplayWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(gReplayWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setSizeGripEnabled(false);
        gReplayWindow->setStatusBar(statusbar);

        retranslateUi(gReplayWindow);

        QMetaObject::connectSlotsByName(gReplayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *gReplayWindow)
    {
        gReplayWindow->setWindowTitle(QApplication::translate("gReplayWindow", "Dama2013", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("gReplayWindow", "Close", 0, QApplication::UnicodeUTF8));
        btnNext->setText(QApplication::translate("gReplayWindow", "Next", 0, QApplication::UnicodeUTF8));
        btnUndo->setText(QApplication::translate("gReplayWindow", "Undo", 0, QApplication::UnicodeUTF8));
        btnGoTo->setText(QApplication::translate("gReplayWindow", "Goto", 0, QApplication::UnicodeUTF8));
        editGoToNum->setText(QApplication::translate("gReplayWindow", "0", 0, QApplication::UnicodeUTF8));
        editAutoPlayInterval->setText(QApplication::translate("gReplayWindow", "0", 0, QApplication::UnicodeUTF8));
        labelInterval->setText(QApplication::translate("gReplayWindow", "Interval (ms)", 0, QApplication::UnicodeUTF8));
        btnStop->setText(QApplication::translate("gReplayWindow", "Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gReplayWindow: public Ui_gReplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GREPLAYWINDOW_H
