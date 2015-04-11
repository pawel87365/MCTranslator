#include "mainwindow.hpp"
#include "Translator.hpp"

#include <QDebug>

MainWindow::MainWindow()
	:
QMainWindow(),
	theTranslator(new Translator())
{
	theUi.setupUi(this);

	bool bRet = false;
	bRet = connect(theUi.theLoadNormaPushButton,	SIGNAL(clicked(bool)), this, SLOT(slotLoadNormalText()));	Q_ASSERT(bRet);
	bRet = connect(theUi.theLoadMorsePushButton,	SIGNAL(clicked(bool)), this, SLOT(slotLoadMorseText()));	Q_ASSERT(bRet);
	bRet = connect(theUi.theSaveNormalPushButton,	SIGNAL(clicked(bool)), this, SLOT(slotSaveNormalText()));	Q_ASSERT(bRet);
	bRet = connect(theUi.theSaveMorsePushButton,	SIGNAL(clicked(bool)), this, SLOT(slotSaveMorseText()));	Q_ASSERT(bRet);
	bRet = connect(theUi.theCodePushButton,			SIGNAL(clicked(bool)), this, SLOT(slotCodeNormalText()));	Q_ASSERT(bRet);
	bRet = connect(theUi.theDecodePushButton,		SIGNAL(clicked(bool)), this, SLOT(slotDecodeMorseText()));	Q_ASSERT(bRet);

	this->setWindowTitle("Morse code translator");
}

MainWindow::~MainWindow()
{
	qDebug() << Q_FUNC_INFO;
}

void MainWindow::slotLoadNormalText()
{
	qDebug() << Q_FUNC_INFO;

	const QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
		"C:\\",
		tr("Text (*.txt)"));

	theUi.theNormalPlainTextEdit->setPlainText(getFileContent(fileName));

}

void MainWindow::slotLoadMorseText()
{
	qDebug() << Q_FUNC_INFO;

	const QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
		"C:\\",
		tr("Text (*.txt)"));	

	theUi.theNormalPlainTextEdit->setPlainText(getFileContent(fileName));

}

void MainWindow::slotSaveNormalText()
{
	qDebug() << Q_FUNC_INFO;

}

void MainWindow::slotSaveMorseText()
{
	qDebug() << Q_FUNC_INFO;
}

void MainWindow::slotCodeNormalText()
{
	qDebug() << Q_FUNC_INFO;

	theUi.theMorseplainTextEdit->setPlainText(theTranslator->translateToMorsCode(theUi.theNormalPlainTextEdit->toPlainText().toUpper()));

}

void MainWindow::slotDecodeMorseText()
{
	qDebug() << Q_FUNC_INFO;

	theUi.theNormalPlainTextEdit->setPlainText(theTranslator->translateFromMorseCode(theUi.theMorseplainTextEdit->toPlainText().toUpper()));

}

const QString MainWindow::getFileContent(const QString &aFileName) const
{
	QFile file(aFileName);

	if(!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::information(0, "error", file.errorString());
		qDebug() << Q_FUNC_INFO << file.errorString();
		return QString();
	}

	QTextStream in(&file);

	// QStringList currentList;
	QString returnString;

	while(!in.atEnd())
	{
		returnString += in.readLine();
	}

	return returnString;
}
