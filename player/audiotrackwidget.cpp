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


AudioTrackWidget::~AudioTrackWidget()
{
    delete ui;
    delete this->track;
}

Ui::AudioTrackWidget *AudioTrackWidget::getUi()
{
    return ui;
}

void AudioTrackWidget::setTrack(AudioTrack *newTrack)
{
    this->track = newTrack;
}

AudioTrack *AudioTrackWidget::getTrack()
{
    return this->track;
}


void AudioTrackWidget::on_volumeSlider_sliderMoved(int position)
{
    this->track->getPlayer()->setVolume(position);
}

