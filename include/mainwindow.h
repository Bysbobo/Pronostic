/********************************************
    * File Name :   "mainwindow.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  10/11/2017
********************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbmanager.h"
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QObject>
#include <vector>

/**
 * @brief The MainWindow class defines the main window of the Prono application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief The constructor of the Main window.
     * @param parent : The parent of the main window widget.
     */
    MainWindow(QWidget *parent = 0);
    /**
     * @brief The destructor of the main window widget.
     */
    ~MainWindow();

private slots:
    // File Menu Actions
    /**
     * @brief This slot is used to open a file when the open action is clicked.
     */
    void open();
    /**
     * @brief This slot is used to save a file when the save action is clicked.
     */
    void save();
    /**
     * @brief This slot is used to save as a file when the save as action is clicked.
     */
    void saveAs();
    /**
     * @brief This slot is used to exit the application when the exit action is clicked.
     */
    void exit() { QApplication::quit(); }

    // League Menu Actions
    /**
     * @brief This slot is used to display all leagues when the display league action is clicked.
     */
    void displayLeagues();
    /**
     * @brief This slot is used to add a league when the add league action is clicked.
     */
    void addLeague();
    /**
     * @brief This slot is used to edit a league when the edit league action is clicked.
     */
    void editLeague();
    /**
     * @brief This slot is used to delete a league when the delete league action is clicked.
     */
    void deleteLeague();

    // Team Menu Actions
    /**
     * @brief This slot is used to display all teams when the display team action is clicked.
     */
    void displayTeams();
    /**
     * @brief This slot is used to add a team when the add team action is clicked.
     */
    void addTeam();
    /**
     * @brief This slot is used to edit a team when the edit team action is clicked.
     */
    void editTeam();
    /**
     * @brief This slot is used to delete a team when the delete team action is clicked.
     */
    void deleteTeam();

    // Match Menu Actions
    /**
     * @brief This slot is used to display all matches when the display match action is clicked.
     */
    void displayMatches();
    /**
     * @brief This slot is used to add a match when the add match action is clicked.
     */
    void addMatch();
    /**
     * @brief This slot is used to edit a match when the edit match action is clicked.
     */
    void editMatch();
    /**
     * @brief This slot is used to delete a match when the delete match action is clicked.
     */
    void deleteMatch();

    // Help Menu Action
    /**
     * @brief This slot is used to show the about widget when the about action is clicked.
     */
    void about();

private:
    /**
     * @brief This method creates the actions. It should be called before the createMenus() method.
     */
    void createActions();
    /**
     * @brief This method creates the menus. It should be called after the createActions() method.
     */
    void createMenus();
    /**
     * @brief This method updates objects information.
     * @param d : The link to the database connection.
     */
    void updateBoms(DbManager *d);

    // To be deleted
    bool refillMatchFromSaveFileToDatabase(const QString& path);

    // DB Access
    /**
     * @brief aDbConnection : The open connection to DB.
     */
    DbManager *apDbConnection;

    // Menus
    /**
     * @brief apFileMenu : The file menu.
     */
    QMenu *apFileMenu;
    /**
     * @brief apLeagueMenu : The league menu.
     */
    QMenu *apLeagueMenu;
    /**
     * @brief apTeamMenu : The team menu.
     */
    QMenu *apTeamMenu;
    /**
     * @brief apMatchMenu : The match menu.
     */
    QMenu *apMatchMenu;
    /**
     * @brief apHelpMenu : The help menu.
     */
    QMenu *apHelpMenu;

    // File actions
    /**
     * @brief apOpenAction : The open action.
     */
    QAction *apOpenAction;
    /**
     * @brief apSaveAction : The save action.
     */
    QAction *apSaveAction;
    /**
     * @brief apSaveAsAction : The save as action.
     */
    QAction *apSaveAsAction;
    /**
     * @brief apExitAction : The exit action.
     */
    QAction *apExitAction;

    // League actions
    /**
     * @brief apReadLeagueAction : The read league action.
     */
    QAction *apReadLeagueAction;
    /**
     * @brief apAddLeagueAction : The add league action.
     */
    QAction *apAddLeagueAction;
    /**
     * @brief apEditLeagueAction : The edit league action.
     */
    QAction *apEditLeagueAction;
    /**
     * @brief apDeleteLeagueAction : The delete league action.
     */
    QAction *apDeleteLeagueAction;

    // Team actions
    /**
     * @brief apReadTeamAction : The read team action.
     */
    QAction *apReadTeamAction;
    /**
     * @brief apAddTeamAction : The add team action.
     */
    QAction *apAddTeamAction;
    /**
     * @brief apEditTeamAction : The edit team action.
     */
    QAction *apEditTeamAction;
    /**
     * @brief apDeleteTeamAction : The delete team action.
     */
    QAction *apDeleteTeamAction;

    // Match actions
    /**
     * @brief apReadMatchAction : The read match action.
     */
    QAction *apReadMatchAction;
    /**
     * @brief apAddMatchAction : The add match action.
     */
    QAction *apAddMatchAction;
    /**
     * @brief apEditMatchAction : The edit match action.
     */
    QAction *apEditMatchAction;
    /**
     * @brief apDeleteMatchAction : The delete match action.
     */
    QAction *apDeleteMatchAction;

    // Help action
    /**
     * @brief apAboutAction : The about action.
     */
    QAction *apAboutAction;

    std::vector<League*> aLeaguesId;
    std::vector<Match*> aMatchesId;
    std::vector<Team*> aTeamsId;
};

#endif // MAINWINDOW_H
