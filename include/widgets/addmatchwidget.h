/********************************************
    * File Name :   "addmatchwidget.h"
    * Authors :     P. Boix and E. Moussy
    * Created on :  09/12/2017
********************************************/

#ifndef ADDMATCHWIDGET_H
#define ADDMATCHWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

/**
 * @brief The AddMatchWidget class is a widget allowing to create a new match.
 */
class AddMatchWidget : public QWidget
{

public:
	/**
     * @brief Constructor of the AddMatchWidget class.
     * @param parent : The parent item of the widget.
     */
	explicit AddMatchWidget(QWidget *parent = 0);
	/**
     * @brief Destructor.
     */
	~AddMatchWidget();

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
     * @brief apNameLineEdit : The line edit in wich the name of the match should be inserted.
     */
    QLineEdit *apNameLineEdit;

    /**
     * @brief apLeagueIdLabel : The league id label.
     */
    QLabel *apLeagueIdLabel;
    /**
     * @brief apLeagueIdLineEdit : The line edit in wich the league id of the match should be inserted.
     */
    QLineEdit *apLeagueIdLineEdit;

    /**
     * @brief apHomeTeamNameLabel : The hometeam name label.
     */
    QLabel *apHomeTeamNameLabel;
    /**
     * @brief apHomeTeamNameLineEdit : The line edit in wich the hometeam name of the match should be inserted.
     */
    QLineEdit *apHomeTeamNameLineEdit;

    /**
     * @brief apAwayTeamNameLabel : The awayteam name label.
     */
    QLabel *apAwayTeamNameLabel;
    /**
     * @brief apAwayTeamNameLineEdit : The line edit in wich the awayteam name of the match should be inserted.
     */
    QLineEdit *apAwayTeamNameLineEdit;

    /**
     * @brief apHomeTeamScoreLabel : The hometeam score label.
     */
    QLabel *apHomeTeamScoreLabel;
    /**
     * @brief apHomeTeamScoreLineEdit : The line edit in wich the hometeam score of the match should be inserted.
     */
    QLineEdit *apHomeTeamScoreLineEdit;

    /**
     * @brief apAwayTeamScoreLabel : The awayteam name label.
     */
    QLabel *apAwayTeamScoreLabel;
    /**
     * @brief apAwayTeamScoreLineEdit : The line edit in wich the awayteam name of the match should be inserted.
     */
    QLineEdit *apAwayTeamScoreLineEdit;

    /**
     * @brief apCreateBtn : The button to create the new match.
     */
    QPushButton *apCreateBtn;
    /**
     * @brief apCancelBtn : The buton to cancel the creation of the new match.
     */
    QPushButton *apCancelBtn;
};

#endif // ADDMATCHWIDGET_H