/*
Copyright 2017-2020 Siemens AG

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without
limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

Author(s): Michael Kraus, Thomas Riedmaier, Abian Blome
*/

#pragma once
#include "IFLUFFIMessageHandler.h"

class CommInt;
class TGTestcaseManager;
class GetTestcaseRequestHandler :
	public IFLUFFIMessageHandler
{
public:
	GetTestcaseRequestHandler(TGTestcaseManager* testcaseManager, std::string testcaseDir, CommInt* commInt);
	virtual ~GetTestcaseRequestHandler();

	void handleFLUFFIMessage(WorkerThreadState* workerThreadState, FLUFFIMessage* req, FLUFFIMessage* resp);

private:
	CommInt* m_CommInt = nullptr;
	std::string m_testcaseDir = "";
	TGTestcaseManager* m_testcaseManager = nullptr;
};
