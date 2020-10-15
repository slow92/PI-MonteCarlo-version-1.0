#!/bin/bash
git init
git add main.c
git add command.sh
git commit -m "old version PI_MonteCarlo"
git remote add origin https://github.com/slow92/PI-MonteCarlo-version-1.0.git
git push origin master -f