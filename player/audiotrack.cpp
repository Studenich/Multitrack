#include "audiotrack.h"
#include "widget.h"
#include <QSlider>

AudioTrack::AudioTrack(QObject *parent)
{

}

AudioTrack::AudioTrack(QWidget *widget, QString filePath, QObject *parent) : QObject(parent)
{
    this->player = new QMediaPlayer(widget);
    this->playlist = new QMediaPlaylist(player);
    this->url = filePath;

    this->player->setPlaylist(playlist);
    this->player->setVolume(80);
    this->playlist->setPlaybackMode(QMediaPlaylist::Loop);

    this->playlist->addMedia(QUrl(filePath));
}

AudioTrack::~AudioTrack()
{
    delete this->player;
    delete this->playlist;
}

QMediaPlayer *AudioTrack::getPlayer()
{
    return this->player;
}

void AudioTrack::run()
{
    this->player->play();
}
