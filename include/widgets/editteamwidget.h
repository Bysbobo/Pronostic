/********************************************
    * File Name :   "editteamwidget.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  10/12/2017
********************************************/

#ifndef EDITTEAMWIDGET_H
#define EDITTEAMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

/**
 * @brief The EditTeamWidget class is a widget allowing to create a new team.
 */
class EditTeamWidget : public QWidget
{
public:
	/**
     * @brief Constructor of the EditTeamWidget class.
     * @param parent : The parent item of the widget.
     */
	explicit EditTeamWidget(QWidget *parent = 0);
	/**
     * @brief Destructor.
     */
	~EditTeamWidget();

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

#endif // EDITTEAMWIDGET_H