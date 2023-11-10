#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "customimage.h"
#include "imageprocessor.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<CustomImage>("PI.Image", 1, 0, "CustomImage");

    ImageProcessor *processor = new ImageProcessor();
    engine.rootContext()->setContextProperty("processor", processor);

    const QUrl url(u"qrc:/PI_P_App/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
