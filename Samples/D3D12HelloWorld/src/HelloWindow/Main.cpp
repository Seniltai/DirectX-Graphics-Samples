//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#include "stdafx.h"
#include "D3D12HelloWindow.h"

#include <thread>

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	//const int NumThreads = 1;		// works
	const int NumThreads = 2;		// does not work
	std::thread threads[NumThreads];
	
	for (int i = 0; i < NumThreads; i++)
	{
		threads[i] = std::thread([&](int i) {
			D3D12HelloWindow sample(1280, 720, L"D3D12 Hello Window");
			Win32Application::Run(&sample, hInstance, nCmdShow);
		}, i);
	}

	for (int i = 0;i < NumThreads; i++)
		threads[i].join();

	return 0;
}
