#include "audiotrackwidget.h"
#include "ui_audiotrackwidget.h"
#include <QDebug>

AudioTrackWidget::AudioTrackWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioTrackWidget)
{
    ui->setupUi(this);
}

AudioTrackWidget::AudioTrackWidget(QString filePath, int number, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioTrackWidget)
{
    ui->setupUi(this);
    url = filePath;
    num = number;
    this->track = new AudioTrack(this, filePath);

    trackName = filePath;
    int i = trackName.length()-1;
    while (i >= 0) {
        if(trackName[i] == '/') {
            trackName.remove(0, i+1);
            break;
        }
        i--;
    }
    trackName.remove(".wav");
    ui->trackNameLabel->setText(trackName);
}

Ui::AudioTrackWidget *AudioTrackWidget::getUi()
{
    return ui;
}

/*int AudioTrackWidget::getSliderPosition()
{
    return ui->volumeSlider->value();
}*/

void AudioTrackWidget::setTrack(AudioTrack *newTrack)
{
    this->track = newTrack;
}

AudioTrack *AudioTrackWidget::getTrack()
{
    return this->track;
}

AudioTrackWidget::~AudioTrackWidget()
{
    delete ui;
}

void AudioTrackWidget::on_volumeSlider_sliderMoved(int position)
{
    this->track->getPlayer()->setVolume(position);
}

