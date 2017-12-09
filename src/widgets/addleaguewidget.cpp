/********************************************
    * File Name :   "addleaguewidget.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  08/12/2017
********************************************/

#include "widgets/addleaguewidget.h"
#include <QMessageBox>

AddLeagueWidget::AddLeagueWidget(QWidget *parent) : QWidget(parent)
{
    // Set the window title
    setWindowTitle(tr("Create League"));

    // Create the name label and line edit
    apNameLabel = new QLabel(tr("Name :"));
    apNameLineEdit = new QLineEdit();

    // Create the buttons
    apCreateBtn = new QPushButton(tr("Create"));
    //connect(apCreateBtn, SIGNAL(pressed()), this, SLOT(createBtnPressed()));
    apCancelBtn = new QPushButton(tr("Cancel"));
    connect(apCancelBtn, SIGNAL(pressed()), this, SLOT(close()));

    // Create the main layout
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apNameLabel,    0, 0);
    apMainLayout->addWidget(apNameLineEdit, 0, 1, 1, 2);
    apMainLayout->addWidget(apCancelBtn,    1, 1, 1, 1, Qt::AlignRight);
    apMainLayout->addWidget(apCreateBtn,    1, 2, 1, 1, Qt::AlignRight);
    setLayout(apMainLayout);
}

AddLeagueWidget::~AddLeagueWidget()
{
    delete apMainLayout;
    delete apNameLabel;
    delete apNameLineEdit;
    delete apCreateBtn;
    delete apCancelBtn;
}
