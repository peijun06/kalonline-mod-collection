/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 
#include <MadCore.h>
#include "MadEggExp.h"


#pragma comment(lib, "MadLib.lib")

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
	IMemory *Memory = new IMemory;
	MadCore core(ul_reason_for_call);
	core.Register(&(PVOID&)Server::CIOServer::Start, MadEggExp::CIOServer::Start);
	//Memory->HookAPI(0x0042F030,EggExp);
	core.Register(&(PVOID&)Server::CPlayer::CPlayer__UpdateTransformExp, CPlayer__UpdateTransformExp);
	return core.Run();
}