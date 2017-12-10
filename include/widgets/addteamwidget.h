/********************************************
    * File Name :   "addteamwidget.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  09/12/2017
********************************************/

#ifndef ADDTEAMWIDGET_H
#define ADDTEAMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

/**
 * @brief The AddTeamWidget class is a widget allowing to create a new team.
 */
class AddTeamWidget : public QWidget
{

public:
	/**
     * @brief Constructor of the AddTeamWidget class.
     * @param parent : The parent item of the widget.
     */
	explicit AddTeamWidget(QWidget *parent = 0);
	/**
     * @brief Destructor.
     */
	~AddTeamWidget();

private:
	/**
     * @brief apMainLayout : The main layout of the widget.
     */
    QGridLayout *apMainLayout;

    /**
     * @brief apSmallNameLabel : The small name label.
     */
    QLabel *apSmallNameLabel;
    /**
     * @brief apSmallNameLineEdit : The line edit in wich the small name of the team should be inserted.
     */
    QLineEdit *apSmallNameLineEdit;

    /**
     * @brief apFullNameLabel : The full name label.
     */
    QLabel *apFullNameLabel;
    /**
     * @brief apFullNameLineEdit : The line edit in wich the full name of the team should be inserted.
     */
    QLineEdit *apFullNameLineEdit;

    /**
     * @brief apCreateBtn : The button to create the new team.
     */
    QPushButton *apCreateBtn;
    /**
     * @brief apCancelBtn : The buton to cancel the creation of the new team.
     */
    QPushButton *apCancelBtn;
};

#endif // ADDTEAMWIDGET_H