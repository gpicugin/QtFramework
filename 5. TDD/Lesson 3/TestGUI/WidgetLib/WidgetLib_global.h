#ifndef WIDGETLIB_GLOBAL_H
#define WIDGETLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WIDGETLIB_LIBRARY)
#  define WIDGETLIB_EXPORT Q_DECL_EXPORT
#else
#  define WIDGETLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // WIDGETLIB_GLOBAL_H
