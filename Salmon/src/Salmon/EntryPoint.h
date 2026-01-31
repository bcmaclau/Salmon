#pragma once

#ifdef SMN_PLATFORM_WINDOWS

extern Salmon::Application* Salmon::CreateApplication();

int main(int argc, char** argv) {

	auto app = Salmon::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif
