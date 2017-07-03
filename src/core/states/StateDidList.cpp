/*!
 * StateDidList.cpp
 *
 * \copyright Copyright (c) 2014 Governikus GmbH & Co. KG
 */

#include "StateDidList.h"
#include "paos/invoke/DidListResponse.h"


using namespace governikus;


StateDidList::StateDidList(const QSharedPointer<WorkflowContext>& pContext)
	: AbstractGenericState(pContext)
{
}


void StateDidList::run()
{
	Q_ASSERT(!getContext()->getDidList().isNull());
	Q_EMIT fireSuccess();
}
