#ifndef QCCNODE_H
#define QCCNODE_H

#include "qdefine.h"

//remeber set default value.
class QCCNode
{
public:
    QCCNode();

public:
    virtual void importData(QMap<QString, QString>&);
    virtual QMap<QString, QString> exportData();

public:
    int m_x;
    int m_y;
    int m_z;
    int m_tag;
    int m_width;
    int m_height;
    int m_rotation;
    float m_anchorX;
    float m_anchorY;
    float m_scaleX;
    float m_scaleY;
    bool m_isVisible;
};

class QCCLayer : public QCCNode
{
public:
    QCCLayer();

    virtual void importData(QMap<QString, QString>&);
    virtual QMap<QString, QString> exportData();

public:
    bool m_isTouchEnable;
};

class QCCLayerColor : public QCCLayer
{
public:
    QCCLayerColor();

    virtual void importData(QMap<QString, QString>&);
    virtual QMap<QString, QString> exportData();

public:
    QColor m_color;
    int m_opacity;
};

class QCCSprite : public QCCLayerColor
{
public:
    QCCSprite();

    virtual void importData(QMap<QString, QString>&);
    virtual QMap<QString, QString> exportData();

public:
    QString m_filePath;
};

class QCCLabelTTF : public QCCLayerColor
{
public:
    QCCLabelTTF();

    virtual void importData(QMap<QString, QString>&);
    virtual QMap<QString, QString> exportData();

public:
    QFont m_font;
    QString m_text;
};

#endif // QCCNODE_H
