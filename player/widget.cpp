#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDir>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
    for(int i=0; i<count; i++) {
        delete audioUi[i];
    }
}

void Widget::on_btn_add_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Open files"),
                                                      QString(),
                                                      tr("Audio Files (*.wav)"));

    foreach (QString filePath, files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));

        audioUi << new AudioTrackWidget(filePath, audioUi.length());
        ui->tracksLayout->addWidget(audioUi[count++]);

        audioUi[count - 1]->getTrack()->getPlayer()->play();
        audioUi[count - 1]->getTrack()->getPlayer()->stop();
    }
}

void Widget::on_btn_play_clicked()
{
    foreach (AudioTrackWidget *trackWidget, audioUi) {
        trackWidget->getTrack()->getPlayer()->play();
    }
}

void Widget::on_btn_pause_clicked()
{
    for(int i=0; i<count; i++) {
        audioUi[i]->getTrack()->getPlayer()->pause();
    }
}

void Widget::on_btn_stop_clicked()
{
    for(int i=0; i<count; i++) {
        audioUi[i]->getTrack()->getPlayer()->stop();
    }
}
