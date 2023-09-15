#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"
#include <vector>

class ItemInfo1
{
public:
	ItemInfo1()
	{
		Text = _T("");
		Value = 0;
	}
	CString Text;
	int Value;
};




class Activation
{
public:
	Activation()
	{

	}
	CString Key, LicenseMode, RegistrationKey, RegistrationName, UserName, ExpirationDate, Save;
};


class GetLicenseInfo
{
public:
	GetLicenseInfo()
	{

	}
	CString selectPrdt, Macid;
};
class NewUserRegInfo
{
public:
	NewUserRegInfo()
	{

	}
	CString
		CustomerName, ProductSubID, HardwareID, PhoneNo, EmailID, Address, RegKey, LicenseStatus, MachineName, ProductName, ProductID, IsUnlimitedLicense, LicenseName, NoOfDays, DateofEntry, EmailStatus, PersonName, LicensePassword, LicenseID, RemainingDays, AllowedFeatures, DisabledFeatures, InitialLicense;
};