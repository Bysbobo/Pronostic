/********************************************
    * File Name :   "addteamwidget.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  09/12/2017
********************************************/

#include "widgets/addteamwidget.h"

AddTeamWidget::AddTeamWidget(QWidget *parent) : QWidget(parent)
{
    // Set the window title
    setWindowTitle(tr("Create Team"));

    // Create all label and their line edit
    apSmallNameLabel = new QLabel(tr("Small name :"));
    apSmallNameLineEdit = new QLineEdit();
    apFullNameLabel = new QLabel(tr("Full name :"));
    apFullNameLineEdit = new QLineEdit();

    // Create the buttons
    apCreateBtn = new QPushButton(tr("Create"));
    //connect(apCreateBtn, SIGNAL(pressed()), this, SLOT(createBtnPressed()));
    apCancelBtn = new QPushButton(tr("Cancel"));
    connect(apCancelBtn, SIGNAL(pressed()), this, SLOT(close()));

    // Create the main layout
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apSmallNameLabel,    0, 0);
    apMainLayout->addWidget(apSmallNameLineEdit, 0, 1, 1, 2);
    apMainLayout->addWidget(apFullNameLabel,     1, 0);
    apMainLayout->addWidget(apFullNameLineEdit,  1, 1, 1, 2);
    apMainLayout->addWidget(apCancelBtn,         2, 1, 1, 1, Qt::AlignRight);
    apMainLayout->addWidget(apCreateBtn,         2, 2, 1, 1, Qt::AlignRight);
    setLayout(apMainLayout);
}

AddTeamWidget::~AddTeamWidget()
{
    delete apMainLayout;
    delete apSmallNameLabel;
    delete apSmallNameLineEdit;
    delete apFullNameLabel;
    delete apFullNameLineEdit;
    delete apCreateBtn;
    delete apCancelBtn;
}
