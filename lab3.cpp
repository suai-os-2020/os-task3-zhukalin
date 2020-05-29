#include <windows.h>
#include <iostream>
#include "lab3.h"

using namespace std;
//
// lab3 code should be located here!
//

#define THREADCOUNT 11

HANDLE Threads[THREADCOUNT],sem[3],mut;

DWORD WINAPI ThreadA(LPVOID);
DWORD WINAPI ThreadB(LPVOID);
DWORD WINAPI ThreadC(LPVOID);
DWORD WINAPI ThreadD(LPVOID);
DWORD WINAPI ThreadE(LPVOID);
DWORD WINAPI ThreadG(LPVOID);
DWORD WINAPI ThreadF(LPVOID);
DWORD WINAPI ThreadH(LPVOID);
DWORD WINAPI ThreadK(LPVOID);
DWORD WINAPI ThreadM(LPVOID);
DWORD WINAPI ThreadI(LPVOID);

DWORD ThreadID;


unsigned int lab3_thread_graph_id() 
{
    return 11;
}

const char* lab3_unsynchronized_threads()
{
    return "bcde";
}

const char* lab3_sequential_threads()
{
    return "deg";
}


DWORD WINAPI ThreadA(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'a' << flush;
		computation();
		ReleaseMutex(mut);
	}
	return 0;
};

DWORD WINAPI ThreadD(LPVOID name)
{
for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'd' << flush;
		computation();
		ReleaseMutex(mut);
	}
    //wait a
	WaitForSingleObject(Threads[0], INFINITE);
	
	Threads[2] = CreateThread(NULL, 0, ThreadE, NULL, 0, &ThreadID);
	Threads[3] = CreateThread(NULL, 0, ThreadB, NULL, 0, &ThreadID);
	Threads[4] = CreateThread(NULL, 0, ThreadC, NULL, 0, &ThreadID);


	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'd' << flush;
		computation();
		ReleaseMutex(mut);
	}
	//wait b
	WaitForSingleObject(Threads[3], INFINITE);

	Threads[5] = CreateThread(NULL, 0, ThreadF, NULL, 0, &ThreadID);

	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'd' << flush;
		computation();
		ReleaseMutex(mut);
	}
	//wait f
	WaitForSingleObject(Threads[5], INFINITE);
	//wait c
	WaitForSingleObject(Threads[4], INFINITE);

	Threads[6] = CreateThread(NULL, 0, ThreadG, NULL, 0, &ThreadID);

	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(sem[0], INFINITE);
		WaitForSingleObject(mut, INFINITE);
		cout << 'd' << flush;
		computation();
		ReleaseMutex(mut);
		ReleaseSemaphore(sem[1], 1, NULL);
	}
	//wait g
	WaitForSingleObject(Threads[6], INFINITE);
	//wait e
	WaitForSingleObject(Threads[2], INFINITE);

	Threads[7] = CreateThread(NULL, 0, ThreadH, NULL, 0, &ThreadID);
	Threads[8] = CreateThread(NULL, 0, ThreadI, NULL, 0, &ThreadID);
	Threads[9] = CreateThread(NULL, 0, ThreadK, NULL, 0, &ThreadID);

	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'd' << flush;
		computation();
		ReleaseMutex(mut);
	}
	
	return 0;
};
 
DWORD WINAPI ThreadB(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'b' << flush;
		computation();
		ReleaseMutex(mut);
	}
	return 0;
};

DWORD WINAPI ThreadC(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'c' << flush;
		computation();
		ReleaseMutex(mut);
	}
	//wait b
	WaitForSingleObject(Threads[3], INFINITE);

	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'c' << flush;
		computation();
		ReleaseMutex(mut);
	}

	return 0;

};
DWORD WINAPI ThreadE(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'e' << flush;
		computation();
		ReleaseMutex(mut);
	}
	//wait b
	WaitForSingleObject(Threads[3], INFINITE);

	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'e' << flush;
		computation();
		ReleaseMutex(mut);
	}

	//wait f
	WaitForSingleObject(Threads[5], INFINITE);
	//wait c
	WaitForSingleObject(Threads[4], INFINITE);

	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(sem[1], INFINITE);
		WaitForSingleObject(mut, INFINITE);
		cout << 'e' << flush;
		computation();
		ReleaseMutex(mut);
		ReleaseSemaphore(sem[2], 1, NULL);
	}
	
	return 0;
};
DWORD WINAPI ThreadF(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'f' << flush;
		computation();
		ReleaseMutex(mut);
	}
	return 0;
};
DWORD WINAPI ThreadG(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(sem[2], INFINITE);
		WaitForSingleObject(mut, INFINITE);
		cout << 'g' << flush;
		computation();
		ReleaseMutex(mut);
		ReleaseSemaphore(sem[0], 1, NULL);
	}
	return 0;
};

DWORD WINAPI ThreadH(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'h' << flush;
		computation();
		ReleaseMutex(mut);
	}
	return 0;
};

DWORD WINAPI ThreadI(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'i' << flush;
		computation();
		ReleaseMutex(mut);
	}
	return 0;
};

DWORD WINAPI ThreadK(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'k' << flush;
		computation();
		ReleaseMutex(mut);
	}

	//wait d
	WaitForSingleObject(Threads[1], INFINITE);
	//wait h
	WaitForSingleObject(Threads[7], INFINITE);
	//wait i
	WaitForSingleObject(Threads[8], INFINITE);
	Threads[10] = CreateThread(NULL, 0, ThreadM, NULL, 0, &ThreadID);


	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'k' << flush;
		computation();
		ReleaseMutex(mut);
	}
	return 0;
};
DWORD WINAPI ThreadM(LPVOID name)
{
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(mut, INFINITE);
		cout << 'm' << flush;
		computation();
		ReleaseMutex(mut);
	}
	return 0;
};


int lab3_init()
{
    mut = CreateMutex(NULL, 0, NULL);
	if (mut == NULL) {
		cout << "CreateMutex error: " << GetLastError();
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		sem[i] = CreateSemaphore(NULL, i == 0 ? 1 : 0, 1, NULL);
		if (sem[i] == NULL) {
			cout << "CreateSemaphore error: " << GetLastError();
			return 1;
		}
	}
  
	Threads[0] = CreateThread(NULL, 0, ThreadA, NULL, 0, &ThreadID);
    Threads[1] = CreateThread(NULL, 0, ThreadD, NULL, 0, &ThreadID);
	//wait a
	WaitForSingleObject(Threads[0], INFINITE);
	//wait d
	WaitForSingleObject(Threads[1], INFINITE);
	//wait k
	WaitForSingleObject(Threads[9], INFINITE);
	//wait m
	WaitForSingleObject(Threads[10], INFINITE);

    for (int i = 0; i < THREADCOUNT; i++)
       CloseHandle(Threads[i]);

   CloseHandle(mut);
   for (int i = 0; i < 3; i++) {
	   CloseHandle(sem[i]);
   }

    return 0;
}
