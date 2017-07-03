/*!
 * \copyright Copyright (c) 2014 Governikus GmbH & Co. KG
 */

#include "StepProcessingGui.h"
#include "generic/BusyOverlayContainer.h"
#include "step/AuthenticateStepsWidget.h"

using namespace governikus;

StepProcessingGui::StepProcessingGui(const QSharedPointer<WorkflowContext>& pContext, AuthenticateStepsWidget* pStepsWidget)
	: StepGui(pContext)
	, mStepsWidget(pStepsWidget)
{
}


StepProcessingGui::~StepProcessingGui()
{
}


void StepProcessingGui::activate()
{
	Q_EMIT setCancelButtonState(ButtonState::ENABLED);
	Q_EMIT setForwardButtonState(ButtonState::HIDDEN);

	mStepsWidget->setCurrentWidget(mStepsWidget->getProcessingPage());
	mStepsWidget->getProcessingPage()->startAnimation();
}


void StepProcessingGui::deactivate()
{
	mStepsWidget->getProcessingPage()->stopAnimation();
}
