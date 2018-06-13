#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
//#include "audiotrackwidget.h"

class AudioTrack : public QObject
{
    Q_OBJECT
public:
    explicit AudioTrack(QObject *parent = nullptr);
    explicit AudioTrack(QWidget *widget, QString filePath, QObject *parent = nullptr);

    QMediaPlayer *getPlayer();

signals:

public slots:
    void run();

private:
    QString             url;
    QMediaPlayer        *player;
    QMediaPlaylist      *playlist;
};

#endif // AUDIOTRACK_H
