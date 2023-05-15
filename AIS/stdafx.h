#include <QtWidgets>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

// DataBase
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qsqlrecord.h>

#ifdef DEBUG
#include <qdebug.h>
#define DBG_PRINT(mes) qDebug() << mes
#else
#define DBG_PRINT(mes) ;
#endif // 

#include <memory>

