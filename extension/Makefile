# Makefile for version_check extension

EXTENSION = version_check
DATA = version_check--1.0.sql \
       version_check--2.0.sql \
       version_check--1.0--2.0.sql
	   
MODULES = version_check

# Two regression suites: the general one and a dedicated one for the
# getversion14() function.
REGRESS = version_check version_check_v14

PG_CONFIG ?= pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)