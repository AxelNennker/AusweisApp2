/*
 * StateWriteHistory.h
 *
 *
 * \brief Writes the history entry .
 *
 * \copyright Copyright (c) 2014 Governikus GmbH & Co. KG
 */

#pragma once

#include "context/AuthContext.h"
#include "states/AbstractGenericState.h"


namespace governikus
{

class StateWriteHistory
	: public AbstractGenericState<AuthContext>
{
	Q_OBJECT
	friend class StateBuilder;

	StateWriteHistory(const QSharedPointer<WorkflowContext>& pContext);
	virtual void run() override;
};

} /* namespace governikus */
