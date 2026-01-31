#include <Salmon.h>

class Sandbox : public Salmon::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Salmon::Application* Salmon::CreateApplication() {
	return new Sandbox();
}