# Makefile for version_check extension (PostgreSQL 13 build)

EXTENSION = version_check
DATA = version_check--1.0.sql
MODULES = version_check

REGRESS = version_check

PG_CONFIG ?= pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)