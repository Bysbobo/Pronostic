#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sqlite3

connection = sqlite3.connect('../resource/pronostic.sqlite')

cursor = connection.cursor()

request = """SELECT id, name, number_teams FROM league ORDER BY id;"""
cursor.execute(request)
leagueRows = cursor.fetchall()
for leagueRow in leagueRows:
    print('LEAGUE - {0}: {1} contains {2} teams.'.format(leagueRow[0], leagueRow[1], leagueRow[2]))
    #print('Contient {0}/{1} matchs au total'.format(len(leagueRows), leagueRow[2]*(leagueRow[2]-1)))
    
    request =  """SELECT id, small_name, full_name FROM team WHERE leagues_id like '""" + str(leagueRow[0]) + """' """
    request += """or leagues_id like '%,""" + str(leagueRow[0]) + """,%' """
    request += """or leagues_id like '%,""" + str(leagueRow[0]) + """' """
    request += """or leagues_id like '""" + str(leagueRow[0]) + """,%';"""
    nbMatchs = 0
    cursor.execute(request)
    teamRows = cursor.fetchall()
    for teamRow in teamRows:
        print('   TEAM {0}-{1} ({2})'.format(teamRow[0], teamRow[1], teamRow[2]))
        
        request =  """SELECT home_team_id, away_team_id FROM match WHERE home_team_id=""" + str(teamRow[0])
        request += """ and league_id=""" + str(leagueRow[0]) + """;"""
        cursor.execute(request)
        matchRows = cursor.fetchall()
        for matchRow in matchRows: 
            print('      {0} - {1}'.format(matchRow[0], matchRow[1]))
            nbMatchs += 1
    print('Nb Matchs: {0}/{1}'.format(nbMatchs, leagueRow[2]*(leagueRow[2]-1)))


connection.close()
