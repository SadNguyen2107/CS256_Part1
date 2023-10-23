// #define NTDDI_VERSION 0x0A000006 //NTDDI_WIN10_RS5
// #define _WIN32_WINNT 0x0A00 // _WIN32_WINNT_WIN10, the _WIN32_WINNT macro must also be defined when defining NTDDI_VERSION

#ifndef GETFILEWINDOW_H
#define GETFILEWINDOW_H

#define FAIL    0
#define SUCCESS 1

#include <windows.h>
#include <shobjidl.h>
#include <objbase.h>
#include <string>
#include <iostream>

//? To Open File Dialog Box
//? Use a COM object called the Common Item Dialog object
//? The Common Item Dialog implements an interface IFileOpenDialog (declared in header file Shobbbjidl.h)

// This Function will return the FilePath
// After open a FileDialog GUI on WINDOWS
int getFileTxtPathWindow(std::string& filePath)
{
    // FLAG
    int success = SUCCESS;

    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE); // Init the COM library
    if (SUCCEEDED(hr))
    {
        IFileOpenDialog *pFileOpen;

        // Create the FileOpenDialog object.
        // Get a Pointer to the object's IFileOpenDialog
        hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void **>(&pFileOpen));

        if (SUCCEEDED(hr))
        {
            // Set the file dialog options
            DWORD dwFlags;
            pFileOpen->GetOptions(&dwFlags);
            pFileOpen->SetOptions(dwFlags | FOS_FORCEFILESYSTEM);

            // Set the file type filter to restrict file selection to .txt files
            COMDLG_FILTERSPEC fileTypes[] = {
                {L"Text Files", L"*.txt"}
            };
            pFileOpen->SetFileTypes(1, fileTypes);

            // Show the Open dialog box.
            hr = pFileOpen->Show(NULL);

            // Get the file name from the dialog box.
            if (hr == HRESULT_FROM_WIN32(ERROR_CANCELLED))   // If the user Pressed Cancel -> Exit
            {
                success = FAIL;
            }
            else if (SUCCEEDED(hr))
            {
                IShellItem *pItem;
                hr = pFileOpen->GetResult(&pItem);
                //? If Succeed return a Shell item object
                //? Shell item which implements IShellItem interface, represent the file that the user selected

                if (SUCCEEDED(hr))
                {
                    PWSTR pszFilePath;
                    hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath); // get the file path in the form of a string

                    // Display the file name to the user.
                    if (SUCCEEDED(hr))
                    {
                        MessageBoxW(NULL, pszFilePath, L"File Path", MB_OK);

                        std::wstring path(pszFilePath);
                        std::string sFilePath(path.begin(), path.end());

                        // Assign the FilePath
                        filePath = sFilePath;

                        CoTaskMemFree(pszFilePath); // For Clean Up Purpose
                        std::cout << filePath << std::endl;
                    }
                    pItem->Release();
                }
            }
            else    // IF THE USER PRESSED [X] Button or an error occured
            {
                success = FAIL;
            }
            pFileOpen->Release();
        }
        CoUninitialize();
    }
    return success;
}

#endif