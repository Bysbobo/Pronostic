/********************************************
    * File Name :   "editleaguewidget.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  10/12/2017
********************************************/

#include "widgets/editleaguewidget.h"

EditLeagueWidget::EditLeagueWidget(QWidget *parent) : QWidget(parent)
{
    // Set the window title
    setWindowTitle(tr("Edit League"));

    // Create all label and their line edit
    apNameLabel = new QLabel(tr("Name :"));
    apNameLineEdit = new QLineEdit();
    apAreaLabel = new QLabel(tr("Area :"));
    apAreaLineEdit = new QLineEdit();

    // Create the buttons
    apCreateBtn = new QPushButton(tr("Create"));
    //connect(apCreateBtn, SIGNAL(pressed()), this, SLOT(createBtnPressed()));
    apCancelBtn = new QPushButton(tr("Cancel"));
    connect(apCancelBtn, SIGNAL(pressed()), this, SLOT(close()));

    // Create the main layout
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apNameLabel,    0, 0);
    apMainLayout->addWidget(apNameLineEdit, 0, 1, 1, 2);
    apMainLayout->addWidget(apAreaLabel,    1, 0);
    apMainLayout->addWidget(apAreaLineEdit, 1, 1, 1, 2);
    apMainLayout->addWidget(apCancelBtn,    2, 1, 1, 1, Qt::AlignRight);
    apMainLayout->addWidget(apCreateBtn,    2, 2, 1, 1, Qt::AlignRight);
    setLayout(apMainLayout);
}

EditLeagueWidget::~EditLeagueWidget()
{
    delete apMainLayout;
    delete apNameLabel;
    delete apNameLineEdit;
    delete apAreaLabel;
    delete apAreaLineEdit;
    delete apCreateBtn;
    delete apCancelBtn;
}