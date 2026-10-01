-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION version_check" to load this file. \quit

CREATE FUNCTION getversion13()
RETURNS boolean
AS 'MODULE_PATHNAME', 'getversion13'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;

CREATE FUNCTION getversion14()
RETURNS boolean
AS 'MODULE_PATHNAME', 'getversion14'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;

CREATE FUNCTION getversion15()
RETURNS boolean
AS 'MODULE_PATHNAME', 'getversion15'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;
