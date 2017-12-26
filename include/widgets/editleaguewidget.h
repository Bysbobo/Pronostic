/********************************************
    * File Name :   "editleaguewidget.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  10/12/2017
********************************************/

#ifndef EDITLEAGUEWIDGET_H
#define EDITLEAGUEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

/**
 * @brief The EditLeagueWidget class is a widget allowing to create a new match.
 */
class EditLeagueWidget : public QWidget
{
public:
	/**
     * @brief Constructor of the EditLeagueWidget class.
     * @param parent : The parent item of the widget.
     */
	explicit EditLeagueWidget(QWidget *parent = 0);
	/**
     * @brief Destructor.
     */
	~EditLeagueWidget();

private:
    /**
     * @brief apMainLayout : The main layout of the widget.
     */
    QGridLayout *apMainLayout;

    /**
     * @brief apNameLabel : The name label.
     */
    QLabel *apNameLabel;
    /**
     * @brief apNameLineEdit : The line edit in wich the name of the league should be inserted.
     */
    QLineEdit *apNameLineEdit;

    /**
     * @brief apAreaLabel : The area label.
     */
    QLabel *apAreaLabel;
    /**
     * @brief apAreaLineEdit : The line edit in wich the name of the area should be inserted.
     */
    QLineEdit *apAreaLineEdit;

    /**
     * @brief apCreateBtn : The button to create the new league.
     */
    QPushButton *apCreateBtn;
    /**
     * @brief apCancelBtn : The buton to cancel the creation of the new league.
     */
    QPushButton *apCancelBtn;
};

#endif // EDITLEAGUEWIDGET_H