#ifndef PROTOCOLSELECTOR_H
#define PROTOCOLSELECTOR_H

#include <QWidget>
#include <QList>

class QToolButton;

class ProtocolSelector : public QWidget
{
public:
    explicit ProtocolSelector(
        const QList<QToolButton *> &buttons,
        QWidget *parent = nullptr
        );
};

#endif // PROTOCOLSELECTOR_H