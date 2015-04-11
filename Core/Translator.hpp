#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <QString>
#include <QHash>
#include <QRegExp>

class Translator
{

public:

	Translator();

	QString translateToMorsCode(const QString &aInputText);

	QString translateFromMorseCode(const QString &aInputText);

private:

	void initRegularExpresions();

	void initMorseCodeMap();

	QHash<QChar, QString> theMorseCodeMap; 	

	QRegExp theNormalTextRegExp;

	QRegExp theMorseTextRegExp;

};

#endif
