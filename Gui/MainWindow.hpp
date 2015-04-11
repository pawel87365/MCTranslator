#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QtWidgets>
#include <QList>
#include <QPointer>
#include <memory>

#include "ui_mainwindow.h"

class Translator;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:

  MainWindow();

  ~MainWindow();

  // void timerEvent(QTimerEvent * event);

  private slots:

    void slotLoadNormalText();

    void slotLoadMorseText();

    void slotSaveNormalText();

    void slotSaveMorseText();

    void slotCodeNormalText();

    void slotDecodeMorseText();

private:

  const QString getFileContent(const QString &aFileName) const;

  std::unique_ptr<Translator> theTranslator;

  Ui::MainWindow theUi;

};

#endif