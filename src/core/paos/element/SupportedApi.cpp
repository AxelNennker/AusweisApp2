/*!
 * \copyright Copyright (c) 2014 Governikus GmbH & Co. KG
 */

#include "SupportedApi.h"

#define SUPPORTED_ECARD_MAJOR 1
#define SUPPORTED_ECARD_MINOR 1
#define SUPPORTED_ECARD_SUBMINOR 4

using namespace governikus;

QString SupportedAPI::getMajor() const
{
	return QString::number(SUPPORTED_ECARD_MAJOR);
}


QString SupportedAPI::getMinor() const
{
	return QString::number(SUPPORTED_ECARD_MINOR);
}


QString SupportedAPI::getSubminor() const
{
	return QString::number(SUPPORTED_ECARD_SUBMINOR);
}
