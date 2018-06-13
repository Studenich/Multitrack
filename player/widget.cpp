#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDir>
//#include <chrono>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
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
        //audioTracks << new AudioTrack((QWidget *)audioUi[i++], filePath);
        //audioUi[audioUi.length()-1]->setTrack(audioTracks[audioTracks.length()-1]);
    }
}

void Widget::on_btn_play_clicked()
{
    //auto begin = std::chrono::steady_clock::now();

    foreach (AudioTrackWidget *trackWidget, audioUi) {
        trackWidget->getTrack()->getPlayer()->play();
    }

    /*auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    qDebug() << "The time: " << elapsed_ms.count() << " mcs\n";*/


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
