﻿/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMIC_H
#define COMIC_H

#include <QObject>

#include <QUrl>
#include <QColor>
#include <QLocale>
#include <QDateTime>
#include <QTimer>

class QNetworkAccessManager;
class QNetworkReply;
class ComicDatabaseResource;
class ComicFileResource;

class Comic : public QObject
{
    Q_OBJECT

public:
    explicit Comic(QObject *parent = 0);
    ~Comic();

    struct ComicInfo {
        QString id;
        QString name;
        QColor color;
        QStringList authors;
        QUrl homepage;
        QLocale::Country country;
        QLocale::Language language;
        QDate startDate;
        QDate endDate;
        QUrl stripSourceUrl;

        ComicInfo() {
            id = QString();
            name = QString();
            color = QColor();
            authors = QStringList();
            homepage = QString();
            country = QLocale::AnyCountry;
            language = QLocale::AnyLanguage;
            startDate = QDate();
            endDate = QDate();
            stripSourceUrl = QUrl();
        }
    };

    QString id() const { return m_info.id; }
    QString name() const { return m_info.name; }
    QColor color() const { return m_info.color; }
    QStringList authors() const { return m_info.authors; }
    QUrl homepage() const { return m_info.homepage; }
    QLocale::Country country() const { return m_info.country; }
    QLocale::Language language() const { return m_info.language; }
    QDate startDate() const { return m_info.startDate; }
    QDate endDate() const { return m_info.endDate; }
    QUrl stripSourceUrl() const { return m_info.stripSourceUrl; }

    virtual QUrl extractStripImageUrl(QByteArray data) = 0;

    QUrl stripImageUrl() const { return m_stripImageUrl; }
    bool favorite() const { return m_favorite; }
    bool newStrip() const { return m_newStrip; }
    bool error() const { return m_error; }
    bool fetching() const { return m_fetching; }
    QDateTime fetchTime() const { return m_fetchTime; }
    QUrl extractedStripImageUrl() const { return m_extractedStripImageUrl; }
    int fetchingProgress() const { return m_fetchingProgress; }
    bool isAnimatedDefined() const { return m_isAnimatedDefined; }
    int random() const { return m_random; }

    void setFavorite(const bool favorite) { m_favorite = favorite; emit favoriteChanged(this);}
    void setNewStrip(const bool newStrip) { m_newStrip = newStrip; emit newStripChanged(this); }
    void setError(const bool error) { m_error = error; emit errorChanged(this);}
    void setFetching(const bool fetching) { m_fetching = fetching; emit fetchingChanged(this); }
    void setFetchingProgress(const bool fetchingProgress) { m_fetchingProgress = fetchingProgress; emit fetchingProgressChanged(this); }
    void setFetchTime(const QDateTime fetchTime) { m_fetchTime = fetchTime; }
    void setStripImageUrl(const QUrl stripImageUrl) { m_stripImageUrl = stripImageUrl; }
    void setExtractedStripImageUrl(const QUrl extractedStripImageUrl) { m_extractedStripImageUrl = extractedStripImageUrl; }
    void setIsAnimatedDefined(const bool isAnimatedDefined) { m_isAnimatedDefined = isAnimatedDefined; }

    void load();
    void save();

    void fetchStrip();
    QString stripImagePath() const;
    bool animated();
    QString sortName() const;
    void abortFetching();
    void read();

protected:
    void fetchStripSource(QUrl stripSrcUrl = QUrl());
    void fetchStripImage(QUrl stripImageUrl);
    QUrl redirectedToUrl();
    bool stripImageDownloaded();
    QUrl regexExtractStripImageUrl(QByteArray data, QString regex, int count = 1);

private slots:
    void onFetchStripSourceFinished();
    void onFetchStripImageFinished();
    void timeout();
    void updateFetchingProgress(qint64 bytesReceived, qint64 bytesTotal);

signals:
    void fetchStarted();
    void fetchSucceeded();
    void networkError();
    void parsingError();
    void savingError();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

    void favoriteChanged(Comic* comic);
    void newStripChanged(Comic* comic);
    void errorChanged(Comic* comic);
    void fetchingChanged(Comic* comic);
    void fetchingProgressChanged(Comic* comic);

protected:
    static const int _minFetchDelay;
    static const int _timeout;

    ComicInfo m_info;

    ComicDatabaseResource* dbResource;
    ComicFileResource* fileResource;
    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_currentReply;
    QTimer* m_timeoutTimer;

    int m_random;
    QUrl m_extractedStripImageUrl;
    QUrl m_stripImageUrl;
    bool m_favorite;
    bool m_newStrip;
    bool m_error;
    bool m_fetching;
    QDateTime m_fetchTime;
    int m_fetchingProgress;
    bool m_animated;
    bool m_isAnimatedDefined;
};

#endif // COMIC_H
