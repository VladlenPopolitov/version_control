-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "ALTER EXTENSION version_check UPDATE TO '3.0'" to load this file. \quit

-- New function introduced in version 5.0 (PostgreSQL 17 build).
CREATE FUNCTION getversion17()
RETURNS boolean
AS 'MODULE_PATHNAME', 'getversion17'
LANGUAGE C STRICT IMMUTABLE PARALLEL SAFE;
