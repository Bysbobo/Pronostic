/********************************************
    * File Name : 	"mainwindow.cpp"
    * Authors : 	P. Boix and E. Moussy
    * Created on : 	10/11/2017
********************************************/

#include "mainwindow.h"
#include "team.h"
#include "match.h"
#include "league.h"
#include "singleton.h"
#include "widgets/addleaguewidget.h"
#include "widgets/addmatchwidget.h"
#include "widgets/addteamwidget.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QFile>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Set window properties
    setWindowTitle(tr("Prono"));
    setMinimumWidth(800);
    setMinimumHeight(600);

    // Create the menus and their repective actions
    createActions();
    createMenus();

    // Create the DB connection
    apDbConnection = DbManager::getInstance(ROOTTODB);

    // Update boms from database
    updateBoms(apDbConnection);
/*
    // Out of scope - Just to fill matches DB
    if( !refillMatchFromSaveFileToDatabase(ROOTTOMATCHES) )
        std::cout << "Aaaaaaaarf" << std::endl;
*/
    // Show the status bar
    statusBar()->showMessage(tr("Ready"), 2000);
}

MainWindow::~MainWindow()
{
    // File actions
    delete apOpenAction;
    delete apSaveAction;
    delete apSaveAsAction;
    delete apExitAction;

    // League actions
    delete apReadLeagueAction;
    delete apAddLeagueAction;
    delete apEditLeagueAction;
    delete apDeleteLeagueAction;

    // Team actions
    delete apReadTeamAction;
    delete apAddTeamAction;
    delete apEditTeamAction;
    delete apDeleteTeamAction;

    // Match actions
    delete apReadMatchAction;
    delete apAddMatchAction;
    delete apEditMatchAction;
    delete apDeleteMatchAction;

    // Help action
    delete apAboutAction;

    // Menus
    delete apFileMenu;
    delete apLeagueMenu;
    delete apTeamMenu;
    delete apMatchMenu;
    delete apHelpMenu;

    // DB Connection
    apDbConnection->kill();
}

void MainWindow::updateBoms(DbManager *d)
{
    Team *tmpT = new Team();
    for (int i = 1; d->extractTeam(i, *tmpT); ++i)
    {
        Team *t = new Team(*tmpT);
        aTeamsId.push_back(t);
    }

    Match *tmpM = new Match();
    for (int i = 1; d->extractMatch(i, *tmpM); ++i)
    {
        Match *m = new Match(*tmpM);
        aMatchesId.push_back(m);
    }

    League *tmpL = new League();
    for (int i = 1; d->extractLeague(i, *tmpL); ++i)
    {
        League *l = new League(*tmpL);
        aLeaguesId.push_back(l);
    }
}

bool MainWindow::refillMatchFromSaveFileToDatabase(const QString& path)
{
    QFile filePath(path);
    if (!filePath.open(QFile::ReadOnly))
    {
        qWarning() << "Failed to open Matchs.txt for reading!";
        return false;
    }

    int firstScore, secondScore, totalIndicator(0);
    QString firstTeam, secondTeam;

    QTextStream stream(&filePath);
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList list = line.split('/');
        
        int count(-1);
        unsigned int listSize = list.size();
        for (unsigned int i = 0; i < listSize; ++i)
        {
            ++count;
            if (count == 0 || count == 1)
                continue;

            bool ok = false;
            switch(count % 4)
            {
                case 2:
                    firstTeam   = list[i]; break;
                case 3:
                    firstScore  = list[i].toInt(&ok); break;
                case 0:
                    secondScore = list[i].toInt(&ok); break;
                case 1:
                    secondTeam  = list[i]; break;
            }

            if ((count % 4) == 1)
            {
                unsigned int firstTeamInd  = retrieveTeamIndicator(firstTeam);
                unsigned int secondTeamInd = retrieveTeamIndicator(secondTeam);
                
                qDebug() << totalIndicator + 1 << ":"
                         << firstTeam << " (" << firstTeamInd
                         << ") - "
                         << secondTeam << " (" << secondTeamInd
                         << ") / " << firstScore << " - " << secondScore;
            
                if (apDbConnection->isOpen())
                {
                    if (!apDbConnection->fillMatch(++totalIndicator, firstTeamInd, secondTeamInd, firstScore, secondScore))
                        stream << "Oups..." << endl;
                }
            }
        }
    }
    
    filePath.close();
    return true;
}

