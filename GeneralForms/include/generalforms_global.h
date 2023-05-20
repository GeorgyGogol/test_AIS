#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(GENERALFORMS_LIB)
#  define GENERALFORMS_EXPORT Q_DECL_EXPORT
# else
#  define GENERALFORMS_EXPORT Q_DECL_IMPORT
# endif
#else
# define GENERALFORMS_EXPORT
#endif
