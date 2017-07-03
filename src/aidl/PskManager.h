/*!
 * PskManager.h
 *
 * \copyright Copyright (c) 2016 Governikus GmbH & Co. KG
 */

#pragma once


#include <QByteArray>
#include <QMutex>


namespace governikus
{

class PskManager
{

	private:
		QByteArray mPsk;
		bool mSecureRandomPsk;
		QMutex mPskMutex;

	public:
		static PskManager& getInstance();
		QString generatePsk(const QString& pClientPartialPsk);
		QByteArray getPsk();
		bool isSecureRandomPsk();
};

}
