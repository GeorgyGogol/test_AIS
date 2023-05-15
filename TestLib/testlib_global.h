#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TESTLIB_LIB)
#  define TESTLIB_EXPORT Q_DECL_EXPORT
# else
#  define TESTLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define TESTLIB_EXPORT
#endif
