#ifndef XFLASHLIB_GLOBAL_H
#define XFLASHLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XFLASHLIB_LIBRARY)
#  define XFLASHLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define XFLASHLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XFLASHLIB_GLOBAL_H
