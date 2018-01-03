#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sqlite3

connection = sqlite3.connect('../resource/pronostic.sqlite')

cursor = connection.cursor()
cursor.execute("SELECT * FROM league;")

for row in cursor:
    print('{0} : {1} ({2})'.format(row[0], row[1], row[2]))

connection.close()