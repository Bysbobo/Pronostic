/********************************************
    * File Name :   "editmatchwidget.cpp"
    * Authors :     P. Boix and E. Moussy
    * Created on :  10/12/2017
********************************************/

#include "widgets/editmatchwidget.h"

EditMatchWidget::EditMatchWidget(QWidget *parent) : QWidget(parent)
{
    // Set the window title
    setWindowTitle(tr("Create Match"));

    // Create all label and their line edit
    apNameLabel = new QLabel(tr("Name :"));
    apNameLineEdit = new QLineEdit();
    apLeagueIdLabel = new QLabel(tr("League Id :"));
    apLeagueIdLineEdit = new QLineEdit();
    apHomeTeamNameLabel = new QLabel(tr("Hometeam Name :"));
    apHomeTeamNameLineEdit = new QLineEdit();
    apAwayTeamNameLabel = new QLabel(tr("Awayteam Name :"));
    apAwayTeamNameLineEdit = new QLineEdit();
    apHomeTeamScoreLabel = new QLabel(tr("Hometeam score :"));
    apHomeTeamScoreLineEdit = new QLineEdit();
    apAwayTeamScoreLabel = new QLabel(tr("Awayteam score :"));
    apAwayTeamScoreLineEdit = new QLineEdit();

    // Create the buttons
    apCreateBtn = new QPushButton(tr("Create"));
    //connect(apCreateBtn, SIGNAL(pressed()), this, SLOT(createBtnPressed()));
    apCancelBtn = new QPushButton(tr("Cancel"));
    connect(apCancelBtn, SIGNAL(pressed()), this, SLOT(close()));

    // Create the main layout
    apMainLayout = new QGridLayout();
    apMainLayout->addWidget(apNameLabel,             0, 0);
    apMainLayout->addWidget(apNameLineEdit,          0, 1, 1, 2);
    apMainLayout->addWidget(apLeagueIdLabel,         1, 0);
    apMainLayout->addWidget(apLeagueIdLineEdit,      1, 1, 1, 2);
    apMainLayout->addWidget(apHomeTeamNameLabel,     2, 0);
    apMainLayout->addWidget(apHomeTeamNameLineEdit,  2, 1, 1, 2);
    apMainLayout->addWidget(apAwayTeamNameLabel,     3, 0);
    apMainLayout->addWidget(apAwayTeamNameLineEdit,  3, 1, 1, 2);
    apMainLayout->addWidget(apHomeTeamScoreLabel,    4, 0);
    apMainLayout->addWidget(apHomeTeamScoreLineEdit, 4, 1, 1, 2);
    apMainLayout->addWidget(apAwayTeamScoreLabel,    5, 0);
    apMainLayout->addWidget(apAwayTeamScoreLineEdit, 5, 1, 1, 2);
    apMainLayout->addWidget(apCancelBtn,             6, 1, 1, 1, Qt::AlignRight);
    apMainLayout->addWidget(apCreateBtn,             6, 2, 1, 1, Qt::AlignRight);
    setLayout(apMainLayout);
}

EditMatchWidget::~EditMatchWidget()
{
    delete apMainLayout;
    delete apNameLabel;
    delete apNameLineEdit;
    delete apLeagueIdLabel;
    delete apLeagueIdLineEdit;
    delete apHomeTeamNameLabel;
    delete apHomeTeamNameLineEdit;
    delete apAwayTeamNameLabel;
    delete apAwayTeamNameLineEdit;
    delete apHomeTeamScoreLabel;
    delete apHomeTeamScoreLineEdit;
    delete apAwayTeamScoreLabel;
    delete apAwayTeamScoreLineEdit;
    delete apCreateBtn;
    delete apCancelBtn;
}