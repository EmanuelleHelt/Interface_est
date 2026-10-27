#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QToolButton>

class QLabel;

class sideBar : public QWidget
{
    Q_OBJECT

public:
    explicit sideBar(QWidget *parent = nullptr);
    ~sideBar();

signals:
    void registrarPacienteClicked();
    void salvarSessaoClicked();
    void sobreClicked();
    // Solicita o ajuste da largura do contêiner lateral.
    void widthRequested(int width);

private:
    QToolButton *btnRegistrarPaciente;
    QToolButton *btnSalvarSessao;
    QToolButton *btnSobre;

    QToolButton* crearBotonMenu(const QString &texto, const QString &rutaIcono);
    void setBotonActivo(QToolButton *btnActivo);
    // Mantém o estado visual do menu.
    bool m_collapsed = false;
    QToolButton *toggleButton = nullptr;
    QLabel *logoLabel = nullptr;

    // Alterna a apresentação dos botões e do logotipo.
    void setCollapsed(bool collapsed);

};


#endif // SIDEBAR_H
