#include "audiotrack.h"
#include "widget.h"
#include <QSlider>

AudioTrack::AudioTrack(QObject *parent)
{

}

AudioTrack::AudioTrack(QWidget *widget, QString filePath, QObject *parent) : QObject(parent)
{
    player = new QMediaPlayer(widget);
    playlist = new QMediaPlaylist(player);
    url = filePath;

    player->setPlaylist(playlist);
    player->setVolume(80);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    playlist->addMedia(QUrl(filePath));
}

QMediaPlayer *AudioTrack::getPlayer()
{
    return this->player;
}

void AudioTrack::run()
{
    player->play();
}
