#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(GENERALLIB_LIB)
#  define GENERALLIB_EXPORT Q_DECL_EXPORT
# else
#  define GENERALLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define GENERALLIB_EXPORT
#endif
