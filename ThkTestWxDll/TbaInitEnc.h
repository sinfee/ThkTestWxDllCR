#pragma once

class TbaInitEnc
{
public:
	TbaInitEnc();
	~TbaInitEnc();
public:
	bool InitEnc();
	bool InitEnc(int argc,char* argv[]);
	void FreeEnc();

public:
	TbaString m_strEnvDll;
};

