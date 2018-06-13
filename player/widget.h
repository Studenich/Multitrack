#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QStandardItem>
#include <QList>
#include "audiotrackwidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btn_add_clicked();
    void on_btn_play_clicked();
    void on_btn_pause_clicked();
    void on_btn_stop_clicked();

private:
    Ui::Widget *ui;
    QList<AudioTrackWidget *> audioUi;
    int count = 0;
};

#endif // WIDGET_H
