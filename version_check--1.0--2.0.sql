-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "ALTER EXTENSION version_check UPDATE TO '2.0'" to load this file. \quit

-- getversion13() already exists from version 1.0 and points at
-- '$libdir/version_check.so', symbol 'getversion13'. It does not need to be
-- re-declared here.

-- New function introduced in version 2.0 (PostgreSQL 14 build).
CREATE FUNCTION getversion14()
RETURNS boolean
AS 'MODULE_PATHNAME', 'getversion14'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;