unsigned int MainWindow::retrieveTeamIndicator(const QString& smallNameToFind)
{
    long unsigned int teamSize = aTeamsId.size();
    for (unsigned int i = 0; i < teamSize; ++i)
    {
        if (aTeamsId[i]->getSmallName() == smallNameToFind)
            return i+1;
    }

    return 0;
}

void MainWindow::createActions()
{
    // File Menu Actions
    apOpenAction = new QAction(tr("Open..."), this);
    apOpenAction->setStatusTip(tr("Load a new file"));
    apOpenAction->setShortcut(QKeySequence::Open);
    QObject::connect(apOpenAction, SIGNAL(triggered(bool)), this, SLOT(open()));

    apSaveAction = new QAction(tr("Save"), this);
    apSaveAction->setStatusTip(tr("Save file"));
    apSaveAction->setShortcut(QKeySequence::Save);
    QObject::connect(apSaveAction, SIGNAL(triggered(bool)), this, SLOT(save()));

    apSaveAsAction = new QAction(tr("Save As..."), this);
    apSaveAsAction->setStatusTip(tr("Save file to another location/name"));
    apSaveAsAction->setShortcut(QKeySequence::SaveAs);
    QObject::connect(apSaveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));

    apExitAction = new QAction(tr("Exit"), this);
    apExitAction->setStatusTip(tr("Exit the application"));
    apExitAction->setShortcut(QKeySequence::Quit);
    QObject::connect(apExitAction, SIGNAL(triggered(bool)), this, SLOT(exit()));

    // League Menu Actions
    apReadLeagueAction = new QAction(tr("Display all the leagues"), this);
    QObject::connect(apReadLeagueAction, SIGNAL(triggered(bool)), this, SLOT(displayLeagues()));

    apAddLeagueAction = new QAction(tr("Add League..."), this);
    apAddLeagueAction->setStatusTip(tr("Create a new league"));
    QObject::connect(apAddLeagueAction, SIGNAL(triggered(bool)), this, SLOT(addLeague()));

    apEditLeagueAction = new QAction(tr("Edit League..."), this);
    apEditLeagueAction->setStatusTip(tr("Edit an existing league"));
    QObject::connect(apEditLeagueAction, SIGNAL(triggered(bool)), this, SLOT(editLeague()));

    apDeleteLeagueAction = new QAction(tr("Delete League..."), this);
    apDeleteLeagueAction->setStatusTip(tr("Delete an existing league"));
    QObject::connect(apDeleteLeagueAction, SIGNAL(triggered(bool)), this, SLOT(deleteLeague()));

    // Team actions
    apReadTeamAction = new QAction(tr("Display all the teams"), this);
    QObject::connect(apReadTeamAction, SIGNAL(triggered(bool)), this, SLOT(displayTeams()));

    apAddTeamAction = new QAction(tr("Add Team..."), this);
    apAddTeamAction->setStatusTip(tr("Create a new team"));
    QObject::connect(apAddTeamAction, SIGNAL(triggered(bool)), this, SLOT(addTeam()));

    apEditTeamAction = new QAction(tr("Edit Team..."), this);
    apEditTeamAction->setStatusTip(tr("Edit an existing team"));
    QObject::connect(apEditTeamAction, SIGNAL(triggered(bool)), this, SLOT(editTeam()));

    apDeleteTeamAction = new QAction(tr("Delete Team..."), this);
    apDeleteTeamAction->setStatusTip(tr("Delete an existing team"));
    QObject::connect(apDeleteTeamAction, SIGNAL(triggered(bool)), this, SLOT(deleteTeam()));

    // Match actions
    apReadMatchAction = new QAction(tr("Display all the matches"), this);
    QObject::connect(apReadMatchAction, SIGNAL(triggered(bool)), this, SLOT(displayMatches()));

    apAddMatchAction = new QAction(tr("Add Match..."), this);
    apAddMatchAction->setStatusTip(tr("Create a new match"));
    QObject::connect(apAddMatchAction, SIGNAL(triggered(bool)), this, SLOT(addMatch()));

    apEditMatchAction = new QAction(tr("Edit Match..."), this);
    apEditMatchAction->setStatusTip(tr("Edit an existing match"));
    QObject::connect(apEditMatchAction, SIGNAL(triggered(bool)), this, SLOT(editMatch()));

    apDeleteMatchAction = new QAction(tr("Delete Match..."), this);
    apDeleteMatchAction->setStatusTip(tr("Delete an existing match"));
    QObject::connect(apDeleteMatchAction, SIGNAL(triggered(bool)), this, SLOT(deleteMatch()));

    // Help action
    apAboutAction = new QAction(tr("About..."), this);
    apAboutAction->setStatusTip(tr("About Prono application"));
    QObject::connect(apAboutAction, SIGNAL(triggered(bool)), this, SLOT(about()));
}

