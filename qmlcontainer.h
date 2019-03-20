#ifndef QMLCONTAINER_H
#define QMLCONTAINER_H

#include <QQuickView>
#include <QWidget>

namespace Ui {
class QMLContainer;
}

class QMLContainer : public QWidget
{
Q_OBJECT

public:
explicit QMLContainer(QWidget *parent = nullptr);
~QMLContainer();
Q_INVOKABLE int reopen_main_window();

private:
Ui::QMLContainer *ui;
QQuickView *view;
};

#endif // QMLCONTAINER_H
