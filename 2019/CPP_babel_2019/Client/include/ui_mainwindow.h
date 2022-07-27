/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLog_out;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_9;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLineEdit *first_name_reg;
    QLineEdit *last_name_reg;
    QLineEdit *user_reg;
    QLineEdit *mail_reg;
    QLineEdit *pass_reg;
    QLineEdit *conf_pass_reg;
    QLineEdit *port_reg;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *sign_up;
    QPushButton *cancel_reg;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *Register;
    QLineEdit *port_edit_login;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_5;
    QPushButton *push_6;
    QTabWidget *tabWidget;
    QWidget *contacts;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidget;
    QWidget *Add_c;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineEdit_4;
    QPushButton *add_contact;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *call_button;
    QLabel *label_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_3;
    QPushButton *send_button;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_2;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout_8;
    QPushButton *servConnect;
    QGridLayout *gridLayout_9;
    QLineEdit *servIp;
    QLineEdit *servPort;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QMenuBar *menubar;
    QMenu *menuile;
    QMenu *menuOptions;
    QMenu *menu_propos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1379, 750);
        QFont font;
        font.setFamily(QString::fromUtf8("Abyssinica SIL"));
        MainWindow->setFont(font);
        actionLog_out = new QAction(MainWindow);
        actionLog_out->setObjectName(QString::fromUtf8("actionLog_out"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_9 = new QVBoxLayout(centralwidget);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_7 = new QHBoxLayout(page);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMouseTracking(false);
        groupBox->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        groupBox->setCheckable(false);
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(13, 348, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        first_name_reg = new QLineEdit(groupBox);
        first_name_reg->setObjectName(QString::fromUtf8("first_name_reg"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(first_name_reg->sizePolicy().hasHeightForWidth());
        first_name_reg->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(first_name_reg);

        last_name_reg = new QLineEdit(groupBox);
        last_name_reg->setObjectName(QString::fromUtf8("last_name_reg"));
        sizePolicy1.setHeightForWidth(last_name_reg->sizePolicy().hasHeightForWidth());
        last_name_reg->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(last_name_reg);

        user_reg = new QLineEdit(groupBox);
        user_reg->setObjectName(QString::fromUtf8("user_reg"));
        sizePolicy1.setHeightForWidth(user_reg->sizePolicy().hasHeightForWidth());
        user_reg->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(user_reg);

        mail_reg = new QLineEdit(groupBox);
        mail_reg->setObjectName(QString::fromUtf8("mail_reg"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mail_reg->sizePolicy().hasHeightForWidth());
        mail_reg->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(mail_reg);

        pass_reg = new QLineEdit(groupBox);
        pass_reg->setObjectName(QString::fromUtf8("pass_reg"));
        sizePolicy2.setHeightForWidth(pass_reg->sizePolicy().hasHeightForWidth());
        pass_reg->setSizePolicy(sizePolicy2);
        pass_reg->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(pass_reg);

        conf_pass_reg = new QLineEdit(groupBox);
        conf_pass_reg->setObjectName(QString::fromUtf8("conf_pass_reg"));
        sizePolicy2.setHeightForWidth(conf_pass_reg->sizePolicy().hasHeightForWidth());
        conf_pass_reg->setSizePolicy(sizePolicy2);
        conf_pass_reg->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(conf_pass_reg);

        port_reg = new QLineEdit(groupBox);
        port_reg->setObjectName(QString::fromUtf8("port_reg"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(port_reg->sizePolicy().hasHeightForWidth());
        port_reg->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(port_reg);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(label);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(17, 268, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sign_up = new QPushButton(groupBox);
        sign_up->setObjectName(QString::fromUtf8("sign_up"));
        sizePolicy3.setHeightForWidth(sign_up->sizePolicy().hasHeightForWidth());
        sign_up->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(sign_up);

        cancel_reg = new QPushButton(groupBox);
        cancel_reg->setObjectName(QString::fromUtf8("cancel_reg"));
        sizePolicy3.setHeightForWidth(cancel_reg->sizePolicy().hasHeightForWidth());
        cancel_reg->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(cancel_reg);


        verticalLayout_7->addLayout(horizontalLayout_2);


        horizontalLayout_6->addWidget(groupBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_12->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_2);


        horizontalLayout_7->addLayout(verticalLayout_12);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalSpacer_6 = new QSpacerItem(20, 225, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_6, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(474, 55, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        gridLayout_4->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));

        gridLayout_4->addWidget(pushButton_3, 3, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));

        gridLayout_3->addWidget(lineEdit, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(lineEdit_2, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        Register = new QPushButton(page_2);
        Register->setObjectName(QString::fromUtf8("Register"));

        gridLayout_4->addWidget(Register, 4, 0, 1, 1);

        port_edit_login = new QLineEdit(page_2);
        port_edit_login->setObjectName(QString::fromUtf8("port_edit_login"));
        sizePolicy2.setHeightForWidth(port_edit_login->sizePolicy().hasHeightForWidth());
        port_edit_login->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(port_edit_login, 1, 0, 1, 1);


        horizontalLayout_8->addLayout(gridLayout_4);

        horizontalSpacer_4 = new QSpacerItem(505, 55, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        gridLayout_5->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 255, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_5, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_5);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_6 = new QVBoxLayout(page_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        push_6 = new QPushButton(page_3);
        push_6->setObjectName(QString::fromUtf8("push_6"));
        push_6->setFlat(true);

        verticalLayout_5->addWidget(push_6);

        tabWidget = new QTabWidget(page_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy4);
        tabWidget->setMaximumSize(QSize(171, 16777215));
        contacts = new QWidget();
        contacts->setObjectName(QString::fromUtf8("contacts"));
        verticalLayout_4 = new QVBoxLayout(contacts);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        listWidget = new QListWidget(contacts);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));

        verticalLayout_4->addWidget(listWidget);

        tabWidget->addTab(contacts, QString());
        Add_c = new QWidget();
        Add_c->setObjectName(QString::fromUtf8("Add_c"));
        gridLayout_7 = new QGridLayout(Add_c);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(Add_c);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy3.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(lineEdit_4, 1, 0, 1, 1);

        add_contact = new QPushButton(Add_c);
        add_contact->setObjectName(QString::fromUtf8("add_contact"));
        sizePolicy2.setHeightForWidth(add_contact->sizePolicy().hasHeightForWidth());
        add_contact->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(add_contact, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 3, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget->addTab(Add_c, QString());

        verticalLayout_5->addWidget(tabWidget);


        gridLayout_11->addLayout(verticalLayout_5, 0, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        call_button = new QPushButton(page_3);
        call_button->setObjectName(QString::fromUtf8("call_button"));
        call_button->setStyleSheet(QString::fromUtf8("background-color: rgb(245,145,66)"));

        horizontalLayout_4->addWidget(call_button);

        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(114, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));

        horizontalLayout_4->addWidget(label_2);


        gridLayout_10->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textBrowser = new QTextBrowser(page_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setLayoutDirection(Qt::LeftToRight);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));

        gridLayout_2->addWidget(textBrowser, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));

        horizontalLayout->addWidget(lineEdit_3);

        send_button = new QPushButton(page_3);
        send_button->setObjectName(QString::fromUtf8("send_button"));
        sizePolicy3.setHeightForWidth(send_button->sizePolicy().hasHeightForWidth());
        send_button->setSizePolicy(sizePolicy3);
        send_button->setStyleSheet(QString::fromUtf8("background-color: rbg(255,255,255)"));

        horizontalLayout->addWidget(send_button);


        gridLayout_2->addLayout(horizontalLayout, 1, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_2, 1, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_11);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_8 = new QVBoxLayout(page_4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox_2 = new QGroupBox(page_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));

        verticalLayout_8->addWidget(groupBox_2);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        verticalLayout_3 = new QVBoxLayout(page_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalSpacer_8 = new QSpacerItem(20, 225, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_8, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_7 = new QSpacerItem(491, 55, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        servConnect = new QPushButton(page_5);
        servConnect->setObjectName(QString::fromUtf8("servConnect"));

        gridLayout_8->addWidget(servConnect, 2, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        servIp = new QLineEdit(page_5);
        servIp->setObjectName(QString::fromUtf8("servIp"));
        sizePolicy2.setHeightForWidth(servIp->sizePolicy().hasHeightForWidth());
        servIp->setSizePolicy(sizePolicy2);
        servIp->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));

        gridLayout_9->addWidget(servIp, 0, 0, 1, 1);

        servPort = new QLineEdit(page_5);
        servPort->setObjectName(QString::fromUtf8("servPort"));
        sizePolicy2.setHeightForWidth(servPort->sizePolicy().hasHeightForWidth());
        servPort->setSizePolicy(sizePolicy2);
        servPort->setMaximumSize(QSize(137, 16777215));
        servPort->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));
        servPort->setEchoMode(QLineEdit::Normal);

        gridLayout_9->addWidget(servPort, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_9, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));

        gridLayout_8->addLayout(horizontalLayout_10, 1, 0, 1, 1);


        horizontalLayout_9->addLayout(gridLayout_8);

        horizontalSpacer_8 = new QSpacerItem(491, 55, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);


        gridLayout_6->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 255, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_9, 2, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_6);

        stackedWidget->addWidget(page_5);

        verticalLayout_9->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1379, 19));
        menuile = new QMenu(menubar);
        menuile->setObjectName(QString::fromUtf8("menuile"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menu_propos = new QMenu(menubar);
        menu_propos->setObjectName(QString::fromUtf8("menu_propos"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menu_propos->menuAction());
        menuile->addAction(actionLog_out);
        menuile->addAction(actionQuitter);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLog_out->setText(QApplication::translate("MainWindow", "Se d\303\251connecter", nullptr));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "             REGISTRATION", nullptr));
        first_name_reg->setText(QString());
        first_name_reg->setPlaceholderText(QApplication::translate("MainWindow", "First name", nullptr));
        last_name_reg->setText(QString());
        last_name_reg->setPlaceholderText(QApplication::translate("MainWindow", "Last name", nullptr));
        user_reg->setText(QString());
        user_reg->setPlaceholderText(QApplication::translate("MainWindow", "Username               *", nullptr));
        mail_reg->setText(QString());
        mail_reg->setPlaceholderText(QApplication::translate("MainWindow", "Email address", nullptr));
        pass_reg->setText(QString());
        pass_reg->setPlaceholderText(QApplication::translate("MainWindow", "Password                *", nullptr));
        conf_pass_reg->setText(QString());
        conf_pass_reg->setPlaceholderText(QApplication::translate("MainWindow", "Confirm password  *", nullptr));
        port_reg->setPlaceholderText(QApplication::translate("MainWindow", "Open Port               *", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">* must be filled</span></p></body></html>", nullptr));
        sign_up->setText(QApplication::translate("MainWindow", "Sign up", nullptr));
        cancel_reg->setText(QApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Login", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Username", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "Password", nullptr));
        Register->setText(QApplication::translate("MainWindow", "Register", nullptr));
        port_edit_login->setPlaceholderText(QApplication::translate("MainWindow", "Open Port for chat and call (ex 4242)", nullptr));
        push_6->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(contacts), QApplication::translate("MainWindow", "Contacts", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("MainWindow", "Username", nullptr));
        add_contact->setText(QApplication::translate("MainWindow", "Add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Add_c), QApplication::translate("MainWindow", "+", nullptr));
        call_button->setText(QApplication::translate("MainWindow", "Call", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Connected</p></body></html>", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("MainWindow", "Type your text here", nullptr));
        send_button->setText(QApplication::translate("MainWindow", "Envoyer", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        servConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        servIp->setPlaceholderText(QApplication::translate("MainWindow", "Ip (Default: 127.0.0.1)", nullptr));
        servPort->setPlaceholderText(QApplication::translate("MainWindow", "Port (Default: 4242)", nullptr));
        menuile->setTitle(QApplication::translate("MainWindow", "Compte", nullptr));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", nullptr));
        menu_propos->setTitle(QApplication::translate("MainWindow", "\303\240 propos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
