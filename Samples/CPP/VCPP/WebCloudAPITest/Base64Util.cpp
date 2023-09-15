#include "pch.h"
#include "Base64Util.h"
#include <iostream>
#include <fstream>


static const std::string base64_chars = \
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"\
"abcdefghijklmnopqrstuvwxyz"\
"0123456789+/";

static inline bool is_base64(BYTE c) 
{
	return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string Base64Util::base64_encode(BYTE const* buf, unsigned int bufLen)
{
    std::string ret;
    int i = 0;
    int j = 0;
    BYTE char_array_3[3];
    BYTE char_array_4[4];

    while (bufLen--) {
        char_array_3[i++] = *(buf++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; (i < 4); i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while ((i++ < 3))
            ret += '=';
    }

    return ret;
}

std::vector<BYTE> Base64Util::base64_decode(std::string const& encoded_string)
{
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    BYTE char_array_4[4], char_array_3[3];
    std::vector<BYTE> ret;

    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret.push_back(char_array_3[i]);
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret.push_back(char_array_3[j]);
    }

    return ret;
}

std::string Base64Util::ConvertToBase64(std::string filePath)
{
    std::basic_ifstream<unsigned char> infSize(filePath.c_str(), std::ios_base::ate | std::ios_base::binary);
    size_t toRead = infSize.tellg();
    infSize.close();
    std::basic_ifstream<unsigned char> inf(filePath.c_str(), std::ios_base::in | std::ios_base::binary);
    std::vector<BYTE> myData;
    myData.resize(toRead);
    inf.read(&myData[0], toRead);
    inf.close();
    return base64_encode(&myData[0], myData.size());
}

bool Base64Util::ConvertFromBase64(std::string base64string, std::string filePathtoSave)
{
    std::vector<BYTE> decodedData = base64_decode(base64string);
    std::basic_ofstream<unsigned char> inf(filePathtoSave.c_str(), std::ios_base::out);
    if(!inf)
    {
        return false;
    }

    for (int i = 0; i < decodedData.size(); i++)
    {
        inf << decodedData[i];
    }
    inf.flush();
    inf.close();
    return true;
}
