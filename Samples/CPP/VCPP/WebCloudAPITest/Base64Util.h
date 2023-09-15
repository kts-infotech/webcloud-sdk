#pragma once
#include <vector>
#include <string>
typedef unsigned char BYTE;

class Base64Util
{
	
	std::string base64_encode(BYTE const* buf, unsigned int bufLen);
	std::vector<BYTE> base64_decode(std::string const&);
public:
	std::string ConvertToBase64(std::string filePath);
	bool ConvertFromBase64(std::string base64string, std::string filePathtoSave);
};

