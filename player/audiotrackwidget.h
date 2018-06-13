#ifndef AUDIOTRACKWIDGET_H
#define AUDIOTRACKWIDGET_H

#pragma once

#include <QWidget>
#include "audiotrack.h"

namespace Ui {
class AudioTrackWidget;
}

class AudioTrackWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioTrackWidget(QWidget *parent = 0);
    explicit AudioTrackWidget(QString filePath, int number, QWidget *parent = 0);
    Ui::AudioTrackWidget *getUi();
    void setTrack(AudioTrack *newTrack);
    AudioTrack *getTrack();
    //int getSliderPosition();
    ~AudioTrackWidget();
signals:

private slots:
    void on_volumeSlider_sliderMoved(int position);

private:
    Ui::AudioTrackWidget *ui;
    AudioTrack *track;

    QString trackName;
    QString url;
    int num;
};

#endif // AUDIOTRACKWIDGET_H