void MainWindow::createMenus()
{
    // File Menu
    apFileMenu = menuBar()->addMenu(tr("File"));
    apFileMenu->addAction(apOpenAction);
    apFileMenu->addSeparator();
    apFileMenu->addAction(apSaveAction);
    apFileMenu->addAction(apSaveAsAction);
    apFileMenu->addSeparator();
    apFileMenu->addAction(apExitAction);

    // League Menu
    apLeagueMenu = menuBar()->addMenu(tr("League"));
    apLeagueMenu->addAction(apReadLeagueAction);
    apLeagueMenu->addAction(apAddLeagueAction);
    apLeagueMenu->addAction(apEditLeagueAction);
    apLeagueMenu->addAction(apDeleteLeagueAction);

    // Team Menu
    apTeamMenu = menuBar()->addMenu(tr("Team"));
    apTeamMenu->addAction(apReadTeamAction);
    apTeamMenu->addAction(apAddTeamAction);
    apTeamMenu->addAction(apEditTeamAction);
    apTeamMenu->addAction(apDeleteTeamAction);

    // Match Menu
    apMatchMenu = menuBar()->addMenu(tr("Match"));
    apMatchMenu->addAction(apReadMatchAction);
    apMatchMenu->addAction(apAddMatchAction);
    apMatchMenu->addAction(apEditMatchAction);
    apMatchMenu->addAction(apDeleteMatchAction);

    // Help Menu
    apHelpMenu = menuBar()->addMenu(tr("Help"));
    apHelpMenu->addAction(apAboutAction);
}

void MainWindow::open()
{

}

void MainWindow::save()
{

}

void MainWindow::saveAs()
{

}

void MainWindow::displayLeagues()
{
    const long unsigned int leagueSize = aLeaguesId.size();
    for (unsigned int i = 0; i < leagueSize; ++i)
        aLeaguesId[i]->displayAll();
}

void MainWindow::addLeague()
{
    // Create the add league widget
    AddLeagueWidget *wdg = new AddLeagueWidget();
    wdg->show();
    wdg->setWindowModality(Qt::ApplicationModal);
}

void MainWindow::editLeague()
{

}

void MainWindow::deleteLeague()
{

}

void MainWindow::displayTeams()
{
    const long unsigned int teamSize = aTeamsId.size();
    for (unsigned int i = 0; i < teamSize; ++i)
        aTeamsId[i]->displayAll();
}

void MainWindow::addTeam()
{
    // Create the add team widget
    AddTeamWidget *wdg = new AddTeamWidget();
    wdg->show();
    wdg->setWindowModality(Qt::ApplicationModal);
}

void MainWindow::editTeam()
{

}

void MainWindow::deleteTeam()
{

}

void MainWindow::displayMatches()
{
    const long unsigned int matchSize = aMatchesId.size();
    for (unsigned int i = 0; i < matchSize; ++i)
        aMatchesId[i]->displayAll();
}

void MainWindow::addMatch()
{
    // Create the add match widget
    AddMatchWidget *wdg = new AddMatchWidget();
    wdg->show();
    wdg->setWindowModality(Qt::ApplicationModal);
}

void MainWindow::editMatch()
{

}

void MainWindow::deleteMatch()
{

}

void MainWindow::about()
{

}