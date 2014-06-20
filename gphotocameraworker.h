#ifndef GPHOTOCAMERAWORKER_H
#define GPHOTOCAMERAWORKER_H

#include <QObject>

#include "gphotocamerasession.h"

class GPhotoCameraWorker : public QObject
{
    Q_OBJECT
public:
    explicit GPhotoCameraWorker(GPContext *context, Camera *camera, QObject *parent = 0);

signals:
    void previewCaptured(QImage);

    //    void imageExposed(int id);
    //    void imageCaptured(int id, const QImage &preview);
    //    void imageMetadataAvailable(int id, const QString &key, const QVariant &value);
    //    void imageAvailable(int id, const QVideoFrame &buffer);
    //    void imageSaved(int id, const QString &fileName);
    void imageCaptured(int id, const QByteArray& imageData, const QString& fileName);
    void imageCaptureError(int id, int error, const QString &errorString);

public slots:
    void capturePreview();
    void capturePhoto(int id, const QString& fileName);

private:
    friend class GPhotoCameraSession;
    GPContext *m_context;
    Camera *m_camera;
    QMutex m_captureMutex;

    QImage capturePreviewImage();
};

#endif // GPHOTOCAMERAWORKER_H