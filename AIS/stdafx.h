// Widgets
#include <QtWidgets>
#include <QMessageBox>

// Classes
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QDir>

// DataBase
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qsqlrecord.h>

#ifdef _DEBUG
#include <QDebug>
#define DBG_PRINT(mes) qDebug() << mes
//#define PLACE_TMP_FILES_IN_CURRENT_DIR
#else
#define DBG_PRINT(mes) ;
#endif // 

// STL
#include <memory>

