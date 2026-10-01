# version_check

PostgreSQL extension providing version-specific helper functions.

The extension name is always `version_check`, and the C source file is always
`version_check.c`. What changes between PostgreSQL major versions is the
*content* of `version_check.c`: its compile-time guard and the set of exported
functions.

## Current build: PostgreSQL 15

This build provides a single SQL function:

```sql
getversion15() RETURNS boolean
```

It returns true when the running PostgreSQL major version is 14, and
false otherwise.

## Compile-time version guard

If you try to build this source against any PostgreSQL version other than 15,
the compiler aborts with:

This extension requires PostgreSQL version 15
Therefore, in practice, whenever this build is compiled and loaded
successfully, getversion15() always returns true.

## Requirements

PostgreSQL 15 only (any minor release of the 15.x series) for this build.
PostgreSQL server development headers (postgresql-server-dev-15).
A C compiler and make.

PGXS build infrastructure (usually shipped with the server dev package).
⚠️ This build works only with PostgreSQL 15.

Building it against any other major version will fail at compile time
with the error This extension requires PostgreSQL version 15.

Future major versions will ship their own copy of version_check.c
with their own functions and their own #error guard, while keeping
the extension name version_check.
Build and install

```sh
make
sudo make install
```

## Usage

Connect to a PostgreSQL 15 database and run:

```sql
CREATE EXTENSION version_check;

SELECT getversion15();
--  getversion15
-- --------------
--  t
```

To remove the extension:

```sql
DROP EXTENSION version_check;
```

## Regression tests

The extension ships with a PGXS-based regression test suite.

Test input: sql/version_check.sql
Expected output: expected/version_check.out
Driver: make installcheck
Run the tests against a running PostgreSQL 15 instance:

```sh
make installcheck
```

The test script does the following:

Creates the extension with CREATE EXTENSION version_check;.
Calls getversion15() and asserts the result is t.
Cross-checks the function result against
current_setting('server_version_num')::int / 10000 = 15.
Calls the function several times in one statement to confirm stability.
Inspects pg_proc to confirm the function is boolean, IMMUTABLE,
STRICT, and PARALLEL SAFE.
Confirms the extension is registered in pg_extension.
Drops the extension.
If any of these checks fail, make installcheck reports a diff between
results/version_check.out and expected/version_check.out.

## Files

version_check.c — PostgreSQL 15 implementation with the
getversion15() function and the compile-time version guard.
version_check--1.0.sql — SQL script that declares the function.
version_check.control — extension control file.
Makefile — PGXS build script, including the REGRESS target.
sql/version_check.sql — regression test input.
expected/version_check.out — expected regression test output.
Adding support for a new PostgreSQL major version

Take the current version_check.c and update the #error guard to the
new version range (e.g. for version 14:
PG_VERSION_NUM < 140000 || PG_VERSION_NUM >= 150000) and the error text
accordingly.
Replace the exported function(s) with the ones appropriate for that
version (e.g. getversion14()), keeping the V1 calling convention.
Update version_check--1.0.sql (or bump to a new script version) with the
new SQL function declarations.
Update sql/version_check.sql and expected/version_check.out to match
the new function names and expected results.
Rebuild and install; the shared library is still installed as
version_check.so and the extension name is still version_check.

## License

Provided as-is, without any warranty.
