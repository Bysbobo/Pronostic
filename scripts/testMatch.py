#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sqlite3

connection = sqlite3.connect('../resource/pronostic.sqlite')

cursor = connection.cursor()
cursor.execute("SELECT * FROM match;")

for row in cursor:
    print('{0} : {1} vs {2} (leag {3}) - {4}/{5}'.format(row[0], row[1], row[2], row[3], row[4], row[5]))

connection.close()