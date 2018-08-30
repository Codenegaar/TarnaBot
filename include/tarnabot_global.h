#include <QtCore/qglobal.h>

#ifdef TARNABOT_LIBRARY
#  define TARNABOTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TARNABOTSHARED_EXPORT Q_DECL_IMPORT
#endif
