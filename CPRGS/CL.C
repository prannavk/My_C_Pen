#include<windows.h>
#include<stdio.h>

int main() {
    STARTUPINFO startupInfo1;
    PROCESS_INFORMATION processInfo1;
    ZeroMemory(&startupInfo1, sizeof(startupInfo1));
    startupInfo1.cb = sizeof(startupInfo1);
    ZeroMemory(&processInfo1, sizeof(processInfo1));

    if(!CreateProcess(NULL, "CLCHILD.exe", NULL, NULL, FALSE, 0L, NULL, NULL, &startupInfo1, &processInfo1)) {
        fprintf(stderr, "CreateProcess Failed: %d\n", GetLastError());
        return 1;
    }


    printf("\nHello CL\n");

    CloseHandle(processInfo1.hProcess);
    CloseHandle(processInfo1.hThread);

    return 0;
}