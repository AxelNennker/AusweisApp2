/*!
 * CertificateDescription.h
 *
 * \brief Implementation of ASN.1 type CertificateDescription with OpenSSL
 *
 * \copyright Copyright (c) 2015 Governikus GmbH & Co. KG
 */

#pragma once

#include "ASN1TemplateUtil.h"
#include "ASN1Util.h"

#include <openssl/asn1t.h>
#include <openssl/err.h>

#include <QCoreApplication>

#include <QSet>
#include <QSharedPointer>
#include <QString>
#include <QVector>


namespace governikus
{


/**
 * As specified in TR-03110-4 chapter 2.2.6:
 *
 *
 * CertificateDescription ::= SEQUENCE {
 *      descriptionType        OBJECT IDENTIFIER,
 *      issuerName             [0x01] UTF8String,
 *      issuerURL              [0x02] PrintableString OPTIONAL,
 *      subjectName            [0x03] UTF8String,
 *      subjectURL             [0x04] PrintableString OPTIONAL,
 *      termsOfUsage           [0x05] ANY DEFINED BY descriptionType,
 *      redirectURL            [0x06] PrintableString OPTIONAL,
 *      commCertificates       [0x07] SET OF OCTET STRING OPTIONAL
 * }
 * \brief The CertificateDescription class
 */

struct CertificateDescription
{
	Q_DECLARE_TR_FUNCTIONS(CertificateDescription)

	// public is necessary here, because Q_DECLARE_TR_FUNCTIONS leaves
	// the visibility set to private.

	public:
		enum class TermsOfUsageType
		{
			PLAIN_TEXT, HTML, PDF
		};

		ASN1_OBJECT* mDescriptionType;
		ASN1_UTF8STRING* mIssuerName;
		ASN1_PRINTABLESTRING* mIssuerURL;
		ASN1_UTF8STRING* mSubjectName;
		ASN1_PRINTABLESTRING* mSubjectURL;
		ASN1_TYPE* mTermsOfUsage;
		ASN1_PRINTABLESTRING* mRedirectURL;
		STACK_OF(ASN1_OCTET_STRING) * mCommCertificates;


		static QSharedPointer<CertificateDescription> fromHex(const QByteArray& pHexValue);
		static QSharedPointer<CertificateDescription> decode(const QByteArray& pBytes);
		QByteArray encode();

		void setDescriptionType(const QByteArray& pOidAsText);
		QByteArray getDescriptionType() const;

		void setIssuerName(const QString& pIssuerName);
		QString getIssuerName() const;

		void setIssuerUrl(const QString& pIssuerUrl);
		QString getIssuerUrl() const;

		void setSubjectName(const QString& pSubjectName);
		QString getSubjectName() const;

		void setSubjectUrl(const QString& pSubjectUrl);
		QString getSubjectUrl() const;

		TermsOfUsageType getTermsOfUsageType() const;
		QString getTermsOfUsage() const;

		void setRedirectUrl(const QString& pRedirectUrl);
		QString getRedirectUrl() const;

		QSet<QString> getCommCertificates() const;

		/*!
		 * \brief Returns the address of service provider.
		 *
		 * \return The address.
		 */
		QString getServiceProviderAddress() const;

		/*!
		 * \brief Returns the purpose of the certificate description.
		 *
		 * \return The purpose.
		 */
		QString getPurpose() const;

		/*!
		 * \brief Returns the data security officer of the certificate description.
		 *
		 * \return The data security officer.
		 */
		QString getDataSecurityOfficer() const;
};

DECLARE_ASN1_FUNCTIONS(CertificateDescription)
DECLARE_ASN1_OBJECT(CertificateDescription)

}  // namespace governikus
