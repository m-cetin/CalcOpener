#include <windows.h>
#include "pch.h"

void ExecuteCalc() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Erstelle den Prozess
    if (!CreateProcess(TEXT("C:\\Windows\\System32\\calc.exe"),   // Pfad zur Anwendung
        NULL,           // Befehlszeilenargumente
        NULL,           // Prozesshandle des Elternprozesses
        NULL,           // Threadhandle des Elternprozesses
        FALSE,          // Handhabung der Vererbung von Handles
        0,              // Erstellungsschöpfungswährend Flaggen
        NULL,           // Umgebungsblock für das neue Verfahren
        NULL,           // Aktuelles Verzeichnis für das neue Verfahren
        &si,            // STARTUPINFO-Struktur
        &pi             // PROCESS_INFORMATION-Struktur
    )) {
        MessageBox(NULL, TEXT("CreateProcess failed!"), TEXT("Error"), MB_ICONERROR);
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        // wenn die DLL in einem Prozess geladen wird
        ExecuteCalc();
        break;

    case DLL_PROCESS_DETACH:
        // wenn die DLL aus einem Prozess entfernt wird
        break;

    case DLL_THREAD_ATTACH:
        // wenn neuer Thread in einem Prozess erstellt wird
        break;

    case DLL_THREAD_DETACH:
        // wenn Thread aus einem Prozess entfernt wird
        break;
    }
    return TRUE;
}
