/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu May 9 22:21:10 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *mainMenuFrame;
    QPushButton *btnLocalAI;
    QPushButton *btnOnlineMP;
    QPushButton *btnLocalMP;
    QPushButton *btnExit;
    QPushButton *btnReplay;
    QFrame *gameTypeFrame;
    QPushButton *btnNewGame;
    QPushButton *btnContinueGame;
    QPushButton *btnBackGameType;
    QGroupBox *groupBox;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QFrame *hostConnectFrame;
    QPushButton *btnHostHostConnect;
    QPushButton *btnConnectHostConnect;
    QPushButton *btnBackHostConnect;
    QFrame *connectFrame;
    QPushButton *btnConnect;
    QPushButton *btnConnectBack;
    QLabel *labelPortConnect;
    QLabel *labelAddrConnect;
    QLineEdit *editPortConnect;
    QLineEdit *editAddrConnect;
    QFrame *hostFrame;
    QLabel *labelPortHost;
    QLineEdit *editPortHost;
    QPushButton *btnHost;
    QPushButton *btnBackHost;
    QFrame *loadFrame;
    QTextEdit *textEditLoad;
    QPushButton *btnLoadBasic;
    QPushButton *btnLoadXML;
    QPushButton *btnLoadContinue;
    QPushButton *btnLoadBack;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1254, 631);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mainMenuFrame = new QFrame(centralWidget);
        mainMenuFrame->setObjectName(QString::fromUtf8("mainMenuFrame"));
        mainMenuFrame->setGeometry(QRect(0, 0, 191, 391));
        mainMenuFrame->setFrameShape(QFrame::NoFrame);
        mainMenuFrame->setFrameShadow(QFrame::Raised);
        btnLocalAI = new QPushButton(mainMenuFrame);
        btnLocalAI->setObjectName(QString::fromUtf8("btnLocalAI"));
        btnLocalAI->setGeometry(QRect(10, 10, 171, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        btnLocalAI->setFont(font);
        btnLocalAI->setAutoDefault(false);
        btnLocalAI->setDefault(false);
        btnLocalAI->setFlat(false);
        btnOnlineMP = new QPushButton(mainMenuFrame);
        btnOnlineMP->setObjectName(QString::fromUtf8("btnOnlineMP"));
        btnOnlineMP->setGeometry(QRect(10, 90, 171, 31));
        QFont font1;
        font1.setPointSize(10);
        btnOnlineMP->setFont(font1);
        btnLocalMP = new QPushButton(mainMenuFrame);
        btnLocalMP->setObjectName(QString::fromUtf8("btnLocalMP"));
        btnLocalMP->setGeometry(QRect(10, 50, 171, 31));
        btnLocalMP->setFont(font1);
        btnExit = new QPushButton(mainMenuFrame);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(10, 350, 171, 31));
        btnExit->setFont(font1);
        btnReplay = new QPushButton(mainMenuFrame);
        btnReplay->setObjectName(QString::fromUtf8("btnReplay"));
        btnReplay->setGeometry(QRect(10, 130, 171, 31));
        btnReplay->setFont(font1);
        gameTypeFrame = new QFrame(centralWidget);
        gameTypeFrame->setObjectName(QString::fromUtf8("gameTypeFrame"));
        gameTypeFrame->setEnabled(true);
        gameTypeFrame->setGeometry(QRect(210, 10, 191, 391));
        gameTypeFrame->setFrameShape(QFrame::NoFrame);
        gameTypeFrame->setFrameShadow(QFrame::Raised);
        btnNewGame = new QPushButton(gameTypeFrame);
        btnNewGame->setObjectName(QString::fromUtf8("btnNewGame"));
        btnNewGame->setGeometry(QRect(10, 60, 171, 31));
        btnNewGame->setFont(font1);
        btnContinueGame = new QPushButton(gameTypeFrame);
        btnContinueGame->setObjectName(QString::fromUtf8("btnContinueGame"));
        btnContinueGame->setGeometry(QRect(10, 100, 171, 31));
        btnContinueGame->setFont(font1);
        btnBackGameType = new QPushButton(gameTypeFrame);
        btnBackGameType->setObjectName(QString::fromUtf8("btnBackGameType"));
        btnBackGameType->setGeometry(QRect(10, 350, 171, 31));
        btnBackGameType->setFont(font1);
        groupBox = new QGroupBox(gameTypeFrame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 171, 41));
        groupBox->setFont(font1);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(100, 14, 51, 20));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 14, 51, 20));
        radioButton->setChecked(true);
        hostConnectFrame = new QFrame(centralWidget);
        hostConnectFrame->setObjectName(QString::fromUtf8("hostConnectFrame"));
        hostConnectFrame->setGeometry(QRect(810, 10, 191, 391));
        hostConnectFrame->setFrameShape(QFrame::NoFrame);
        hostConnectFrame->setFrameShadow(QFrame::Raised);
        btnHostHostConnect = new QPushButton(hostConnectFrame);
        btnHostHostConnect->setObjectName(QString::fromUtf8("btnHostHostConnect"));
        btnHostHostConnect->setGeometry(QRect(10, 10, 171, 31));
        btnHostHostConnect->setFont(font1);
        btnConnectHostConnect = new QPushButton(hostConnectFrame);
        btnConnectHostConnect->setObjectName(QString::fromUtf8("btnConnectHostConnect"));
        btnConnectHostConnect->setGeometry(QRect(10, 50, 171, 31));
        btnConnectHostConnect->setFont(font1);
        btnBackHostConnect = new QPushButton(hostConnectFrame);
        btnBackHostConnect->setObjectName(QString::fromUtf8("btnBackHostConnect"));
        btnBackHostConnect->setGeometry(QRect(10, 352, 171, 31));
        btnBackHostConnect->setFont(font1);
        connectFrame = new QFrame(centralWidget);
        connectFrame->setObjectName(QString::fromUtf8("connectFrame"));
        connectFrame->setGeometry(QRect(610, 10, 191, 391));
        connectFrame->setFrameShape(QFrame::NoFrame);
        connectFrame->setFrameShadow(QFrame::Raised);
        btnConnect = new QPushButton(connectFrame);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(10, 70, 171, 31));
        btnConnect->setFont(font1);
        btnConnect->setFlat(false);
        btnConnectBack = new QPushButton(connectFrame);
        btnConnectBack->setObjectName(QString::fromUtf8("btnConnectBack"));
        btnConnectBack->setGeometry(QRect(10, 352, 171, 31));
        btnConnectBack->setFont(font1);
        labelPortConnect = new QLabel(connectFrame);
        labelPortConnect->setObjectName(QString::fromUtf8("labelPortConnect"));
        labelPortConnect->setGeometry(QRect(10, 10, 46, 13));
        labelPortConnect->setFont(font1);
        labelAddrConnect = new QLabel(connectFrame);
        labelAddrConnect->setObjectName(QString::fromUtf8("labelAddrConnect"));
        labelAddrConnect->setGeometry(QRect(10, 40, 46, 13));
        labelAddrConnect->setFont(font1);
        editPortConnect = new QLineEdit(connectFrame);
        editPortConnect->setObjectName(QString::fromUtf8("editPortConnect"));
        editPortConnect->setGeometry(QRect(60, 10, 121, 20));
        editPortConnect->setFont(font1);
        editAddrConnect = new QLineEdit(connectFrame);
        editAddrConnect->setObjectName(QString::fromUtf8("editAddrConnect"));
        editAddrConnect->setGeometry(QRect(60, 40, 121, 20));
        editAddrConnect->setFont(font1);
        hostFrame = new QFrame(centralWidget);
        hostFrame->setObjectName(QString::fromUtf8("hostFrame"));
        hostFrame->setGeometry(QRect(410, 10, 191, 391));
        hostFrame->setFrameShape(QFrame::NoFrame);
        hostFrame->setFrameShadow(QFrame::Raised);
        labelPortHost = new QLabel(hostFrame);
        labelPortHost->setObjectName(QString::fromUtf8("labelPortHost"));
        labelPortHost->setGeometry(QRect(10, 10, 46, 13));
        labelPortHost->setFont(font1);
        editPortHost = new QLineEdit(hostFrame);
        editPortHost->setObjectName(QString::fromUtf8("editPortHost"));
        editPortHost->setGeometry(QRect(40, 10, 141, 20));
        editPortHost->setFont(font1);
        btnHost = new QPushButton(hostFrame);
        btnHost->setObjectName(QString::fromUtf8("btnHost"));
        btnHost->setGeometry(QRect(10, 40, 171, 31));
        btnHost->setFont(font1);
        btnBackHost = new QPushButton(hostFrame);
        btnBackHost->setObjectName(QString::fromUtf8("btnBackHost"));
        btnBackHost->setGeometry(QRect(10, 352, 171, 31));
        btnBackHost->setFont(font1);
        loadFrame = new QFrame(centralWidget);
        loadFrame->setObjectName(QString::fromUtf8("loadFrame"));
        loadFrame->setGeometry(QRect(1010, 10, 191, 391));
        loadFrame->setFrameShape(QFrame::NoFrame);
        loadFrame->setFrameShadow(QFrame::Raised);
        textEditLoad = new QTextEdit(loadFrame);
        textEditLoad->setObjectName(QString::fromUtf8("textEditLoad"));
        textEditLoad->setGeometry(QRect(10, 10, 171, 311));
        btnLoadBasic = new QPushButton(loadFrame);
        btnLoadBasic->setObjectName(QString::fromUtf8("btnLoadBasic"));
        btnLoadBasic->setGeometry(QRect(10, 330, 81, 23));
        btnLoadBasic->setFont(font1);
        btnLoadXML = new QPushButton(loadFrame);
        btnLoadXML->setObjectName(QString::fromUtf8("btnLoadXML"));
        btnLoadXML->setGeometry(QRect(100, 330, 81, 23));
        btnLoadXML->setFont(font1);
        btnLoadContinue = new QPushButton(loadFrame);
        btnLoadContinue->setObjectName(QString::fromUtf8("btnLoadContinue"));
        btnLoadContinue->setGeometry(QRect(100, 360, 81, 23));
        btnLoadContinue->setFont(font1);
        btnLoadBack = new QPushButton(loadFrame);
        btnLoadBack->setObjectName(QString::fromUtf8("btnLoadBack"));
        btnLoadBack->setGeometry(QRect(10, 360, 81, 23));
        btnLoadBack->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dama2013", 0, QApplication::UnicodeUTF8));
        btnLocalAI->setText(QApplication::translate("MainWindow", "Local AI", 0, QApplication::UnicodeUTF8));
        btnOnlineMP->setText(QApplication::translate("MainWindow", "Online MP", 0, QApplication::UnicodeUTF8));
        btnLocalMP->setText(QApplication::translate("MainWindow", "Local MP", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        btnReplay->setText(QApplication::translate("MainWindow", "Replay", 0, QApplication::UnicodeUTF8));
        btnNewGame->setText(QApplication::translate("MainWindow", "New Game", 0, QApplication::UnicodeUTF8));
        btnContinueGame->setText(QApplication::translate("MainWindow", "Continue Game", 0, QApplication::UnicodeUTF8));
        btnBackGameType->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Choose your color", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Black", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "White", 0, QApplication::UnicodeUTF8));
        btnHostHostConnect->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
        btnConnectHostConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        btnBackHostConnect->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
        btnConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        btnConnectBack->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
        labelPortConnect->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        labelAddrConnect->setText(QApplication::translate("MainWindow", "Address", 0, QApplication::UnicodeUTF8));
        editPortConnect->setText(QApplication::translate("MainWindow", "11111", 0, QApplication::UnicodeUTF8));
        editAddrConnect->setText(QApplication::translate("MainWindow", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        labelPortHost->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        editPortHost->setText(QApplication::translate("MainWindow", "11111", 0, QApplication::UnicodeUTF8));
        btnHost->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
        btnBackHost->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
        textEditLoad->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        btnLoadBasic->setText(QApplication::translate("MainWindow", "Load Basic", 0, QApplication::UnicodeUTF8));
        btnLoadXML->setText(QApplication::translate("MainWindow", "Load XML", 0, QApplication::UnicodeUTF8));
        btnLoadContinue->setText(QApplication::translate("MainWindow", "Continue", 0, QApplication::UnicodeUTF8));
        btnLoadBack->setText(QApplication::translate("MainWindow", "Back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
