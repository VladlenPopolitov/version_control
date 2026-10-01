/*
 * version_check.c
 *
 * PostgreSQL 13 build of the "version_check" extension.
 *
 * The extension name is always "version_check"; the source file name is
 * always "version_check.c". Only the contents of this file (the compile-time
 * guard and the set of exported functions) are specific to a given major
 * version. To support another major version, provide a different copy of
 * this file with its own guard and its own functions.
 */

#include "postgres.h"
#include "fmgr.h"

/*
 * Hard compile-time guard: this translation unit must be built against
 * PostgreSQL 17 only. PG_VERSION_NUM for PostgreSQL 17.x is 170000..170999.
 */
#ifdef PG_VERSION_NUM
#if PG_VERSION_NUM < 170000 || PG_VERSION_NUM >= 180000
#error "This extension requires PostgreSQL version 17"
#endif
#else
#error "This extension requires PostgreSQL version 17"
#endif

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(getversion13);

/*
 * getversion13
 *
 * Returns true when the server major version is 13.
 * Because of the compile-time guard above, this function can only ever
 * be built against PostgreSQL 13, so in practice it always returns true.
 * The runtime check is kept as a defensive measure.
 */
Datum
getversion13(PG_FUNCTION_ARGS)
{
#if PG_VERSION_NUM >= 130000 && PG_VERSION_NUM < 140000
	PG_RETURN_BOOL(true);
#else
	PG_RETURN_BOOL(false);
#endif
}

PG_FUNCTION_INFO_V1(getversion14);

/*
 * getversion14
 *
 * Returns true when the server major version is 14.
 * Because of the compile-time guard above, this function can only ever
 * be built against PostgreSQL 14, so in practice it always returns true.
 * The runtime check is kept as a defensive measure.
 */
Datum
getversion14(PG_FUNCTION_ARGS)
{
#if PG_VERSION_NUM >= 140000 && PG_VERSION_NUM < 150000
	PG_RETURN_BOOL(true);
#else
	PG_RETURN_BOOL(false);
#endif
}

PG_FUNCTION_INFO_V1(getversion15);

/*
 * getversion15
 *
 * Returns true when the server major version is 15.
 * Because of the compile-time guard above, this function can only ever
 * be built against PostgreSQL 15, so in practice it always returns true.
 * The runtime check is kept as a defensive measure.
 */
Datum
getversion15(PG_FUNCTION_ARGS)
{
#if PG_VERSION_NUM >= 150000 && PG_VERSION_NUM < 160000
	PG_RETURN_BOOL(true);
#else
	PG_RETURN_BOOL(false);
#endif
}

PG_FUNCTION_INFO_V1(getversion16);

/*
 * getversion16
 *
 * Returns true when the server major version is 16.
 * Because of the compile-time guard above, this function can only ever
 * be built against PostgreSQL 16, so in practice it always returns true.
 * The runtime check is kept as a defensive measure.
 */
Datum
getversion16(PG_FUNCTION_ARGS)
{
#if PG_VERSION_NUM >= 160000 && PG_VERSION_NUM < 170000
	PG_RETURN_BOOL(true);
#else
	PG_RETURN_BOOL(false);
#endif
}

PG_FUNCTION_INFO_V1(getversion17);

/*
 * getversion17
 *
 * Returns true when the server major version is 17.
 * Because of the compile-time guard above, this function can only ever
 * be built against PostgreSQL 17, so in practice it always returns true.
 * The runtime check is kept as a defensive measure.
 */
Datum
getversion17(PG_FUNCTION_ARGS)
{
#if PG_VERSION_NUM >= 170000 && PG_VERSION_NUM < 180000
	PG_RETURN_BOOL(true);
#else
	PG_RETURN_BOOL(false);
#endif
}
