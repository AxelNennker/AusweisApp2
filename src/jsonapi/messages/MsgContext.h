/*!
 * \brief Context of JSON API.
 *
 * \copyright Copyright (c) 2016 Governikus GmbH & Co. KG
 */

#pragma once

#include "MsgTypes.h"
#include "context/AuthContext.h"
#include "context/WorkflowContext.h"

namespace governikus
{

class MsgContext
{
	Q_DISABLE_COPY(MsgContext)

	protected:
		MsgLevel mApiLevel;
		QList<MsgType> mStateMessages;
		QSharedPointer<WorkflowContext> mContext;

	public:
		MsgContext();

		void setApiLevel(MsgLevel pApiLevel);
		MsgLevel getApiLevel() const;

		MsgType getLastStateMsg() const;

		bool isActiveWorkflow() const;

		QSharedPointer<AuthContext> getAuthContext();
		QSharedPointer<const AuthContext> getAuthContext() const;

		QSharedPointer<WorkflowContext> getWorkflowContext();
		QSharedPointer<const WorkflowContext> getWorkflowContext() const;
};

class MsgDispatcherContext
	: public MsgContext
{
	public:
		void clear();
		void addStateMsg(MsgType pMsgType);
		void setWorkflowContext(const QSharedPointer<WorkflowContext>& pContext);
};

} /* namespace governikus */
