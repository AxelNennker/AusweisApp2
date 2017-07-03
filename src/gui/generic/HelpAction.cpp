/*!
 * HelpAction.cpp
 *
 * \copyright Copyright (c) 2014 Governikus GmbH & Co. KG
 */

#include "HelpAction.h"

#include "LanguageLoader.h"
#include "SingletonHelper.h"
#include "VersionNumber.h"

#include <QCoreApplication>
#include <QDesktopServices>
#include <QDir>
#include <QFile>
#include <QLoggingCategory>
#include <QStringBuilder>
#include <QUrl>


using namespace governikus;

defineSingleton(HelpAction)

Q_DECLARE_LOGGING_CATEGORY(gui)

//Mapping object name to help file, \see AppQtMainWidget::onContentActionClicked()
const QMap<QString, QString> HelpAction::mHelpMapping = {
	{QStringLiteral("setupAssistant"), QStringLiteral("wizard-info.html")},
	{QStringLiteral("ausweisenPage"), QStringLiteral("identify.html")},
	{QStringLiteral("providerPage"), QStringLiteral("provider.html")},
	{QStringLiteral("historyPage"), QStringLiteral("history.html")},
	{QStringLiteral("generalTab"), QStringLiteral("settings-general.html")},
	{QStringLiteral("pinTab"), QStringLiteral("settings-pin-management.html")}
};


HelpAction& HelpAction::getInstance()
{
	return *Instance;
}


QString HelpAction::getHelpPath(QLocale::Language pLang) const
{
	const QString langDir = QCoreApplication::applicationDirPath() % QStringLiteral("/help/") % QLocale(pLang).bcp47Name().mid(0, 2) % '/';

	if (QDir(langDir).exists())
	{
		return langDir;
	}

	return QString();
}


QLocale::Language HelpAction::getExistingHelpLanguage() const
{
	QLocale::Language lang = LanguageLoader::getInstance().getUsedLocale().language();
	if (!getHelpPath(lang).isNull())
	{
		return lang;
	}

	lang = LanguageLoader::getInstance().getFallbackLanguage();
	if (!getHelpPath(lang).isNull())
	{
		return lang;
	}

	return QLocale::AnyLanguage;
}


QString HelpAction::getContextMapping(const QString& pObjectName) const
{
	if (mHelpMapping.contains(pObjectName))
	{
		return mHelpMapping.value(pObjectName);
	}
	else
	{
		qCWarning(gui) << "Cannot find help mapping:" << pObjectName;
	}

	return QStringLiteral("index.html");
}


QString HelpAction::getHelpUrl(const QString& pObjectName) const
{
	QLocale::Language lang = getExistingHelpLanguage();
	if (lang == QLocale::AnyLanguage)
	{
		return getOnlineUrl();
	}

	return QUrl::fromLocalFile(getHelpPath(lang)).toString() + getContextMapping(pObjectName);
}


QUrl HelpAction::getHelpUrlWrapper(const QString& pObjectName) const
{
	auto url = getHelpUrl(pObjectName);
	if (!url.contains('#'))
	{
		return url;
	}

	QFile file(QDir::tempPath() + QStringLiteral("/AusweisApp2_help.html"));
	if (file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		stream << QStringLiteral("<html><head><meta http-equiv=\"refresh\" content=\"0;url=%1\"/></head></html>").arg(url) << endl;
	}

	return QUrl::fromLocalFile(file.fileName());
}


QString HelpAction::getOnlineUrl(const QString& pObjectName) const
{
#ifdef Q_OS_OSX
	const QLatin1String osPath("macOS");
#else
	const QLatin1String osPath("Windows");
#endif

	const auto& appVersion = VersionNumber::getApplicationVersion().getVersionNumber();
	const QString ver = QString::number(appVersion.majorVersion()) % '.' % QString::number(appVersion.minorVersion());
	const QString locale = QLocale(LanguageLoader::getInstance().getUsedLocale().language()).bcp47Name().mid(0, 2);
	const QString mapping = getContextMapping(pObjectName);
	return QStringLiteral("https://www.ausweisapp.bund.de/ausweisapp2/handbuch/") % ver % '/' % locale % '/' % osPath % '/' % mapping;
}


void HelpAction::openContextHelp(const QString& pObjectName)
{
	//const auto& url = getInstance().getHelpUrlWrapper(pObjectName);
	const auto& url = QUrl(getInstance().getOnlineUrl(pObjectName));
	qCDebug(gui) << "Open manual:" << pObjectName << "|" << url;
	QDesktopServices::openUrl(url);
}
