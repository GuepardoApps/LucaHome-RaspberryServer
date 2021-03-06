#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>

#include "../../common/utils/Tools.h"

#include "../../common/dto/BirthdayDto.h"
#include "../../common/dto/ChangeDto.h"
#include "../../common/dto/CoinDto.h"
#include "../../common/dto/GpioDto.h"
#include "../../common/dto/InformationDto.h"
#include "../../common/dto/ListedMenuDto.h"
#include "../../common/dto/MapContentDto.h"
#include "../../common/dto/MenuDto.h"
#include "../../common/dto/MeterDataDto.h"
#include "../../common/dto/MoneyMeterDataDto.h"
#include "../../common/dto/PointDto.h"
#include "../../common/dto/PuckJsDto.h"
#include "../../common/dto/ScheduleDto.h"
#include "../../common/dto/ShoppingEntryDto.h"
#include "../../common/dto/UserDto.h"
#include "../../common/dto/WirelessSocketDto.h"
#include "../../common/dto/WirelessSwitchDto.h"

#ifndef XMLWRITER_H
#define XMLWRITER_H

class XmlWriter
{
public:
	XmlWriter();
	~XmlWriter();

	static std::string GenerateBirthdaysXml(std::vector<BirthdayDto>);
	static std::string GenerateChangesXml(std::vector<ChangeDto>);
	static std::string GenerateCoinsXml(std::vector<CoinDto>);
	static std::string GenerateListedMenuXml(std::vector<ListedMenuDto>);
	static std::string GenerateMapContentsXml(std::vector<MapContentDto>);
	static std::string GenerateMenuXml(std::vector<MenuDto>);
	static std::string GenerateMeterDataXml(std::vector<MeterDataDto>);
	static std::string GenerateMoneyMeterDataXml(std::vector<MoneyMeterDataDto>);
	static std::string GenerateSettingsXml(
		int, int, int, 
		std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, 
		std::vector<GpioDto>, std::vector<PuckJsDto>, std::vector<ScheduleDto>, std::vector<WirelessSocketDto>, std::vector<WirelessSwitchDto>);
	static std::string GenerateShoppingListXml(std::vector<ShoppingEntryDto>);
	static std::string GenerateTemperatureSettingsXml(int, int, int, int, int, bool);
	static std::string GenerateUsersXml(std::vector<UserDto>);
};

#endif
