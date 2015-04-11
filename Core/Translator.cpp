#include "Translator.hpp"
#include "MorseCodeChars.hpp"
#include <QStringList>
#include <QDebug>

Translator::Translator()
	:
theNormalTextRegExp(),
	theMorseCodeMap()
{
	qDebug() << Q_FUNC_INFO;

	initMorseCodeMap();
	initRegularExpresions();
}

QString Translator::translateToMorsCode(const QString &aInputText)
{
	qDebug() << Q_FUNC_INFO;

	QStringList wordsList = aInputText.split(' ');

	QString outString;

	/// TO_DO make fast access to QList (iterator or smth like this)
	/// TO_DO sprawdzic z QStringRef oraz QStringMatcher
	for(int i = 0; i < wordsList.count(); i++)
	{
		for(int j = 0; j < wordsList.at(i).size(); j++)
		{
			if(false == theNormalTextRegExp.exactMatch(wordsList.at(i).at(j)))
				continue;

			outString += theMorseCodeMap[wordsList.at(i).at(j)];
			outString += ' ';
		}

		outString += ' ';

	}

	return outString;
}

QString Translator::translateFromMorseCode(const QString &aInputText)
{
	qDebug() << Q_FUNC_INFO;


	QStringList wordsList = aInputText.split("  ");

	QString outString;

	/// TO_DO make fast access to QList (iterator or smth like this)
	/// TO_DO sprawdzic z QStringRef oraz QStringMatcher
	for(int i = 0; i < wordsList.count(); i++)
	{

		const QStringList singleWord = wordsList.at(i).split(' ');

		for(int j = 0; j < singleWord.count(); j++)
		{			
			QString singleChar = singleWord.at(j);
			qDebug() << Q_FUNC_INFO << singleChar;			
			if(false == theMorseTextRegExp.exactMatch(singleChar))
				continue;

			outString += theMorseCodeMap.key(singleChar);
		}

		outString += ' ';

	}

	return outString;


	return QString();
}

void Translator::initMorseCodeMap()
{
	qDebug() << Q_FUNC_INFO;

	theMorseCodeMap['A'] = MorseChars::A;
	theMorseCodeMap['B'] = MorseChars::B;
	theMorseCodeMap['C'] = MorseChars::C;
	theMorseCodeMap['D'] = MorseChars::D;
	theMorseCodeMap['E'] = MorseChars::E;
	theMorseCodeMap['F'] = MorseChars::F;
	theMorseCodeMap['G'] = MorseChars::G;
	theMorseCodeMap['H'] = MorseChars::H;
	theMorseCodeMap['I'] = MorseChars::I;
	theMorseCodeMap['J'] = MorseChars::J;
	theMorseCodeMap['K'] = MorseChars::K;
	theMorseCodeMap['L'] = MorseChars::L;
	theMorseCodeMap['M'] = MorseChars::M;
	theMorseCodeMap['N'] = MorseChars::N;
	theMorseCodeMap['O'] = MorseChars::O;
	theMorseCodeMap['P'] = MorseChars::P;
	theMorseCodeMap['Q'] = MorseChars::Q;
	theMorseCodeMap['R'] = MorseChars::R;
	theMorseCodeMap['S'] = MorseChars::S;
	theMorseCodeMap['T'] = MorseChars::T;
	theMorseCodeMap['U'] = MorseChars::U;
	theMorseCodeMap['V'] = MorseChars::V;
	theMorseCodeMap['W'] = MorseChars::W;
	theMorseCodeMap['X'] = MorseChars::X;
	theMorseCodeMap['Y'] = MorseChars::Y;
	theMorseCodeMap['Z'] = MorseChars::Z;
	theMorseCodeMap['1'] = MorseChars::ONE;
	theMorseCodeMap['2'] = MorseChars::TWO;
	theMorseCodeMap['3'] = MorseChars::TREE;
	theMorseCodeMap['4'] = MorseChars::FOUR;
	theMorseCodeMap['5'] = MorseChars::FIVE;
	theMorseCodeMap['6'] = MorseChars::SIX;
	theMorseCodeMap['7'] = MorseChars::SEVEN;
	theMorseCodeMap['8'] = MorseChars::EIGHT;
	theMorseCodeMap['9'] = MorseChars::NINE;
	theMorseCodeMap['0'] = MorseChars::ZERO;
}

void Translator::initRegularExpresions()
{
	qDebug() << Q_FUNC_INFO;

	theNormalTextRegExp.setPattern("[A-Z]|[1-9]");

	using namespace MorseChars;
	const QString inputPatern = A+OR+B+OR+C+OR+D+OR+E+OR+F+
		OR+G+OR+H+OR+I+OR+J+OR+K+OR+L+OR+M+OR+N+OR+O+OR+P+
		OR+Q+OR+R+OR+S+OR+T+OR+U+OR+W+OR+X+OR+Y+OR+Z+OR+ONE+
		OR+TWO+OR+TREE+OR+FOUR+OR+FIVE+OR+SIX+OR+SEVEN+OR+
		EIGHT+OR+NINE+OR+ZERO+OR;

	theMorseTextRegExp.setPattern(inputPatern);
}
