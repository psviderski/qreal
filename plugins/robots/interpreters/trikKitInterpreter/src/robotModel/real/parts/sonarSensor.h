#pragma once

#include "robotModel/parts/trikSonarSensor.h"

namespace trikKitInterpreter {
namespace robotModel {
namespace real {
namespace parts {

class SonarSensor : public robotModel::parts::TrikSonarSensor
{
	Q_OBJECT

public:
	SonarSensor(interpreterBase::robotModel::DeviceInfo const &info
			, interpreterBase::robotModel::PortInfo const &port);

	void read() override;
};

}
}
}
}
