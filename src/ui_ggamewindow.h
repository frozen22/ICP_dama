/********************************************************************************
** Form generated from reading UI file 'ggamewindow.ui'
**
** Created: Wed May 8 17:52:00 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGAMEWINDOW_H
#define UI_GGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gGameWindow
{
public:
    QWidget *centralwidget;
    QFrame *gameFrame;
    QTextEdit *textEditGame;
    QFrame *deskFrame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnHighLightGame;
    QPushButton *btnSaveXMLGame;
    QPushButton *btnSaveBasicGame;
    QPushButton *btnBackGame;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gGameWindow)
    {
        if (gGameWindow->objectName().isEmpty())
            gGameWindow->setObjectName(QString::fromUtf8("gGameWindow"));
        gGameWindow->resize(581, 440);
        centralwidget = new QWidget(gGameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gameFrame = new QFrame(centralwidget);
        gameFrame->setObjectName(QString::fromUtf8("gameFrame"));
        gameFrame->setGeometry(QRect(0, 0, 581, 421));
        gameFrame->setFrameShape(QFrame::NoFrame);
        gameFrame->setFrameShadow(QFrame::Raised);
        textEditGame = new QTextEdit(gameFrame);
        textEditGame->setObjectName(QString::fromUtf8("textEditGame"));
        textEditGame->setGeometry(QRect(420, 10, 151, 271));
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
        btnHighLightGame = new QPushButton(gameFrame);
        btnHighLightGame->setObjectName(QString::fromUtf8("btnHighLightGame"));
        btnHighLightGame->setGeometry(QRect(420, 290, 151, 23));
        QFont font;
        font.setPointSize(10);
        btnHighLightGame->setFont(font);
        btnSaveXMLGame = new QPushButton(gameFrame);
        btnSaveXMLGame->setObjectName(QString::fromUtf8("btnSaveXMLGame"));
        btnSaveXMLGame->setGeometry(QRect(420, 350, 151, 23));
        btnSaveXMLGame->setFont(font);
        btnSaveBasicGame = new QPushButton(gameFrame);
        btnSaveBasicGame->setObjectName(QString::fromUtf8("btnSaveBasicGame"));
        btnSaveBasicGame->setGeometry(QRect(420, 320, 151, 23));
        btnSaveBasicGame->setFont(font);
        btnBackGame = new QPushButton(gameFrame);
        btnBackGame->setObjectName(QString::fromUtf8("btnBackGame"));
        btnBackGame->setGeometry(QRect(420, 380, 151, 23));
        btnBackGame->setFont(font);
        gGameWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(gGameWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setSizeGripEnabled(false);
        gGameWindow->setStatusBar(statusbar);

        retranslateUi(gGameWindow);

        QMetaObject::connectSlotsByName(gGameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *gGameWindow)
    {
        gGameWindow->setWindowTitle(QApplication::translate("gGameWindow", "Dama2013", 0, QApplication::UnicodeUTF8));
        btnHighLightGame->setText(QApplication::translate("gGameWindow", "Highlight", 0, QApplication::UnicodeUTF8));
        btnSaveXMLGame->setText(QApplication::translate("gGameWindow", "Save - XML", 0, QApplication::UnicodeUTF8));
        btnSaveBasicGame->setText(QApplication::translate("gGameWindow", "Save - Basic", 0, QApplication::UnicodeUTF8));
        btnBackGame->setText(QApplication::translate("gGameWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gGameWindow: public Ui_gGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGAMEWINDOW_H
