#!/bin/bash

sed -i 's/VARCHAR /VARCHAR(255) /g' *.sql

sed -i 's/SMALLDATETIME/DATETIME/g' *.sql

sed -i 's/DATETIME/VARCHAR(255)/g' *.sql

sed -i '1s/^CREATE TABLE /-- CREATE TABLE IF NOT EXISTS /g' *.sql

sed -i "s/Impact evaluation of Puntos de Encuentro's communication strategy in Nicaragua/Impact evaluation of Puntos de Encuentro''s communication strategy in Nicaragua/g" course.sql

sed -i "s/MOSCTHA's mobile health clinic/MOSCTHA''s mobile health clinic/g"  page.sql
