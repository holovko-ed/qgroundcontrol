#include "QGeoServiceProviderPluginQGC.h"
#include "QGeoTiledMappingManagerEngineQGC.h"
#include <QGCLoggingCategory.h>

QGC_LOGGING_CATEGORY(QGeoServiceProviderFactoryQGCLog, "qgc.qtlocationplugin.qgeoserviceproviderfactoryqgc")

QGeoServiceProviderFactoryQGC::QGeoServiceProviderFactoryQGC(QObject *parent)
    : QObject(parent)
{
    qCDebug(QGeoServiceProviderFactoryQGCLog) << Q_FUNC_INFO << this;
}

QGeoServiceProviderFactoryQGC::~QGeoServiceProviderFactoryQGC()
{
    qCDebug(QGeoServiceProviderFactoryQGCLog) << Q_FUNC_INFO << this;
}

QGeoCodingManagerEngine* QGeoServiceProviderFactoryQGC::createGeocodingManagerEngine(
   const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters);
    if (error) {
        *error = QGeoServiceProvider::NotSupportedError;
    }
    if (errorString) {
        *errorString = "Geocoding Not Supported";
    }
    return nullptr;
}

QGeoMappingManagerEngine* QGeoServiceProviderFactoryQGC::createMappingManagerEngine(
   const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    if (error) {
        *error = QGeoServiceProvider::NoError;
    }
    if (errorString) {
        *errorString = "";
    }
    // TODO: m_engine->networkAccessManager();
    return new QGeoTiledMappingManagerEngineQGC(parameters, error, errorString);
}

QGeoRoutingManagerEngine* QGeoServiceProviderFactoryQGC::createRoutingManagerEngine(
   const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters);
    if (error) {
        *error = QGeoServiceProvider::NotSupportedError;
    }
    if (errorString) {
        *errorString = "Routing Not Supported";
    }
    return nullptr;
}

QPlaceManagerEngine* QGeoServiceProviderFactoryQGC::createPlaceManagerEngine(
   const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    Q_UNUSED(parameters);
    if (error) {
        *error = QGeoServiceProvider::NotSupportedError;
    }
    if (errorString) {
        *errorString = "Place Not Supported";
    }
    return nullptr;
}
