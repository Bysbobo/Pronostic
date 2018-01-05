#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sqlite3

connection = sqlite3.connect('../resource/pronostic.sqlite')

cursor = connection.cursor()

cursor.execute("SELECT id, name, number_teams FROM league ORDER BY id;")
leagueRows = cursor.fetchall()
for row in leagueRows:
    print('LEAGUE - {0}: {1} contains {2} teams.'.format(row[0], row[1], row[2]))
    
    cursor.execute("SELECT home_team_id, away_team_id FROM match WHERE league_id=?;", (row[0],))
    matchRows = cursor.fetchall()
    for match in matchRows:
        print('{0}-{1}'.format(match[0], match[1]))






connection.close()