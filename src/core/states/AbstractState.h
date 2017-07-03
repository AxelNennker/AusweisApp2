/*!
 * AbstractState.h
 *
 * \brief Base class for all states taken by the state machine.
 *
 * \copyright Copyright (c) 2014 Governikus GmbH & Co. KG
 */

#pragma once

#include "Result.h"
#include "context/WorkflowContext.h"

#include <QSharedPointer>
#include <QState>


namespace governikus
{


class AbstractState
	: public QState
{
	Q_OBJECT
	Q_DISABLE_COPY(AbstractState)

	template<typename ModelClass> friend class AbstractGenericState;

	private:
		const QSharedPointer<WorkflowContext> mContext;
		const bool mConnectOnCardRemoved;

		AbstractState(const QSharedPointer<WorkflowContext>& pContext, bool pConnectOnCardRemoved);
		virtual void run() = 0;

	protected:
		QVector<QMetaObject::Connection> mConnections;

		void onExit(QEvent* pEvent) override;


		bool isCancellationByUser();
		void setResult(const Result& pResult);

	public:
		static QString getClassName(const char* pName);

		template<typename T>
		static bool isState(const QString& pState)
		{
			return pState == getClassName(T::staticMetaObject.className());
		}


		virtual ~AbstractState();

		void onEntry(QEvent* pEvent) override;

		QString getStateName() const;
		void setStateName(const QString& pName);

	Q_SIGNALS:
		void fireSuccess();
		void fireError();
		void fireCancel();

	public Q_SLOTS:
		void onStateApprovedChanged();
		virtual void onUserCancelled();
		void onCardRemoved(const QString& pReaderName);
};

} /* namespace governikus */
