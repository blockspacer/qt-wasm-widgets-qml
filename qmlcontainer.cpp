
#include <QQmlEngine>
#include <QQmlContext>

#include "mainwindow.h"
#include "qmlcontainer.h"
#include "ui_qmlcontainer.h"

#if defined(Q_OS_HTML5) or defined(Q_OS_WASM) or defined(__EMSCRIPTEN__)
#define PLATFORM_WASM
#endif

QMLContainer::QMLContainer(QWidget *parent) :
QWidget(parent),
ui(new Ui::QMLContainer)
{
  ui->setupUi(this);

  view = new QQuickView();

  // https://stackoverflow.com/a/41006903
  view->setResizeMode(QQuickView::SizeRootObjectToView);

  qmlRegisterType<QMLContainer>("com.myself", 1, 0, "QMLContainer");

  // add single instance of your object to the QML context as a property
  // the object will be available in QML with name "myObject"
  QMLContainer* myObject = this;//new QMLContainer();
  myObject->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding );

   // see https://felgo.com/cross-platform-development/how-to-expose-a-qt-cpp-class-with-signals-and-slots-to-qml
  view->engine()->rootContext()->setContextProperty("myObject", myObject);

  QWidget *container = QWidget::createWindowContainer(view, this);
  container->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding );
  /*container->setGeometry(0, 0, 200, 200);
  container->setMinimumSize(200, 200);
  container->setMaximumSize(200, 200);
  container->setFocusPolicy(Qt::TabFocus);*/
  view->setSource(QUrl("qrc:/main.qml"));
  ui->gridLayout_2->addWidget(container);

  this->repaint();
}

QMLContainer::~QMLContainer()
{
  delete ui;
}

int QMLContainer::reopen_main_window()
{
#ifdef PLATFORM_WASM
  printf("recreate_main_window\n");
  MainWindow w;
  w.show();
#else
  printf("reopen_main_window\n");
  parentWidget()->show();
#endif
  this->hide();
  view->hide();
  view->close();
  this->update();
  this->repaint();
  this->close();
  this->update();
  this->repaint();
  parentWidget()->raise();
  parentWidget()->show();
  parentWidget()->showNormal();
  parentWidget()->update();
  parentWidget()->repaint();

  printf("reopen_main_window OK\n");
  return 1;
}
