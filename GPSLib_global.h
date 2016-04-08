#ifndef GPSLIB_GLOBAL_H
#define GPSLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GPSLIB_LIBRARY)
#  define GPSLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GPSLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GPSLIB_GLOBAL_H
