#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <QWidget>

namespace Ui {
class sidePanel;
}

class sidePanel : public QWidget
{
    Q_OBJECT

public:
    explicit sidePanel(QWidget *parent = nullptr);
    ~sidePanel();

signals:
    void iniciarAuditivoClicado();
    void pararAuditivoClicado();
    void selecionarAudioClicado();
    void volumeAlterado(int volDir, int volEsq);

private slots:
    void aoMudarVolume();

private:
    Ui::sidePanel *ui; // O ponteiro para a sua tela do Qt Designer
};

#endif // SIDEPANEL_H