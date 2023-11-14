#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <filesystem>
#include <wingdi.h>
#pragma comment(lib, "winmm.lib")

void replace_all(
    std::string& s,
    std::string const& toReplace,
    std::string const& replaceWith
) {
    std::string buf;
    std::size_t pos = 0;
    std::size_t prevPos;

    // Reserves rough estimate of final size of string.
    buf.reserve(s.size());

    while (true) {
        prevPos = pos;
        pos = s.find(toReplace, pos);
        if (pos == std::string::npos)
            break;
        buf.append(s, prevPos, pos - prevPos);
        buf += replaceWith;
        pos += toReplace.size();
    }

    buf.append(s, prevPos, s.size() - prevPos);
    s.swap(buf);
}

std::string setWallpaper(std::string imageName)
{
    // Get the current directory and store it into a char string
    char buf[256];
    GetCurrentDirectoryA(256, buf);
    std::string filepath = std::string(buf) + std::string("\\pahom\\") + imageName + ".png";
    std::cout << "file: " << filepath << std::endl;
    std::cout << "After replace file: " << filepath << std::endl;

    return filepath;
}

int main() {
  std::cout << "brother, I brought you something to eat" << std::endl;

  //
  // change resolution screen
  //
  
  UINT32 numPathArrayElements=0, numModeInfoArrayElements = 0;
  UINT32 filter = QDC_ALL_PATHS;
  GetDisplayConfigBufferSizes(filter,&numPathArrayElements, &numModeInfoArrayElements);

  DISPLAYCONFIG_PATH_INFO* pathArray = new DISPLAYCONFIG_PATH_INFO[numPathArrayElements];
  DISPLAYCONFIG_MODE_INFO* modeInfoArray = new DISPLAYCONFIG_MODE_INFO[numModeInfoArrayElements];
  ZeroMemory(pathArray, sizeof(DISPLAYCONFIG_PATH_INFO)* numPathArrayElements);
  ZeroMemory(modeInfoArray, sizeof(DISPLAYCONFIG_MODE_INFO)* numModeInfoArrayElements);
  QueryDisplayConfig(filter,&numPathArrayElements,pathArray,&numModeInfoArrayElements,modeInfoArray,NULL);

  int ix = pathArray[0].sourceInfo.modeInfoIdx; //assuming path[0] is primary
  modeInfoArray[ix].sourceMode.width = 1280;
  modeInfoArray[ix].sourceMode.height = 720;
  SetDisplayConfig(numPathArrayElements, pathArray, numModeInfoArrayElements, modeInfoArray, SDC_APPLY | SDC_USE_SUPPLIED_DISPLAY_CONFIG | SDC_ALLOW_CHANGES | SDC_SAVE_TO_DATABASE);
 
  UINT32 numPathArrayElements=0, numModeInfoArrayElements = 0;
  UINT32 filter = QDC_ALL_PATHS;
  GetDisplayConfigBufferSizes(filter,&numPathArrayElements, &numModeInfoArrayElements);

  DISPLAYCONFIG_PATH_INFO* pathArray = new DISPLAYCONFIG_PATH_INFO[numPathArrayElements];
  DISPLAYCONFIG_MODE_INFO* modeInfoArray = new DISPLAYCONFIG_MODE_INFO[numModeInfoArrayElements];
  ZeroMemory(pathArray, sizeof(DISPLAYCONFIG_PATH_INFO)* numPathArrayElements);
  ZeroMemory(modeInfoArray, sizeof(DISPLAYCONFIG_MODE_INFO)* numModeInfoArrayElements);
  QueryDisplayConfig(filter,&numPathArrayElements,pathArray,&numModeInfoArrayElements,modeInfoArray,NULL);

  int ix = pathArray[0].sourceInfo.modeInfoIdx; //assuming path[0] is primary
  modeInfoArray[ix].sourceMode.width = 1280;
  modeInfoArray[ix].sourceMode.height = 720;
  SetDisplayConfig(numPathArrayElements, pathArray, numModeInfoArrayElements, modeInfoArray, SDC_APPLY | SDC_USE_SUPPLIED_DISPLAY_CONFIG | SDC_ALLOW_CHANGES | SDC_SAVE_TO_DATABASE);

  
  std::string filepathWallpaper = setWallpaper("black2ch");
  LPVOID FilePath = (LPVOID)filepathWallpaper.c_str();

  SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, FilePath, SPIF_UPDATEINIFILE);
  PlaySound("phrase.wav", NULL, SND_FILENAME | SND_SYNC);
}
