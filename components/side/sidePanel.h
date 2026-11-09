#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <QWidget>
#include <QTime>

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
    void canalEstimuloAlterado(int index);
    void tipoEstimuloAlterado(int index);
    void reproducaoCiclicaToggled(bool checked);
    void tempoReproducaoCiclicaAlterado(const QTime &tempo);
    void duracaoEstimuloAlterada(const QTime &tempo);
    void freqAudioAlterada(int valor);
    void duracaoMsAlterada(int valor);
    void amplitudeAlterada(int valor);
    void freqPortadoraAlterada(int valor);
    void freqModulacaoAlterada(int valor);
    void fatorAMAlterado(int valor);
    void exponencialModAlterada(int valor);
    void faseFMAlterada(int valor);
    void fatorFMAlterado(int valor);

private slots:
    void aoMudarVolume();

private:
    Ui::sidePanel *ui;
};

#endif // SIDEPANEL_H