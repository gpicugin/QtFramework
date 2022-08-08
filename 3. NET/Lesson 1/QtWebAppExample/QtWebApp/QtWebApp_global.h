#ifndef QTWEBAPP_GLOBAL_H
#define QTWEBAPP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTWEBAPP_LIBRARY)
#  define QTWEBAPP_EXPORT Q_DECL_EXPORT
#else
#  define QTWEBAPP_EXPORT Q_DECL_IMPORT
#endif

#endif // QTWEBAPP_GLOBAL_H
