/*!
 * AccessRoleAndRight.cpp
 *
 * \copyright Copyright (c) 2015 Governikus GmbH & Co. KG
 */

#include "AccessRoleAndRight.h"


using namespace governikus;


QList<AccessRight> AccessRoleAndRightsUtil::mAllRights;
QList<AccessRight> AccessRoleAndRightsUtil::mAllDisplayedOrderedRights;


AccessRoleAndRightsUtil::AccessRoleAndRightsUtil()
	: QObject()
{
}


const QList<AccessRight>& AccessRoleAndRightsUtil::allDisplayedOrderedRights()
{
	if (mAllDisplayedOrderedRights.isEmpty())
	{
		mAllDisplayedOrderedRights += AccessRight::READ_DG05;
		mAllDisplayedOrderedRights += AccessRight::READ_DG13;
		mAllDisplayedOrderedRights += AccessRight::READ_DG04;
		mAllDisplayedOrderedRights += AccessRight::READ_DG07;
		mAllDisplayedOrderedRights += AccessRight::READ_DG08;
		mAllDisplayedOrderedRights += AccessRight::READ_DG09;
		mAllDisplayedOrderedRights += AccessRight::READ_DG17;
		mAllDisplayedOrderedRights += AccessRight::READ_DG01;
		mAllDisplayedOrderedRights += AccessRight::READ_DG03;
		mAllDisplayedOrderedRights += AccessRight::RESTRICTED_IDENTIFICATION;
		mAllDisplayedOrderedRights += AccessRight::READ_DG10;
		mAllDisplayedOrderedRights += AccessRight::READ_DG06;
		mAllDisplayedOrderedRights += AccessRight::AGE_VERIFICATION;
		mAllDisplayedOrderedRights += AccessRight::COMMUNITY_ID_VERIFICATION;
		mAllDisplayedOrderedRights += AccessRight::READ_DG02;
		mAllDisplayedOrderedRights += AccessRight::READ_DG19;
		mAllDisplayedOrderedRights += AccessRight::INSTALL_QUAL_CERT;
		mAllDisplayedOrderedRights += AccessRight::INSTALL_CERT;
	}
	return mAllDisplayedOrderedRights;
}


const QList<AccessRight>& AccessRoleAndRightsUtil::allRights()
{
	if (mAllRights.isEmpty())
	{
		mAllRights.append(AccessRight::WRITE_DG17);
		mAllRights.append(AccessRight::WRITE_DG18);
		mAllRights.append(AccessRight::WRITE_DG19);
		mAllRights.append(AccessRight::WRITE_DG20);
		mAllRights.append(AccessRight::WRITE_DG21);

		mAllRights.append(AccessRight::RFU_32);
		mAllRights.append(AccessRight::RFU_31);
		mAllRights.append(AccessRight::RFU_30);
		mAllRights.append(AccessRight::RFU_29);

		mAllRights.append(AccessRight::READ_DG21);
		mAllRights.append(AccessRight::READ_DG20);
		mAllRights.append(AccessRight::READ_DG19);
		mAllRights.append(AccessRight::READ_DG18);
		mAllRights.append(AccessRight::READ_DG17);
		mAllRights.append(AccessRight::READ_DG16);
		mAllRights.append(AccessRight::READ_DG15);
		mAllRights.append(AccessRight::READ_DG14);
		mAllRights.append(AccessRight::READ_DG13);
		mAllRights.append(AccessRight::READ_DG12);
		mAllRights.append(AccessRight::READ_DG11);
		mAllRights.append(AccessRight::READ_DG10);
		mAllRights.append(AccessRight::READ_DG09);
		mAllRights.append(AccessRight::READ_DG08);
		mAllRights.append(AccessRight::READ_DG07);
		mAllRights.append(AccessRight::READ_DG06);
		mAllRights.append(AccessRight::READ_DG05);
		mAllRights.append(AccessRight::READ_DG04);
		mAllRights.append(AccessRight::READ_DG03);
		mAllRights.append(AccessRight::READ_DG02);
		mAllRights.append(AccessRight::READ_DG01);

		mAllRights.append(AccessRight::INSTALL_QUAL_CERT);
		mAllRights.append(AccessRight::INSTALL_CERT);
		mAllRights.append(AccessRight::PIN_MANAGEMENT);
		mAllRights.append(AccessRight::CAN_ALLOWED);
		mAllRights.append(AccessRight::PRIVILEGED_TERMINAL);
		mAllRights.append(AccessRight::RESTRICTED_IDENTIFICATION);
		mAllRights.append(AccessRight::COMMUNITY_ID_VERIFICATION);
		mAllRights.append(AccessRight::AGE_VERIFICATION);
	}

	return mAllRights;
}


QString AccessRoleAndRightsUtil::toDisplayText(AccessRight pRight)
{
	switch (pRight)
	{
		case AccessRight::WRITE_DG17:
			return tr("WRITE_DG17");

		case AccessRight::WRITE_DG18:
			return tr("WRITE_DG18");

		case AccessRight::WRITE_DG19:
			return tr("WRITE_DG19");

		case AccessRight::WRITE_DG20:
			return tr("WRITE_DG20");

		case AccessRight::WRITE_DG21:
			return tr("WRITE_DG21");

		/* 32-29: reserved for future use */
		case AccessRight::READ_DG21:
			return tr("Optional data");

		case AccessRight::READ_DG20:
			return tr("Residence permit II");

		case AccessRight::READ_DG19:
			return tr("Residence permit I");

		case AccessRight::READ_DG18:
			return tr("Community-ID");

		case AccessRight::READ_DG17:
			return tr("Address");

		case AccessRight::READ_DG16:
			return tr("RFU");

		case AccessRight::READ_DG15:
			return tr("RFU");

		case AccessRight::READ_DG14:
			return tr("RFU");

		case AccessRight::READ_DG13:
			return tr("Birth name");

		case AccessRight::READ_DG12:
			return tr("Optional data");

		case AccessRight::READ_DG11:
			return tr("Gender");

		case AccessRight::READ_DG10:
			return tr("Nationality");

		case AccessRight::READ_DG09:
			return tr("Place of birth");

		case AccessRight::READ_DG08:
			return tr("Date of birth");

		case AccessRight::READ_DG07:
			return tr("Doctoral degree");

		case AccessRight::READ_DG06:
			return tr("Religious / artistic name");

		case AccessRight::READ_DG05:
			return tr("Family name");

		case AccessRight::READ_DG04:
			return tr("Given name(s)");

		case AccessRight::READ_DG03:
			return tr("Valid until");

		case AccessRight::READ_DG02:
			return tr("Issuing country");

		case AccessRight::READ_DG01:
			return tr("Document type");

		case AccessRight::INSTALL_QUAL_CERT:
			return tr("Installation of qualified signature certificates");

		case AccessRight::INSTALL_CERT:
			return tr("Installation of signature certificates");

		case AccessRight::PIN_MANAGEMENT:
			return tr("PIN Management");

		case AccessRight::CAN_ALLOWED:
			return tr("CAN allowed");

		case AccessRight::PRIVILEGED_TERMINAL:
			return tr("Privileged terminal");

		case AccessRight::RESTRICTED_IDENTIFICATION:
			return tr("Pseudonym");

		case AccessRight::COMMUNITY_ID_VERIFICATION:
			return tr("Address verification");

		case AccessRight::AGE_VERIFICATION:
			return tr("Age verification");

		default:
			return tr("Unknown");
	}
}
