//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2025 Ryo Suzuki
//	Copyright (c) 2016-2025 OpenSiv3D Project
//
//	Copyright (c) 2025      Ryoga-exe
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <iostream>
# include <Siv3D/System/ISystem.hpp>
# include <Siv3D/Error.hpp>
# include <Siv3D/Engine/Siv3DEngine.hpp>
# include <Siv3D/FreestandingMessageBox/FreestandingMessageBox.hpp>
# include <Siv3D/EngineLog.hpp>

void Main();

namespace s3d::detail::init
{
	void InitCommandLines();
}

int ios_main()
{
	using namespace s3d;
	
	std::clog << "OpenSiv3D for iOS\n";
	
	detail::init::InitCommandLines();
	
	Siv3DEngine engine;
	
	try
	{
		SIV3D_ENGINE(System)->init();
	}
	catch (const Error& error)
	{
		FreestandingMessageBox::ShowError(error.messageUTF8());
		std::cerr << error << '\n';
		return -1;
	}

	LOG_DEBUG("Main() ---");

	Main();
	
	LOG_DEBUG("--- Main()");
    
    return 0;
}
