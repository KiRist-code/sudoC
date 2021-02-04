#include<iostream>
#include<stdlib.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>

using namespace std;

int main(int argc, char** argv){

    if(IsUserAnAdmin() == false) {
        BOOL bShellExecute = FALSE;
        SHELLEXECUTEINFO stShellInfo = { sizeof(SHELLEXECUTEINFO) }; // 구조체 초기화

        try{
            stShellInfo.lpVerb = TEXT("runas");
            stShellInfo.lpFile = TEXT("./sudo.cpp");
        }
        catch(int e){
            printf("[ERROR Code] : %d",e);
        }

        stShellInfo.nShow = SW_SHOWNORMAL;                               
        bShellExecute = ShellExecuteEx(&stShellInfo);

        if(!bShellExecute)
        {
            DWORD dwStatus = GetLastError();
            if(dwStatus == ERROR_CANCELLED)
            {
                printf("[ERROR] Permission Denied");
            }
            else if (dwStatus == ERROR_FILE_NOT_FOUND)
            {
                printf("[ERROR] Sudo-Excute-File is not exist ");
            }
        }
    }

}
