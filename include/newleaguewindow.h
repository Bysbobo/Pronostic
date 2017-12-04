/********************************************
    * File Name :   "newleaguewindow.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  03/12/2017
********************************************/

#ifndef NEWLEAGUEWINDOW_H
#define NEWLEAGUEWINDOW_H

#include <QMainWindow>

/**
 * @brief The NewLeagueWindow class defines the new league window called for an add of a new league.
 */
class NewLeagueWindow : public QMainWindow
{
public:
	/**
     * @brief The constructor of the new league window.
     * @param parent : The parent of the new league window widget.
     */
	NewLeagueWindow(QWidget *parent = 0);
	/**
     * @brief The destructor of the new league window widget.
     */
	~NewLeagueWindow();

// private slots:    // Introduire Q_OBJECT si slot a inserer

private:

};

#endif // NEWLEAGUEWINDOW_H