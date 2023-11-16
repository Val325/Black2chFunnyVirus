#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <filesystem>
#include <wingdi.h>
#include <image.h>
#include <sound_asset.h>
#include <locale.h>
#define WIN32_LEAN_AND_MEAN
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
    std::string filepath = std::string(buf) + "\\" +  imageName + ".png";
    //std::string filepath = std::filesystem::current_path().u8string() + std::string("\\") + imageName + std::string(".png");
    std::cout << "file: " << filepath << std::endl;
    std::cout << "After replace file: " << filepath << std::endl;

    return filepath;
}



int main() {
  setlocale(LC_ALL, "RU");
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);
  //SetConsoleOutputCP(CP_UTF8);


  std::string tempfilepath;

  int hwnd = GetConsoleWindow();
  int hmenu = GetSystemMenu(hwnd, false);
  unsigned int hWindow = EnableMenuItem(hmenu, SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
  
  
  std::cout << "brother, I brought you something to eat" << std::endl;
  std::cout << "%%%%%%%%%######*#%@@@@@@@@@@%%%*+==++-=-*@@@@%##%%#%%%%%@@@@@@@@@@@@%**%######*\n";
  std::cout << "%%%%%%%%%######*#%@@@@@@@@@%%%%*=-======@@%%%#####%##%%%%%@@%@@@@@@@@#*###*##*#\n";
  std::cout << "%%%%%%%%######**#%@@@@@@@@%%%%#+=-===+-#@@@%###***###%#%%%%%#%%%@%@@@%*####****\n";
  std::cout << "%%%%%%%%######**#%@@@@%@@@@%%%#+=-+=-=-%@@%###***+++*###########%%@@@%**##*#**#\n";
  std::cout << "%@%%%%%%%#####**#%@@@%%%%%%%%%#+--==-+=%@@%##***+++==++==++****###%@@%**#*#***#\n";
  std::cout << "@@@@@@@@@%%%##*+#%@@@@@%%%%%%%#+--==-+@@@%%%#***++++===+===++**##%%@@%+#*#%#*#*\n";
  std::cout << "@@@@@@@@@@@@@%#*#%@@@@%%%@%%%%#+=-==-+@@%#%%##++++++==+====+***###%@@#+###*#***\n";
  std::cout << "@@@@@@@@@@@@@@%%%@@@%%%%%%%%%%#+==---*@%##%#**##*+=++++=++++***##%%@%+#*%*****#\n";
  std::cout << "@@@@@@@@@@@@@@@%%@@@%%%%%%%%%%#+===--*@%**#%%#**##+==+++===++**##%%@#+**#*****%\n";
  std::cout << "@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%#+=-===#%#%**%#+-=%%#*++++**#####%%#%@*+#*******#\n";
  std::cout << "@@@@@@@@@@@@@@@%@%%%%%%%%%%%%%#+====*%###*+*#*++==*#==#%%#%####%%#@%#+*#*+****#\n";
  std::cout << "@@@@@@@@@@@@@@@@%%%%%%%####*****#%##%%####+++**++**+=*#+++==#@###%%*#**#**#***#\n";
  std::cout << "@@@@@@@@@@@@@@@@%%###****+++++==+%%#%%####*+++*+###++##*+***##**%%*****#**#***#\n";
  std::cout << "@@@@@@@@@@@@@@@%##****++++=======#%%%%####*++++*##*+*##*++++**#%%*+**#*##******\n";
  std::cout << "@@@@@@@@@@@@%#****++++++=========+%%%%#%#*+++=+#%*==*%*++***##%##****#*#******#\n";
  std::cout << "@@@@@@@@@@@##****++++======----==+##%%%#**+====+%#**#%+=+***##%%%#**#**###**#*#\n";
  std::cout << "@@@@@@@@@%##**++++========------==+#@%%#**+=+++**+**#+==+**##%%**##%%*####***##\n";
  std::cout << "@@@@@@@@%#**++++===========--=-===+#@@%###*++*****#**+==+**##%+++*####%#*#***##\n";
  std::cout << "@@@@@@@%#***+++=============-=====+%%%%%#####%%%#*#***+*+**#%#*++****##%%*#####\n";
  std::cout << "@@@@@@%##**+++==============-====++%%%%%###*#@@@@@@@#**#####*##++++*###*#%#####\n";
  std::cout << "@@@@@@%##**+++=============--==+++*@%%%%%%###*#@@%%%*#%%%%#*###*+=-=*****##%@@%\n";
  std::cout << "@@@@@%##***+++=+++==============++*#%%%%%%%@%%#***#%%%%%##**###**++*++****##%@@\n";
  std::cout << "@@@@@%##***++++++==++==+======++++**%@%%%%%%##%#*#%%@%####*##***+**++++****##%@\n";
  std::cout << "@@@@%%##***++++++++=+++==++++++++++**%@%%@%%%%%%#%@@%########**+=++=+++*****##%\n";
  std::cout << "@@@@%%##****+++++++++++++++++++++++***#@%@@@%@%@%#%##%#####**++======+=++****#%\n";
  std::cout << "@@@@%%##*****++++++++++******+**+******##%%%%##%########*#******+=======++*###%\n";
  std::cout << "@%%@%%####*****++**++++****+**+*********###%#%########**********++++*++*++**##%\n";
  std::cout << "@%@@%%%###*******+**++++**************#*################********+***********##%\n";
  std::cout << "@%%@%%%###***********++****+****###*##*****####*######*********************###%\n";
  std::cout << "@%%%%%###*****####**************#***#######*#**######**#*******+**********####%\n";
  std::cout << "@%%%%%######**##%###*********####*#####################**************####*###%@\n";
  std::cout << "@@%%%##########%%@%####*###*##*######%#%#######**#*###**********#######**###%@%\n";
  std::cout << "@@%%%#########%%%@%%######*########%%#%%%#####%########*******#############%%%%\n";


  
  tempfilepath = std::filesystem::temp_directory_path().u8string();
  std::cout << "Current temp path is " << tempfilepath  << '\n';
  
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

  std::string full_path_image = tempfilepath + std::string("image.png");
  std::string full_path_sound = tempfilepath + std::string("sound.wav");

  std::cout << "full path image: " << full_path_image << "\n";
  std::cout << "full path sound: " << full_path_sound << "\n";
  
  //save byte array to png
  FILE* fp_image = fopen("image.png","wb");
  //316 * 336 is size image. Height and width
  fwrite(black2ch_jpg, sizeof (BYTE) , 316*336 , fp_image);
  fclose(fp_image);

  //save byte array to wav
  FILE* fp_sound = fopen("sound.wav","wb");
  fwrite(phrase_wav, sizeof (BYTE),phrase_wav_len , fp_sound);
  fclose(fp_sound);

  //Move files
  
  try {
    std::filesystem::rename("image.png", full_path_image);
  } catch (std::filesystem::filesystem_error& e) {
    std::cout << e.what() << '\n';
  }

  try {
    std::filesystem::rename("sound.wav", full_path_sound);
  } catch (std::filesystem::filesystem_error& e) {
    std::cout << e.what() << '\n';
  }
  
  //std::string filepathWallpaper = setWallpaper("iChamage");
  //std::wstring filepathWallpaper = L"//image.png";
  //wchar_t buf[256];
  //GetCurrentDirectoryW(256, buf);
  //std::wstring filepathWallpaper = std::wstring(buf) + L"\\image.png";
  LPVOID FilePath = (LPVOID)full_path_image.c_str();

  SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, FilePath, SPIF_UPDATEINIFILE);
  PlaySound(full_path_sound.c_str(), NULL, SND_FILENAME | SND_SYNC);
  
  while (true){
    system("pause");
    system("cls");
  }

}
