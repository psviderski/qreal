#pragma once

#include <commonTwoDModel/engine/configurer.h>

namespace trikKitInterpreter {

class TrikTwoDModelConfigurer : public twoDModel::Configurer
{
public:
	TrikTwoDModelConfigurer(QString const &leftWheelPort, QString const &rightWheelPort);

	QString robotImage() const override;
	interpreterBase::robotModel::PortInfo defaultLeftWheelPort() const override;
	interpreterBase::robotModel::PortInfo defaultRightWheelPort() const override;

private:
	QString const mLeftWheelPort;
	QString const mRightWheelPort;
};

}