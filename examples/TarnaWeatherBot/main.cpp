#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QObject>
#include <tarnabot.h>

using namespace Telegram;

QString getWeatherByLocation(double latitude, double longitude);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    TarnaBot bot("589997728:AAEk8GGyTaDublEsxttXugV5CKjXCqnSPv4");
    
    while(true) 
    {
        foreach(Update u, bot.getUpdates())
        {
            if(u.getHasMessage())
            {
                if(u.getMessage().getHasText())
                {
                    qDebug() << "Text received.";
                }
                
                if(u.getMessage().getHasLocation())
                {
                    qDebug() << "Location";
                    getWeatherByLocation(u.getMessage().getLocation().getLatitude(), u.getMessage().getLocation().getLongitude());
                }
            }
        }
    }
    return a.exec();
}

QString getWeatherByLocation(double latitude, double longitude)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(0);
    QNetworkReply *reply;
    QEventLoop loop;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    
    QUrl url("api.openweathermap.org/data/2.5/weather");
    QUrlQuery query;
    query.addQueryItem("lon", QString::number(longitude));
    query.addQueryItem("lat", QString::number(latitude));
    query.addQueryItem("APPID", "07c2a736e4e78fa246c650b89875d338");
    url.setQuery(query);
    qDebug() << url;
    reply = manager->get(QNetworkRequest(url));
    loop.exec();
    qDebug() << reply->readAll();
}
