-- Regression tests for the version_check extension (PostgreSQL 13 build).
-- Expected output is captured in expected/version_check.out.

CREATE EXTENSION version_check;

-- Basic call: should return true on PostgreSQL 13.
SELECT getversion13();

-- Cross-check against the server's own version number: both expressions
-- must agree, i.e. the function result must equal the result of comparing
-- the major version reported by the server with 13.
SELECT getversion13() = (current_setting('server_version_num')::int / 10000 = 13) AS matches;

-- The function is declared IMMUTABLE and STRICT, so calling it repeatedly
-- must give the same result.
SELECT getversion13(), getversion13(), getversion13();

-- Confirm the function metadata exposed by the catalog.
SELECT proname,
       prorettype::regtype,
       provolatile,
       proisstrict,
       proparallel
FROM pg_proc
WHERE proname = 'getversion13';

-- Confirm the extension is registered and owns the function.
SELECT extname
FROM pg_extension
WHERE extname = 'version_check';

DROP EXTENSION version_check;
